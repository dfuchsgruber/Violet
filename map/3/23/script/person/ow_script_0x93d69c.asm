.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93d69c
ow_script_0x93d69c:
trainerbattlestd 0x0 0x88 0x0 str_0x949b31 str_0x949b9d
loadpointer 0x0 str_0x949b9d
callstd MSG_FACE
end
