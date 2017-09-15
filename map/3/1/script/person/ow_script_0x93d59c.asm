.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93d59c
ow_script_0x93d59c:
lock
faceplayer
call ow_script_0x8a7f80
loadpointer 0x0 str_0x949632
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x949573
setvar BATTLE_SONG_OVERRIDE 0x165
trainerbattlecont 0x1 0x84 0x0 str_0x94948c str_0x949515 ow_script_0x93d5e1


.global ow_script_0x93d5e1
ow_script_0x93d5e1:
call ow_script_0x8a7f80
loadpointer 0x0 str_0x94918c
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x800f
setflag 0x934
fadescreen 0x0
release
end


.global ow_script_0x8a7f80
ow_script_0x8a7f80:
setvar 0x8000 0x1
setvar 0x8001 0xf
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x949573
ow_script_0x949573:
loadpointer 0x0 str_0x949581
callstd MSG
special 0x7
release
end
