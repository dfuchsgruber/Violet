.include "overworld_script.s"

.include "std.s"

.global ow_script_0x965848
ow_script_0x965848:
lockall
clearflag PKMNMENU
showsprite 0x1
setvar LASTTALKED 0x1
setvar 0x8004 0x1
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x963705
callstd MSG
special 0x7
setvar 0x8004 0x1
setvar 0x8005 0x22
setvar 0x8006 0x19
special 0x24
waitmovement 0x0
hidesprite 0x800f
setflag PKMNMENU
addvar STORY_PROGRESS 0x1
setworldmapflag WM_INFERIOR
releaseall
end
