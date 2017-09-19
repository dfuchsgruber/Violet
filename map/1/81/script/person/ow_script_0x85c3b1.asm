.include "overworld_script.s"

.include "std.s"

.global ow_script_0x85c3b1
ow_script_0x85c3b1:
trainerbattlestd 0x0 0xa3 0x0 str_0x864425 str_0x86444f
loadpointer 0x0 str_0x86444f
callstd MSG_FACE
end
