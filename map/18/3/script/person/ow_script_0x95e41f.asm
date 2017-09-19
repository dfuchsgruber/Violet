.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95e41f
ow_script_0x95e41f:
trainerbattlestd 0x0 0x95 0x0 str_0x95e437 str_0x95e496
loadpointer 0x0 str_0x95e496
callstd MSG_FACE
end
