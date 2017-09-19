.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86d25e
ow_script_0x86d25e:
trainerbattlestd 0x0 0xab 0x0 str_0x86d276 str_0x86d2a0
loadpointer 0x0 str_0x86d2a0
callstd MSG_FACE
end
