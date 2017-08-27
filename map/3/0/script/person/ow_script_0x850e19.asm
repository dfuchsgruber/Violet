.include "overworld_script.s"

.include "std.s"

.global ow_script_0x850e19
ow_script_0x850e19:
loadpointer 0x0 str_0x850e5f
callstd MSG
givepokemon POKEMON_LOCKSCHAL 0xf ITEM_NONE 0x0 0x0 0x0
givepokemon POKEMON_WELUNO 0xf ITEM_NONE 0x0 0x0 0x0
givepokemon POKEMON_SEEKID 0xf ITEM_NONE 0x0 0x0 0x0
copyvarifnotzero 0x8000 0x44
copyvarifnotzero 0x8001 0x63
callstd ITEM_OBTAIN
setflag FRBADGE_1
end
