.include "overworld_script.s"

.include "std.s"

.global ow_script_0x72b101
ow_script_0x72b101:
trainerbattlestd 0x0 0x60 0x0 str_0x743970 str_0x8ede0e
loadpointer 0x0 str_0x8ede0e
callstd MSG_FACE
end
