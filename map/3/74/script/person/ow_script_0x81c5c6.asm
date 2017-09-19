.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81c5c6
ow_script_0x81c5c6:
trainerbattlestd 0x0 0x3c 0x0 str_0x8774d7 str_0x88adf9
loadpointer 0x0 str_0x88adf9
callstd MSG_FACE
end
