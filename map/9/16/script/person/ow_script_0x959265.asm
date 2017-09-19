.include "overworld_script.s"

.include "std.s"

.global ow_script_0x959265
ow_script_0x959265:
trainerbattlestd 0x0 0x90 0x0 str_0x9592b0 str_0x95927d
loadpointer 0x0 str_0x95927d
callstd MSG_FACE
end
