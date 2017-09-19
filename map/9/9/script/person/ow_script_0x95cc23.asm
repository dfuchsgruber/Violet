.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95cc23
ow_script_0x95cc23:
checkflag ORINA_CITY_DONNERSTEIN
gotoif EQUAL ow_script_0x95cc66
lock
faceplayer
loadpointer 0x0 str_0x95cd1c
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_DONNERSTEIN
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95cc5b
loadpointer 0x0 str_0x95ccac
callstd MSG
setflag ORINA_CITY_DONNERSTEIN
release
end


.global ow_script_0x95cc5b
ow_script_0x95cc5b:
loadpointer 0x0 str_0x95cc70
callstd MSG
release
end


.global ow_script_0x95cc66
ow_script_0x95cc66:
loadpointer 0x0 str_0x95ccac
callstd MSG_FACE
end
