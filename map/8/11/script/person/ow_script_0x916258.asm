.include "overworld_script.s"

.include "std.s"

.global ow_script_0x916258
ow_script_0x916258:
call ow_script_0x89e33c
loadpointer 0x0 str_0x931d8f
callstd MSG
faceplayer
loadpointer 0x0 str_0x931bb9
callstd MSG_FACE
special 0x7
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end
