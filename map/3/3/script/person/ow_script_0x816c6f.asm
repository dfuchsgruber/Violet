.include "overworld_script.s"

.include "std.s"

.global ow_script_0x816c6f
ow_script_0x816c6f:
cry POKEMON_PIKACHU 0x0
loadpointer 0x0 str_0x817948
callstd MSG_FACE
waitcry
end
