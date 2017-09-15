.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a89ae
ow_script_0x8a89ae:
trainerbattlestd 0x0 0xe 0x0 str_0x8aa83e str_0x8aa8fb
loadpointer 0x0 str_0x8aa8fb
callstd MSG_FACE
end
