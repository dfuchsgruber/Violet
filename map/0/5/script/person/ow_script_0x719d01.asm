.include "overworld_script.s"

.include "std.s"

.global ow_script_0x719d01
ow_script_0x719d01:
trainerbattlestd 0x0 0x4d 0x0 str_0x71a83d str_0x71a860
loadpointer 0x0 str_0x71a860
callstd MSG_FACE
end