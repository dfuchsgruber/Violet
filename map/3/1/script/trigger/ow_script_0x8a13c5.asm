.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8a17e7
ow_script_movs_0x8a17e7:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8a17e3
ow_script_movs_0x8a17e3:
.byte LOOK_RIGHT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a1604
ow_script_movs_0x8a1604:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a1603
ow_script_movs_0x8a1603:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a13c5
ow_script_0x8a13c5:
lockall
playsong MUS_ROCKET_HQ_AND_AZURIA_HOHLE_AND_TOP_4_BRUNO 0x0
special 0x0
applymovement 0x7f ow_script_movs_0x8a17e7
waitmovement 0x0
loadpointer 0x0 str_0x8a17ec
callstd MSG
sound 0x15
applymovement 0x3 ow_script_movs_0x8a17e3
applymovement 0x4 ow_script_movs_0x8a17e3
waitmovement 0x0
loadpointer 0x0 str_0x8a1608
callstd MSG
applymovement 0x3 ow_script_movs_0x8a1604
applymovement 0x7f ow_script_movs_0x8a1603
waitmovement 0x0
special 0x113
getplayerpos 0x8000 0x8001
compare 0x8001 0x1a
callif EQUAL ow_script_0x8a15f3
trainerbattlecont 0x1 0x4 0x0 str_0x8a158f str_0x8a15bf ow_script_0x8a1433


.global ow_script_movs_0x8a14a9
ow_script_movs_0x8a14a9:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8a1433
ow_script_0x8a1433:
loadpointer 0x0 str_0x8a14b2
callstd MSG
applymovement 0x3 ow_script_movs_0x8a14a9
waitmovement 0x0
hidesprite 0x3
loadpointer 0x0 str_0x8a146b
callstd MSG
applymovement 0x4 ow_script_movs_0x8a14a9
waitmovement 0x0
hidesprite 0x4
goto ow_script_0x8a1af3


.global ow_script_movs_0x8a27a5
ow_script_movs_0x8a27a5:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a1e5c
ow_script_movs_0x8a1e5c:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a1cc6
ow_script_movs_0x8a1cc6:
.byte SAY_SMILE
.byte STOP


.global ow_script_movs_0x8a1c28
ow_script_movs_0x8a1c28:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x8a1af3
ow_script_0x8a1af3:
showsprite 0x5
getplayerpos 0x8000 0x8001
compare 0x8001 0x1a
callif EQUAL ow_script_0x8a27ae
applymovement 0x5 ow_script_movs_0x8a27a5
waitmovement 0x0
call ow_script_0x8a2791
loadpointer 0x0 str_0x8f2375
callstd MSG
special 0x7
sound 0x15
applymovement 0x5 ow_script_movs_0x8a1e5c
waitmovement 0x0
checksound
call ow_script_0x8a2791
loadpointer 0x0 str_0x8f2c1e
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a1cdd
callstd MSG
special 0x7
sound 0x5
applymovement 0x5 ow_script_movs_0x8a1cc6
waitmovement 0x0
checksound
call ow_script_0x8a2791
loadpointer 0x0 str_0x8f2c62
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x8a1c28
waitmovement 0x0
hidesprite 0x5
setvar STORY_PROGRESS 0xc
releaseall
end


.global ow_script_0x8a2791
ow_script_0x8a2791:
setvar 0x8000 0x1
setvar 0x8001 0x17
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8a1cc9
ow_script_0x8a1cc9:
setvar 0x8000 0x0
setvar 0x8001 0xc
setvar 0x8002 0xe
special 0x6
return


.global ow_script_movs_0x8a27ba
ow_script_movs_0x8a27ba:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8a27ae
ow_script_0x8a27ae:
applymovement 0x5 ow_script_movs_0x8a27ba
waitmovement 0x0
return


.global ow_script_movs_0x8a15ff
ow_script_movs_0x8a15ff:
.byte STEP_DOWN
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x8a15f3
ow_script_0x8a15f3:
applymovement 0x3 ow_script_movs_0x8a15ff
waitmovement 0x0
return
