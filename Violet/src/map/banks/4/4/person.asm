.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_4_4_person_1
.global ow_script_map_4_4_person_0

ow_script_map_4_4_person_0:
loadpointer 0x0 str_0x8a08b0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a08b0:
    .string "Einst war ich ein glorreicher\nTrainer.\lAber nunDOTS\lNunDOTS bin ich ein alter GreisDOTS"


.elseif LANG_EN

.endif


ow_script_map_4_4_person_1:
loadpointer 0x0 str_0x8a0909
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a0909:
    .string "Amonia ist der perfekte Ort für\nTrainer, die sich zur Ruhe setzten\lwollen."


.elseif LANG_EN

.endif