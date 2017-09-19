.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a89d3
ow_script_0x8a89d3:
trainerbattlestd 0x0 0xf 0x0 str_0x8aaad4 str_0x8aab7f
loadpointer 0x0 str_0x8aab7f
callstd MSG_FACE
end
