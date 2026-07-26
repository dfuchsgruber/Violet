# Hook ABI And Patch Forms

## Patch Forms

1. Data/table repoint: write an aligned data address without a Thumb bit.
2. Dispatch replacement: write `callback | 1` into a function-pointer table.
3. Whole-function replacement: load an odd target and `bx`; implement the original entry ABI.
4. Mid-function splice: call through a local `_blxr*` veneer, replay displaced work, and branch to a fixed continuation.
5. Inline edit: replace opcodes or scalar literals in place.

## Review A Callable Hook

Disassemble the base ROM around the `.org`. Record instruction boundaries, incoming control-flow edges, live registers, flags, SP offset, stack arguments, overwritten literals, and the first safe continuation. Then compare the wrapper instruction by instruction.

At a C call boundary:

- r0-r3, r12, flags, and LR are volatile;
- r4-r11 and SP are callee-saved;
- SP must remain correctly aligned;
- arguments beyond r0-r3 occupy the expected caller stack slots;
- callable overlay addresses must be odd/Thumb;
- fixed continuations must use the correct branch state.

Do not assume a C compiler preserves flags or volatile registers. Replay displaced instructions only when their original inputs still exist.

## Authoritative Wrappers

Read these when their domain is involved:

- `src/main_init_hook.asm`: initializes custom memory/debug state, replays boot writes, resumes at `0x08000421`.
- `src/malloc_hook.asm`: extracts intercepted caller information and returns through exact engine continuations.
- `src/battle/hooks.asm` and `src/battle/ability/hooks.asm`.
- `src/overworld/overworld_hooks.asm`.
- `src/pokemon/structure/hooks.asm` and `src/pokemon/moveset_hook.asm`.

The damage shim near `patches/battle.asm:825` reconstructs stack arguments for `battle_base_damage_calculate`; never change that C signature without changing and revalidating the shim.

## Patch-File Hazards

Armips sites lack `.area`/span guards. Check ranges, not merely duplicate `.org` values: a later patch can overlap an earlier multi-instruction sequence or literal pool. Verify literal-pool reach, overwritten instruction width, alignment, and table storage width/count. All literal engine addresses bind the patchset to exact BPRD bytes.
