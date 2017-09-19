.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93cb68
ow_script_0x93cb68:
compare KARMA_VALUE 0x7fff
gotoif HIGHER ow_script_0x93d65f
loadpointer 0x0 str_0x93d5fd
callstd MSG_FACE
end


.global ow_script_0x93d65f
ow_script_0x93d65f:
loadpointer 0x0 str_0x948bab
callstd MSG_FACE
end
