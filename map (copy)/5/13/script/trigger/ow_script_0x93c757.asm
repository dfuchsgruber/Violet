.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x93cb65
ow_script_movs_0x93cb65:
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x93c757
ow_script_0x93c757:
applymovement 0xff ow_script_movs_0x93cb65
waitmovement 0x0
goto ow_script_0x93ca75
