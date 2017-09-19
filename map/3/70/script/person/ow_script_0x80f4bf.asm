.include "overworld_script.s"

.include "std.s"

.global ow_script_0x80f4bf
ow_script_0x80f4bf:
trainerbattlestd 0x0 0x7 0x0 str_0x80f4d7 str_0x80f517
loadpointer 0x0 str_0x80f517
callstd MSG_FACE
end
