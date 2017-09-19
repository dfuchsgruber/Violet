.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81afdd
ow_script_0x81afdd:
trainerbattlestd 0x0 0x3f 0x0 str_0x81aff5 str_0x81b06e
loadpointer 0x0 str_0x81b06e
callstd MSG_FACE
end
