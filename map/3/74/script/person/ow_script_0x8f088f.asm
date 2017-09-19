.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f088f
ow_script_0x8f088f:
checkflag SILVANIA_FOREST_RIN
gotoif EQUAL ow_script_0x8f4675
loadpointer 0x0 str_0x8f461a
callstd MSG_FACE
end


.global ow_script_0x8f4675
ow_script_0x8f4675:
loadpointer 0x0 str_0x8f4d9d
callstd MSG_FACE
end
