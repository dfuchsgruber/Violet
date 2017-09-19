.include "overworld_script.s"

.include "std.s"

.global ow_script_0x9270c4
ow_script_0x9270c4:
checkflag ROUTE_2_LINKCABLE
gotoif EQUAL ow_script_0x8aaf95
lock
faceplayer
loadpointer 0x0 str_0x8abe1c
callstd MSG
copyvarifnotzero 0x8000 ITEM_LINKKABEL
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
loadpointer 0x0 str_0x8ab77f
callstd MSG
setflag ROUTE_2_LINKCABLE
release
end


.global ow_script_0x8aaf95
ow_script_0x8aaf95:
loadpointer 0x0 str_0x8ab6bf
callstd MSG_FACE
end
