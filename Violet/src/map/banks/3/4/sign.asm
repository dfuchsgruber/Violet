.include "vars.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_map_3_4_sign_1
.global ow_script_0x8f1d32
.global ow_script_map_3_4_sign_4
.global ow_script_0x8f1d54
.global ow_script_map_3_4_sign_5
.global ow_script_map_3_4_sign_0
.global ow_script_map_3_4_sign_2
.global ow_script_map_3_4_sign_3

ow_script_map_3_4_sign_0:
loadpointer 0x0 str_0x8f1c5d
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8f1c5d:
    .string "Eingang: Felsige Ödnis\nSüden: Wasserpfad"


.elseif LANG_EN

.endif


ow_script_map_3_4_sign_1:
loadpointer 0x0 str_0x8f1c91
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8f1c91:
    .string "Kaskada, die Stadt der Wasserfälle"


.elseif LANG_EN

.endif


ow_script_map_3_4_sign_2:
loadpointer 0x0 str_0x8f1cbf
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8f1cbf:
    .string "Ein ganz gewöhnliches Haus"


.elseif LANG_EN

.endif


ow_script_map_3_4_sign_3:
loadpointer 0x0 str_0x8f1d5b
callstd MSG
setvar DYN_MULTICHOICE_ITEM_CNT 0x1
checkflag KASKADA_BLACKMARKET_RECEIVED_PAROLE
callif EQUAL ow_script_0x8f1d54
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8f1d32
loadpointer 0x0 str_0x8f1d1f
callstd MSG
warp 0x8 0xb 0x0 0x0 0x0
waitstate
end

.align 4
choice:
    .word str_kaskada_parole_choice_0, 0
    .word str_kaskada_parole_choice_1, 0

ow_script_0x8f1d32:
loadpointer 0x0 str_0x8f1d3c
callstd MSG
end


ow_script_0x8f1d54:
addvar DYN_MULTICHOICE_ITEM_CNT 0x1
return


.ifdef LANG_GER

str_0x8f1d5b:
    .string " PLAYER klopft an \nDOTS\lDOTS DOTS\lParole?"



str_kaskada_parole_choice_0:
    .string "DOTS DOTS DOTS"



str_kaskada_parole_choice_1:
    .string "Nachtschwarz"



str_0x8f1d1f:
    .string "Einlass gewährt!"



str_0x8f1d3c:
    .string "Kein Einlass gewährt!"


.elseif LANG_EN

.endif


ow_script_map_3_4_sign_4:
loadpointer 0x0 str_0x8f1db6
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8f1db6:
    .string "Norden: Küstenberg"


.elseif LANG_EN

.endif


ow_script_map_3_4_sign_5:
loadpointer 0x0 str_0x8fffd9
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8fffd9:
    .string "Haus des Namensexperten"


.elseif LANG_EN

.endif