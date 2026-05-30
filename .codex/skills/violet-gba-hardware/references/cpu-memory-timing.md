# CPU, Memory, And Timing

Source: GBATEK GBA Reference, especially "GBA Technical Data", "GBA Memory Map", and "LCD Dimensions and Timings": https://mgba-emu.github.io/gbatek/

## CPU

- CPU: ARM7TDMI at `16 * 1024 * 1024 Hz` (`16.78 MHz`).
- Instruction modes:
  - ARM: 32-bit opcodes.
  - THUMB: 16-bit opcodes.
- Game Pak ROM is a 16-bit bus, so ROM-resident THUMB code is usually better density/performance for ordinary C. ARM code is best when copied to internal WRAM and justified by hot-path needs.
- Violet's C build is Thumb-oriented; match local hook/assembly conventions before changing code mode assumptions.

## Frame Budget

- Screen: 240x160.
- Refresh: about `59.737 Hz`.
- One frame: about `280,896` CPU cycles.
- Visible draw period: 160 scanlines, about `197,120` cycles.
- VBlank: 68 scanlines, about `83,776` cycles.
- Per scanline: `1,232` cycles total; visible drawing is `960`, HBlank is `272`.

Implications for Violet:

- Spread setup work across `callback1` state machines and `big_callback` tasks.
- Keep per-frame callbacks small.
- Large decompression/copy/list-building work should be staged, queued, or done while the display is blank/fading.

## Memory Map

Common regions:

- BIOS: `0x00000000-0x00003FFF`, 16 KiB.
- EWRAM/on-board WRAM: `0x02000000-0x0203FFFF`, 256 KiB, slower 16-bit bus.
- IWRAM/on-chip WRAM: `0x03000000-0x03007FFF`, 32 KiB, fast 32-bit bus.
- I/O registers: `0x04000000-0x040003FE`.
- Palette RAM: `0x05000000-0x050003FF`, 1 KiB.
- VRAM: `0x06000000-0x06017FFF`, 96 KiB.
- OAM: `0x07000000-0x070003FF`, 1 KiB.
- Game Pak ROM: `0x08000000-0x0DFFFFFF` mirrored across wait-state regions.
- Game Pak SRAM/Flash area: `0x0E000000-0x0E00FFFF`, 8-bit bus.

Violet naming:

- `EWRAM` globals live in slow 256 KiB WRAM and are common for heap-backed UI/global state.
- IWRAM is scarce and should be reserved for hot engine data/code/stacks or local patterns that already require it.

## Access Widths

- IWRAM and I/O are fast 32-bit regions.
- EWRAM is slower and 16-bit wide; 32-bit access costs more cycles.
- VRAM and palette RAM are 16-bit wide; 32-bit access is allowed and often useful for copies.
- OAM, palette RAM, and VRAM should be treated as 16/32-bit write targets. Avoid byte writes.
- Game Pak SRAM is byte-only and CPU-only; DMA cannot access it.

## Endianness

GBA is little-endian. Multi-byte values store the least significant byte at the lowest address.

