.include "overworld_script.s"

.include "std.s"

.global ow_script_0x89627f
ow_script_0x89627f:
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89d4bd
callstd MSG_FACE
special 0x7
end
