.include "overworld_script.s"

.include "std.s"

.global ow_script_0x80f39f
ow_script_0x80f39f:
trainerbattlestd 0x0 0x14 0x0 str_0x80f3b7 str_0x80f40b
loadpointer 0x0 str_0x80f40b
callstd MSG_FACE
end
