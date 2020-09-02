.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "pathfinding.s"

.global ow_script_map_18_2_trigger_0

ow_script_movs_0x95db3c:
.byte FACE_DOWN
.byte STOP


ow_script_map_18_2_trigger_0:
addvar STORY_PROGRESS 0x1
end

// this stuff doesn't add anything to the story whatsoever, remove it therefore...
lockall
sound 0x9
clearflag PKMNMENU
showsprite 0x1
pause 0x20
npc_move_to_player 1
faceplayer
draw_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT
loadpointer 0x0 str_0x95dbb7
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x95dd1d
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x95db3f
callstd MSG
hide_mugshot
npc_move_to 1 0x13 0x10
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

str_0x95dbb7:
	.autostring 35 2 "PLAYER DOTS\nErst treffe ich hier auf RIVAL, dann auf dich DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWeißt du, wie es ist, eine vernichtende Niederlage beigebracht zu bekommen?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch habe meinen Vater herausgefordert DOTS\pDOTS doch gegen ein Mitglied der Top Vier hatte ich wohl keine Chance.\pDOTS DOTS DOTS\nDOTS DOTS DOTS"


str_0x95dd1d:
    .autostring 35 2 "Dieses selbstgefällige Grinsen auf seinem Gesicht DOTS\pDOTS Er hat mich nicht einmal ernst genommen DOTS DOTS DOTS"


str_0x95db3f:
	.autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pIch weiß gar nicht, warum ich dir das erzähle.\pWas interessiert dich mein Versagen DOTS\pIn Zukunft werde ich nicht mehr verlieren.\pDie Sache mit meinem Vater\nDOTS ist noch nicht vorbei DOTS"

.elseif LANG_EN

.endif