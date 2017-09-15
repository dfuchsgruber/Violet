.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a79e8
ow_script_0x8a79e8:
trainerbattlestd 0x0 0xc 0x0 str_0x8a9ca1 str_0x8a95fb
loadpointer 0x0 str_0x8a95fb
callstd MSG_FACE
end
