.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_9_1_person_2
.global ow_script_map_9_1_person_1
.global ow_script_map_9_1_person_3

ow_script_map_9_1_person_1:
loadpointer 0x0 str_0x196800
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x196800:
    .string "Ich kann dir nur dringed davon\nabraten, ein Darlehn bei der Orina\lCity aufzunehmen.\pEin Großteil deines Preisgelds\nverschwindet im Handumdrehen und\lehe du dich versiehst, besitzt du\lkein Geld mehr."


.elseif LANG_EN

.endif


ow_script_map_9_1_person_2:
loadpointer 0x0 str_0x19675c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x19675c:
    .string "Es ist wirklich eine Schande, dass\ndiese Stadt kein ordentliches\lEinkaufszentrum besitzt."


.elseif LANG_EN

.endif


ow_script_map_9_1_person_3:
loadpointer 0x0 str_0x19684c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x19684c:
    .string "Diese Stadt ist ein Ort voller\nWunder. Die Laz.Corp. bringt uns\lder Zukunft jeden Tag ein Stück\lnäher."


.elseif LANG_EN

.endif