.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x89dc15
ow_script_movs_0x89dc15:
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x89d952
ow_script_movs_0x89d952:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x89db68
ow_script_movs_0x89db68:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x89db6e
ow_script_movs_0x89db6e:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x89d8c1
ow_script_0x89d8c1:
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89dc19
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x89dc15
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89db85
callstd MSG
special 0x7
clearflag ANOMIA_RIVAL_OUTSIDE_PLAYER_HOUSE
showsprite 0x5
sound 0x9
checksound
sound 0x15
applymovement 0xff ow_script_movs_0x89d952
applymovement 0x3 ow_script_movs_0x89d952
waitmovement 0x0
checksound
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89d956
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x89db68
waitmovement 0x0
applymovement 0xff ow_script_movs_0x89db6e
applymovement 0x3 ow_script_movs_0x89db6e
waitmovement 0x0
call ow_script_0x89db71
loadpointer 0x0 str_0x980cd8
callstd MSG
special 0x7
goto ow_script_0x89e433


.global ow_script_movs_0x89e5fe
ow_script_movs_0x89e5fe:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89e321
ow_script_movs_0x89e321:
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x89e601
ow_script_movs_0x89e601:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x89de04
ow_script_movs_0x89de04:
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x89df4c
ow_script_movs_0x89df4c:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x89de00
ow_script_movs_0x89de00:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x89ddfc
ow_script_movs_0x89ddfc:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_0x89e433
ow_script_0x89e433:
showsprite 0x6
sound 0x9
checksound
applymovement 0xff ow_script_movs_0x89e5fe
applymovement 0x3 ow_script_movs_0x89e5fe
applymovement 0x5 ow_script_movs_0x89e5fe
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89e366
callstd MSG
special 0x7
call ow_script_0x89e33c
loadpointer 0x0 str_0x89e350
callstd MSG
special 0x7
applymovement 0x6 ow_script_movs_0x89e321
waitmovement 0x0
applymovement 0xff ow_script_movs_0x89e601
applymovement 0x3 ow_script_movs_0x89e601
applymovement 0x5 ow_script_movs_0x89e601
waitmovement 0x0
call ow_script_0x89db71
loadpointer 0x0 str_0x89e03c
callstd MSG
special 0x7
showsprite 0x7
sound 0x9
checksound
applymovement 0xff ow_script_movs_0x89e5fe
applymovement 0x3 ow_script_movs_0x89e5fe
applymovement 0x5 ow_script_movs_0x89e5fe
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89e210
callstd MSG
special 0x7
applymovement 0x7 ow_script_movs_0x89de04
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x89df52
callstd MSG
special 0x7
applymovement 0x7 ow_script_movs_0x89df4c
waitmovement 0x0
applymovement 0xff ow_script_movs_0x89e601
applymovement 0x3 ow_script_movs_0x89e601
applymovement 0x5 ow_script_movs_0x89e601
waitmovement 0x0
special 0x113
applymovement 0x7f ow_script_movs_0x89de00
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x89df1e
callstd MSG
special 0x7
call ow_script_0x89e328
loadpointer 0x0 str_0x89de07
callstd MSG
special 0x7
applymovement 0x7f ow_script_movs_0x89ddfc
waitmovement 0x0
special 0x114
goto ow_script_0x89e77b


.global ow_script_movs_0x89ed9f
ow_script_movs_0x89ed9f:
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x89ed9b
ow_script_movs_0x89ed9b:
.byte STEP_LEFT
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x89ebf7
ow_script_movs_0x89ebf7:
.byte STEP_IN_PLACE_UP
.byte STEP_IN_PLACE_UP
.byte STOP


.global ow_script_movs_0x89ea7c
ow_script_movs_0x89ea7c:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte FACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STOP


.global ow_script_movs_0x89ea17
ow_script_movs_0x89ea17:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89e9cd
ow_script_movs_0x89e9cd:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STOP


.global ow_script_movs_0x89e934
ow_script_movs_0x89e934:
.byte STEP_RIGHT
.byte STEP_UP
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89e909
ow_script_movs_0x89e909:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


.global ow_script_0x89e77b
ow_script_0x89e77b:
applymovement 0x5 ow_script_movs_0x89e601
waitmovement 0x0
call ow_script_0x89db71
loadpointer 0x0 str_0x89ee4c
callstd MSG
special 0x7
showsprite 0x4
sound 0x9
checksound
applymovement 0xff ow_script_movs_0x89e5fe
applymovement 0x3 ow_script_movs_0x89e5fe
applymovement 0x5 ow_script_movs_0x89e5fe
applymovement 0x6 ow_script_movs_0x89e5fe
applymovement 0x7 ow_script_movs_0x89e5fe
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89eda2
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x89ed9f
applymovement 0x3 ow_script_movs_0x89ed9b
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89ebfb
callstd MSG
special 0x7
applymovement 0x4 ow_script_movs_0x89ebf7
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89ea85
callstd MSG
special 0x7
applymovement 0x6 ow_script_movs_0x89ea7c
waitmovement 0x0
call ow_script_0x89e328
loadpointer 0x0 str_0x89ea1d
callstd MSG
special 0x7
applymovement 0x6 ow_script_movs_0x89ea17
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89e9d4
callstd MSG
special 0x7
applymovement 0x7 ow_script_movs_0x89e9cd
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x89e939
callstd MSG
special 0x7
applymovement 0x7 ow_script_movs_0x89e934
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89e90e
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x89e909
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89e896
callstd MSG
special 0x7
goto ow_script_0x922e6e


.global ow_script_movs_0x89f189
ow_script_movs_0x89f189:
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STOP


.global ow_script_movs_0x89f119
ow_script_movs_0x89f119:
.byte STEP_LEFT
.byte STEP_UP
.byte FACE_DOWN
.byte STOP


.global ow_script_0x922e6e
ow_script_0x922e6e:
setvar STORY_PROGRESS 0x8
callasm 0x91a44c1
pause 0x1
copyvar 0x8004 LASTRESULT
bufferpokemon 0x0 LASTRESULT
givepokemon 0x8004 0x5 ITEM_SINELBEERE 0x0 0x0 0x0
fanfare 0x13e
loadpointer 0x0 str_0x889b91
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
call ow_script_0x893bb5
setflag PKMNMENU
applymovement 0xff ow_script_movs_0x89f189
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89f11e
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x89f119
waitmovement 0x0
goto ow_script_0x89f51e


.global ow_script_movs_0x89fa1a
ow_script_movs_0x89fa1a:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STOP


.global ow_script_movs_0x89f960
ow_script_movs_0x89f960:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89f8b2
ow_script_movs_0x89f8b2:
.byte STEP_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STOP


.global ow_script_movs_0x89f86a
ow_script_movs_0x89f86a:
.byte STEP_UP
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89f7ac
ow_script_movs_0x89f7ac:
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8a0014
ow_script_movs_0x8a0014:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x89f7be
ow_script_movs_0x89f7be:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte LOOK_LEFT
.byte FACE_DOWN
.byte STOP


.global ow_script_0x89f51e
ow_script_0x89f51e:
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89fa22
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89fa5d
callstd MSG
special 0x7
applymovement 0x3 ow_script_movs_0x89fa1a
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89f966
callstd MSG
special 0x7
applymovement 0x3 ow_script_movs_0x89f960
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89f8b8
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x89f8b2
waitmovement 0x0
call ow_script_0x89db71
loadpointer 0x0 str_0x89f86e
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x89f86a
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89f7c9
callstd MSG
special 0x7
applymovement 0x4 ow_script_movs_0x89f7ac
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x8a0014
applymovement 0x4 ow_script_movs_0x89f7be
applymovement 0x5 ow_script_movs_0x8a0014
applymovement 0x6 ow_script_movs_0x8a0014
applymovement 0x7 ow_script_movs_0x8a0014
applymovement 0xff ow_script_movs_0x8a0014
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89f64c
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89f603
callstd MSG
special 0x7
goto ow_script_0x89fa80


.global ow_script_movs_0x8a02f4
ow_script_movs_0x8a02f4:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8a02f7
ow_script_movs_0x8a02f7:
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a02c5
ow_script_movs_0x8a02c5:
.byte JUMP_IN_PLACE_FACE_RIGHT
.byte JUMP_IN_PLACE_FACE_RIGHT
.byte STOP


.global ow_script_movs_0x8a01ab
ow_script_movs_0x8a01ab:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89fef6
ow_script_movs_0x89fef6:
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x89fc4c
ow_script_movs_0x89fc4c:
.byte LOOK_RIGHT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x89fe38
ow_script_movs_0x89fe38:
.byte JUMP_IN_PLACE_FACE_DOWN
.byte JUMP_IN_PLACE_FACE_DOWN
.byte SAY_DOUBLE_EXCLAM
.byte STOP


.global ow_script_movs_0x89fc40
ow_script_movs_0x89fc40:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_0x89fa80
ow_script_0x89fa80:
applymovement 0x4 ow_script_movs_0x8a02f4
applymovement 0x3 ow_script_movs_0x8a02f7
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a02c9
callstd MSG
special 0x7
applymovement 0x3 ow_script_movs_0x8a02c5
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a0269
callstd MSG
special 0x7
call ow_script_0x89e33c
loadpointer 0x0 str_0x8a01ae
callstd MSG_FACE
special 0x7
applymovement 0x3 ow_script_movs_0x8a01ab
applymovement 0x4 ow_script_movs_0x8a01ab
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a001e
callstd MSG
special 0x7
applymovement 0x3 ow_script_movs_0x89fef6
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89fe98
callstd MSG
special 0x7
call ow_script_0x89e33c
loadpointer 0x0 str_0x89fe3d
callstd MSG
special 0x7
sound 0x15
applymovement 0xff ow_script_movs_0x89fc4c
applymovement 0x3 ow_script_movs_0x89fc4c
applymovement 0x5 ow_script_movs_0x89fc4c
applymovement 0x7 ow_script_movs_0x89fc4c
applymovement 0x4 ow_script_movs_0x89fe38
waitmovement 0x0
checksound
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89fd21
callstd MSG
special 0x7
call ow_script_0x89e33c
loadpointer 0x0 str_0x89fc50
callstd MSG
special 0x7
applymovement 0x6 ow_script_movs_0x89fc40
waitmovement 0x0
sound 0x9
hidesprite 0x6
applymovement 0xff ow_script_movs_0x89e5fe
applymovement 0x3 ow_script_movs_0x89e5fe
applymovement 0x5 ow_script_movs_0x89e5fe
applymovement 0x7 ow_script_movs_0x89e5fe
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x89fba5
callstd MSG
special 0x7
goto ow_script_0x89e54e


.global ow_script_movs_0x8a039c
ow_script_movs_0x8a039c:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x89ff8d
ow_script_movs_0x89ff8d:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_DOWN
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x89ff88
ow_script_movs_0x89ff88:
.byte STEP_UP
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x89e54e
ow_script_0x89e54e:
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a039f
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x8a039c
applymovement 0x3 ow_script_movs_0x8a039c
applymovement 0x5 ow_script_movs_0x8a039c
applymovement 0x7 ow_script_movs_0x8a039c
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a0376
callstd MSG
special 0x7
call ow_script_0x89db71
loadpointer 0x0 str_0x8a035f
callstd MSG
special 0x7
call ow_script_0x8a0496
call ow_script_0x89db71
loadpointer 0x0 str_0x8a02fb
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89ff93
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x89ff8d
waitmovement 0x0
applymovement 0xff ow_script_movs_0x89ff88
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89fefb
callstd MSG
special 0x7
goto ow_script_0x8a04ab


.global ow_script_0x8a04ab
ow_script_0x8a04ab:
goto ow_script_0x8facfc


.global ow_script_0x8facfc
ow_script_0x8facfc:
setwildbattle POKEMON_STARALILI 0x2 ITEM_NONE
dowildbattle
compare LASTRESULT 0xff
gotoif EQUAL ow_script_0x8a116d
compare LASTRESULT 0x1
gotoif NOT_EQUAL ow_script_0x8fb3e3
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a10a1
callstd MSG
special 0x7
applymovement 0x4 ow_script_movs_0x8a01ab
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a1073
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8a1036
callstd MSG
special 0x7
goto ow_script_0x8a23fe


.global ow_script_movs_0x8a1189
ow_script_movs_0x8a1189:
.byte STEP_DOWN
.byte STEP_DOWN
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8a102e
ow_script_movs_0x8a102e:
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte JUMP_IN_PLACE_FACE_RIGHT
.byte JUMP_IN_PLACE_FACE_RIGHT
.byte STOP


.global ow_script_movs_0x8a22c8
ow_script_movs_0x8a22c8:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8a0ee0
ow_script_movs_0x8a0ee0:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8a0d18
ow_script_movs_0x8a0d18:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8a0d07
ow_script_movs_0x8a0d07:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8a0d22
ow_script_movs_0x8a0d22:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8a0d2e
ow_script_movs_0x8a0d2e:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x922f09
ow_script_movs_0x922f09:
.byte STEP_IN_PLACE_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


.global ow_script_0x8a23fe
ow_script_0x8a23fe:
applymovement 0xff ow_script_movs_0x8a1189
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x8a102e
waitmovement 0x0
applymovement 0x4 ow_script_movs_0x8a22c8
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8a0ff4
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a0f9b
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8a0f25
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a0ee7
callstd MSG
special 0x7
applymovement 0x7 ow_script_movs_0x8a0ee0
waitmovement 0x0
applymovement 0x4 ow_script_movs_0x8a01ab
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a0d3d
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x8a0d18
applymovement 0x3 ow_script_movs_0x8a0d07
applymovement 0x5 ow_script_movs_0x8a0d22
applymovement 0x7 ow_script_movs_0x8a0d2e
applymovement 0x4 ow_script_movs_0x922f09
waitmovement 0x0
goto ow_script_0x8a24ab


.global ow_script_0x8a24ab
ow_script_0x8a24ab:
goto ow_script_0x8a324a


.global ow_script_0x8a324a
ow_script_0x8a324a:
setflag BLACKOUT_BYPASS
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a3164
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a2fdd
callstd MSG
special 0x7
compare STARTER_SELECTED 0x0
gotoif EQUAL ow_script_0x8a2d8f
compare STARTER_SELECTED 0x1
gotoif EQUAL ow_script_0x8a2da3
trainerbattlelosable 0x9 0x148 0x0 str_0x8a30ff str_0x8a3129
goto ow_script_0x8a2db7


.global ow_script_0x8a2db7
ow_script_0x8a2db7:
copyvar 0x8006 LASTRESULT
compare 0x8006 0x0
callif NOT_EQUAL ow_script_0x8a2dd8
compare 0x8006 0x0
callif EQUAL ow_script_0x8a2dea
goto ow_script_0x8a32d6


.global ow_script_movs_0x8a3ef8
ow_script_movs_0x8a3ef8:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a3e37
ow_script_movs_0x8a3e37:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8a3cc1
ow_script_movs_0x8a3cc1:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8a3cd1
ow_script_movs_0x8a3cd1:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8a3ccb
ow_script_movs_0x8a3ccb:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8a3cf3
ow_script_movs_0x8a3cf3:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8a3cda
ow_script_movs_0x8a3cda:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8a3ce5
ow_script_movs_0x8a3ce5:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x8a32d6
ow_script_0x8a32d6:
special 0x113
applymovement 0x7f ow_script_movs_0x8a3ef8
waitmovement 0x0
call ow_script_0x89db71
loadpointer 0x0 str_0x8a3e3e
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8a3e79
callstd MSG
special 0x7
applymovement 0x7f ow_script_movs_0x8a3e37
waitmovement 0x0
special 0x114
applymovement 0xff ow_script_movs_0x8a3cc1
applymovement 0x3 ow_script_movs_0x8a3cc1
applymovement 0x5 ow_script_movs_0x8a3cc1
applymovement 0x7 ow_script_movs_0x8a3cc1
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a3cfd
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x8a3cd1
applymovement 0x3 ow_script_movs_0x8a3ccb
applymovement 0x4 ow_script_movs_0x8a3cf3
applymovement 0x5 ow_script_movs_0x8a3cda
applymovement 0x7 ow_script_movs_0x8a3ce5
waitmovement 0x0
goto ow_script_0x8a3efe


.global ow_script_0x8a3efe
ow_script_0x8a3efe:
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a4a2b
compare TRAINERSCHOOL_CORRECT_ANSWERS 0xa
callif EQUAL ow_script_0x8a4909
callstd MSG
goto ow_script_0x8a5594


.global ow_script_0x8a5594
ow_script_0x8a5594:
loadpointer 0x0 str_0x8a62af
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x89ff88
waitmovement 0x0
applymovement 0x4 ow_script_movs_0x8a02f4
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a61c1
callstd MSG
special 0x7
copyvarifnotzero 0x8000 ITEM_POKEBALL
copyvarifnotzero 0x8001 ITEM_TIMERBALL
callstd ITEM_OBTAIN
goto ow_script_0x8a5fe1


.global ow_script_0x8a5fe1
ow_script_0x8a5fe1:
special 0x0
call ow_script_0x8a0ce9
additem ITEM_POKEBALL 0xa
compare TRAINERSCHOOL_CORRECT_ANSWERS 0xa
callif EQUAL ow_script_0x8a607a
compare STARTER_SELECTED 0x0
callif EQUAL ow_script_0x8a62d0
compare STARTER_SELECTED 0x1
callif EQUAL ow_script_0x8a6d9d
compare STARTER_SELECTED 0x2
callif EQUAL ow_script_0x8a6dad
dowildbattle
countpokemon
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x8a6046
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a6151
callstd MSG
special 0x7
goto ow_script_0x8a5fe1


.global ow_script_0x89c5ee
ow_script_0x89c5ee:
setvar 0x8000 0x0
setvar 0x8001 0xe
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8a6046
ow_script_0x8a6046:
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a6081
callstd MSG
special 0x7
goto ow_script_0x8a6dbc


.global ow_script_movs_0x8a7ac4
ow_script_movs_0x8a7ac4:
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8a7aca
ow_script_movs_0x8a7aca:
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte LOOK_UP
.byte STOP


.global ow_script_0x8a6dbc
ow_script_0x8a6dbc:
applymovement 0x4 ow_script_movs_0x8a01ab
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a7c05
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a7bbf
callstd MSG
special 0x7
applymovement 0x3 ow_script_movs_0x8a02f7
applymovement 0xff ow_script_movs_0x8a1189
waitmovement 0x0
applymovement 0x4 ow_script_movs_0x8a02f4
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a7b8a
callstd MSG
special 0x7
sound 0x36
applymovement 0x3 ow_script_movs_0x8a02c5
waitmovement 0x0
checksound
sound 0x35
checksound
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a7b45
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a7b26
callstd MSG
special 0x7
applymovement 0x4 ow_script_movs_0x8a01ab
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a7af9
callstd MSG
special 0x7
call ow_script_0x89db71
loadpointer 0x0 str_0x8a7ad0
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x8a7ac4
applymovement 0x3 ow_script_movs_0x8a7aca
waitmovement 0x0
applymovement 0x4 ow_script_movs_0x8a02f4
waitmovement 0x0
call ow_script_0x89db71
loadpointer 0x0 str_0x8a7aa5
callstd MSG
special 0x7
sound 0x36
applymovement 0x5 ow_script_movs_0x8a02c5
waitmovement 0x0
checksound
sound 0x35
checksound
call ow_script_0x89db71
loadpointer 0x0 str_0x8a7a8a
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a7a63
callstd MSG
special 0x7
applymovement 0x4 ow_script_movs_0x8a01ab
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a7a46
callstd MSG
special 0x7
removeitem ITEM_POKEBALL 0xa
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8a7a04
callstd MSG
special 0x7
goto ow_script_0x8a9e01


.global ow_script_movs_0x8a8f0e
ow_script_movs_0x8a8f0e:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_DOWN
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8a8f07
ow_script_movs_0x8a8f07:
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8a8f04
ow_script_movs_0x8a8f04:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8a8e6d
ow_script_movs_0x8a8e6d:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8a8c91
ow_script_movs_0x8a8c91:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8a8c8c
ow_script_movs_0x8a8c8c:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x8a8c5a
ow_script_movs_0x8a8c5a:
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8a8c57
ow_script_movs_0x8a8c57:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8aabe2
ow_script_movs_0x8aabe2:
.byte LOOK_UP
.byte STOP


.global ow_script_0x8a9e01
ow_script_0x8a9e01:
applymovement 0x5 ow_script_movs_0x8a8f0e
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x8a8f07
waitmovement 0x0
applymovement 0x4 ow_script_movs_0x8a8f04
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a8ecd
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8a8eb7
callstd MSG
special 0x7
sound 0x36
applymovement 0x7 ow_script_movs_0x8a02c5
waitmovement 0x0
checksound
sound 0x35
checksound
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a8e74
callstd MSG
special 0x7
applymovement 0x7 ow_script_movs_0x8a8e6d
waitmovement 0x0
applymovement 0x4 ow_script_movs_0x8a8c91
waitmovement 0x0
fadesong MUS_0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a8df9
callstd MSG
special 0x7
applymovement 0x4 ow_script_movs_0x8a8c8c
waitmovement 0x0
applymovement 0xff ow_script_movs_0x8a8f04
applymovement 0x5 ow_script_movs_0x8a8f04
applymovement 0x7 ow_script_movs_0x8a8f04
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a8dbf
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a8c94
callstd MSG
special 0x7
fanfare 0x13e
waitfanfare
playsong MUS_TRAINERSCHOOL 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8a8c6e
callstd MSG
special 0x7
call ow_script_0x89db71
loadpointer 0x0 str_0x8a8c5e
callstd MSG
special 0x7
fadesong MUS_0
applymovement 0x4 ow_script_movs_0x8a8c5a
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x8a8c57
waitmovement 0x0
applymovement 0xff ow_script_movs_0x8aabe2
waitmovement 0x0
call ow_script_0x8aabe4
loadpointer 0x0 str_0x8a8c31
callstd MSG
loadpointer 0x0 str_0x8af042
callstd MSG
special 0x7
fanfare 0x13e
waitfanfare
playsong MUS_TRAINERSCHOOL 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8a8a28
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a8a01
callstd MSG
special 0x7
call ow_script_0x89db71
loadpointer 0x0 str_0x8a89ec
callstd MSG
special 0x7
goto ow_script_0x8ab99d


.global ow_script_0x8ab99d
ow_script_0x8ab99d:
applymovement 0x4 ow_script_movs_0x8a8c5a
waitmovement 0x0
fadesong MUS_0
applymovement 0xff ow_script_movs_0x8a8c57
waitmovement 0x0
applymovement 0x5 ow_script_movs_0x8aabe2
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8abc30
callstd MSG
special 0x7
fanfare 0x13e
waitfanfare
playsong MUS_TRAINERSCHOOL 0x0
call ow_script_0x89db71
loadpointer 0x0 str_0x8abbec
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8abbd6
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8abbb5
callstd MSG
special 0x7
applymovement 0x4 ow_script_movs_0x8a8c5a
waitmovement 0x0
fadesong MUS_0
applymovement 0x5 ow_script_movs_0x8a8c57
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x8aabe2
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8abb05
callstd MSG
special 0x7
fanfare 0x13e
waitfanfare
playsong MUS_TRAINERSCHOOL 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8abade
callstd MSG
special 0x7
call ow_script_0x89db71
loadpointer 0x0 str_0x8abaa9
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8aba75
callstd MSG
special 0x7
goto ow_script_0x8abd3a


.global ow_script_movs_0x8ad1c9
ow_script_movs_0x8ad1c9:
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8af17e
ow_script_movs_0x8af17e:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8acfc1
ow_script_movs_0x8acfc1:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x8acfca
ow_script_movs_0x8acfca:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x8acfbe
ow_script_movs_0x8acfbe:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8acec7
ow_script_movs_0x8acec7:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8ace0a
ow_script_movs_0x8ace0a:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8accac
ow_script_movs_0x8accac:
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8abd3a
ow_script_0x8abd3a:
applymovement 0x4 ow_script_movs_0x8ad1c9
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x8af17e
applymovement 0x5 ow_script_movs_0x8af17e
applymovement 0xff ow_script_movs_0x8af17e
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8acfd5
callstd MSG
special 0x7
applymovement 0x4 ow_script_movs_0x8acfc1
waitmovement 0x0
applymovement 0x4 ow_script_movs_0x8acfca
waitmovement 0x0
hidesprite 0x4
applymovement 0x3 ow_script_movs_0x8acfbe
applymovement 0x5 ow_script_movs_0x8acfbe
applymovement 0x7 ow_script_movs_0x8acfbe
applymovement 0xff ow_script_movs_0x8acfbe
waitmovement 0x0
call ow_script_0x89db71
loadpointer 0x0 str_0x8acecc
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x8acec7
waitmovement 0x0
applymovement 0x5 ow_script_movs_0x8acfca
waitmovement 0x0
hidesprite 0x5
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8ace11
callstd MSG
special 0x7
applymovement 0x3 ow_script_movs_0x8ace0a
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x8acfca
waitmovement 0x0
hidesprite 0x3
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8accb0
callstd MSG
special 0x7
applymovement 0x7 ow_script_movs_0x8accac
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x8acfca
waitmovement 0x0
hidesprite 0x7
goto ow_script_0x8ad1ce


.global ow_script_0x8ad1ce
ow_script_0x8ad1ce:
call ow_script_0x8a0ce9
goto ow_script_0x8af180


.global ow_script_0x8af180
ow_script_0x8af180:
setvar TRAINERSCHOOL_DONE 0x1
setflag TRAINERSCHOOL_FAUN_INSIDE
setvar STORY_PROGRESS 0x8
end


.global ow_script_0x8a0ce9
ow_script_0x8a0ce9:
checkitem ITEM_POKEBALL 0x1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a126e
removeitem ITEM_POKEBALL 0x1
goto ow_script_0x8a0ce9


.global ow_script_0x8a126e
ow_script_0x8a126e:
return


.global ow_script_0x89e1fc
ow_script_0x89e1fc:
setvar 0x8000 0x1
setvar 0x8001 0x9
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x89db71
ow_script_0x89db71:
setvar 0x8000 0x1
setvar 0x8001 0x8
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8aabe4
ow_script_0x8aabe4:
call ow_script_0x89c5ee
buffernumber 0x0 0x50f4
return


.global ow_script_0x8a6dad
ow_script_0x8a6dad:
setvar 0x8004 0x4
special 0x10
setwildbattle POKEMON_GLUMANDA 0x5 ITEM_NONE
return


.global ow_script_0x8a6d9d
ow_script_0x8a6d9d:
setvar 0x8004 0x1
special 0x10
setwildbattle POKEMON_BISASAM 0x5 ITEM_NONE
return


.global ow_script_0x8a62d0
ow_script_0x8a62d0:
setvar 0x8004 0x7
special 0x10
setwildbattle POKEMON_SCHIGGY 0x5 ITEM_NONE
return


.global ow_script_0x8a607a
ow_script_0x8a607a:
setvar NEXT_POKEMON_SHINY 0x1
return


.global ow_script_0x8a4909
ow_script_0x8a4909:
loadpointer 0x0 str_0x8a4916
setvar NEXT_POKEMON_SHINY 0x1
return


.global ow_script_0x8a2dea
ow_script_0x8a2dea:
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a2dfc
callstd MSG
special 0x7
return


.global ow_script_0x8a2dd8
ow_script_0x8a2dd8:
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a2f28
callstd MSG
special 0x7
return


.global ow_script_0x8a2da3
ow_script_0x8a2da3:
trainerbattlelosable 0x9 0x147 0x0 str_0x8a30ff str_0x8a3129
goto ow_script_0x8a2db7


.global ow_script_0x8a2d8f
ow_script_0x8a2d8f:
trainerbattlelosable 0x9 0x146 0x0 str_0x8a30ff str_0x8a3129
goto ow_script_0x8a2db7


.global ow_script_0x8fb3e3
ow_script_0x8fb3e3:
call ow_script_0x89c5ee
loadpointer 0x0 str_0x922ed1
callstd MSG
special 0x7
goto ow_script_0x8a04ab


.global ow_script_0x8a116d
ow_script_0x8a116d:
special 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a22df
callstd MSG
special 0x7
goto ow_script_0x8a04ab


.global ow_script_movs_0x8a0358
ow_script_movs_0x8a0358:
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_UP
.byte JUMP_IN_PLACE_FACE_RIGHT
.byte JUMP_IN_PLACE_FACE_RIGHT
.byte STOP


.global ow_script_0x8a0496
ow_script_0x8a0496:
applymovement 0x5 ow_script_movs_0x8a0358
waitmovement 0x0
applymovement 0x4 ow_script_movs_0x8a22c8
waitmovement 0x0
return


.global ow_script_0x89e33c
ow_script_0x89e33c:
setvar 0x8000 0x1
setvar 0x8001 0xa
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x893bb5
ow_script_0x893bb5:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
call ow_script_0x95832f
closeonkeypress
clearflag TRANS_DISABLE
return


.global ow_script_0x95832f
ow_script_0x95832f:
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x958377
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x958963
return


.global ow_script_0x958963
ow_script_0x958963:
loadpointer 0x0 str_0x1a83ae
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x958978
return


.global ow_script_0x958978
ow_script_0x958978:
call ow_script_0x1aba65
bufferboxname 0x0 0x4037
special2 0x800d 0x165
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x95899b
loadpointer 0x0 str_0x9589f7
callstd MSG_KEEPOPEN
return


.global ow_script_0x95899b
ow_script_0x95899b:
special2 0x800d 0x18a
bufferboxname 0x2 0x800d
loadpointer 0x0 str_0x9589ae
callstd MSG_KEEPOPEN
return


.global ow_script_0x1aba65
ow_script_0x1aba65:
fadescreen 0x1
special 0x166
waitstate
lock
faceplayer
return


.global ow_script_0x958377
ow_script_0x958377:
loadpointer 0x0 str_0x1a83ae
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x880bba
return


.global ow_script_0x880bba
ow_script_0x880bba:
countpokemon
subvar LASTRESULT 0x1
copyvar 0x8004 LASTRESULT
fadescreen 0x1
special 0x9e
waitstate
return


.global ow_script_0x89e328
ow_script_0x89e328:
setvar 0x8000 0x0
setvar 0x8001 0xa
setvar 0x8002 0xe
special 0x6
return
