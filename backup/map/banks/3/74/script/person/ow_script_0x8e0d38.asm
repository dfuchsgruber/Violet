.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8e0d38
ow_script_0x8e0d38:
loadpointer 0x0 str_0x8e2c92
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e2c92

str_0x8e2c92:
    .string "Ich suche hier nach dem Pokémon\nSkorgla. Es heißt, dass es sich\lhier finden lässt."
        
        
.elseif LANG_EN

.endif
