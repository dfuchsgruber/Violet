.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94c0f7
ow_script_0x94c0f7:
loadpointer 0x0 str_0x94e05a
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e05a

str_0x94e05a:
    .string "Im Museum stellen sie eines meiner\nGemälde aus. Es zeigt den großen\lDrachen Rayquaza, den Herrscher\ldes Himmels.\pIch bin so stolz!"
        
        
.elseif LANG_EN

.endif
