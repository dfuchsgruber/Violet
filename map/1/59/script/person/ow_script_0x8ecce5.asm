.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8ecce5
ow_script_0x8ecce5:
trainerbattlestd 0x0 0x6d 0x0 str_0x928049 str_0x9280cb
loadpointer 0x0 str_0x9280cb
callstd MSG_FACE
end
