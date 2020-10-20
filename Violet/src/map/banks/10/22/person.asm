.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"

.global ow_script_map_10_22_person_2
.global ow_script_map_10_22_person_1
.global ow_script_map_10_22_person_0
.global ow_script_0x86be02

ow_script_map_10_22_person_0:
loadpointer 0x0 str_0x966059
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x966059:
    .string "Kann man das, was sie im Fernsehen\nzeigen, überhaupt noch als Sendung\lbezeichnen?\pIch habe viel mehr das Gefühl,\npermament der Werbung ausgesetzt\lzu sein."


.elseif LANG_EN

.endif


ow_script_map_10_22_person_2:
checkflag INFERIOR_TM_BRUELLER
gotoif EQUAL ow_script_0x86be02
lock
faceplayer
loadpointer 0x0 str_0x965cb1
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_TM05
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x965c57
callstd MSG
setflag INFERIOR_TM_BRUELLER
release
end


ow_script_0x86be02:
loadpointer 0x0 str_0x96395c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x965cb1:
    .string "Weißt du, was deine Gegner auf\njeden Fall verschrecken wird?\pAngsteinjagendes Gebrüll!\nRwaaahr! Rwaaaaaahr!\pWillst du auch so brüllen lernen\nwie ich?"



str_0x965c57:
    .string "Diese Tm enthält Brüller!\nWendest du sie an, vertreibst du\ldeinen Gegner vom Kampffeld."



str_0x96395c:
    .string "Arbeitest du auch fleißig an\ndeinem Gebrüll, ja?\pRwaaaahr! Rwaaaaaahhhhr!"


.elseif LANG_EN

.endif


ow_script_map_10_22_person_1:
loadpointer 0x0 str_0x965de4
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x965de4:
    .string "Selbst an Wintertagen herrschen in\nInferior Höchsttemperaturen.\pWir haben hier sogut wie niemals\nSchneefall."


.elseif LANG_EN

.endif