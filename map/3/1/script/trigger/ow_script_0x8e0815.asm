.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8e1841
ow_script_movs_0x8e1841:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8e1745
ow_script_movs_0x8e1745:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8e1742
ow_script_movs_0x8e1742:
.byte 0x0
.byte STOP


.global ow_script_movs_0x8e162b
ow_script_movs_0x8e162b:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8e1521
ow_script_movs_0x8e1521:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8e146d
ow_script_movs_0x8e146d:
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8e0815
ow_script_0x8e0815:
lockall
applymovement 0xff ow_script_movs_0x8e1841
waitmovement 0x0
loadpointer 0x0 str_0x8e17bd
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x8e1748
callstd MSG_KEEPOPEN
applymovement 0x2b ow_script_movs_0x8e1745
applymovement 0x29 ow_script_movs_0x8e1742
waitmovement 0x0
loadpointer 0x0 str_0x8e1702
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x8e167c
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x8e162e
callstd MSG_KEEPOPEN
applymovement 0x2b ow_script_movs_0x8e162b
applymovement 0x29 ow_script_movs_0x8e162b
waitmovement 0x0
loadpointer 0x0 str_0x8e15cc
callstd MSG_KEEPOPEN
sound 0x15
applymovement 0x2a ow_script_movs_0x8e162b
waitmovement 0x0
applymovement 0x29 ow_script_movs_0x8e1521
applymovement 0x2a ow_script_movs_0x8e1521
applymovement 0x2b ow_script_movs_0x8e1521
waitmovement 0x0
loadpointer 0x0 str_0x8e14fb
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x8e148e
callstd MSG_KEEPOPEN
getplayerpos 0x8000 0x8001
compare 0x8001 0x1e
gotoif EQUAL ow_script_0x8e1470
compare 0x8001 0x20
gotoif EQUAL ow_script_0x8e147c
applymovement 0x2a ow_script_movs_0x8e146d
waitmovement 0x0
loadpointer 0x0 str_0x8e12f8
callstd MSG_KEEPOPEN
applymovement 0x2a ow_script_movs_0x8e1841
waitmovement 0x0
loadpointer 0x0 str_0x8e11b9
callstd MSG_KEEPOPEN
applymovement 0x2a ow_script_movs_0x8e162b
loadpointer 0x0 str_0x8e0f79
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
goto ow_script_0x8f6e54


.global ow_script_0x8f6e54
ow_script_0x8f6e54:
loadpointer 0x0 str_0x8e1015
goto ow_script_0x8e1b14


.global ow_script_0x8e1b14
ow_script_0x8e1b14:
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
callif EQUAL ow_script_0x8e22eb
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8e0cdc
callstd MSG_KEEPOPEN
special 0x7
trainerbattlecont 0x1 0x2c 0x0 str_0x8e0c9c str_0x8e0c71 ow_script_0x8e09cc


.global ow_script_movs_0x8e0c56
ow_script_movs_0x8e0c56:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8e09cc
ow_script_0x8e09cc:
loadpointer 0x0 str_0x8e0c5e
callstd MSG_KEEPOPEN
showsprite 0x2c
showsprite 0x2d
applymovement 0x2c ow_script_movs_0x8e0c56
applymovement 0x2d ow_script_movs_0x8e0c56
waitmovement 0x0
applymovement 0x2a ow_script_movs_0x8e162b
waitmovement 0x0
sound 0x15
applymovement 0x29 ow_script_movs_0x8e1521
applymovement 0x2a ow_script_movs_0x8e1521
applymovement 0x2b ow_script_movs_0x8e1521
applymovement 0xff ow_script_movs_0x8e1521
waitmovement 0x0
loadpointer 0x0 str_0x8e0b99
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x8e0b24
callstd MSG
fadescreen 0x1
hidesprite 0x29
hidesprite 0x2a
hidesprite 0x2b
hidesprite 0x2d
fadescreen 0x0
goto ow_script_0x8e1b5e


.global ow_script_movs_0x8e1d9e
ow_script_movs_0x8e1d9e:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x8e1b5e
ow_script_0x8e1b5e:
applymovement 0xff ow_script_movs_0x8e1d9e
waitmovement 0x0
goto ow_script_0x8e1da1


.global ow_script_movs_0x8e0b21
ow_script_movs_0x8e0b21:
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8e1da1
ow_script_0x8e1da1:
applymovement 0x2c ow_script_movs_0x8e0b21
waitmovement 0x0
loadpointer 0x0 str_0x8e0aa8
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 0x15
copyvarifnotzero 0x8001 0x1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x8e0a79
callstd MSG
fadescreen 0x1
hidesprite 0x2c
fadescreen 0x0
setvar 0x4054 0x80
setflag 0x229
setvar 0x8000 0x8
special2 0x8000 0xc
releaseall
end


.global ow_script_0x8e22eb
ow_script_0x8e22eb:
addvar _buffer1 0x1
goto ow_script_0x8e0da6


.global ow_script_0x8e0da6
ow_script_0x8e0da6:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8e0f0b
callstd MSG_KEEPOPEN
special 0x7
loadpointer 0x0 str_0x8e0ef0
callstd MSG_KEEPOPEN
sound 0x41
givemoney 0x5dc 0x0
loadpointer 0x0 str_0x8e0edc
callstd MSG_KEEPOPEN
checksound
loadpointer 0x0 str_0x8e0e4f
callstd MSG
fadescreen 0x1
hidesprite 0x2a
fadescreen 0x0
applymovement 0x2b ow_script_movs_0x8e1745
applymovement 0x29 ow_script_movs_0x8e1742
waitmovement 0x0
loadpointer 0x0 str_0x8e0e17
callstd MSG
fadescreen 0x1
hidesprite 0x2b
hidesprite 0x29
fadescreen 0x0
setvar 0x4054 0x7f
setflag 0x229
setvar 0x8000 0xfff2
special2 0x8000 0xc
releaseall
end


.global ow_script_movs_0x8e148b
ow_script_movs_0x8e148b:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8e147c
ow_script_0x8e147c:
applymovement 0x2a ow_script_movs_0x8e148b
waitmovement 0x0
return


.global ow_script_movs_0x8e1488
ow_script_movs_0x8e1488:
.byte STEP_UP
.byte STOP


.global ow_script_0x8e1470
ow_script_0x8e1470:
applymovement 0x2a ow_script_movs_0x8e1488
waitmovement 0x0
return
