---
name: violet-injection-audit
description: Audit Violet binary injections, armips patches, Thumb hook wrappers, overlay linking, fixed-address engine calls, table repoints, and C/assembly ABI boundaries. Use when adding, changing, reviewing, or debugging patches.asm, patches/*.asm, C functions reached from injected code, linker placement, EWRAM overlay state, or base-ROM compatibility.
---

# Violet Injection Audit

## Workflow

1. Read `references/overlay-build.md` for the link/import model and address limits.
2. Classify each site as a data repoint, callable-pointer replacement, whole-function tail replacement, mid-function call splice, or inline opcode edit.
3. Read `references/hook-abi.md` before interpreting or changing a callable site.
4. Disassemble the exact BPRD input bytes around every changed `.org`; do not infer displaced instructions from the patch alone.
5. Trace the target C declaration, definition, callers, mutable state, and continuation. Treat nearby assembly wrappers as the authoritative entry ABI.
6. Run the checks in `references/audit-checklist.md`, then build the ROM and inspect final section/ROM bounds.

## Rules

- Set bit zero on Thumb function pointers; do not set it on data pointers.
- Preserve AAPCS callee-saved registers, stack alignment, live engine registers, displaced instructions, and the intended continuation.
- Treat C signatures and hook shims as one contract, especially when arguments are reconstructed on the stack.
- Keep mutable overlay globals in explicit EWRAM or existing engine RAM; the linker discards ordinary writable sections.
- Assume every fixed address is valid only for the exact base-ROM revision.
- Verify table element width, length, sentinel, and every consumer when repointing data.

## Fast Checks

```bash
rg -n '\.org|\.word .*\\| 1|ldr r[0-9]+, =.*\\| 1|_blxr' Violet/patches Violet/src
arm-none-eabi-readelf -S Violet/bld/linked.o
nix --extra-experimental-features 'nix-command flakes' develop -c make -C Violet bld/violet.gba
```
