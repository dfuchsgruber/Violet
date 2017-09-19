.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81b238
ow_script_0x81b238:
trainerbattlestd 0x0 0x3a 0x0 str_0x81b250 str_0x81b289
loadpointer 0x0 str_0x81b289
callstd MSG_FACE
end
