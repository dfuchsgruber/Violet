.include "overworld_script.s"

.include "std.s"

.global ow_script_0x864603
ow_script_0x864603:
trainerbattlestd 0x0 0xa8 0x0 str_0x9661e8 str_0x966268
loadpointer 0x0 str_0x966268
callstd MSG_FACE
end
