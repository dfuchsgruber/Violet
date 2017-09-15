.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8de697
ow_script_0x8de697:
trainerbattlestd 0x0 0x37 0x0 str_0x8e658b str_0x8e65f1
loadpointer 0x0 str_0x8e65f1
callstd MSG_FACE
end
