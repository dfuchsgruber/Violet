.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81a631
ow_script_0x81a631:
lockall
goto ow_script_0x8a5ca9


.global ow_script_movs_0x8a5fc7
ow_script_movs_0x8a5fc7:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x8ab113
ow_script_movs_0x8ab113:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8a5ca9
ow_script_0x8a5ca9:
applymovement 0x2 ow_script_movs_0x8a5fc7
waitmovement 0x0
singlemovement 0xff 0x1
waitmovement 0x0
call ow_script_0x8a7343
applymovement 0x2 ow_script_movs_0x8ab113
waitmovement 0x0
end
