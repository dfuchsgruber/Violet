.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x933e11
ow_script_movs_0x933e11:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x933e0d
ow_script_movs_0x933e0d:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x933c58
ow_script_movs_0x933c58:
.byte STEP_UP
.byte STEP_UP
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x933c5d
ow_script_movs_0x933c5d:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x933ac1
ow_script_0x933ac1:
checkflag KASKADA_BLACKMARKET_PRIMUS
gotoif LESS ow_script_0x933fe1
checkflag KASKADA_BLACKMARKET_BLAISE
gotoif LESS ow_script_0x933fe1
checkflag KASKADA_BLACKMARET_BB_SHIP
gotoif LESS ow_script_0x933fe1
lock
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x933f08
callstd MSG
special 0x7
showsprite 0x1d
showsprite 0x1e
showsprite 0x1f
setflag PKMNMENU
applymovement 0x1d ow_script_movs_0x933e11
applymovement 0x1e ow_script_movs_0x933e11
applymovement 0x1f ow_script_movs_0x933e11
waitmovement 0x0
sound 0x15
applymovement 0xff ow_script_movs_0x933e0d
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x933c60
callstd MSG
special 0x7
applymovement 0x1d ow_script_movs_0x933c58
waitmovement 0x0
applymovement 0xff ow_script_movs_0x933c5d
waitmovement 0x0
goto ow_script_0x935a41


.global ow_script_0x935a41
ow_script_0x935a41:
setflag BLACKOUT_BYPASS
loadpointer 0x0 str_0x933bb4
callstd MSG
trainerbattlelosable 0x9 0x73 0x0 str_0x933c29 str_0x935b22
goto ow_script_0x936ffe


.global ow_script_movs_0x935b64
ow_script_movs_0x935b64:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x935c46
ow_script_movs_0x935c46:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x937090
ow_script_movs_0x937090:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_UP
.byte STOP


.global ow_script_0x936ffe
ow_script_0x936ffe:
clearflag BLACKOUT_BYPASS
applymovement 0xff ow_script_movs_0x935b64
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x93661f
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x935c46
waitmovement 0x0
call ow_script_0x92f097
loadpointer 0x0 str_0x9365b7
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x935b64
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x9362bd
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x1d
hidesprite 0x1e
hidesprite 0x1f
fadescreen 0x0
applymovement 0xff ow_script_movs_0x935c46
waitmovement 0x0
call ow_script_0x92f097
loadpointer 0x0 str_0x9360fc
callstd MSG
special 0x7
applymovement 0x20 ow_script_movs_0x937090
waitmovement 0x0
hidesprite 0x20
releaseall
end


.global ow_script_0x933fe1
ow_script_0x933fe1:
lock
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x9359bb
callstd MSG
special 0x7
release
end
