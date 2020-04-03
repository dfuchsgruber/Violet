.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_0_7_trainer_1
.global ow_script_map_0_7_trainer_0

ow_script_map_0_7_trainer_0:
trainerbattlestd 0x0 0x6b 0x0 str_0x8c7ece str_0x8c7efc
loadpointer 0x0 str_0x8c7efc
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c7ece:
    .string "Dieser Ort ist wirklich\nwunderschön, nicht?"



str_0x8c7efc:
    .string "Dieses bläulich leuchtende Gestein\nist faszinierend."


.elseif LANG_EN

.endif


ow_script_map_0_7_trainer_1:
loadpointer 0x0 str_0x8c8e19
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c8e19:
    .string "Diese Höhle hat sich im Laufe der\nJahre mit Meereswasser gefüllt.\pSie liegt direkt unterhalb von\nKaskada, der Stadt der Quellen und\ldes Wassers."


.elseif LANG_EN

.endif