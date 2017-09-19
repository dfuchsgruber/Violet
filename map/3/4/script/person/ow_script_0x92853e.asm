.include "overworld_script.s"

.include "std.s"

.global ow_script_0x92853e
ow_script_0x92853e:
lock
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x92ee2b
callstd MSG_YES_NO
special 0x7
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x945ea6
call ow_script_0x92f097
loadpointer 0x0 str_0x92ecf0
callstd MSG
special 0x7
setflag KASKADA_BLACKMARKET_RECEIVED_PAROLE
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end


.global ow_script_0x92f097
ow_script_0x92f097:
setvar 0x8000 0x0
setvar 0x8001 0x19
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x945ea6
ow_script_0x945ea6:
call ow_script_0x92f097
loadpointer 0x0 str_0x92edce
callstd MSG_FACE
special 0x7
end
