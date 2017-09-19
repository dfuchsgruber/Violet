.include "overworld_script.s"

.include "std.s"

.global ow_script_0x9591b3
ow_script_0x9591b3:
trainerbattlestd 0x0 0x8f 0x0 str_0x959205 str_0x9591cb
loadpointer 0x0 str_0x9591cb
callstd MSG_FACE
end
