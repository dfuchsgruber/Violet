.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"


.global ow_script_movs_0x89568f
ow_script_movs_0x89568f:
.byte STEP_UP
.byte STOP


.global ow_script_0x895259
ow_script_0x895259:
loadpointer 0x0 str_0x89d64f
callstd MSG
applymovement 0xff ow_script_movs_0x89568f
waitmovement 0x0
end
