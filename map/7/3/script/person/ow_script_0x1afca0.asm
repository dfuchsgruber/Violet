.include "overworld_script.s"

.include "std.s"

.global ow_script_0x1afca0
ow_script_0x1afca0:
lock
faceplayer
setvar 0x8004 0x3
setvar 0x8005 0x5
special 0x173
textcolor 0x3
loadpointer 0x0 str_0x1b46c9
callstd MSG_KEEPOPEN
release
end
