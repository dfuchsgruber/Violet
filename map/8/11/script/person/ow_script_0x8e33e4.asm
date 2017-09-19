.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e33e4
ow_script_0x8e33e4:
trainerbattlestd 0x0 0x71 0x0 str_0x931930 str_0x9318e0
loadpointer 0x0 str_0x9318e0
callstd MSG_FACE
end
