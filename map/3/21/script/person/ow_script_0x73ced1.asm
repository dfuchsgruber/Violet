.include "overworld_script.s"

.include "std.s"

.global ow_script_0x73ced1
ow_script_0x73ced1:
trainerbattlestd 0x0 0x1c7 0x0 str_0x743d3a str_0x743d7f
loadpointer 0x0 str_0x743d7f
callstd MSG_FACE
end
