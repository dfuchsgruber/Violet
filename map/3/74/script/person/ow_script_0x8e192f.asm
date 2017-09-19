.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e192f
ow_script_0x8e192f:
trainerbattlestd 0x0 0x30 0x0 str_0x8e1c76 str_0x8e1cdd
loadpointer 0x0 str_0x8e1cdd
callstd MSG_FACE
end
