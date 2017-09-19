.include "overworld_script.s"

.include "std.s"

.global ow_script_0x899055
ow_script_0x899055:
call ow_script_0x89db71
loadpointer 0x0 str_0x89f18d
callstd MSG_FACE
special 0x7
end
