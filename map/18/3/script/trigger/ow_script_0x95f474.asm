.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95f474
ow_script_0x95f474:
lockall
clearflag PKMNMENU
setvar LASTTALKED 0xb
showsprite 0xb
setvar 0x8004 0xb
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x95e7e5
callstd MSG_KEEPOPEN
goto ow_script_0x95e6bd


.global ow_script_0x95e6bd
ow_script_0x95e6bd:
loadpointer 0x0 str_0x95eb33
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95e771
special 0x7
sound 0x15
applymovement 0x800f ow_script_movs_0x8a1cc6
waitmovement 0x0
call ow_script_0x92f097
loadpointer 0x0 str_0x95e710
callstd MSG
special 0x7
setvar 0x8004 0xb
setvar 0x8005 0x1d
setvar 0x8006 0x17
special 0x24
waitmovement 0x0
hidesprite 0x800f
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x95e771
ow_script_0x95e771:
loadpointer 0x0 str_0x95e77f
callstd MSG_KEEPOPEN
goto ow_script_0x95e6bd
