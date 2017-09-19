.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a1a0c
ow_script_0x8a1a0c:
givepokemon POKEMON_KIRLIA 0x1e ITEM_NONE 0x0 0x0 0x0
copyvarifnotzero 0x8000 ITEM_FUNKELSTEIN
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
end
