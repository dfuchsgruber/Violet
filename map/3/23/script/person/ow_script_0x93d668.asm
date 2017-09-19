.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93d668
ow_script_0x93d668:
trainerbattlestd 0x0 0x86 0x0 str_0x948c85 str_0x9497f6
loadpointer 0x0 str_0x9497f6
callstd MSG_FACE
end
