.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a5564
ow_script_0x8a5564:
lock
faceplayer
checkflag WONDERTRADE
gotoif EQUAL ow_script_0x8a5ccb
call ow_script_0x8a7343
release
end


.global ow_script_0x8a7343
ow_script_0x8a7343:
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8aac71
callstd MSG
special 0x7
fanfare 0x13e
loadpointer 0x0 str_0x8aa801
callstd MSG_KEEPOPEN
closeonkeypress
waitfanfare
setflag WONDERTRADE
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8ab119
callstd MSG_FACE
special 0x7
setvar STORY_PROGRESS 0x10
return


.global ow_script_0x8a5ccb
ow_script_0x8a5ccb:
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8a7951
callstd MSG
special 0x7
release
end
