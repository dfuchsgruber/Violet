.include "overworld_script.s"

.include "std.s"

.global ow_script_0x949f37
ow_script_0x949f37:
trainerbattlestd 0x0 0x8c 0x0 str_0x94db4f str_0x94dba2
loadpointer 0x0 str_0x94dba2
callstd MSG_FACE
end
