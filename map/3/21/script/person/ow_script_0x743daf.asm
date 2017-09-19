.include "overworld_script.s"

.include "std.s"

.global ow_script_0x743daf
ow_script_0x743daf:
trainerbattlestd 0x0 0x68 0x0 str_0x744635 str_0x7446c2
loadpointer 0x0 str_0x7446c2
callstd MSG_FACE
end
