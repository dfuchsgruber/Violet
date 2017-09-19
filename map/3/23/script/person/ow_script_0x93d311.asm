.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93d311
ow_script_0x93d311:
trainerbattlestd 0x0 0x85 0x0 str_0x949732 str_0x9497bd
loadpointer 0x0 str_0x9497bd
callstd MSG_FACE
end
