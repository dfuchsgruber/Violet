.include "overworld_script.s"

.include "std.s"

.global ow_script_0x938360
ow_script_0x938360:
trainerbattlestd 0x0 0x7f 0x0 str_0x93bc2f str_0x93bc87
loadpointer 0x0 str_0x93bc87
callstd MSG_FACE
end
