.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8e63b5
ow_script_movs_0x8e63b5:
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8e63a3
ow_script_movs_0x8e63a3:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8e639b
ow_script_movs_0x8e639b:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8e3332
ow_script_0x8e3332:
lockall
clearflag PKMNMENU
showsprite 0x11
setflag PKMNMENU
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
applymovement 0x11 ow_script_movs_0x8e63b5
waitmovement 0x0
getplayerpos 0x8000 0x8001
compare 0x8001 0x9
callif HIGHER_OR_EQUAL ow_script_0x8e63a6
compare 0x8001 0xa
callif HIGHER_OR_EQUAL ow_script_0x8e63a6
applymovement 0xff ow_script_movs_0x8e63a3
waitmovement 0x0
applymovement 0x11 ow_script_movs_0x8e639b
waitmovement 0x0
goto ow_script_0x8fb3fe


.global ow_script_0x8fb3fe
ow_script_0x8fb3fe:
call ow_script_0x89ba6e
compare STARTER_SELECTED 0x0
gotoif EQUAL ow_script_0x8e33a7
compare STARTER_SELECTED 0x1
gotoif EQUAL ow_script_0x8e33bb
trainerbattlecont 0x1 0x14b 0x0 str_0x8e627c str_0x8e6231 ow_script_0x8e63b7


.global ow_script_0x8e63b7
ow_script_0x8e63b7:
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8e6164
callstd MSG
special 0x7
setflag DETEKTOR_ID
copyvarifnotzero 0x8000 ITEM_DETEKTOR
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
call ow_script_0x89ba6e
loadpointer 0x0 str_0x9681e9
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x11
fadescreen 0x0
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x8e33bb
ow_script_0x8e33bb:
trainerbattlecont 0x1 0x14a 0x0 str_0x8e627c str_0x8e6231 ow_script_0x8e63b7


.global ow_script_0x8e33a7
ow_script_0x8e33a7:
trainerbattlecont 0x1 0x149 0x0 str_0x8e627c str_0x8e6231 ow_script_0x8e63b7


.global ow_script_movs_0x8e63b2
ow_script_movs_0x8e63b2:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8e63a6
ow_script_0x8e63a6:
applymovement 0x11 ow_script_movs_0x8e63b2
waitmovement 0x0
return
