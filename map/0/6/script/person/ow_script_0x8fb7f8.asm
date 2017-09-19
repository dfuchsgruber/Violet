.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb7f8
ow_script_0x8fb7f8:
trainerbattlestd 0x0 0x55 0x0 str_0x8feb10 str_0x8feb72
loadpointer 0x0 str_0x8feb72
callstd MSG_FACE
end
