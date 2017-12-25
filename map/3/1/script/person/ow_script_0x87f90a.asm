.include "overworld_script.s"

.include "std.s"

.global ow_script_0x87f90a
ow_script_0x87f90a:
lock
faceplayer
checkflag MERIANA_CITY_BLACK_BELT
gotoif EQUAL ow_script_0x8a28fd
loadpointer 0x0 str_0x8a29c0
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_SCHWARZGURT
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
loadpointer 0x0 str_0x8a2922
callstd MSG_KEEPOPEN
closeonkeypress
release
setflag MERIANA_CITY_BLACK_BELT
end


.global ow_script_0x87f3c1
ow_script_0x87f3c1:
lock
faceplayer
loadpointer 0x0 str_0x87f3ce
callstd MSG
release
end


.global ow_script_0x8a28fd
ow_script_0x8a28fd:
loadpointer 0x0 str_0x8a2907
callstd MSG_FACE
end