.include "overworld_script.s"

.include "std.s"

.global ow_script_0x937859
ow_script_0x937859:
checkflag ROUTE_4_HM_FLY
gotoif EQUAL ow_script_0x937886
lock
faceplayer
loadpointer 0x0 str_0x937a0a
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_VM02
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x937917
callstd MSG_KEEPOPEN
closeonkeypress
setflag ROUTE_4_HM_FLY
end


.global ow_script_0x937886
ow_script_0x937886:
loadpointer 0x0 str_0x937890
callstd MSG_FACE
end
