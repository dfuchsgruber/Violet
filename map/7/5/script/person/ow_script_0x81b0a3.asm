.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81b0a3
ow_script_0x81b0a3:
trainerbattlestd 0x0 0x3e 0x0 str_0x81b0bb str_0x81b0f6
loadpointer 0x0 str_0x81b0f6
callstd MSG_FACE
end
