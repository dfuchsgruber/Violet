.include "overworld_script.s"

.include "std.s"

.global ow_script_0x958a81
ow_script_0x958a81:
trainerbattlestd 0x0 0x8e 0x0 str_0x959139 str_0x959100
loadpointer 0x0 str_0x959100
callstd MSG_FACE
end
