.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8a7dbc
ow_script_movs_0x8a7dbc:
.byte JUMP_RIGHT
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8a74fc
ow_script_movs_0x8a74fc:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8a74ff
ow_script_movs_0x8a74ff:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8a73a5
ow_script_movs_0x8a73a5:
.byte STEP_RIGHT
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8a73a1
ow_script_movs_0x8a73a1:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a71a2
ow_script_0x8a71a2:
sound 0xa
applymovement 0x2b ow_script_movs_0x8a7dbc
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a752d
callstd MSG
sound 0xa
applymovement 0x2c ow_script_movs_0x8a7dbc
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a7502
callstd MSG
applymovement 0x2b ow_script_movs_0x8a74fc
applymovement 0x2c ow_script_movs_0x8a74ff
waitmovement 0x0
loadpointer 0x0 str_0x8a74d8
callstd MSG
fadescreen 0x1
call ow_script_0x8a91b8
fadescreen 0x0
applymovement 0x52 ow_script_movs_0x8a73a5
applymovement 0xff ow_script_movs_0x8a73a1
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a73a9
callstd MSG
special 0x7
setvar STORY_PROGRESS 0xe
warp 0x3 0x42 0x0 0x0 0x0
end


.global ow_script_0x8a7095
ow_script_0x8a7095:
setvar 0x8000 0x1
setvar 0x8001 0xb
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8a91b8
ow_script_0x8a91b8:
hidesprite 0x2c
hidesprite 0x2b
hidesprite 0x2e
pause 0x60
return
