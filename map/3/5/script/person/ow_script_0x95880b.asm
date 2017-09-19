.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95880b
ow_script_0x95880b:
trainerbattlestd 0x0 0x8d 0x0 str_0x958823 str_0x9588a4
loadpointer 0x0 str_0x9588a4
callstd MSG_FACE
end
