.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8a09c6
ow_script_movs_0x8a09c6:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a09c9
ow_script_movs_0x8a09c9:
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8f6e33
ow_script_0x8f6e33:
lockall
sound 0x15
applymovement 0xff ow_script_movs_0x8a09c6
waitmovement 0x0
loadpointer 0x0 str_0x8a0956
callstd MSG
applymovement 0xff ow_script_movs_0x8a09c9
waitmovement 0x0
end
