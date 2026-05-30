# Gameplay Patterns

## Attack Data

- `Violet/models/attack.py` defines the attack table and localized attack-name table.
- `Violet/src/attacks/attacks.pms` contains entries with fields: `effect`, `base_power`, `type`, `accuracy`, `pp`, `effect_accuracy`, `affects_whom`, `priority`, `flags`, `effect_table`, `category`, and `rating`.
- `Violet/src/attacks/attack_names.pms` stores localized fixed-size move names.
- `constants/attacks.const`, `attack_flags.const`, `attack_categories.const`, `attack_affects_whom_flags.const`, and `pokemon_types.const` back symbolic fields.

## Battle Code

- `include/c/battle/state.h` describes `battle_state_t`, Violet's `battle_state2_t`, battle results, AI/history structs, and battle sprite info.
- `include/c/battle/battler.h` contains battle-side Pokemon state and damage tracking.
- `src/battle/damage.c` handles base damage, item/ability/stat/weather/screen modifiers, critical behavior, and minimum damage.
- `src/attacks/effectiveness.c` stores type-effectiveness triples; values use 20 for super-effective, 10 implicit neutral, 5 resisted, and 0 immune.
- Move-specific behavior may live in C under `src/attacks/`, assembly battle scripts under `src/attacks/*.asm`, and hooks under `src/battle/hooks.asm`.

## Pokemon Code

- `include/c/pokemon/virtual.h` defines `pid_t`, `box_pokemon`, `pokemon`, status constants, party globals, and attribute APIs.
- Use `pokemon_get_attribute` / `pokemon_set_attribute` rather than reaching into encrypted substructures unless the local code already does.
- Pokemon generation logic is split between `src/pokemon/pokemon_new.c` and `src/pokemon/structure/checksum.c`.
- Basestats, evolutions, movesets, egg moves, accessible moves, TM/HM compatibility, and Pokédex data are model-backed/generated data.

## Items, Abilities, And Effects

- Item hold effects are looked up through `item_get_hold_effect` and `item_get_hold_effect_parameter`.
- Abilities commonly go through `ability_execute` for contextual behavior and direct ability checks for formula modifiers.
- Constants often keep German names such as `TYPE_KAEFER`, `TYPE_FEUER`, `POKEMON_TRAGOSSO`, or `ITEM_ASCHETASCHE`; use existing symbolic names.

## Known Sharp Edges

- Review `violet-romhack-core/references/bug-notes.md` before editing damage or Pokemon creation.
- `pid_t` in Violet is not the vanilla PID semantics; it directly encodes gender, shiny, hidden power, Unown letter, nature, and form.
- `pokemon_calculate_checksum` currently returns the stored checksum, effectively bypassing normal checksum calculation.
- `pokemon_is_shiny` ignores TID and reads `pid.fields.is_shiny`.

