.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8a71a0
ow_script_movs_0x8a71a0:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a7199
ow_script_movs_0x8a7199:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a7020
ow_script_movs_0x8a7020:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8a7006
ow_script_movs_0x8a7006:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a7003
ow_script_movs_0x8a7003:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8a69da
ow_script_movs_0x8a69da:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8a6ac4
ow_script_movs_0x8a6ac4:
.byte LOOK_LEFT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8a685c
ow_script_0x8a685c:
lockall
playsong MUS_ROCKET_HQ_AND_AZURIA_HOHLE_AND_TOP_4_BRUNO 0x0
sound 0x15
applymovement 0xff ow_script_movs_0x8a71a0
waitmovement 0x0
checksound
special 0x113
applymovement 0x7f ow_script_movs_0x8a7199
waitmovement 0x0
loadpointer 0x0 str_0x8a7134
callstd MSG
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a70a9
callstd MSG
special 0x7
loadpointer 0x0 str_0x8a7027
callstd MSG
applymovement 0x7f ow_script_movs_0x8a7020
waitmovement 0x0
special 0x114
showsprite 0x52
setflag PKMNMENU
getplayerpos 0x8000 0x8001
compare 0x8001 0x37
gotoif HIGHER ow_script_0x8a7011
compare 0x8001 0x38
gotoif HIGHER ow_script_0x8a7011
compare 0x8001 0x39
gotoif HIGHER ow_script_0x8a7011
applymovement 0x52 ow_script_movs_0x8a7006
waitmovement 0x0
applymovement 0xff ow_script_movs_0x8a7003
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a6f8a
callstd MSG
special 0x7
sound 0x15
applymovement 0x52 ow_script_movs_0x8a71a0
waitmovement 0x0
checksound
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a6f16
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x8a69da
waitmovement 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a6bac
callstd MSG_FACE
special 0x7
sound 0x15
applymovement 0x2b ow_script_movs_0x8a6ac4
applymovement 0x2c ow_script_movs_0x8a6ac4
applymovement 0x2d ow_script_movs_0x8a6ac4
applymovement 0x2e ow_script_movs_0x8a6ac4
waitmovement 0x0
checksound
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a6b82
callstd MSG
special 0x7
loadpointer 0x0 str_0x8a6bfa
callstd MSG
applymovement 0xff ow_script_movs_0x8a7003
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a6b0d
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a6ac8
callstd MSG_FACE
special 0x7
goto ow_script_0x8fbc26


.global ow_script_0x8fbc26
ow_script_0x8fbc26:
getplayerpos 0x8000 0x8001
compare 0x8001 0x37
gotoif EQUAL ow_script_0x8a6d2a
compare 0x8001 0x38
gotoif EQUAL ow_script_0x8a6d3d
compare 0x8001 0x39
gotoif EQUAL ow_script_0x8a6d50
compare 0x8001 0x3a
gotoif EQUAL ow_script_0x8a6d63
goto ow_script_0x8d42de


.global ow_script_0x8d42de
ow_script_0x8d42de:
setflag 0x1e7
setflag 0x1e7
setflag 0x1e7
setflag 0x1e7
trainerbattlecont 0x1 0x8 0x0 str_0x8a69df str_0x8a6a97 ow_script_0x8a71a2


.global ow_script_movs_0x8a6d84
ow_script_movs_0x8a6d84:
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a6d8d
ow_script_movs_0x8a6d8d:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a6d63
ow_script_0x8a6d63:
applymovement 0xff ow_script_movs_0x8a6d84
applymovement 0x52 ow_script_movs_0x8a6d8d
waitmovement 0x0
return


.global ow_script_movs_0x8a6d7f
ow_script_movs_0x8a6d7f:
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a6d8c
ow_script_movs_0x8a6d8c:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a6d50
ow_script_0x8a6d50:
applymovement 0xff ow_script_movs_0x8a6d7f
applymovement 0x52 ow_script_movs_0x8a6d8c
waitmovement 0x0
return


.global ow_script_movs_0x8a6d7b
ow_script_movs_0x8a6d7b:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a6d8b
ow_script_movs_0x8a6d8b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a6d3d
ow_script_0x8a6d3d:
applymovement 0xff ow_script_movs_0x8a6d7b
applymovement 0x52 ow_script_movs_0x8a6d8b
waitmovement 0x0
return


.global ow_script_movs_0x8a6d76
ow_script_movs_0x8a6d76:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a6d8a
ow_script_movs_0x8a6d8a:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a6d2a
ow_script_0x8a6d2a:
applymovement 0xff ow_script_movs_0x8a6d76
applymovement 0x52 ow_script_movs_0x8a6d8a
waitmovement 0x0
return


.global ow_script_movs_0x8a701d
ow_script_movs_0x8a701d:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8a7011
ow_script_0x8a7011:
applymovement 0x52 ow_script_movs_0x8a701d
waitmovement 0x0
return
