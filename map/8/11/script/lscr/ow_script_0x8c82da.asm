.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8c8300
ow_script_movs_0x8c8300:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8c82da
ow_script_0x8c82da:
lockall
pause 0x28
call ow_script_0x92f097
loadpointer 0x0 str_0x8c80e4
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8c8300
waitmovement 0x0
hidesprite 0x2
addvar STORY_PROGRESS 0x1
set_intern_bank 0x10 0x10
loadbytefrompointer 0x12 0x10121012
set_intern_bank 0xfe 0x6b
end
