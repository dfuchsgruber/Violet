.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_9_3_person_3
.global ow_script_map_9_3_person_1
.global ow_script_map_9_3_person_0
.global ow_script_map_9_3_person_2

ow_script_map_9_3_person_0:
loadpointer 0x0 str_0x85ff50
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x85ff50:
    .string "Es ist wirklich sehr\nnervenaufreibend zu warten, bis man\lan der Reihe ist, findest du nicht?"


.elseif LANG_EN

.endif


ow_script_map_9_3_person_2:
loadpointer 0x0 str_0x85ffad
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x85ffad:
    .string "Aufgrund meines Alters vergesse ich\nnicht selten Diskretionsabstand\leinzahlten."


.elseif LANG_EN

.endif


ow_script_map_9_3_person_3:
loadpointer 0x0 str_0x95aae7
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95aae7:
    .string "Ich bevorzuge den Bankautomaten.\nAuf diese Weise muss ich nicht so\llange anstehen."


.elseif LANG_EN

.endif


ow_script_map_9_3_person_1:
loadpointer 0x0 str_0x95ab3b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95ab3b:
    .string "Ich bewache die Rücklagen der\nOrina City Bank.\lOb ich nur ein einzelner Polizist\lbin?\pÄhmDOTS! Nein! Natürlich nicht.\nHinter dieser Türe sind noch\lhundert weitereDOTS"


.elseif LANG_EN

.endif