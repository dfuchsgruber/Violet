.include "overworld_script.s"

.include "std.s"

.global ow_script_0x92d1b6
ow_script_0x92d1b6:
trainerbattlestd 0x0 0x78 0x0 str_0x93690c str_0x9368a9
loadpointer 0x0 str_0x9368a9
callstd MSG_FACE
end
