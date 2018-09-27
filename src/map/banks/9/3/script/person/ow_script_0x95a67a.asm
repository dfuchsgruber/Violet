.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95a67a
ow_script_0x95a67a:
loadpointer 0x0 str_0x95ab3b
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95ab3b

str_0x95ab3b:
    .string "Ich bewache die Rücklagen der\nOrina City Bank.\lOb ich nur ein einzelner Polizist\lbin?\pÄhmDOTS! Nein! Natürlich nicht.\nHinter dieser Türe sind noch\lhundert weitereDOTS"
        
        
.elseif LANG_EN

.endif
