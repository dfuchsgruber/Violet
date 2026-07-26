---
name: violet-battle-pokemon
description: Work with Violet Pokemon, battle, attacks, abilities, items, evolution, move learning, wild encounters, basestats, and gameplay mechanics code or generated data. Use for damage formulas, type effectiveness, Pokemon creation, party/battle structs, move data, and battle scripts.
---

# Violet Battle And Pokemon

## Core Workflow

1. Locate whether the change is code (`Violet/src/battle`, `Violet/src/attacks`, `Violet/src/pokemon`, `Violet/src/item`) or data (`Violet/src/**/*.pms`, `Violet/models/*.py`, constants).
2. For data shape changes, trigger `violet-pms-models`; for constants, trigger `violet-constants`.
3. Read the matching headers in `Violet/include/c/battle`, `Violet/include/c/pokemon`, `Violet/include/c/item`, or top-level includes before editing structs.
4. Check battle script interactions in `include/as/battlescript.s`, `src/attacks/*bsc*.asm`, and `include/c/battle/battlescript.h` when changing move effects.
5. Validate both compile and generated data where possible.

## Read When Needed

Read `references/gameplay-patterns.md` for attack/Pokemon data layout, battle globals, and known sharp edges.

Read `references/battle-lifecycle.md` for allocation, script dispatch, custom states, battler identity, catching, form changes, and teardown.

Read `references/pokemon-storage.md` before changing PID fields, boxed/party layouts, creation, checksum handling, evolution, abilities, or contest-stat storage.

Read `references/mechanics-audit.md` when reviewing formulas, abilities, AI, item effects, and evolution predicates.

Trigger `violet-gba-hardware` when battle/Pokemon work is performance-sensitive, stack-heavy, hardware-timed, or depends on ROM/EWRAM/IWRAM layout.

## Project Rules

- Use generated constants for species, attacks, types, categories, abilities, items, flags, and battle statuses.
- Preserve FireRed ABI/global names where headers map directly onto engine memory.
- Be careful with bitfields in `pid_t`, Pokemon substructures, battle states, and save structs; changing layout can corrupt data.
- Damage and battle code is integer math; preserve order of operations intentionally.
- Battle code often uses globals such as `active_attack`, `attacking_battler`, `defending_battler`, `battle_flags`, `battle_state`, and `battle_state2`.

## Fast Checks

```bash
rg -n "ATTACK_<name>|HOLD_EFFECT_|CATEGORY_|TYPE_|ATTRIBUTE_|battle_state2|active_attack" Violet/src Violet/include Violet/constants
nix --extra-experimental-features 'nix-command flakes' develop -c make -C Violet bld/src/battle/damage.o
```
