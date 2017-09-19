.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e2bf7
ow_script_0x8e2bf7:
trainerbattlestd 0x0 0x33 0x0 str_0x8e2c0f str_0x8e2c5c
loadpointer 0x0 str_0x8e2c5c
callstd MSG_FACE
end
