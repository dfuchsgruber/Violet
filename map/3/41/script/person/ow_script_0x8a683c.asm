.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a683c
ow_script_0x8a683c:
trainerbattlestd 0x0 0xa 0x0 str_0x8a8910 str_0x8a896a
loadpointer 0x0 str_0x8a896a
callstd MSG_FACE
end
