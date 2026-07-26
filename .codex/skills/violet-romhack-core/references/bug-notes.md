# Bug Notes And Sharp Edges

These are observations from repository exploration. Items under Confirmed were independently
traced through callers during the 2026-07 two-pass audit, but have not all been reproduced in an
emulator.

## Confirmed High-Risk Bugs

- `Violet/src/save/block_restore.asm`: the three backward-copy source pointers are not chunk-tail
  pointers. Their resolved ranges overlap, reach before `csave`, and omit the final 596 bytes of the
  3780-byte structure. Fix the pointers as inclusive ends of three contiguous chunks and assert that
  their sizes cover exactly `sizeof(custom_memory)`.
- `Violet/src/map/dungeon2/ocean/blocks.c`: the border flood fill checks `y` instead of neighbor
  `y2`, so traversal from `(0,0)` queues `(0,-1)` and indexes far outside the map. It also uses
  height as row stride and can overrun its fixed stack through duplicate enqueues.
- `Violet/src/data_structures/hashmap.c`: updating a key also appends a duplicate, so A* reads the
  stale cost/predecessor. Removal shifts capacity rather than live elements and loses the singleton
  return value.
- `Violet/src/data_structures/pathfinding.c`: path reconstruction has no output-capacity parameter;
  its caller allocates 256 bytes and the path plus STOP can exceed that buffer.

## Confirmed Gameplay Bugs

- `Violet/src/battle/damage.c`: Choice Specs handling assigns `spAttack = (150 * attack) / 100` instead of scaling `spAttack`, and the following generic `if (attackerHoldEffect == HOLD_EFFECT_CHOICE_ITEM)` scales `attack` again for every choice item. Check this before touching damage math.
- `Violet/src/battle/damage.c`: the special-move hold-effect branch modifies `attack`, not
  `spAttack`.
- `Violet/src/pokemon/pokemon_new.c`: `pokemon_new_by_prngs` accepts destination `pokemon *p`, but egg moves are appended to `opponent_pokemon[0]` and stats are recalculated on `opponent_pokemon[0]`. This looks wrong unless the function is intentionally only used for wild opponent slot 0.
- `Violet/src/battle/ai/switching.c`: one effectiveness call passes defender types before ability
  although the helper signature expects ability, type1, type2; another block adjusts the `score`
  pointer instead of `*score`.
- `Violet/src/battle/ai/ai.c`: the chosen-switch-target mask uses `&=` where the controller contract
  requires setting a bit.
- `Violet/src/battle/ability/before_attack.c`: stance change assigns `type1` twice and leaves
  `type2` stale.
- `Violet/src/pokemon/evolutions/evolution.c`: held-item daytime evolution uses
  `hour > 6 || hour < 22`, which is true for every valid hour, and item removal happens during the
  cancellable lookup rather than successful completion.
- `Violet/src/pokemon/util.c`: `DEBUG("Species %d, type %d\n");` has format placeholders without arguments. Depending on debug macro expansion, this may be undefined behavior or a compile warning when that path is built.

## Suspicious Or Worth Checking

- `Violet/include/c/achivements.h` is empty and `Violet/src/achievements/` contains no implementation files. Treat achievements as an unfinished feature scaffold; note the existing misspelling `achivements` in the header name.
- `Violet/src/attacks/effectiveness.c`: after the `{0xfe, 0xfe, 0}` marker, normal/fighting vs ghost are repeated before the final `{0xff, 0xff, 0}`. Confirm sentinel semantics before modifying type effectiveness.
- Several files keep very active `DEBUG(...)` calls in hot paths, especially wild encounters, dungeon generation, weather, and battle damage. Check whether debug logging is intended for release builds before adding more.
- Naming typos such as `recipies`, `critcial_hit.c`, `prepeare`, and `sucess` are established in code and symbol names. Preserve existing spellings when matching ABI or symbol references.

## Search Patterns

```bash
rg -n "TODO|FIXME|BUG|There is a bug|Warning:|no idea|opponent_pokemon\\[0\\]|HOLD_EFFECT_CHOICE_ITEM|recipies|critcial" Violet/src Violet/include Violet/tools Violet/models
```
