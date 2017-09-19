.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a122a
ow_script_0x8a122a:
compare TRAINERSCHOOL_DONE 0x0
gotoif EQUAL ow_script_0x8a0ce0
loadpointer 0x0 str_0x8a0c83
callstd MSG_FACE
fadescreen 0x1
fanfare 0x0
special 0x0
waitfanfare
fadescreen 0x0
loadpointer 0x0 str_0x8a0c66
callstd MSG_FACE
end


.global ow_script_0x8a0ce0
ow_script_0x8a0ce0:
loadpointer 0x0 str_0x8a11ed
callstd MSG_FACE
end
