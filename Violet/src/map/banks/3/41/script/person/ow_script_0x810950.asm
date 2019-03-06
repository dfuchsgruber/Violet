.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x810950
ow_script_0x810950:
trainerbattlestd 0x0 0x17 0x0 str_0x810968 str_0x810989
loadpointer 0x0 str_0x810989
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x810968

str_0x810968:
    .string "Ich fühle, was andere fühlenDOTS"
        
        
.global str_0x810989

str_0x810989:
    .string "Ich fühleDOTS"
        
        
.elseif LANG_EN

.endif
