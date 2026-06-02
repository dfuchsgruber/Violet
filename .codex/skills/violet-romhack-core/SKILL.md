---
name: violet-romhack-core
description: Work in the Pokemon Violet FireRed romhack repository outside narrow data-model tasks. Use for build flow, repo navigation, C/Thumb hooks, assets, scripts, generated symbols, save/flags/vars, language handling, map/project wiring, and general coding changes in Violet.
---

# Violet Romhack Core

## First Pass

1. Work from the repository root that contains `Violet/makefile`.
2. Inspect the nearby subsystem under `Violet/src/<domain>/` and matching headers under `Violet/include/c/<domain>/` before editing.
3. Prefer existing engine helpers over new abstractions: `callback1_set`, `big_callback_new`, `tbox_*`, `bg_*`, `oam_*`, `var_access`, `checkflag`, `setflag`, and generated constants headers.
4. Use generated constants from `Violet/constants/**/*.const` via `include/c/constants/*.h` or `include/as/constants/*.s`; trigger `violet-constants` for constant table work.
5. Use `.pms` and `Violet/models/*.py` for structured ROM data; trigger `violet-pms-models` for PMS/model changes.

## Read When Needed

Read `references/architecture.md` for layout, build, hooks, assets, strings, save memory, and validation notes.

Read `references/c-feature-patterns.md` before adding a new C/H feature or when matching repository coding style and construction conventions.

Read `references/bug-notes.md` before changing battle damage, Pokemon generation, or anything found by TODO/bug scans.

Trigger `violet-gba-hardware` when a change touches hardware timing, memory placement, VRAM/OAM/palette access, DMA, interrupts, input sampling, sound timers/FIFOs, or cartridge/save behavior.

## Project Rules

- C is built as C99 Thumb code with `-Wall -Werror -Wextra -Wconversion -O2`; keep casts explicit and warnings clean.
- The linked overlay is imported by armips at `0x09000000`; do not assume normal hosted C runtime behavior.
- RAM and ROM are scarce. Minimize storage widths in structs and persistent data: prefer `u8`, `u16`, and bitfields such as `u8 flag : 1` over `bool` when storing state, because `bool` is 4 bytes in this codebase.
- New persistent game state should usually go in `custom_memory csave` or existing saveblock slack only after checking layout impact.
- User-facing text usually needs both German and English through `LANGDEP(PSTRING(...), PSTRING(...))` in C or `.ifdef LANG_GER` / `.elseif LANG_EN` in assembly.
- Match the local feature shape: table-driven registries, heap-backed UI state, script-facing special/callasm glue, persistent `csave` state, or stateless service helpers.
- Avoid editing generated headers under `Violet/include/c/constants/` and `Violet/include/as/constants/`.
- Avoid touching `Violet/bld/` outputs except by running build/index tools.

## Fast Checks

```bash
python -m py_compile Violet/tools/index/*.py Violet/models/*.py
nix --extra-experimental-features 'nix-command flakes' develop -c make -C Violet bld/violet.gba
```
