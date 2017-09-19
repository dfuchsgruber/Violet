.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a9625
ow_script_0x8a9625:
trainerbattlestd 0x0 0x9 0x0 str_0x8a9d7f str_0x8aaf13
loadpointer 0x0 str_0x8aaf13
callstd MSG_FACE
end
