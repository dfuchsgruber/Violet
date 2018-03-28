.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94e78b
ow_script_0x94e78b:
loadpointer 0x0 str_0x94e795
callstd MSG
end


.ifdef LANG_GER
.global str_0x94e795

str_0x94e795:
    .string "Steh auf, du versoffener Hund!\nWo warst du nur wieder die ganze\lNacht?"
        
        
.elseif LANG_EN

.endif
