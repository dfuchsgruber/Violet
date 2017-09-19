.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8623e3
ow_script_0x8623e3:
trainerbattlestd 0x0 0x42 0x0 str_0x8f2a42 str_0x8f2adf
loadpointer 0x0 str_0x8f2adf
callstd MSG_FACE
end
