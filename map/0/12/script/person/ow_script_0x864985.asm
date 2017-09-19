.include "overworld_script.s"

.include "std.s"

.global ow_script_0x864985
ow_script_0x864985:
trainerbattlestd 0x0 0xae 0x0 str_0x86584d str_0x8658b7
loadpointer 0x0 str_0x8658b7
callstd MSG_FACE
end
