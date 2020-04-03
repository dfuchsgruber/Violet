.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_3_2_sign_2
.global ow_script_map_3_2_sign_0
.global ow_script_map_3_2_sign_3
.global ow_script_map_3_2_sign_1

ow_script_map_3_2_sign_1:
loadpointer 0x0 str_0x8ca664
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8ca664:
    .string "Arena von Aktania\pTyp: Gestein\nLeiter: Lester"


.elseif LANG_EN

.endif


ow_script_map_3_2_sign_3:
loadpointer 0x0 str_0x8c1aac
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8c1aac:
    .string "Tempel der Wächter"


.elseif LANG_EN

.endif


ow_script_map_3_2_sign_0:
loadpointer 0x0 str_0x8cee15
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8cee15:
    .string "Aktania - die Stadt des ewigen\nSonnenscheins\pDOTS\pDOTS\pDer Text ist durchgestrichenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_2_sign_2:
loadpointer 0x0 str_0x8f60c7
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8f60c7:
    .string "Ein Pokémon könnte hier bestimmt\nhochkraxeln DOTS"


.elseif LANG_EN

.endif