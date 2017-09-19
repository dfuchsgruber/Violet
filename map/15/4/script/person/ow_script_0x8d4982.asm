.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8d4982
ow_script_0x8d4982:
trainerbattlestd 0x0 0x25 0x0 str_0x8d499a str_0x8d49d0
loadpointer 0x0 str_0x8d49d0
callstd MSG_FACE
end
