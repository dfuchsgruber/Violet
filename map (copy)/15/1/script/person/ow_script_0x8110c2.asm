.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8110c2
ow_script_0x8110c2:
cry POKEMON_MAEHIKEL 0x0
loadpointer 0x0 str_0x810f25
showpokepic POKEMON_MAEHIKEL 0x0 0x0
callstd MSG_FACE
hidepokepic
end
