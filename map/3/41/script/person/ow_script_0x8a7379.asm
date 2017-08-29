.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a7379
ow_script_0x8a7379:
trainerbattlestd 0x0 0xb 0x0 str_0x8a9536 str_0x8a959f
loadpointer 0x0 str_0x8a959f
callstd MSG_FACE
end
