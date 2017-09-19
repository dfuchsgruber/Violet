.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86c216
ow_script_0x86c216:
trainerbattlestd 0x0 0x69 0x0 str_0x922d48 str_0x926a50
loadpointer 0x0 str_0x926a50
callstd MSG_FACE
end
