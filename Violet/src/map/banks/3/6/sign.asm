.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_3_6_sign_0
.global ow_script_map_3_6_sign_1
.global ow_script_map_3_6_sign_2

ow_script_map_3_6_sign_1:
loadpointer 0x0 str_0x8601de
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8601de:
    .string "Der Volcano - das Herz des Feuers"


.elseif LANG_EN

.endif


ow_script_map_3_6_sign_2:
loadpointer 0x0 str_0x86020b
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x86020b:
    .string "Arena von Inferior\pTyp: Feuer\nLeiter: Igva"


.elseif LANG_EN

.endif


ow_script_map_3_6_sign_0:
loadpointer 0x0 str_0x961de7
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x961de7:
    .string "Inferior - Die Höllenpforte"


.elseif LANG_EN

.endif