.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81b4e8
ow_script_0x81b4e8:
lock
faceplayer
checkflag FRBADGE_2
gotoif EQUAL ow_script_0x81b507
trainerbattlecont 0x1 0x19f 0x0 str_0x81b548 str_0x81b611 ow_script_0x81b512


.global ow_script_0x81b512
ow_script_0x81b512:
loadpointer 0x0 str_0x81b6b4
callstd MSG
fanfare 0x104
loadpointer 0x0 str_0x81b747
callstd MSG_KEEPOPEN
waitfanfare
loadpointer 0x0 str_0x81b772
callstd MSG
copyvarifnotzero 0x8000 ITEM_TM19
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x81b828
callstd MSG
setflag FRBADGE_2
release
end


.global ow_script_0x81b507
ow_script_0x81b507:
loadpointer 0x0 str_0x81b652
callstd MSG
release
end
