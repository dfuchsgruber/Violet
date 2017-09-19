.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x92d0b8
ow_script_movs_0x92d0b8:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x928a7c
ow_script_movs_0x928a7c:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x928a0e
ow_script_movs_0x928a0e:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x9288c3
ow_script_movs_0x9288c3:
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x9288bf
ow_script_movs_0x9288bf:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x9288ba
ow_script_movs_0x9288ba:
.byte STEP_UP
.byte STEP_RIGHT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x9286d6
ow_script_movs_0x9286d6:
.byte STEP_RIGHT
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x9312ac
ow_script_movs_0x9312ac:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x92e56b
ow_script_movs_0x92e56b:
.byte STEP_UP
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x9283a5
ow_script_0x9283a5:
lockall
playsong MUS_REVOLUTION 0x0
special 0x113
applymovement 0x7f ow_script_movs_0x92d0b8
waitmovement 0x0
special 0x114
call ow_script_0x89c5ee
loadpointer 0x0 str_0x92d01d
callstd MSG
special 0x7
call ow_script_0x8e63f4
loadpointer 0x0 str_0x92cf46
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x92ce82
callstd MSG
special 0x7
call ow_script_0x8e63f4
loadpointer 0x0 str_0x928b41
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x928a7f
callstd MSG
special 0x7
applymovement 0xc ow_script_movs_0x928a7c
waitmovement 0x0
applymovement 0xb ow_script_movs_0x92d0b8
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x928a11
callstd MSG
special 0x7
applymovement 0xb ow_script_movs_0x928a0e
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x9288c7
callstd MSG
special 0x7
applymovement 0xb ow_script_movs_0x9288c3
waitmovement 0x0
sound 0x15
applymovement 0xb ow_script_movs_0x9288bf
applymovement 0xc ow_script_movs_0x9288bf
waitmovement 0x0
special 0x113
applymovement 0x7f ow_script_movs_0x9288c3
applymovement 0xb ow_script_movs_0x9288ba
waitmovement 0x0
special 0x114
call ow_script_0x8e63f4
loadpointer 0x0 str_0x9286da
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x9286d6
waitmovement 0x0
applymovement 0xb ow_script_movs_0x9312ac
pause 0x40
call ow_script_0x89c5ee
loadpointer 0x0 str_0x9286b8
callstd MSG
special 0x7
applymovement 0xc ow_script_movs_0x92e56b
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x928594
callstd MSG
goto ow_script_0x92d67a


.global ow_script_movs_0x92dc7e
ow_script_movs_0x92dc7e:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x92dc7a
ow_script_movs_0x92dc7a:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x92db7c
ow_script_movs_0x92db7c:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x92da68
ow_script_movs_0x92da68:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x92da70
ow_script_movs_0x92da70:
.byte STEP_LEFT
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x92da6b
ow_script_movs_0x92da6b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x92d849
ow_script_movs_0x92d849:
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_UP
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x92d7a5
ow_script_movs_0x92d7a5:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x93a4d4
ow_script_movs_0x93a4d4:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x92d7b6
ow_script_movs_0x92d7b6:
.byte STEP_DOWN
.byte FACE_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte LOOK_LEFT
.byte STOP


.global ow_script_0x92d67a
ow_script_0x92d67a:
special 0x7
showsprite 0xd
applymovement 0xd ow_script_movs_0x92dc7e
waitmovement 0x0
sound 0x15
applymovement 0xc ow_script_movs_0x92dc7a
applymovement 0xff ow_script_movs_0x92dc7a
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x92dc49
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92dbcf
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x92db7f
callstd MSG
special 0x7
applymovement 0xd ow_script_movs_0x92db7c
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92db39
callstd MSG
special 0x7
applymovement 0xd ow_script_movs_0x92da68
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92db05
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x935f18
callstd MSG
special 0x7
applymovement 0xc ow_script_movs_0x92da70
waitmovement 0x0
applymovement 0xd ow_script_movs_0x92da6b
waitmovement 0x0
applymovement 0xff ow_script_movs_0x92da68
applymovement 0xc ow_script_movs_0x92da68
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92d98d
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x936ef3
callstd MSG
special 0x7
applymovement 0xc ow_script_movs_0x92d849
waitmovement 0x0
applymovement 0xd ow_script_movs_0x92db7c
applymovement 0xff ow_script_movs_0x92db7c
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x92d7c0
callstd MSG
special 0x7
applymovement 0xc ow_script_movs_0x92d7a5
waitmovement 0x0
applymovement 0xff ow_script_movs_0x93a4d4
applymovement 0xd ow_script_movs_0x92d7b6
waitmovement 0x0
goto ow_script_0x92dc84


.global ow_script_movs_0x92e6ec
ow_script_movs_0x92e6ec:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x92e6ef
ow_script_movs_0x92e6ef:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x92dc84
ow_script_0x92dc84:
pause 0x40
call ow_script_0x89e1fc
loadpointer 0x0 str_0x93a4de
callstd MSG
special 0x7
applymovement 0xd ow_script_movs_0x92e6ec
applymovement 0xff ow_script_movs_0x92e6ef
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92e6d7
callstd MSG_YES_NO
special 0x7
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x93a667
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x92e662
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92e5ea
callstd MSG
goto ow_script_0x92df8a


.global ow_script_movs_0x92e21e
ow_script_movs_0x92e21e:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x92e021
ow_script_movs_0x92e021:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x93c1e9
ow_script_movs_0x93c1e9:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x92df8a
ow_script_0x92df8a:
loadpointer 0x0 str_0x92e221
callstd MSG
special 0x7
applymovement 0xd ow_script_movs_0x92e21e
applymovement 0xff ow_script_movs_0x92e21e
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92e138
callstd MSG
special 0x7
applymovement 0xd ow_script_movs_0x92e6ec
applymovement 0xff ow_script_movs_0x92e6ef
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92e024
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x92e021
waitmovement 0x0
applymovement 0xd ow_script_movs_0x93c1e9
waitmovement 0x0
hidesprite 0x1
hidesprite 0x2
hidesprite 0x3
hidesprite 0x4
hidesprite 0x5
hidesprite 0x6
hidesprite 0x7
hidesprite 0x8
hidesprite 0x9
hidesprite 0xa
hidesprite 0xb
hidesprite 0xc
hidesprite 0xd
goto ow_script_0x941cae


.global ow_script_0x941cae
ow_script_0x941cae:
fadescreen 0x1
showsprite 0xe
showsprite 0x10
showsprite 0x11
showsprite 0x12
showsprite 0x13
showsprite 0x14
showsprite 0x15
clearflag KASKADA_IGVA
clearflag KASKADA_FELIX_DONE
fadescreen 0x0
fadesong MUS_ROUTE_24_25
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x93a667
ow_script_0x93a667:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x92e4e6
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92e56f
callstd MSG_KEEPOPEN
goto ow_script_0x92df8a
