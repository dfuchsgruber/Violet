.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8aa963
ow_script_0x8aa963:
trainerbattlestd 0x0 0x11 0x0 str_0x8ab8e2 str_0x8abf92
loadpointer 0x0 str_0x8abf92
callstd MSG_FACE
end
