.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x89c605
ow_script_movs_0x89c605:
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x89c614
ow_script_movs_0x89c614:
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x89c602
ow_script_movs_0x89c602:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x89c5da
ow_script_movs_0x89c5da:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x89c5e4
ow_script_movs_0x89c5e4:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x89c3c1
ow_script_movs_0x89c3c1:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89c563
ow_script_movs_0x89c563:
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x89c3c4
ow_script_movs_0x89c3c4:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x89c3b8
ow_script_movs_0x89c3b8:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89c3b4
ow_script_movs_0x89c3b4:
.byte STEP_LEFT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89c3ad
ow_script_movs_0x89c3ad:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89c3a9
ow_script_movs_0x89c3a9:
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89c3a2
ow_script_movs_0x89c3a2:
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x89c399
ow_script_movs_0x89c399:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte FACE_DOWN
.byte STOP


.global ow_script_0x89c150
ow_script_0x89c150:

call ow_script_0x89ba6e
loadpointer 0x0 str_0x89c626
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x89c605
applymovement 0xff ow_script_movs_0x89c614
waitmovement 0x0
pause 0x18
applymovement 0x9 ow_script_movs_0x89c602
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89c567
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x89c5da
applymovement 0x1 ow_script_movs_0x89c5e4
waitmovement 0x0
applymovement 0x9 ow_script_movs_0x89c3c1
waitmovement 0x0
special 0x113
fadesong MUS_0
applymovement 0x7f ow_script_movs_0x89c563
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89c3c8
callstd MSG
special 0x7
applymovement 0x7f ow_script_movs_0x89c3c4
waitmovement 0x0
special 0x114
applymovement 0x9 ow_script_movs_0x89c3b8
waitmovement 0x0
sound 0x17
setmaptile 0x3 0x21 0x2c6 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3b4
waitmovement 0x0
sound 0x17
setmaptile 0x2 0x21 0x2c5 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3ad
waitmovement 0x0
sound 0x17
setmaptile 0x6 0x21 0x2c5 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3a9
waitmovement 0x0
sound 0x17
setmaptile 0x7 0x21 0x2c6 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3a2
waitmovement 0x0
sound 0x17
setmaptile 0x7 0x23 0x2c6 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c399
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89c29e
callstd MSG
special 0x7
goto ow_script_0x898639


.global ow_script_0x898639
ow_script_0x898639:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
playsong MUS_JEROPARDY 0x0
setvar 0x8000 0x0
goto ow_script_0x89c871


.global ow_script_0x89c871
ow_script_0x89c871:

setvar STORY_PROGRESS 0x6
callasm trainerschool_test_init
waitstate

clearflag TRANS_DISABLE
fadescreen 0x0
goto ow_script_0x89d3db


.global ow_script_movs_0x89d4b7
ow_script_movs_0x89d4b7:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x89d4ba
ow_script_movs_0x89d4ba:
.byte LOOK_LEFT
.byte STOP


.global ow_script_0x89d3db
ow_script_0x89d3db:
fadesong MUS_TRAINERSCHOOL
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89d5d3
callstd MSG
special 0x7
applymovement 0x9 ow_script_movs_0x89c3b8
waitmovement 0x0
sound 0x17
setmaptile 0x3 0x21 0x2b9 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3b4
waitmovement 0x0
sound 0x17
setmaptile 0x2 0x21 0x2b8 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3ad
waitmovement 0x0
sound 0x17
setmaptile 0x6 0x21 0x2b8 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3a9
waitmovement 0x0
sound 0x17
setmaptile 0x7 0x21 0x2b9 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3a2
waitmovement 0x0
sound 0x17
setmaptile 0x7 0x23 0x2b9 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c399
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89d54d
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x89d4b7
applymovement 0x1 ow_script_movs_0x89d4ba
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89d4bd
callstd MSG
special 0x7
goto ow_script_0x8a4b76


.global ow_script_0x8a4b76
ow_script_0x8a4b76:
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
end


.global ow_script_0x89d3d1
ow_script_0x89d3d1:
addvar 0x8000 0x1
return
