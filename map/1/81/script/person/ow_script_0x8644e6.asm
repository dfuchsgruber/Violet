.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8644e6
ow_script_0x8644e6:
trainerbattlestd 0x0 0xa7 0x0 str_0x96612f str_0x9661bb
loadpointer 0x0 str_0x9661bb
callstd MSG_FACE
end
