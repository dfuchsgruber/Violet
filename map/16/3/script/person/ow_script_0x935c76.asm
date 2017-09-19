.include "overworld_script.s"

.include "std.s"

.global ow_script_0x935c76
ow_script_0x935c76:
trainerbattlestd 0x0 0x7a 0x0 str_0x9376da str_0x93771d
loadpointer 0x0 str_0x93771d
callstd MSG_FACE
end
