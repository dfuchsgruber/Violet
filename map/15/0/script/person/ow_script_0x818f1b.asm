.include "overworld_script.s"

.include "std.s"

.global ow_script_0x818f1b
ow_script_0x818f1b:
trainerbattlestd 0x0 0x1e 0x0 str_0x818f6a str_0x818f33
loadpointer 0x0 str_0x818f33
callstd MSG_FACE
end
