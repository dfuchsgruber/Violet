.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8cee6b
ow_script_0x8cee6b:
setflag TRANS_DISABLE
loadpointer 0x0 str_0x8cb5e0
callstd MSG_FACE
end
