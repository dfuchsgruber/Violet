.include "overworld_script.s"

.include "std.s"

.global ow_script_0x87f8a4
ow_script_0x87f8a4:
checkflag KADKADA_ZAUBERWASSER
gotoif EQUAL ow_script_0x87f3b7
lock
faceplayer
loadpointer 0x0 str_0x87f432
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_ZAUBERWASSER
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
loadpointer 0x0 str_0x87f4bb
callstd MSG
setflag KADKADA_ZAUBERWASSER
release
end


.global ow_script_0x87f3b7
ow_script_0x87f3b7:
loadpointer 0x0 str_0x87f4bb
callstd MSG_FACE
end
