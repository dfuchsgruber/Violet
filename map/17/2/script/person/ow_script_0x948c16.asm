.include "overworld_script.s"

.include "std.s"

.global ow_script_0x948c16
ow_script_0x948c16:
trainerbattlestd 0x0 0x89 0x0 str_0x94bffc str_0x94c063
loadpointer 0x0 str_0x94c063
callstd MSG_FACE
end
