.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86bd41
ow_script_0x86bd41:
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


.global ow_script_0x86be02
ow_script_0x86be02:
loadpointer 0x0 str_0x96395c
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x965cb1

str_0x965cb1:
    .string "Weißt du, was deine Gegner auf\njeden Fall verschrecken wird?\pAngsteinjagendes Gebrüll!\nRwaaahr! Rwaaaaaahr!\pWillst du auch so brüllen lernen\nwie ich?"
        
        
.global str_0x965c57

str_0x965c57:
    .string "Diese Tm enthält Brüller!\nWendest du sie an, vertreibst du\ldeinen Gegner vom Kampffeld."
        
        
.global str_0x96395c

str_0x96395c:
    .string "Arbeitest du auch fleißig an\ndeinem Gebrüll, ja?\pRwaaaahr! Rwaaaaaahhhhr!"
        
        
.elseif LANG_EN

.endif
