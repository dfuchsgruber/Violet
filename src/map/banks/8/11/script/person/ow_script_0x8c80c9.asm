.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8c80c9
ow_script_0x8c80c9:
loadpointer 0x0 str_0x8c830d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8c830d

str_0x8c830d:
    .string "Als ich mich Team Violet\nangeschlossen habe, wurde ich\lsofort dem Kommandanten der\lzweiten Division zugeteilt,\lMistral.\pEr ist ein äußert ambitionierter\nMann, skrupellos und mächtig."
        
        
.elseif LANG_EN

.endif
