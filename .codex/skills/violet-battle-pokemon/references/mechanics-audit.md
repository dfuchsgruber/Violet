# Mechanics Audit Guide

## Integer Formula Review

Expand each branch into named intermediate values. Check:

- the correct physical/special source stat;
- mutually exclusive item/ability branches;
- multiplication order, truncation, overflow, and caps;
- attacker versus defender and active versus target battler;
- zero-valued enum sentinels, especially Normal type as zero;
- interaction order among weather, STAB, effectiveness, criticals, burn, screens, items, and abilities.

The type chart uses `0xFE` as a special separator with Foresight-style semantics; it is not an ordinary matchup or universal final terminator.

## Known Review Hotspots

- `battle/damage.c`: Choice Band/Specs stat selection and branch exclusivity.
- `battle/ability/before_attack.c`: stance form type1/type2 writes.
- `battle/ai`: bitmask update semantics for `ai_switch_target_chosen`.
- `pokemon/evolutions/evolution.c`: daytime predicates and held-item transaction timing.
- `pokemon/pokemon_new.c`: destination pointer use during moves/stat finalization.
- Type overrides use zero as “no override,” which cannot explicitly encode Normal if `TYPE_NORMAL == 0`.

Treat these as hypotheses to prove from callers, constants, and tests, not as automatic edits.
