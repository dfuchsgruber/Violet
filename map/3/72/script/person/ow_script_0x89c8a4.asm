.include "overworld_script.s"

.include "std.s"

.global ow_script_0x89c8a4
ow_script_0x89c8a4:
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a0824
callstd MSG_FACE
special 0x7
end
