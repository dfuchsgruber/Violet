.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95e564
ow_script_0x95e564:
trainerbattlestd 0x0 0x96 0x0 str_0x95e57c str_0x95e5cf
loadpointer 0x0 str_0x95e5cf
callstd MSG_FACE
end
