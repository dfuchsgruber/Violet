.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95ffe5
ow_script_0x95ffe5:
trainerbattlestd 0x0 0x9d 0x0 str_0x962cce str_0x962d24
loadpointer 0x0 str_0x962d24
callstd MSG_FACE
end
