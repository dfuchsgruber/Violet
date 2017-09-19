.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a5553
ow_script_0x8a5553:
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a679f
callstd MSG_FACE
special 0x7
end
