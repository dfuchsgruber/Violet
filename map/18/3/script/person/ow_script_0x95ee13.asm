.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95ee13
ow_script_0x95ee13:
trainerbattlestd 0x0 0x98 0x0 str_0x95f49e str_0x95f53d
loadpointer 0x0 str_0x95f53d
callstd MSG_FACE
end
