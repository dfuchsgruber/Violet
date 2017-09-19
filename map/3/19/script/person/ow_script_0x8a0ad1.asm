.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a0ad1
ow_script_0x8a0ad1:
trainerbattlestd 0x0 0x6c 0x0 str_0x927db0 str_0x927d4e
loadpointer 0x0 str_0x927d4e
callstd MSG_FACE
end
