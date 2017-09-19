.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e6a52
ow_script_0x8e6a52:
trainerbattlestd 0x0 0x44 0x0 str_0x8f2b8a str_0x8f3993
loadpointer 0x0 str_0x8f3993
callstd MSG_FACE
end
