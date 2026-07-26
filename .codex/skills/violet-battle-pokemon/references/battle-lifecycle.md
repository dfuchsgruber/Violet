# Battle Engine Lifecycle

## State

The battle allocation hook creates and clears `mega_state`, `trainer_ai_state2`, and `battle_state2`. Later hooks assume these pointers are valid. `battle_state2` coordinates custom statuses, before-attack sequencing, extended attack-done processing, dropped items/OAM, double-wild catching, aggression, golden-apple state, and fleeing RNG.

The normal flow is:

`battle callback → selection/controllers → priority → before-attack hook → battle-script dispatch → damage/type/effects → extended x49 attack-done states → end-turn effects → teardown`

The normal free hook reverts temporary forms, restores ally-party state, performs survival/handicap cleanup, frees custom state, and nulls pointers. Audit every abnormal exit for equivalent cleanup.

## Battle Scripts

`bsc_offset` is an instruction pointer. Each C command must consume exactly its encoded byte width or replace the pointer with another ROM script. An asynchronous command must push the correct continuation/callback before redirecting execution. The custom before-attack state serializes ability, handicap, attacker-item, and defender-item work; the x49 extension waits for vanilla attack-done completion before custom ability/item work.

## Battlers

Use:

- opponent: `battler ^ 1`
- partner: `battler ^ 2`
- side: `battler & 1`

Never use battler order as party order; resolve the battler-to-party index.

Critical shared globals include `battlers`, attacker/defender/active battler, active attack/slot, result flags, critical multiplier, damage values, battle flags/weather/state/resources/scripting, controller buffers, parties, script stacks, and save state. Reverse-engineered struct offsets are ABI.

## Cross-Path Hazards

- Custom state allocation failure is not generally handled.
- Double-wild catching shares `battle_state2->throwing_pokeball`; clear it on every cancel/failure route.
- Temporary forms mutate party species/stats and rely on normal teardown for reversion.
- Expanded item IDs are `u16`; audit any controller or state field that stores a chosen item in `u8`.
