.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95e1b2
ow_script_0x95e1b2:
trainerbattlestd 0x0 0x93 0x0 str_0x95e1ca str_0x95e223
loadpointer 0x0 str_0x95e223
callstd MSG_FACE
end
