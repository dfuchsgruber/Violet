.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_movs_0x95db3c
ow_script_movs_0x95db3c:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x95dad0
ow_script_0x95dad0:
lockall
sound 0x9
clearflag PKMNMENU
showsprite 0x1
pause 0x20
setvar 0x8004 0x1
special 0x1b
waitmovement 0x0
faceplayer
draw_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT
loadpointer 0x0 str_0x95dbb7
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x95dd1d
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x95db3f
callstd MSG
hide_mugshot
setvar 0x8004 0x1
setvar 0x8005 0x13
setvar 0x8006 0x10
special 0x24
waitmovement 0x0
applymovement 0x1 ow_script_movs_0x95db3c
waitmovement 0x0
pause 0x10
hidesprite 0x1
sound 0x9
pause 0x10
addvar STORY_PROGRESS 0x1
releaseall
end


.ifdef LANG_GER
.global str_0x95dbb7

str_0x95dbb7:
	.autostring 35 2 "PLAYER DOTS\nErst treffe ich hier auf RIVAL, dann auf dich DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWeißt du, wie es ist, eine vernichtende Niederlage beigebracht zu bekommen?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch habe meinen Vater herausgefordert DOTS\pDOTS doch gegen ein Mitglied der Top Vier hatte ich wohl keine Chance.\pDOTS DOTS DOTS\nDOTS DOTS DOTS"
        
.global str_0x95dd1d

str_0x95dd1d:
    .autostring 35 2 "Dieses selbstgefällige Grinsen auf seinem Gesicht DOTS\pDOTS Er hat mich nicht einmal ernst genommen DOTS DOTS DOTS"
        
.global str_0x95db3f

str_0x95db3f:
	.autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pIch weiß gar nicht, warum ich dir das erzähle.\pWas interessiert dich mein Versagen DOTS\pIn Zukunft werde ich nicht mehr verlieren.\pDie Sache mit meinem Vater\nDOTS ist noch nicht vorbei DOTS"
        
.elseif LANG_EN

.endif
