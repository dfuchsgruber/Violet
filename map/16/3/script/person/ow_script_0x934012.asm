.include "overworld_script.s"

.include "std.s"

.global ow_script_0x934012
ow_script_0x934012:
trainerbattlestd 0x0 0x79 0x0 str_0x936e16 str_0x936e78
loadpointer 0x0 str_0x936e78
callstd MSG_FACE
end
