.include "overworld_script.s"

.include "std.s"

.global ow_script_0x938349
ow_script_0x938349:
trainerbattlestd 0x0 0x7e 0x0 str_0x93bb9e str_0x93bbf6
loadpointer 0x0 str_0x93bbf6
callstd MSG_FACE
end
