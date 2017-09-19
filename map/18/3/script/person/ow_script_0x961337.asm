.include "overworld_script.s"

.include "std.s"

.global ow_script_0x961337
ow_script_0x961337:
trainerbattlestd 0x0 0x9f 0x0 str_0x962fde str_0x96313e
loadpointer 0x0 str_0x96313e
callstd MSG_FACE
end
