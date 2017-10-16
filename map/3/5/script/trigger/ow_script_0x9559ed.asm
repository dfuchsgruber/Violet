.include "overworld_script.s"

.include "std.s"

.global ow_script_0x9559ed
ow_script_0x9559ed:
lockall
clearflag PKMNMENU
showsprite 0x27
setvar 0x8004 0x27
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x8a7f80
loadpointer 0x0 str_0x955b31
callstd MSG_KEEPOPEN
special 0x7
copyvarifnotzero 0x8000 ITEM_EICHS_PAKET
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
call ow_script_0x8a7f80
loadpointer 0x0 str_0x955a4c
callstd MSG
special 0x7
setvar 0x8004 0x27
setvar 0x8005 0x3c
setvar 0x8006 0x1f
special 0x24
waitmovement 0x0
hidesprite 0x27
addvar STORY_PROGRESS 0x1
releaseall
end
