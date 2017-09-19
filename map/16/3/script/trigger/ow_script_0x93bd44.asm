.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x93be3f
ow_script_movs_0x93be3f:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x93bf7b
ow_script_movs_0x93bf7b:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x93bf53
ow_script_movs_0x93bf53:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x93be44
ow_script_movs_0x93be44:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x93be49
ow_script_movs_0x93be49:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x93bd44
ow_script_0x93bd44:
lockall
special 0x113
applymovement 0x7f ow_script_movs_0x93be3f
waitmovement 0x0
call ow_script_0x8a2791
loadpointer 0x0 str_0x93c76b
callstd MSG
special 0x7
loadpointer 0x0 str_0x93c7d3
callstd MSG
call ow_script_0x8a2791
loadpointer 0x0 str_0x93c80f
callstd MSG
special 0x7
loadpointer 0x0 str_0x93c62b
callstd MSG
call ow_script_0x8a2791
loadpointer 0x0 str_0x93c56c
callstd MSG
special 0x7
loadpointer 0x0 str_0x93c4d7
callstd MSG
call ow_script_0x8a2791
loadpointer 0x0 str_0x93c41a
callstd MSG
special 0x7
loadpointer 0x0 str_0x93c1f6
callstd MSG
call ow_script_0x8a2791
loadpointer 0x0 str_0x93bf80
callstd MSG
special 0x7
applymovement 0x17 ow_script_movs_0x93bf7b
waitmovement 0x0
sound 0x9
checksound
hidesprite 0x17
loadpointer 0x0 str_0x93bf57
callstd MSG
sound 0x15
applymovement 0x16 ow_script_movs_0x93bf53
waitmovement 0x0
loadpointer 0x0 str_0x93bf25
callstd MSG
applymovement 0x7f ow_script_movs_0x93be44
waitmovement 0x0
special 0x114
setvar 0x8004 0x16
special 0x1b
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x93be4c
callstd MSG
setvar 0x8004 0x16
setvar 0x8005 0x18
setvar 0x8006 0x4b
special 0x24
waitmovement 0x0
applymovement 0x16 ow_script_movs_0x93be49
waitmovement 0x0
sound 0x9
hidesprite 0x16
checksound
addvar STORY_PROGRESS 0x1
releaseall
end
