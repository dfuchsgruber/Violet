.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x87e9ca
ow_script_0x87e9ca:
loadpointer 0x0 str_0x87f1e8
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x87f1e8

str_0x87f1e8:
    .string "Ich liebe den Regen, wenn er auf\ndas Dach niederprasst und dabei\lgemütlich knattert."
        
        
.elseif LANG_EN

.endif
