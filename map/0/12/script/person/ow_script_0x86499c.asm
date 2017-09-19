.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86499c
ow_script_0x86499c:
trainerbattlestd 0x0 0xaf 0x0 str_0x96646f str_0x9664e4
loadpointer 0x0 str_0x9664e4
callstd MSG_FACE
end
