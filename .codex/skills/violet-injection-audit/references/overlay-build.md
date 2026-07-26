# Overlay Build And Memory Map

## Pipeline

`Violet/makefile` recursively discovers C, assembly, PMS, map, and asset inputs. `pypreproc` runs before GCC/as. C is C99 Thumb/interworking ARM7TDMI with long calls, no builtins, and warnings as errors. `ld -r` resolves overlay symbols and FireRed engine symbols from `bprd.sym`. Armips opens the base ROM at `0x08000000`, applies fixed-address patches, and imports `bld/linked.o` at `0x09000000`.

`patches.asm` includes global hooks, music, and overworld patches before importing the overlay. Domain patch files are included through `patches/hooks.asm`.

## Linked Sections

`linker.ld` retains only:

- `.text*` and `.rodata*` in ROM from `0x09000000`
- `free_ewram` as NOLOAD at `0x0203B174`, limited to `0x4000` bytes

Everything else is discarded. Use the `EWRAM` section macro from `include/c/types.h` for mutable overlay globals. Ensure initialization explicitly clears or assigns NOLOAD state before any hook reads it.

At the 2026-07 audit baseline, `linked.o` used about 4,394,396 bytes of text, 6,830,264 bytes of rodata, and 5,744 bytes of the 16,384-byte EWRAM window; the overlay ended near `0x09AB4660`.

## Bounds Hazard

The linker declares 32 MiB beginning at `0x09000000`, but a 32 MiB GBA ROM mapped from `0x08000000` ends at `0x0A000000`. Linking can therefore succeed with an impossible cartridge address. Independently verify:

- the last imported ROM byte is below `0x0A000000`;
- the final ROM file is no larger than 32 MiB;
- `free_ewram` ends no later than `0x0203F174`;
- no required initialized `.data` or zeroed `.bss` was discarded.

The default postpatch validation only indexes worldmap positions; it does not prove these bounds.
