.include "overworld_script.s"

.include "std.s"

.global ow_script_meriana_dummy
ow_script_meriana_dummy:
givepokemon POKEMON_EVOLI 0x5 0 0 0 0
givepokemon POKEMON_NINCADA 0x19 0 0 0 0
givepokemon POKEMON_SKORGLA 0x23 0 0 0 0
givepokemon POKEMON_PORYGON2 0x1e ITEM_DUBIOSDISK 0x0 0x0 0x0

copyvarifnotzero 0x8000 ITEM_FUNKELSTEIN
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN

copyvarifnotzero 0x8000 ITEM_WASSERSTEIN
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN

copyvarifnotzero 0x8000 ITEM_SONDERBONBON
copyvarifnotzero 0x8001 99
callstd ITEM_OBTAIN

copyvarifnotzero 0x8000 ITEM_LINKKABEL
copyvarifnotzero 0x8001 99
callstd ITEM_OBTAIN



end
