# Save And Runtime Data Contracts

`custom_memory csave` is an EWRAM mirror persisted by assembly save hooks. It contains extended flags/vars/Pokédex data, incubator, dungeon state, gym state, roamers, berries, environment flags, settings, medicine-pocket state, and UI selections. `new_game.c` clears the full structure.

`src/save/block_restore.asm` places `csave` chunks in save-sector tails. `patches/save.asm` replaces load/store handling and size tables and disables saveblock relocation. The commented C serializer is not the active path.

Treat this as a serialized ABI:

- do not insert, reorder, resize, or repack fields without updating all assembly chunk offsets and size tables;
- compare assembly coverage with `sizeof(custom_memory)`;
- preserve padding and bitfield layout deliberately;
- add migration/version handling before intentionally breaking existing saves.

No custom-save migration/version field was identified in the 2026-07 audit.

Dungeon2 persists seed/configuration in `csave.dg2`, generates buffers/nodes in staged callbacks, and exposes layouts through the dynamic map loader. RTC/daily hashing affects dungeon selection and encounters.

Map/wild/evolution/move data are commonly sentinel-terminated. Model width, label, and sentinel are runtime engine ABI; malformed generated data can walk into unrelated ROM.
