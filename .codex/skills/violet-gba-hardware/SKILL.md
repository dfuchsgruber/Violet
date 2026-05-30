---
name: violet-gba-hardware
description: Use GBATEK-informed Game Boy Advance hardware constraints when coding Violet: ARM7TDMI timing, WRAM/IWRAM/EWRAM, VRAM/OAM/palette access, BG modes, sprites, DMA, VBlank/HBlank, interrupts, keypad polling, sound timers/FIFOs, Game Pak ROM/SRAM/Flash, and performance-sensitive C/Thumb code.
---

# Violet GBA Hardware

## Core Workflow

1. Identify which hardware surface the code touches: CPU/timing, memory, display, DMA/interrupts/input, sound, or cartridge/save.
2. Prefer Violet's wrapper APIs (`bg_*`, `oam_*`, `pal_*`, `dma*`, `tbox_*`, `callback1_set`, `big_callback_new`) over direct register writes unless the nearby code is already low-level.
3. Respect the frame budget: the GBA runs at about 16.78 MHz and one frame is about 280,896 cycles. Split expensive work across callbacks/tasks.
4. Treat VRAM, OAM, and palette writes as timing-sensitive. Queue them for VBlank/DMA helpers or update during staged setup/fade/forced blank.
5. Keep keypad reads centralized through `super.keys*`; GBATEK recommends sampling input once per frame.
6. When in doubt, read the smallest relevant reference below and then inspect the matching Violet helper implementation.

## Read When Needed

- `references/cpu-memory-timing.md`: CPU speed, ARM/Thumb, memory map, EWRAM/IWRAM, access widths, endianness, frame timing.
- `references/video-bg-oam.md`: LCD controller, BG modes, tilemaps, palettes, OAM/sprites, VBlank/HBlank display timing.
- `references/dma-interrupt-input.md`: DMA channels, VBlank/HBlank DMA, interrupt rules, keypad registers and per-frame input.
- `references/sound-cartridge-save.md`: DMA sound, timers, Game Pak ROM, SRAM/Flash/EEPROM implications.
- `references/violet-mapping.md`: how these hardware facts map to Violet's existing skills and helper APIs.

## Project Rules

- Do not add all-in-one UI constructors that decompress graphics, allocate tilemaps, create OAMs, and start list menus in a single frame.
- Do not process normal UI input in interrupt handlers or hardware keypad IRQs; use `super.keys_new` / `super.keys_new_and_repeated` from the frame loop.
- Do not write arbitrary bytes to VRAM, palette RAM, or OAM. These regions are effectively 16/32-bit oriented in practice, and Violet already has helpers for copying/queueing.
- Use DMA helpers for large graphics/tilemap/palette copies and check `dma3_busy(-1)` around transitions that depend on the result.
- Be conservative with IWRAM (`0x03000000`, 32 KiB fast WRAM). It is valuable for stacks, interrupt state, hot code/data, and engine globals.
- Prefer THUMB-sized code for ROM-resident C unless a local assembly/hook pattern proves otherwise; ARM code runs best from internal WRAM, not Game Pak ROM.

## Source

Hardware notes are condensed from GBATEK, especially the GBA Reference sections: https://mgba-emu.github.io/gbatek/
