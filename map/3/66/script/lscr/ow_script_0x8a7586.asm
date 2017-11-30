.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8a820e
ow_script_movs_0x8a820e:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8a8214
ow_script_movs_0x8a8214:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x80358f
ow_script_movs_0x80358f:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a7f34
ow_script_movs_0x8a7f34:
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8a7f2b
ow_script_movs_0x8a7f2b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8a794f
ow_script_movs_0x8a794f:
.byte SAY_QUESTION
.byte STOP


.global ow_script_movs_0x8a792d
ow_script_movs_0x8a792d:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8a78ed
ow_script_movs_0x8a78ed:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8a7586
ow_script_0x8a7586:
applymovement 0x3 ow_script_movs_0x8a820e
applymovement 0xff ow_script_movs_0x8a8214
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a7f97
callstd MSG
special 0x7
sound 0x15
applymovement 0x2 ow_script_movs_0x80358f
waitmovement 0x0
checksound
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8a7f3d
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8a7f34
waitmovement 0x0
sound 0x7
checksound
applymovement 0x2 ow_script_movs_0x8a7f2b
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a7e8d
callstd MSG
special 0x7
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8a7dbf
callstd MSG
special 0x7
sound 0x15
applymovement 0xff ow_script_movs_0x8a794f
applymovement 0x3 ow_script_movs_0x8a794f
waitmovement 0x0
checksound
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8a7930
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8a792d
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a78f1
callstd MSG
special 0x7
sound 0x15
applymovement 0x2 ow_script_movs_0x8a78ed
waitmovement 0x0
checksound
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8a7830
callstd MSG
special 0x7
call ow_script_0x8a91d4
loadpointer 0x0 str_0x8a77ae
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a7789
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a776a
callstd MSG_FACE
special 0x7
goto ow_script_0x8a934f


.global ow_script_movs_0x8a7761
ow_script_movs_0x8a7761:
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_IN_PLACE_LEFT
.byte STEP_IN_PLACE_LEFT
.byte STOP


.global ow_script_movs_0x8a76e4
ow_script_movs_0x8a76e4:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8a774a
ow_script_movs_0x8a774a:
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x803489
ow_script_movs_0x803489:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8aa36d
ow_script_movs_0x8aa36d:
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STOP


.global ow_script_movs_0x8aa1b5
ow_script_movs_0x8aa1b5:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8aa181
ow_script_movs_0x8aa181:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8a9a49
ow_script_movs_0x8a9a49:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x8a934f
ow_script_0x8a934f:
fanfare 0x13e
loadpointer 0x0 str_0x8aa319
callstd MSG_KEEPOPEN
setflag POKEDEX
closeonkeypress
waitfanfare
applymovement 0x2 ow_script_movs_0x8a7761
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x8a76e4
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a7751
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8a774a
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x803489
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a76ee
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8aabee
callstd MSG
special 0x7
nop
nop
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8aa57d
callstd MSG
special 0x7
call ow_script_0x8a7095
loadpointer 0x0 str_0x8aa381
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8aa36d
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8aa372
callstd MSG
special 0x7
fanfare 0x13e
applymovement 0x2 ow_script_movs_0x8aa36d
loadpointer 0x0 str_0x8aa338
callstd MSG_KEEPOPEN
waitmovement 0x0
waitfanfare
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8aa305
callstd MSG
special 0x7
call ow_script_0x8a7095
loadpointer 0x0 str_0x8aa27f
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8aa22a
callstd MSG
special 0x7
sound 0x15
applymovement 0x2 ow_script_movs_0x8a78ed
waitmovement 0x0
checksound
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8aa1b8
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8aa1b5
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8aa184
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8aa181
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a9f82
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8aa36d
waitmovement 0x0
sound 0x7
checksound
loadpointer 0x0 str_0x8a9c83
callstd MSG
applymovement 0x2 ow_script_movs_0x8aa36d
call ow_script_0x8ab100
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a9a4c
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8a9a49
waitmovement 0x0
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8a99f1
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a9950
callstd MSG_FACE
special 0x7
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 str_0x8a992f
callstd MSG
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x0
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a9640
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a9771
callstd MSG
special 0x7
setvar 0x8000 0xfe
goto ow_script_0x8aac32


.align 4
choice:
    .word str_route_2_lab_choice_0, 0
    .word str_route_2_lab_choice_1, 0

.global ow_script_movs_0x8ab040
ow_script_movs_0x8ab040:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8aafce
ow_script_movs_0x8aafce:
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte LOOK_LEFT
.byte STOP


.global ow_script_0x8aac32
ow_script_0x8aac32:
special2 0x8000 0xc
call ow_script_0x8a7095
loadpointer 0x0 str_0x8ab043
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8ab040
waitmovement 0x0
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8aafd4
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8aafce
waitmovement 0x0
goto ow_script_0x8ad21f


.global ow_script_0x8ad21f
ow_script_0x8ad21f:
setflag ROUTE_2_RIVAL_INSIDE_LAB
setvar STORY_PROGRESS 0xf
end


.global ow_script_0x8a9640
ow_script_0x8a9640:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a965b
callstd MSG
special 0x7
setvar 0x8000 0x2
goto ow_script_0x8aac32


.global ow_script_0x8ab100
ow_script_0x8ab100:
fanfare 0x13e
additem ITEM_POKEBALL 0x5
loadpointer 0x0 str_0x8ad201
callstd MSG_KEEPOPEN
closeonkeypress
waitfanfare
return


.global ow_script_movs_0x8037d2
ow_script_movs_0x8037d2:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x8a91d4
ow_script_0x8a91d4:
applymovement 0x1 ow_script_movs_0x8037d2
waitmovement 0x0
call ow_script_0x8a7095
return
