.include "flags.s"
.include "songs.s"
.include "map_connections.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "species.s"
.include "map_adjacency_types.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


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
call ow_script_0x89e33c
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
call ow_script_0x89e33c
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
callasm trainerschool_selection_init
waitstate
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
special 0x16F
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
setflag BLACKOUT_BYPASS
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
compare 0x8006 0xFF
callif EQUAL ow_script_0x8a2dd8
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
copyvarifnotzero 0x8001 10
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
setflag CAUGHT_POKEDEX_DISABLE 
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
clearflag CAUGHT_POKEDEX_DISABLE
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
fadesong 0
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
fadesong 0
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
fadesong 0
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
fadesong 0
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



.ifdef LANG_GER
.global str_0x89dc19

str_0x89dc19:
    .string "PLAYER! Na los, komm schon!"
        
        
.global str_0x89db85

str_0x89db85:
    .string "Endlich geht es ans Eingemachte!\nDieser öde Test hatte es in sich,\laber wenn es ums Kämpfen geht, bin\lich euch allen haushoch überlegen!"
        
        
.global str_0x89d956

str_0x89d956:
    .string "Da kommt auch schon Maike.\pSie ist vor einiger Zeit mit ihrem\nBruder Brix nach Theto gekommen.\lDer war wohl eine ziemlich große\lNummer in Hoenn und sie versucht\laus seinem Schatten zu steigen."
        
        
.global str_0x980cd8

str_0x980cd8:
    .string "PLAYER, RIVAL!\pWas haltet ihr denn von den\nGerüchten, die man sich erzählt?\lDer Klassenbeste soll ein\lschillerndes Pokémon von Faun\lbekommen.\pAufregend nicht? Mein Bruder\nhat mir einmal von schillernden\lPokémon erzählt.\pSie sind sehr selten und\nglitzern in einer für die Art\lunübliche Farbe.\pAllerdings mache ich\nmir keine zu großen HoffnungenDOTS"
        
        
.global str_0x89e366

str_0x89e366:
    .string "Und das ist Blaise.\pEr ist ein ziemlicher Miesepeter,\nwenn du mich fragst.\pWenn er einmal etwas sagt, ist\nes eigentlich nie sonderlich nettDOTS"
        
        
.global str_0x89e350

str_0x89e350:
    .string "Diese Schule macht mich krankDOTS"
        
        
.global str_0x89e03c

str_0x89e03c:
    .string "Sein Vater soll ein sehr mächtiger\nTrainer sein und wie wir unter\lFaun gelernt haben.\pWegen ihm ist Blaise überhaupt\nhier, denn ich denke, wenn es nach\lBlaise ginge, hätten wir ihn in\lder Trainerschule nie zu Gesicht\lbekommen."
        
        
.global str_0x89e210

str_0x89e210:
    .string "Ah und zu guter letzt kommt auch\nendlich noch Felix.\pEr ist der Enkel von Faun und man\nsollte glauben, dass er dadurch\lirgendwelche Vorteile genießt,\laber das Gegenteil ist der Fall.\pMit niemandem sonst geht Faun\nso hart ins Gericht!"
        
        
.global str_0x89df52

str_0x89df52:
    .string "Hallo Leute!\pHattet ihr ein gutes Gefühl bei\nder Prüfung?\pIch denke, dass Faun keinen von\nuns wirklich durchfallen lassen\lwürdeDOTS\pBis auf mich vielleicht, wenn\nich es mir so recht überlege!"
        
        
.global str_0x89df1e

str_0x89df1e:
    .string "Na Blaise? Wie immer schlecht\ngelaunt?\pSei doch nicht immer so ein\nSpielverderber.\pWie ist es dir denn in der\nPrüfung ergangen?"
        
        
.global str_0x89de07

str_0x89de07:
    .string "Das kann dir noch gleichgültiger\nsein als mir.\pVom Auswendiglernen ist noch\nniemand ein guter Trainer geworden.\pDiese ganze Trainerschule ist\neine völlig hinfällige Einrichtung.\pFaun will nicht einsehen,\ndass seine glorreichen Tage\lgezählt sind und versucht jetzt mit\laller Mühe einen Beitrag zu leistenDOTS\pWäre mein dummer Vater\nnicht, hätte ich diesem ganzen\lKindergarten hier entgehen können."
        
        
.global str_0x89ee4c

str_0x89ee4c:
    .string "Du hast Recht, RIVAL!\pBlaise ist wirklich unmöglichDOTS"
        
        
.global str_0x89eda2

str_0x89eda2:
    .string "So zusammen! Ich bin soeben mit der\nAuswertung eurer Ergebnisse fertig\lgeworden.\pWir werden nun mit der\npraktischen Prüfung beginnen,\lbitte stellt euch dazu in einer\lReihe auf."
        
        
.global str_0x89ebfb

str_0x89ebfb:
    .string "Nun gut! Die praktische Prüfung\nsetzt sich aus drei Teilen\lzusammen.\pZuerst werdet ihr ein wildes\nPokémon bezwingen, dann eines\leinfangen und zuletzt noch\lgegeneinander in einem\lTrainerkampf antreten."
        
        
.global str_0x89ea85

str_0x89ea85:
    .string "Zuallererst braucht ihr aber noch\nein Pokémon, mit welchem ihr die\lPrüfung und eure Trainerkarriere\lbestreiten wollt.\pEs wird euer Partner sein und\neuch durch schwierige und\lglückliche Zeiten begleiten.\pZuerst würde ich Blaise\nbitten, eines dieser fünf Pokémon\lauszuwählen. Trete bitte vor!"
        
        
.global str_0x89ea1d

str_0x89ea1d:
    .string "Zumindest ein kleiner Ausgleich für\ndiese FarceDOTS"
        
        
.global str_0x89e9d4

str_0x89e9d4:
    .string "Der nächste wärst dann du Felix,\nkomm bitte auch zu mir."
        
        
.global str_0x89e939

str_0x89e939:
    .string "Danke Opi - ähm ich meine natürlich\nHerr Faun!\pMit diesem Pokémon an meiner\nSeite kann mich kein Hindernis\lstoppen!"
        
        
.global str_0x89e90e

str_0x89e90e:
    .string "PLAYER, würdest nun du bitte\nvortreten?"
        
        
.global str_0x89e896

str_0x89e896:
    .string "Es sind noch drei Pokémon übrig\ngeblieben, aber wähle trotzdem mit\lBedacht.\pEines dieser Pokémon wird dein\ntreuer Freund und Parnter werden."
        
        
.global str_0x889b91

str_0x889b91:
    .string "PLAYER hat ein BUFFER_1\nerhalten!"
        
        
.global str_0x89f11e

str_0x89f11e:
    .string "Eine vorzügliche Wahl!\pIch hatte mir schon gedacht, dass\ndu dich für BUFFER_1 entscheiden\lwürdest.\pEs passt wirklich hervorragend\nzu dir."
        
        
.global str_0x89fa22

str_0x89fa22:
    .string "Soweit so gut, als nächsten würde\nich bitte RIVAL bitten."
        
        
.global str_0x89fa5d

str_0x89fa5d:
    .string "Ich bin ja schon so aufgeregt!"
        
        
.global str_0x89f966

str_0x89f966:
    .string "Dieses Pokémon ist genau richtig!\nDamit werde ich ohne Zweifel der\lstärkste Trainer Thetos werden!"
        
        
.global str_0x89f8b8

str_0x89f8b8:
    .string "Und zuletzt noch Maike, für dich\nbleibt noch ein einziges Pokémon\lübrig."
        
        
.global str_0x89f86e

str_0x89f86e:
    .string "Ok, dann nehme ich wohl dieses."
        
        
.global str_0x89f7c9

str_0x89f7c9:
    .string "Da ihr nun alle mit einem Pokémon\nausgestattet seid, beginnen wir\lmit dem ersten Teil der\lpraktischen Prüfung.\pFolgt mir bitte alle zum hohen\nGras."
        
        
.global str_0x89f64c

str_0x89f64c:
    .string "Im hohen Gras lauern wilde Pokémon,\ndie ihr besiegen könnt, um\lErfahrungspunkte zu sammeln und so\leuren eigenen Pokémon zu Stärke zu\lverhelfen.\pRIVAL, warum machst du nicht\nden Anfang?"
        
        
.global str_0x89f603

str_0x89f603:
    .string "Oh super, dann kann ich gleich\nzeigen, was mein Pokémon drauf hat!"
        
        
.global str_0x8a02c9

str_0x8a02c9:
    .string "Woah! Ein Pokémon ist aus dem Gras\ngesprungen!"
        
        
.global str_0x8a0269

str_0x8a0269:
    .string "Ha! Das war ein Kinderspiel!\nAbsolut kein Problem für den\lkünftigen stärksten Trainer der\lWelt!"
        
        
.global str_0x8a01ae

str_0x8a01ae:
    .string "PeinlichDOTS"
        
        
.global str_0x8a001e

str_0x8a001e:
    .string "Blaise! So langsam ist es genug mit\ndeinen herablassenden Sprüchen.\pDein Vater hat dich auch in meine\nObhut gegeben, um dir den nötigen\lRespekt vor Pokémon und Trainern\lbeizubringen.\pDiese Tugenden sind genauso\nwichtig wie gute Fertigkeiten im\lKampf, das muss dir klar sein!"
        
        
.global str_0x89fe98

str_0x89fe98:
    .string "Außerdem wenn du schon so große\nTöne spuckst, warum versuchst du\les nicht erst einmal, Blaise?"
        
        
.global str_0x89fe3d

str_0x89fe3d:
    .string "Wohl eher nicht. Ich habe bereits,\nwas ich brauche, um meinen Vater\lin die Schranken zu weisen.\pDieses Pokémon wird mir zu\ngroßer Macht verhelfen, warum\lsollte ich mir diesen Kindergarten\lalso weiter zumuten?"
        
        
.global str_0x89fd21

str_0x89fd21:
    .string "Jetzt hör mir mal zu, du verzogenes\nBalg!\pIch habe keine Mühen gescheut,\naus euch fähige junge Trainer zu\lmachen, und so willst du es mir\lund deinem Vater danken?"
        
        
.global str_0x89fc50

str_0x89fc50:
    .string "Es ist mir egal, was Sie von mir\nhalten.\pSie selbst sind auch nicht mehr\nals ein Relikt aus vergangen Tagen.\pSie mögen ja einmal ein\ngroßartiger Trainer gewesen sein,\laber in Zukunft werden neue Kräfte\lden Ton angeben.\pIch brauche mich nicht vor\nIhnen zu rechtfertigen, ich werde\lauf eigene Faust meinen Vater\lstürzen und mir diese Welt zu Füßen legen.\pIn diesem Sinne wünsche\nich noch ein angenehmes Leben!"
        
        
.global str_0x89fba5

str_0x89fba5:
    .string "Das ist doch nicht zu fassen!\pWie kann jemand nur derart\nverbissen gegen alles und jeden\lvorgehen?"
        
        
.global str_0x8a039f

str_0x8a039f:
    .string "Argh! Dieser Narr! Er kommt viel zu\nsehr nach seinem VaterDOTS\pDOTS\pLassen wir uns davon aber nicht\nabbringen."
        
        
.global str_0x8a0376

str_0x8a0376:
    .string "Maike, würdest du bitte - ähmDOTS"
        
        
.global str_0x8a035f

str_0x8a035f:
    .string "Oh äh ja, natürlich, natürlich!"
        
        
.global str_0x8a02fb

str_0x8a02fb:
    .string "Puh! Diese wilden Pokémon sind ganz\nschon furchteinflößendDOTS"
        
        
.global str_0x89ff93

str_0x89ff93:
    .string "Unsinn, das hast du gut gemeistert!\pPLAYER, würdest du nun vortreten?"
        
        
.global str_0x89fefb

str_0x89fefb:
    .string "Wenn dich ein Pokémon angreift,\nversuche seine Kraftpunkte auf 0\lzu reduzieren."
        
        
.global str_0x8a10a1

str_0x8a10a1:
    .string "Sehr gut, ausgezeichnet!"
        
        
.global str_0x8a1073

str_0x8a1073:
    .string "Felix, würdest du bitte den\nSchluss machen?"
        
        
.global str_0x8a1036

str_0x8a1036:
    .string "Aber sicher doch, Opi - ähm, ich\nmeine natürlich Herr Faun!"
        
        
.global str_0x8a0ff4

str_0x8a0ff4:
    .string "Ah, mein Pokémon hat mein Vertrauen\nnicht enttäuscht."
        
        
.global str_0x8a0f9b

str_0x8a0f9b:
    .string "Oh ja, das war nicht übel, ganz\npassabel, will ich meinen.\pLass dir aber einen Erfolg nicht\nzu Kopf steigen, hörst du Junge?"
        
        
.global str_0x8a0f25

str_0x8a0f25:
    .string "Opi, muss das denn wirklich sein?"
        
        
.global str_0x8a0ee7

str_0x8a0ee7:
    .string "Hier bin ich für dich immer noch\nHerr Faun!\pUnd jetzt geh zurück in die Reihe!"
        
        
.global str_0x8a0d3d

str_0x8a0d3d:
    .string "Sehr gut! Wie ich sehe, hat es\nkeinem von euch Probleme bereitet,\lein wildes Pokémon zu besiegen.\lNatürlich entspricht das auch\lmeinen Erwartungen an euch.\pIm nächsten Teil werdet ihr\neure Fertigkeiten als Trainer im\lZweikampf unter Beweis stellen.\pSucht euch einen Partner\nund begebt euch zu den Kampffeldern."
        
        
.global str_0x8a3164

str_0x8a3164:
    .string "Jeder von euch wird nun das von ihm\ngewählte Pokémon in den Kampf\lschicken.\pEs kommt beim Kämpfen nicht\nimmer nur auf den Sieg an, sondern\ldarauf, über seine Grenzen\lhinauszuwachsen.\pGebt alles und setzt alles\nVertrauen in euren neuen Partner."
        
        
.global str_0x8a2fdd

str_0x8a2fdd:
    .string "Kannst du es fassen, PLAYER?\pDavon haben wir immer geträumt.\nMit unseren Pokémon gegeneinander\lantreten.\pLass uns den ersten von vielen\nKämpfen bestreiten!"
        
        
.global str_0x8a30ff

str_0x8a30ff:
    .string "Das ist unfair! Ich war noch gar\nnicht bereit!"
        
        
.global str_0x8a3129

str_0x8a3129:
    .string "Ich bin dir immer einen Schritt\nvoraus!"
        
        
.global str_0x8a3e3e

str_0x8a3e3e:
    .string "Verloren? So werde ich doch nie mit\nmeinem Bruder Brix gleichziehen\lkönnenDOTS"
        
        
.global str_0x8a3e79

str_0x8a3e79:
    .string "Mach dir keinen Kopf, ich bin eben\nkein gewöhnlicher Gegner."
        
        
.global str_0x8a3cfd

str_0x8a3cfd:
    .string "Das sah doch alles sehr gut aus,\njeder von euch hat tapfer und\lmutig gekämpft.\pAuf mehr kommt es nicht an. Eine\nNiederlage ist nur ein Schritt auf\ldem Weg zum Sieg.\pBleibt also nur noch eine\nletzte Prüfung.\pIch würde euch wieder zum\nhohen Gras bitten, wo ihr nun\lunter Beweis stellen müsst, dass\lihr fähig seid, ein wildes Pokémon\leinzufangen.\pDerjenige mit den\nbesten Ergebnissen im\ltheoretischen Teil darf sich an\leinem schillernden Pokémon versuchen."
        
        
.global str_0x8a4a2b

str_0x8a4a2b:
    .string "Ah, scheinbar war Blaise der\neinzige von euch, der die volle\lPunktzahl im Test erzielt hat.\pSeine Belohung wird er natürlich\nnicht erhalten.\pBeginnen wir also mit dem\nletzten Teil der Prüfung."
        
        
.global str_0x8a62af

str_0x8a62af:
    .string "PLAYER, kommst du bitte nach vorne?"
        
        
.global str_0x8a61c1

str_0x8a61c1:
    .string "Du erhältst von mir nun 10\nPokébälle, mit denen du versuchen\lsollst, das Pokémon, das dir\lbegegnet, einzufangen.\pViel Glück!"
        
        
.global str_0x8a6151

str_0x8a6151:
    .string "Lass dich nicht entmutigen.\pVersuche es am besten gleich noch\neinmal, ich werde deinen Vorrat an\lPokébällen aufstocken."
        
        
.global str_0x8a6081

str_0x8a6081:
    .string "Ausgezeichnet. Es ist sehr wichtig,\nmehrere Pokémon im Team zu führen,\lum auf die verschiedensten\lHerausforderungen vorbereitet zu\lsein."
        
        
.global str_0x8a7c05

str_0x8a7c05:
    .string "RIVAL, du bist nun an der Reihe!"
        
        
.global str_0x8a7bbf

str_0x8a7bbf:
    .string "Kinderspiel! Ich werde dem Pokémon\nzeigen, wo es lang geht!"
        
        
.global str_0x8a7b8a

str_0x8a7b8a:
    .string "Whoa! Jetzt wird es Zeit für einen\nPokeball!"
        
        
.global str_0x8a7b45

str_0x8a7b45:
    .string "Das war fast zu einfach!\pDieses Pokémon wird sich super in\nmein Team einfügen."
        
        
.global str_0x8a7b26

str_0x8a7b26:
    .string "Das hast du gut gemacht, RIVAL!"
        
        
.global str_0x8a7af9

str_0x8a7af9:
    .string "Oh ok. Ich werde mein Bestes geben.\nIch darf nicht scheiternDOTS"
        
        
.global str_0x8a7ad0

str_0x8a7ad0:
    .string "Na gut! Dann werde ich es\nversuchenDOTS"
        
        
.global str_0x8a7aa5

str_0x8a7aa5:
    .string "Na gut! Jetzt los, Pokeball!"
        
        
.global str_0x8a7a8a

str_0x8a7a8a:
    .string "Hab ich esDOTS geschafft?"
        
        
.global str_0x8a7a63

str_0x8a7a63:
    .string "Ja, das hast du Maike! Gut\ngemacht! "
        
        
.global str_0x8a7a46

str_0x8a7a46:
    .string "Fehlst nur noch du, Felix!"
        
        
.global str_0x8a7a04

str_0x8a7a04:
    .string "Ich werde dich nicht enttäuschen,\nOpi - ähm ich meine Herr Faun!"
        
        
.global str_0x8a8ecd

str_0x8a8ecd:
    .string "Versuche das Pokémon zu schwächen,\nehe du es fängst."
        
        
.global str_0x8a8eb7

str_0x8a8eb7:
    .string "Na gut, los geht\s!"
        
        
.global str_0x8a8e74

str_0x8a8e74:
    .string "Nicht übel, Felix. Stell dich\njetzt bitte wieder zu den anderen."
        
        
.global str_0x8a8df9

str_0x8a8df9:
    .string "Sehr gut! Damit haben wir unsere\nPrüfungen beendet und ich kann nun\ldie Ergebnisse verkünden.\pBeginnen wir mit dir, RIVAL."
        
        
.global str_0x8a8dbf

str_0x8a8dbf:
    .string "Jetzt wird es spannend!\nIch kann es kaum noch ertragen!"
        
        
.global str_0x8a8c94

str_0x8a8c94:
    .string "Die theoretischen Prüfungen hast du\nmit 6 richtigen Antworten\lbestanden.\pIm Kampftest hast du dich\naußerordentlich gut geschlagen.\pUnd auch der Feldtest hat dir\nkeine Probleme bereitet.\pDa würde ich doch meinen,\ndass du dich mit Stolz einen\lechten Trainer nennen kannst!"
        
        
.global str_0x8a8c6e

str_0x8a8c6e:
    .string "Herzlichen Glückwunsch, RIVAL."
        
        
.global str_0x8a8c5e

str_0x8a8c5e:
    .string "Toll gemacht!"
        
        
.global str_0x8a8c31

str_0x8a8c31:
    .string "Nun kommen wir zu dir, PLAYER."
        
        
.global str_0x8af042

str_0x8af042:
    .string "Die theoretische Prüfung hast du\nmit BUFFER_1 Antworten absolviert.\pIm Kampftest hast du dich\naußerordentlich gut geschlagen und\lauch den Feldtest mit Bravour\lbestanden.\pAuch du hast die Prüfung\nsomit bestanden, PLAYER!"
        
        
.global str_0x8a8a28

str_0x8a8a28:
    .string "Klasse!"
        
        
.global str_0x8a8a01

str_0x8a8a01:
    .string "Da hast du aber Schwein gehabt,\nwas?"
        
        
.global str_0x8a89ec

str_0x8a89ec:
    .string "Wirklich toll, PLAYER!"
        
        
.global str_0x8abc30

str_0x8abc30:
    .string "Maike! In der theoretischen Prüfung\nhast du mit 7 richtigen Antworten\lbestanden.\pDen Kampf hast du zwar verloren,\naber Talent bewiesen und auch ist\les dir gelungen, ein Pokémon\leinzufangen.\pAuch du kannst dich vollen\nStolzes einen Trainer nennen!"
        
        
.global str_0x8abbec

str_0x8abbec:
    .string "Wahnsinn! Vielleicht habe ich doch\nnoch eine Chance, mit Brix\lgleichzuziehen."
        
        
.global str_0x8abbd6

str_0x8abbd6:
    .string "Gut gemacht, Maike!"
        
        
.global str_0x8abbb5

str_0x8abbb5:
    .string "Meinen herzlichen Glückwunsch!"
        
        
.global str_0x8abb05

str_0x8abb05:
    .string "Und jetzt noch zu dir Felix.\pIm Test hast du 9 richtige\nAntworten geliefert, deinen Kampf\lgewonnen und mühelos ein wildes\lPokémon eingefangen.\pWas soll ich sagen, außer,\ndass ich sehr stolz auf dich bin?\pAuch du hast natürlich bestanden!"
        
        
.global str_0x8abade

str_0x8abade:
    .string "Danke, Opi!"
        
        
.global str_0x8abaa9

str_0x8abaa9:
    .string "Wahnsinn, Felix!\nDu warst wirklich einsame Spitze!"
        
        
.global str_0x8aba75

str_0x8aba75:
    .string "Du wirst sicherlich ein\nstarker Gegner sein!"
        
        
.global str_0x8acfd5

str_0x8acfd5:
    .string "Es ist wirklich ein großartiger\nMoment euch, meine Schützlinge,\lnun aufbrechen zu sehen.\pIhr seid die Zukunft Thetos und\nwenn ich euch einige Tugenden\leines alten Mannes mit auf den Weg\lgeben konnte, erfüllt mich das\ldurch und durch mit Glück.\pIch mag ein strenger Lehrer\nund manchmal etwas ungestüm\lgewesen sein, aber ich hoffe ihr\lwisst, dass ich nur an eurem\lGelingen bemüht war.\pZieht nun hinaus in die Welt!\pLebt euren Traum!"
        
        
.global str_0x8acecc

str_0x8acecc:
    .string "Herr Faun war ein toller Lehrer.\pIhr alle seid so starke Trainer\ngeworden und ich bin immer ein\lNachzügler gewesen.\pMein Bruder hat so viel Talent\nund Charisma, ich muss mich\lwirklich anstrengen, wenn ich ihn\ljemals einholen will.\pIhr werdet mir alle\nschrecklich fehlen, aber von nun\lan müssen wir auf eigenen Beinen stehen.\pBis dann, Leute!"
        
        
.global str_0x8ace11

str_0x8ace11:
    .string "Also PLAYER, Felix!\nEndlich ist es soweit. Wir können\lin die weite Welt aufbrechen! Wir\lsehen uns bald wieder, hoffe ich!\lPokémon fangen sich nicht von\lselbst, also sage ich nur: Bye!"
        
        
.global str_0x8accb0

str_0x8accb0:
    .string "Opi war wirklich klasse!\pDie Schulzeit wird mir fehlen, ihr\nwart alle tolle Freunde.\pAber jetzt haben wir unsere\neigenen Wege vor uns.\pDas ist aber auf keinen Fall\nein Abschied für immer, die Welt\list ja bekanntlich sehr klein.\pWenn wir uns das nächste\nMal begegnen, sind wir alle schon\lein Stück weiter gekommen.\pViel Glück, Leute!"
        
        
.global str_0x8a4916

str_0x8a4916:
    .string "Oh! Scheinbar haben gleich zwei\nLeute mit voller Punktzahl\labgeschnitten.\pZum einen Blaise und zum anderen\nPLAYER. Da Blaise sich aber für zu\lgut erachtet, uns mit seiner\lAnwesenheit zu beehren, darf nun\lPLAYER sich daran probieren, ein\lschillerndes Pokémon einzufangen."
        
        
.global str_0x8a2dfc

str_0x8a2dfc:
    .string "PLAYER, du hast geschummelt!\pDu hast das stärkere Pokémon\ngewählt, das ist unfair!\pIch will noch einmal!"
        
        
.global str_0x8a2f28

str_0x8a2f28:
    .string "PLAYER! Ich wusste, dass ich\ngewinne!\pDu hast keine Chance, es ist nur\nnatürlich gegen den künftigen\lstärksten Trainer Thetos zu verlieren!"
        
        
.global str_0x922ed1

str_0x922ed1:
    .string "Versuche das wilde Pokémon mit\nAngriffen zu bekämpfen!"
        
        
.global str_0x8a22df

str_0x8a22df:
    .string "Das war wohl nichts. Versuche es\ngleich noch einmal. Und achte\ldarauf, die Kraftpunkte deines\lGegners auf 0 zu reduzieren."
        
        
.global str_0x1a83ae

str_0x1a83ae:
    .string "Möchtest du BUFFER_1 einen\nSpitznamen geben?"
        
        
.global str_0x9589f7

str_0x9589f7:
    .string "BUFFER_2 wurde an das Lagerungs-\nSystem gesendet.\pEs wurde in Box\nQUOTE_STARTBUFFER_1QUOTE_END abgelegt."
        
        
.global str_0x9589ae

str_0x9589ae:
    .string "Box QUOTE_STARTBUFFER_3QUOTE_END im\nLagerungssystem ist voll.\pBUFFER_2 wurde in Box\nQUOTE_STARTBUFFER_1QUOTE_END übertragen."
        
        
.elseif LANG_EN

.endif
