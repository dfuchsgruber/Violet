.include "callstds.s"
.include "overworld_script.s"
.include "ordinals.s"
.include "flags.s"

.global ow_script_map_3_1_sign_2
.global ow_script_map_3_1_sign_0
.global ow_script_0x84ea05
.global ow_script_map_3_1_sign_1
.global ow_script_map_3_1_sign_4
.global ow_script_map_3_1_sign_3

ow_script_map_3_1_sign_0:
loadpointer 0x0 str_0x8dea7d
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8dea7d:
    .string "Arena von Meriana City\pTyp: Kampf\nLeiter: Manus"


.elseif LANG_EN

.endif


ow_script_map_3_1_sign_1:
checkflag MERIANA_CITY_HIKER_BLOCKING_ROUTE_4
gotoif 0 ow_script_0x84ea05
loadpointer 0x0 str_0x84e9d5
callstd MSG_SIGN
end


ow_script_0x84ea05:
loadpointer 0x0 str_0x84ea0f
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x84e9d5:
    .string "Die Arena ist einem Kampf-Dojo\nnachempfunden."



str_0x84ea0f:
    .string "Arenaleiter Manus außer Haus,\nArena geschlossen."


.elseif LANG_EN

.endif


ow_script_map_3_1_sign_2:
loadpointer 0x0 str_0x8a3c11
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8a3c11:
    .string "Westen: Route 2"


.elseif LANG_EN

.endif


ow_script_map_3_1_sign_3:
loadpointer 0x0 str_0x8a3c2c
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8a3c2c:
    .string "Eingang zum Wassertunnel\nNorden: Kaskada"


.elseif LANG_EN

.endif


ow_script_map_3_1_sign_4:
loadpointer 0x0 str_0x8a3c60
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8a3c60:
    .string "Meriana City, die Stadt am Fuße\ndes Wassergebirges."


.elseif LANG_EN

.endif