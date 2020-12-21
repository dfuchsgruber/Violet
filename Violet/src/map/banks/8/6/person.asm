.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_8_6_person_1
.global ow_script_map_8_6_person_0

ow_script_map_8_6_person_0:
loadpointer 0x0 str_0x87f1e8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x87f1e8:
    .autostring 34 2 "Das höchste aller Gefühle für mich ist es, bei Regen das Teehaus hier zu besuchen.\pWenn es draußen stürmt und donnert, sitze ich drinnen bei einer Tasse heißem Tee.\pDas ist doch wirklich Luxus, oder nicht?"
.elseif LANG_EN

.endif


ow_script_map_8_6_person_1:
loadpointer 0x0 str_0x87f23e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x87f23e:
    .autostring 34 2 "Meine Frau ist ganz besessen von diesem Teehaus hier.\pStändig höre ich sie nur von den verschiedensten Sorten und Geschmäckern schwärmen.\pAber für mich interessiert sie sich im Grunde gar nicht mehrDOTS"


.elseif LANG_EN

.endif