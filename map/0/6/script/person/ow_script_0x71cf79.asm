.include "overworld_script.s"

.include "std.s"

.global ow_script_0x71cf79
ow_script_0x71cf79:
trainerbattlestd 0x0 0x52 0x0 str_0x7287d7 str_0x72880b
loadpointer 0x0 str_0x72880b
callstd MSG_FACE
end
