.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_0_12_trainer_2
.global ow_script_map_0_12_trainer_1
.global ow_script_map_0_12_trainer_0

ow_script_map_0_12_trainer_0:
trainerbattlestd 0x0 0xae 0x0 str_0x86584d str_0x8658b7
loadpointer 0x0 str_0x8658b7
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x86584d:
    .string "Unfassbar, dass man ein Kind bis\nhierher hat kommen lassen.\pIch werde deinem Siegeszug ein\nEnde machen."



str_0x8658b7:
    .string "Du musst wohl der Junge sein, vor\ndem Mistral uns gewarnt hat."


.elseif LANG_EN

.endif


ow_script_map_0_12_trainer_1:
trainerbattlestd 0x0 0xaf 0x0 str_0x96646f str_0x9664e4
loadpointer 0x0 str_0x9664e4
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x96646f:
    .string "Du magst es vielleicht mit unseren\nRüpeln aufnehmen können,\laber wir von der Violet Elite,\lwerden dich vernichten."



str_0x9664e4:
    .string "BeachtlichDOTS\nGegen Mistral hast du letztlich\laber keine ChancenDOTS"


.elseif LANG_EN

.endif


ow_script_map_0_12_trainer_2:
setvar 0x8004 0xa
special 0x19
waitstate
end