.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95f864
ow_script_0x95f864:
lockall
faceplayer
loadpointer 0x0 str_0x95fd2c
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x3
loadpointer 0x0 str_0x95fcf3
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95fe6b
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x95fa47
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x95f9d1
callstd MSG_KEEPOPEN
special 0x7
trainerbattlecont 0x1 0x9b 0x0 str_0x95f937 str_0x95f8bc ow_script_0x960424


.global ow_script_0x960424
ow_script_0x960424:
setvar 0x8004 0xffec
special2 0x8004 0xc
loadpointer 0x0 str_0x95f8fc
callstd MSG
sound 0x7
clearflag ASCHHAIN_NUGGET
showsprite 0x2
goto ow_script_0x95fb9a


.global ow_script_0x95fb9a
ow_script_0x95fb9a:
copyvar 0x8004 LASTTALKED
setvar 0x8005 0x12
setvar 0x8006 0x25
special 0x24
waitmovement 0x0
sound 0x9
hidesprite 0x800f
checksound
releaseall
end


.global ow_script_0x95fa47
ow_script_0x95fa47:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x95fa93
callstd MSG_KEEPOPEN
special 0x7
loadpointer 0x0 str_0x95fa65
callstd MSG
goto ow_script_0x95fb9a


.global ow_script_0x95fe6b
ow_script_0x95fe6b:
checkmoney 0x5dc 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95fcc6
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x95fc52
callstd MSG_KEEPOPEN
special 0x7
sound 0x41
loadpointer 0x0 str_0x95fc38
callstd MSG_KEEPOPEN
checksound
setvar 0x8004 0x8
special2 0x8004 0xc
loadpointer 0x0 str_0x95fbb9
callstd MSG
goto ow_script_0x95fb9a


.global ow_script_0x95fcc6
ow_script_0x95fcc6:
loadpointer 0x0 str_0x95fcd2
callstd MSG
releaseall
release
end
