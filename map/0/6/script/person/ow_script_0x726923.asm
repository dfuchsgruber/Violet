.include "overworld_script.s"

.include "std.s"

.global ow_script_0x726923
ow_script_0x726923:
trainerbattlestd 0x0 0x56 0x0 str_0x8fb7a5 str_0x8fb810
loadpointer 0x0 str_0x8fb810
callstd MSG_FACE
end
