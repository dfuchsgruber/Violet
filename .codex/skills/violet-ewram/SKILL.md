---
name: violet-ewram
description: Enforce Violet's EWRAM placement rule for mutable C storage. Use whenever adding, changing, or reviewing file-scope variables, static variables, persistent state, buffers, arrays, pointers to heap allocations, UI state, battle state, map state, or any C code that may emit mutable `.bss` or `.data` in the Violet ROM hack.
---

# Violet EWRAM Safety

Violet's linker discards ordinary object-file `.bss` and `.data`. Every mutable variable with static storage duration must use the project's `EWRAM` attribute so references resolve through `free_ewram`.

## Mandatory Rule

Never introduce mutable file-scope or function-local `static` storage without `EWRAM`.

Use:

```c
EWRAM u16 pending_target = 0;
EWRAM bool pending = false;
EWRAM state_t *state = NULL;
EWRAM u8 buffer[32] = {0};
```

Do not use:

```c
static u16 pending_target;
bool pending;
state_t *state;
static u8 buffer[32];
```

The rule applies whether storage is initialized or zero-initialized and whether it holds data directly or only a pointer to heap-allocated data. `EWRAM` is defined in `include/c/types.h` as placement in section `free_ewram`.

Normal automatic function-local variables may remain on the stack. Compile-time constants that are genuinely read-only and emitted to ROM do not need `EWRAM`. Do not add `EWRAM` to functions.

## Workflow

1. Before editing, inspect nearby persistent-state declarations and `include/c/types.h`.
2. For every new or modified variable, classify its storage duration:
   - automatic local: stack, no `EWRAM`;
   - mutable static storage duration: `EWRAM` is mandatory;
   - immutable ROM data: keep `const` and verify it is not emitted into writable `.data`.
3. Prefer an existing project state structure when the variable belongs to one. Its file-scope pointer or instance must still use `EWRAM`.
4. Give EWRAM globals project-specific names. Add `extern EWRAM ...` declarations to headers only when other translation units need access.
5. Build the affected object, then build `bld/violet.gba`. Object compilation alone is insufficient because discarded-section failures occur during linking.
6. Inspect suspect objects when needed:

```bash
arm-none-eabi-readelf -SW bld/path/to/file.o
arm-none-eabi-readelf -sW bld/path/to/file.o
```

New mutable symbols must resolve to `free_ewram`, not `.bss` or `.data`.

## Audit Checks

Search changed C files for likely violations:

```bash
rg -n "^(static[[:space:]]+)?(bool|u8|u16|u32|s8|s16|s32|int|size_t|[A-Za-z_][A-Za-z0-9_]*_t)[[:space:]*]+[A-Za-z_]" <changed-files>
```

Review matches manually; declarations split across lines and macro-defined types can evade simple searches. Treat linker diagnostics such as “defined in discarded section `.bss`” or `.data` as an EWRAM-placement failure first.

Validate with:

```bash
nix --extra-experimental-features 'nix-command flakes' develop -c make -C Violet bld/violet.gba
```

Do not report completion until the linked ROM target succeeds.
