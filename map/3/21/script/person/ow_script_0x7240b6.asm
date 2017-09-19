.include "overworld_script.s"

.include "std.s"

.global ow_script_0x7240b6
ow_script_0x7240b6:
trainerbattlestd 0x0 0x61 0x0 str_0x8ede71 str_0x8edee6
loadpointer 0x0 str_0x8edee6
callstd MSG_FACE
end
