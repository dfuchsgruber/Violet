.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86d36a
ow_script_0x86d36a:
trainerbattlestd 0x0 0xad 0x0 str_0x86d382 str_0x86d3cd
loadpointer 0x0 str_0x86d3cd
callstd MSG_FACE
end
