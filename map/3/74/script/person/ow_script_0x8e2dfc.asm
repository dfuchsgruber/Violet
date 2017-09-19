.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e2dfc
ow_script_0x8e2dfc:
trainerbattlestd 0x0 0x34 0x0 str_0x8e30de str_0x8e311d
loadpointer 0x0 str_0x8e311d
callstd MSG_FACE
end
