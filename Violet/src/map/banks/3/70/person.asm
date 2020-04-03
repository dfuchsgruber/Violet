.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_3_70_trainer_2
.global ow_script_map_3_70_trainer_0
.global ow_script_map_3_70_trainer_1

ow_script_map_3_70_trainer_1:
trainerbattlestd 0x0 0x7 0x0 str_0x80f4d7 str_0x80f517
loadpointer 0x0 str_0x80f517
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x80f4d7:
    .string "Ich respektiere die Natur und das\nselbe solltest du auch tun!"



str_0x80f517:
    .string "Du hast die Natur respektiert, das\nwar der Grund für deinen Sieg."


.elseif LANG_EN

.endif


ow_script_map_3_70_trainer_0:
trainerbattlestd 0x0 0x5 0x0 str_0x8106f1 str_0x81089a
loadpointer 0x0 str_0x81089a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8106f1:
    .string "Zeit für einen Kampf!"



str_0x81089a:
    .string "Du bist der verdiente Sieger."


.elseif LANG_EN

.endif


ow_script_map_3_70_trainer_2:
loadpointer 0x0 str_0x83f669
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x83f669:
    .string "Entschuldigung, aber der Zutritt zu\ndiesem Bereich, steht nicht allen\lLeuten zu."


.elseif LANG_EN

.endif