.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81c2cf
ow_script_0x81c2cf:
trainerbattlestd 0x0 0x3b 0x0 str_0x81c2e7 str_0x81c32b
loadpointer 0x0 str_0x81c32b
callstd MSG_FACE
end
