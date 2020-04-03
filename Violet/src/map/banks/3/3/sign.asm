.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_map_3_3_sign_0
.global ow_script_map_3_3_sign_2
.global ow_script_map_3_3_sign_1
.global ow_script_map_3_3_sign_4
.global ow_script_0x8f63f6
.global ow_script_map_3_3_sign_5
.global ow_script_map_3_3_sign_3

ow_script_map_3_3_sign_1:
loadpointer 0x0 str_0x8deaae
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8deaae:
    .string "Arena von Silvania\pTyp: Pflanze\nLeiter: Mia"


.elseif LANG_EN

.endif


ow_script_map_3_3_sign_0:
loadpointer 0x0 str_0x81af29
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x81af29:
    .string "Silvania\pDie Stadt der Natur"


.elseif LANG_EN

.endif


ow_script_map_3_3_sign_2:
loadpointer 0x0 str_0x8de313
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8de313:
    .string "Haus von Mia"


.elseif LANG_EN

.endif


ow_script_map_3_3_sign_3:
loadpointer 0x0 str_0x8de321
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8de321:
    .string "Beerenladen"


.elseif LANG_EN

.endif


ow_script_map_3_3_sign_4:
loadpointer 0x0 str_0x8f5caa
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8f5caa:
    .string "Silvania Wald"


.elseif LANG_EN

.endif


ow_script_map_3_3_sign_5:
compare STORY_PROGRESS 0x1c
callif LESS ow_script_0x8f63f6
loadpointer 0x0 str_0x8f615e
callstd MSG_SIGN
end


ow_script_0x8f63f6:
loadpointer 0x0 str_0x8f6400
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8f615e:
    .string "Die Tür der Silvania-Arena ist aus\nedlem Holz gefertigt."



str_0x8f6400:
    .string "Die Tür scheint verschlossen zu\nsein."


.elseif LANG_EN

.endif