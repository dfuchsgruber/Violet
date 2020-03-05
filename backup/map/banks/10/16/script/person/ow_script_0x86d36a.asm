.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x86d36a
ow_script_0x86d36a:
trainerbattlestd 0x0 0xad 0x0 str_0x86d382 str_0x86d3cd
loadpointer 0x0 str_0x86d3cd
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x86d382

str_0x86d382:
    .string "Ich schwitze nicht! Das ist\nMassageöl, das meinen Körper\lglänzen lässt!"
        
        
.global str_0x86d3cd

str_0x86d3cd:
    .string "Ich schwöre dir, das ist kein\nSchweiß!"
        
        
.elseif LANG_EN

.endif
