.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e903e
ow_script_0x8e903e:
trainerbattlestd 0x0 0x47 0x0 str_0x8f4388 str_0x8f43ce
loadpointer 0x0 str_0x8f43ce
callstd MSG_FACE
end
