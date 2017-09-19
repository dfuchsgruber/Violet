.include "overworld_script.s"

.include "std.s"

.global ow_script_0x864763
ow_script_0x864763:
trainerbattlestd 0x0 0xad 0x0 str_0x8657cf str_0x86582b
loadpointer 0x0 str_0x86582b
callstd MSG_FACE
end
