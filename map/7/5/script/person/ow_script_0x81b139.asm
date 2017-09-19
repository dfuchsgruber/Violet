.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81b139
ow_script_0x81b139:
trainerbattlestd 0x0 0x3d 0x0 str_0x81b151 str_0x81b1b1
loadpointer 0x0 str_0x81b1b1
callstd MSG_FACE
end
