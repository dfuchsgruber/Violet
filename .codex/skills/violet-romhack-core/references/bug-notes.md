# Bug Notes And Sharp Edges

These are observations from repository exploration, not all confirmed by running the ROM.

## Likely Bugs

- `Violet/src/battle/damage.c`: Choice Specs handling assigns `spAttack = (150 * attack) / 100` instead of scaling `spAttack`, and the following generic `if (attackerHoldEffect == HOLD_EFFECT_CHOICE_ITEM)` scales `attack` again for every choice item. Check this before touching damage math.
- `Violet/src/pokemon/pokemon_new.c`: `pokemon_new_by_prngs` accepts destination `pokemon *p`, but egg moves are appended to `opponent_pokemon[0]` and stats are recalculated on `opponent_pokemon[0]`. This looks wrong unless the function is intentionally only used for wild opponent slot 0.
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
