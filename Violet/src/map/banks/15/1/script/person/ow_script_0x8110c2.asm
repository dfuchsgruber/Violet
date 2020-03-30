.include "callstds.s"
.include "species.s"
.include "overworld_script.s"


.global ow_script_0x8110c2
ow_script_0x8110c2:
cry POKEMON_STARALILI 0x0
loadpointer 0x0 str_0x810f25
showpokepic POKEMON_STARALILI 0x0 0x0
callstd MSG_FACE
hidepokepic
end
