.include "overworld_script.s"

.include "std.s"

.global ow_script_0x935c8d
ow_script_0x935c8d:
trainerbattlestd 0x0 0x7b 0x0 str_0x937767 str_0x9377c1
loadpointer 0x0 str_0x9377c1
callstd MSG_FACE
end
