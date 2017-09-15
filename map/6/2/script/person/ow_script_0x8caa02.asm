.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8caa02
ow_script_0x8caa02:
checkflag FRBADGE_1
gotoif EQUAL ow_script_0x8caa15
loadpointer 0x0 str_0x8caa1f
callstd MSG_FACE
end


.global ow_script_0x8caa15
ow_script_0x8caa15:
loadpointer 0x0 str_0x8cab11
callstd MSG_FACE
end
