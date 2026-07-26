# Pokemon Storage And Generation

Violet deliberately changes the vanilla storage contract:

- `patches/pokemon.asm` disables vanilla substructure encryption/decryption.
- It forces fixed ABCD substructure order.
- It redirects checksum handling.

The structure remains ABI-shaped but is plaintext and fixed-order. Returning the stored checksum is therefore part of the current redesign, not by itself proof of a bug. Compatibility with vanilla saves/Pokémon is intentionally lost.

## PID And Ability Semantics

Custom `pid_t` fields encode nature, gender, shiny, hidden-power, Unown, and form semantics. Audit every remaining vanilla PID consumer for incompatible assumptions.

Hidden-ability state uses coolness bit 7. Any routine that writes a full contest-stat byte must preserve this bit.

## Creation And Evolution

- Pokémon constructors must operate on their pointer parameter, not a global party/battle slot.
- Calculate stats only after moves, level, species, IV/EV, and form data are finalized.
- Evolution traversal has a depth guard but no visited set; cycles can duplicate results and long families truncate.
- Held-item evolution predicates should not irreversibly remove the item unless completion is guaranteed.
- Time-window predicates must be reviewed at midnight boundaries and across all 0-23 hours.

Generated move/evolution/wild tables are sentinel-driven. Verify sentinel presence and consumer bounds whenever their models change.
