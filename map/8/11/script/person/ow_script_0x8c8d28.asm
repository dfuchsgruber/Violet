.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c8d28
ow_script_0x8c8d28:
compare KARMA_VALUE 0x7fff
gotoif EQUAL ow_script_0x8c8d3d
loadpointer 0x0 str_0x92f0aa
callstd MSG_FACE
end


.global ow_script_0x8c8d3d
ow_script_0x8c8d3d:
loadpointer 0x0 str_0x8c8d47
callstd MSG_FACE
end
