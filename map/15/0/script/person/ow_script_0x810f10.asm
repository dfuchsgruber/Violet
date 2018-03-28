.include "overworld_script.s"

.include "std.s"

.global ow_script_0x810f10
ow_script_0x810f10:
cry POKEMON_STARALILI 0x0
loadpointer 0x0 str_0x810f25
showpokepic POKEMON_STARALILI 0x0 0x0
callstd MSG_FACE
hidepokepic
end


.ifdef LANG_GER
.global str_0x810f25

str_0x810f25:
    .string "Staralili!"
        
        
.elseif LANG_EN

.endif
