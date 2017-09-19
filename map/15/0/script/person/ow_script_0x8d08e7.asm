.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8d08e7
ow_script_0x8d08e7:
trainerbattlestd 0x0 0x23 0x0 str_0x8d40f1 str_0x8d4147
loadpointer 0x0 str_0x8d4147
callstd MSG_FACE
end
