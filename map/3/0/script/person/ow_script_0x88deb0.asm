.include "overworld_script.s"

.include "std.s"

.global ow_script_0x88deb0
ow_script_0x88deb0:
copyvarifnotzero 0x8000 0x3a
copyvarifnotzero 0x8001 0x1
callstd ITEM_OBTAIN
setwildbattle POKEMON_MAEHIKEL 0x1c ITEM_NONE
dowildbattle
end
