.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x81f986
ow_script_0x81f986:
loadpointer 0x0 str_0x86c9f0
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x86c9f0

str_0x86c9f0:
    .string "Ich habe gehört, dass es in dieser\nWüste goldene Kakteen geben soll.\pSchüttelt man an ihnen, so soll\nman Pokémon antreffen können."
        
        
.elseif LANG_EN

.endif
