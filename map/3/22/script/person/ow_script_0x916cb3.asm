.include "overworld_script.s"

.include "std.s"

.global ow_script_0x916cb3
ow_script_0x916cb3:
trainerbattlestd 0x0 0x75 0x0 str_0x935cc0 str_0x935d50
loadpointer 0x0 str_0x935d50
callstd MSG_FACE
end