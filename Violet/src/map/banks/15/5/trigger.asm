.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "pathfinding.s"

.global ow_script_map_15_5_trigger_0

ow_script_map_15_5_trigger_0:
lockall
loadpointer 0 str_dieb
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8d4859
callstd MSG
special 0xF

compare LASTTALKED 1
gotoif EQUAL talking_to_thief
setvar LASTTALKED 0x1
getplayerpos 0x8005 0x8006
addvar 0x8006 1
npc_move_to 1 0xFFFF 0xFFFF waitmovement=1
applymovement 0xFF mov_fd
waitmovement 0
applymovement 1 mov_fu
waitmovement 0
talking_to_thief:
copyvar 0x8004 LASTTALKED
special SPECIAL_SET_TARGET_NPC_TO_VAR
faceplayer
loadpointer 0 str_dieb
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8d4782
callstd MSG
special 0xF
loadpointer 0x0 str_0x8d4644
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0 str_dieb
setvar 0x8000 0
special 0xE
trainerbattlecont 0x1 0x26 0x0 str_0x8d4604 str_0x8d469f ow_script_0x8d44f8

ow_script_0x8d44f8:
setflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
loadpointer 0x0 str_0x8d4525
callstd MSG
fadescreen 0x1
hidesprite 0x1
pause 0x18
fadescreen 0x0
setvar ROUTE_3_MILL_ALTARIA_EGG_SCRIPT 0x1
releaseall
end


mov_fd:
    .byte LOOK_DOWN, STOP
mov_fu:
    .byte LOOK_UP, STOP


.ifdef LANG_GER

str_dieb:
	.string "Dieb"
str_0x8d4859:
	.autostring 35 2 "Hehe!\nJetzt kann ich mir endlich dieses Ei unter den Nagel reißen!"
str_0x8d4782:
	.autostring 35 2 "Was? Wer bist du denn?\pWeißt du etwa auch von dem goldenen Altaria, das hier nistet?\pKeine Chance, sein Ei ist kostbar und ich werde es mir unter den Nagel reißen!"
str_0x8d4644:
    .autostring 35 2 "Ich werde nicht zulassen, dass dem Altaria sein Ei stiehlst!"
str_0x8d4604:
    .autostring 35 2 "Hehe!\pDann wirst du es wohl verteidigen müssen!"
str_0x8d469f:
    .autostring 35 2 "Verdammt!\nDas schöne Ei DOTS"
str_0x8d4525:
    .autostring 35 2 "Urgh!\pWas hast du denn davon dieses dumme Ei zu beschützen?\pDOTS DOTS DOTS\pIch verziehe michDOTS"
.elseif LANG_EN

.endif