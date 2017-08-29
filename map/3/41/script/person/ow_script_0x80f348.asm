.include "overworld_script.s"

.include "std.s"

.global ow_script_0x80f348
ow_script_0x80f348:
trainerbattlestd 0x0 0x13 0x0 str_0x80f360 str_0x80f391
loadpointer 0x0 str_0x80f391
callstd MSG_FACE
end
