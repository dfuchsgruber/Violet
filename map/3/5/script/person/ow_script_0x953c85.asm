.include "overworld_script.s"

.include "std.s"

.global ow_script_0x953c85
ow_script_0x953c85:
checkflag ORINA_CITY_TM_MATSCHBOMBE
gotoif EQUAL ow_script_0x953cb2
lock
faceplayer
loadpointer 0x0 str_0x9552a7
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_TM36
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x955217
callstd MSG
setflag ORINA_CITY_TM_MATSCHBOMBE
release
end


.global ow_script_0x953cb2
ow_script_0x953cb2:
loadpointer 0x0 str_0x9551cc
callstd MSG_FACE
end
