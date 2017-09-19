.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8645db
ow_script_0x8645db:
trainerbattlestd 0x0 0xac 0x0 str_0x966317 str_0x96638a
loadpointer 0x0 str_0x96638a
callstd MSG_FACE
end
