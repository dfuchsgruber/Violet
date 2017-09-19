.include "overworld_script.s"

.include "std.s"

.global ow_script_0x915104
ow_script_0x915104:
trainerbattlestd 0x0 0x6f 0x0 str_0x92ddd7 str_0x92de26
loadpointer 0x0 str_0x92de26
callstd MSG_FACE
end
