.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x95db3c
ow_script_movs_0x95db3c:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x95dad0
ow_script_0x95dad0:
lockall
sound 0x9
clearflag PKMNMENU
showsprite 0x1
pause 0x20
setvar 0x8004 0x1
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x89e33c
loadpointer 0x0 str_0x95dbb7
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x95dd1d
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x95db3f
callstd MSG
special 0x7
setvar 0x8004 0x1
setvar 0x8005 0x13
setvar 0x8006 0x10
special 0x24
waitmovement 0x0
applymovement 0x1 ow_script_movs_0x95db3c
waitmovement 0x0
pause 0x10
hidesprite 0x1
sound 0x9
pause 0x10
addvar STORY_PROGRESS 0x1
releaseall
end
