.include "overworld_script.s"

.include "std.s"

.global ow_script_0x84e9c2
ow_script_0x84e9c2:
checkflag 0x932
callif EQUAL ow_script_0x84ea05
loadpointer 0x0 str_0x84e9d5
callstd MSG_SIGN
end


.global ow_script_0x84ea05
ow_script_0x84ea05:
loadpointer 0x0 str_0x84ea0f
callstd MSG_SIGN
end
