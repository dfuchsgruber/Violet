# Mapping Hardware Concepts To Violet Skills

Use this file to decide which Violet skill/reference to combine with hardware notes.

## UI Skill

Combine with `violet-gba-ui` when touching:

- `callback1_set`, `generic_callback1`, custom screen pumps,
- `big_callback_new` tasks,
- BG/tbox setup,
- OAM sprites and arrows,
- list menus,
- fades and transitions.

Hardware relationship:

- The 59.7 Hz frame and limited VBlank window explain why UI creation is split across states.
- `generic_vblank_handler` is where queued OAM attributes, graphics, palettes, and DMA work are flushed.
- List menu input belongs in big callbacks because keypad state is sampled once per frame and tasks are proceeded by the frame pump.

## Romhack Core Skill

Combine with `violet-romhack-core` when touching:

- C/Thumb hooks,
- linker/import behavior,
- save memory,
- generated assets,
- low-level helper APIs,
- performance-sensitive engine code.

Hardware relationship:

- C runs in a ROM/Thumb-oriented environment, not a hosted OS process.
- IWRAM/EWRAM placement matters.
- Game Pak ROM/SRAM/Flash have different bus widths and DMA permissions.

## Battle/Pokemon Skill

Combine with `violet-battle-pokemon` for:

- hot battle loops,
- data tables read every turn/frame,
- party/Pokemon structs,
- move/item/ability effects.

Hardware relationship:

- Avoid per-frame or per-hit scans over large ROM data where existing lookup tables/cache fields exist.
- Be mindful of EWRAM/IWRAM and stack usage in battle callbacks.

## Constants/PMS Skills

Combine with `violet-constants` or `violet-pms-models` for:

- generated constants,
- generated structured data,
- ROM-resident data tables and assets.

Hardware relationship:

- Data may ultimately live in ROM and be read through a 16-bit Game Pak bus.
- Generated headers should describe IDs/data; feature code should still use engine helpers for transferring display data to VRAM/OAM/palette memory.

