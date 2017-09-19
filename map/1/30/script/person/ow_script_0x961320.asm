.include "overworld_script.s"

.include "std.s"

.global ow_script_0x961320
ow_script_0x961320:
trainerbattlestd 0x0 0x9e 0x0 str_0x962eb8 str_0x962f39
loadpointer 0x0 str_0x962f39
callstd MSG_FACE
end
