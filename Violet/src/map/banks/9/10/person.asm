.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_9_10_person_0
.global ow_script_map_9_10_person_3
.global ow_script_map_9_10_person_1
.global ow_script_map_9_10_person_2

ow_script_map_9_10_person_0:
loadpointer 0x0 str_0x95cd9c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95cd9c:
    .string "Im Fernsehen läuft zunehmend mehr\nMüllDOTS\pIch frage mich, wann eine echte\nAlternative dazu aufkommt."


.elseif LANG_EN

.endif


ow_script_map_9_10_person_1:
loadpointer 0x0 str_0x95ce0c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95ce0c:
    .string "Bücher sind der Weg, einen Geist\nauch über den Tod hinweg am Leben\lzu erhalten."


.elseif LANG_EN

.endif


ow_script_map_9_10_person_2:
loadpointer 0x0 str_0x95ce67
callstd MSG
end


.ifdef LANG_GER

str_0x95ce67:
    .string "Es DOTS verfolgt DOTS\nmich DOTS\lDer Mondschatten DOTS\lDar DOTS Dark DOTS DarkraiDOTS"


.elseif LANG_EN

.endif


ow_script_map_9_10_person_3:
loadpointer 0x0 str_0x95cec0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95cec0:
    .string "Seit Tagen nun leidet meine\nTochter an schrecklichen\lAlbträumenDOTS"


.elseif LANG_EN

.endif