.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95ff99
ow_script_0x95ff99:
checkflag ASHBAG_RECEIVED
gotoif EQUAL ow_script_0x95ffc6
lock
faceplayer
loadpointer 0x0 str_0x96149c
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_ASCHETASCHE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x9613d8
callstd MSG
setflag ASHBAG_RECEIVED
release
end


.global ow_script_0x95ffc6
ow_script_0x95ffc6:
loadpointer 0x0 str_0x9613d8
callstd MSG_FACE
end
