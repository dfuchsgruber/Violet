.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8cac75
ow_script_0x8cac75:
trainerbattlestd 0x0 0x12 0x0 str_0x8cac8d str_0x8cad12
loadpointer 0x0 str_0x8cad12
callstd MSG_FACE
end
