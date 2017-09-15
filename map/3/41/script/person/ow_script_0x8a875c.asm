.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a875c
ow_script_0x8a875c:
trainerbattlestd 0x0 0xd 0x0 str_0x8a9ce9 str_0x8a9d56
loadpointer 0x0 str_0x8a9d56
callstd MSG_FACE
end
