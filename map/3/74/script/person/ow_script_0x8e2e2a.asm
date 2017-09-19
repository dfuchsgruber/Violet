.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e2e2a
ow_script_0x8e2e2a:
trainerbattlestd 0x0 0x38 0x0 str_0x8e6784 str_0x8e67f6
loadpointer 0x0 str_0x8e67f6
callstd MSG_FACE
end
