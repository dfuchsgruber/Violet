.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb15f
ow_script_0x8fb15f:
setvar LASTTALKED 0x36
goto ow_script_0x8d35c7


.global ow_script_0x8d35c7
ow_script_0x8d35c7:
lockall
playsong MUS_BEGEGNUNG_MIT_TRAINER_GORE 0x0
showsprite 0x32
showsprite 0x33
showsprite 0x34
showsprite 0x35
showsprite 0x36
getplayerpos 0x8000 0x8001
compare 0x8000 0xd
callif EQUAL ow_script_0x8d3f37
compare 0x8000 0xe
callif EQUAL ow_script_0x8d3f43
compare 0x8000 0x10
callif EQUAL ow_script_0x8d3f4d
goto ow_script_0x8d3f7c


.global ow_script_movs_0x8d3ef2
ow_script_movs_0x8d3ef2:
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


.global ow_script_0x8d3f7c
ow_script_0x8d3f7c:
applymovement 0x36 ow_script_movs_0x8d3ef2
waitmovement 0x0
goto ow_script_0x8d40bf


.global ow_script_0x8d40bf
ow_script_0x8d40bf:
lockall
sound 0x15
singlemovement 0xff 0x0
waitmovement 0x0
singlemovement 0xff 0x62
waitmovement 0x0
goto ow_script_0x8fb128


.global ow_script_0x8fb128
ow_script_0x8fb128:
setflag PKMNMENU
pause 0x40
call ow_script_0x8d3f23
settrainerflag 0x19
trainerbattlecont 0x1 0x19 0x0 str_0x8d3efa str_0x8d3bb9 ow_script_0x8d4033


.global ow_script_0x8d4033
ow_script_0x8d4033:
applymovement 0x32 ow_script_movs_0x8d3ef2
applymovement 0x33 ow_script_movs_0x8d3ef2
applymovement 0x34 ow_script_movs_0x8d3ef2
applymovement 0x35 ow_script_movs_0x8d3ef2
waitmovement 0x0
loadpointer 0x0 str_0x8d38fe
callstd MSG
singlemovement 0x36 0x4
call ow_script_0x8d3f23
loadpointer 0x0 str_0x8d3f8b
callstd MSG
special 0x7
singlemovement 0x36 0x1
call ow_script_0x8d3f23
loadpointer 0x0 str_0x8d3be3
callstd MSG_YES_NO
special 0x7
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8d3734
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d3858
callstd MSG
special 0x7
call ow_script_0x8d3f23
loadpointer 0x0 str_0x8d375f
callstd MSG
special 0x7
setvar 0x8006 0xa
goto ow_script_0x8d3691


.global ow_script_movs_0x8d36f5
ow_script_movs_0x8d36f5:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8d36f1
ow_script_movs_0x8d36f1:
.byte STEP_IN_PLACE_UP
.byte STEP_IN_PLACE_UP
.byte STOP


.global ow_script_0x8d3691
ow_script_0x8d3691:
special2 0x8006 0xc
applymovement 0x36 ow_script_movs_0x8d36f5
waitmovement 0x0
call ow_script_0x8d3f23
loadpointer 0x0 str_0x8d36f8
callstd MSG
special 0x7
applymovement 0x32 ow_script_movs_0x8d36f1
applymovement 0x33 ow_script_movs_0x8d36f1
applymovement 0x34 ow_script_movs_0x8d36f1
applymovement 0x35 ow_script_movs_0x8d36f1
loadpointer 0x0 str_0x8d371c
callstd MSG
waitmovement 0x0
fadescreen 0x1
hidesprite 0x32
hidesprite 0x33
hidesprite 0x34
hidesprite 0x35
hidesprite 0x36
pause 0x20
goto ow_script_0x8d402a


.global ow_script_0x8d402a
ow_script_0x8d402a:
fadescreen 0x0
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x8d3f23
ow_script_0x8d3f23:
setvar 0x8000 0x1
setvar 0x8001 0x13
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8d3734
ow_script_0x8d3734:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d3aaf
callstd MSG
special 0x7
call ow_script_0x8d3f23
loadpointer 0x0 str_0x8d39ed
callstd MSG
special 0x7
setvar 0x8006 0xfff5
goto ow_script_0x8e22e1


.global ow_script_0x8e22e1
ow_script_0x8e22e1:
addvar DIFFICULTY_LEVEL_RANGE 0x1
goto ow_script_0x8d3691


.global ow_script_0x8d3f4d
ow_script_0x8d3f4d:
singlemovement 0x36 0x20
waitmovement 0x0
return


.global ow_script_0x8d3f43
ow_script_0x8d3f43:
singlemovement 0x36 0x1f
waitmovement 0x0
return


.global ow_script_0x8d3f37
ow_script_0x8d3f37:
call ow_script_0x8d3f43
call ow_script_0x8d3f43
return
