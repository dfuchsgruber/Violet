.include "overworld_script.s"

.include "std.s"

.global ow_script_0x948ce3
ow_script_0x948ce3:
trainerbattlestd 0x0 0x8a 0x0 str_0x94c11f str_0x94c18b
loadpointer 0x0 str_0x94c18b
callstd MSG_FACE
end
