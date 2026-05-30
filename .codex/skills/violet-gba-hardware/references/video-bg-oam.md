# Video, BGs, OAM, And Palettes

Source: GBATEK GBA LCD Video Controller sections: https://mgba-emu.github.io/gbatek/#gbalcdvideocontroller

## Display Controller

Important `DISPCNT` concepts:

- BG modes 0-2 are tile/map based.
- BG modes 3-5 are bitmap based.
- BG0-BG3 and OBJ display are enabled separately.
- Forced blank allows fast access to VRAM, palette RAM, and OAM.
- One-dimensional OBJ character mapping is commonly used by GBA engines for simpler sprite tile allocation.

Violet mostly uses tile/map BG screens with helpers like `bg_setup`, `bg_set_tilemap`, `bg_decompress_vram`, `bg_copy_rectangle`, and `bg_virtual_sync_reqeust_push`.

## BGs

For text/tile BG modes:

- BG priority is 0-3, where 0 is highest.
- Character base blocks are 16 KiB units.
- Screen base blocks are 2 KiB units.
- A 32x32 tilemap is 2 KiB, matching the common `malloc_and_clear(0x800)` pattern.
- Screen sizes above 32x32 consume adjacent 2 KiB screen blocks.

Violet implications:

- Do not let BG char/map base allocations overlap across active layers.
- Keep tbox tile reservations non-overlapping inside a BG char block.
- Queue BG sync/copy work; do not assume direct writes instantly appear on screen.

## Palettes

- Palette RAM is 1 KiB: 256 BG colors and 256 OBJ colors.
- Colors are 15-bit BGR values stored in 16-bit entries.
- Color index 0 is transparent for BG/OBJ palettes; BG palette 0 color 0 is also the backdrop color.

Violet implications:

- Use existing palette helpers such as `pal_decompress`, `pal_proceed`, fade helpers, and local OAM palette allocation/free helpers.
- Be careful writing palettes during fades; nearby code often checks `fading_is_active()`.

## OAM And Sprites

- OAM holds 128 OBJ entries plus rotation/scaling data.
- Sprite priority against BGs is 0-3, where 0 is highest.
- Hardware supports many sprite sizes from 8x8 to 64x64, but line budget and OBJ tile memory still matter.
- OAM memory is timing-sensitive; Violet maintains shadow OAM and copies attributes during VBlank.

Violet implications:

- Use `oam_new_forward_search`, `oam_free`, `oam_gfx_load`, `oam_pal_load`, and local wrappers.
- Keep OAM callbacks tiny: position, animation, visibility, palette tick. Put scans/list decisions in big callbacks.
- Free OAM graphics/palettes with the matching local helper and reset IDs to the local inactive marker, often `0xFF`.

## VBlank And HBlank

- VRAM, OAM, and palette RAM are all safely accessible during VBlank.
- VRAM and palette RAM can be accessed in HBlank; OAM in HBlank requires the DISPCNT HBlank-free bit and reduces sprite capacity.
- CPU access outside blanking inserts waits rather than losing data, but doing too much visible-period video memory work steals cycles and can cause stalls.

Violet implications:

- Prefer the engine's queues and VBlank pump (`generic_vblank_handler`) for OAM/graphics/palettes/DMA.
- Staged UI setup should wait for fade/DMA state before switching modes or freeing resources.

