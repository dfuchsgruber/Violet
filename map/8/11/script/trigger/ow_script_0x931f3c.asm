.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x9339f0
ow_script_movs_0x9339f0:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x933904
ow_script_movs_0x933904:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x931fc2
ow_script_movs_0x931fc2:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x931fc5
ow_script_movs_0x931fc5:
.byte STEP_UP
.byte STOP


.global ow_script_0x931f3c
ow_script_0x931f3c:
lockall
fadesong MUS_PIRATE
special 0x113
applymovement 0x7f ow_script_movs_0x9339f0
waitmovement 0x0
loadpointer 0x0 str_0x93386b
callstd MSG
loadpointer 0x0 str_0x9337e5
callstd MSG
showsprite 0x1a
pause 0x18
loadpointer 0x0 str_0x933908
callstd MSG
sound 0x15
applymovement 0x18 ow_script_movs_0x933904
applymovement 0x19 ow_script_movs_0x933904
waitmovement 0x0
loadpointer 0x0 str_0x9338d3
callstd MSG
applymovement 0x1a ow_script_movs_0x931fc2
applymovement 0x18 ow_script_movs_0x931fc5
applymovement 0x19 ow_script_movs_0x931fc5
pause 0x38
goto ow_script_0x93395a


.global ow_script_movs_0x933b99
ow_script_movs_0x933b99:
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x9339f6
ow_script_movs_0x9339f6:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_0x93395a
ow_script_0x93395a:
hidesprite 0x18
hidesprite 0x19
hidesprite 0x1a
applymovement 0x2 ow_script_movs_0x933b99
waitmovement 0x0
hidesprite 0x2
applymovement 0x7f ow_script_movs_0x9339f6
waitmovement 0x0
special 0x114
addvar STORY_PROGRESS 0x1
fadesong MUS_BLACK_MARKET
releaseall
end
