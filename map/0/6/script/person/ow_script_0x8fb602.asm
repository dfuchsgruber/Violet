.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb602
ow_script_0x8fb602:
checkflag FELSIGE_ODNIS_TM_STEEL_WING
gotoif EQUAL ow_script_0x8fb752
lock
faceplayer
loadpointer 0x0 str_0x8fb630
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_TM47
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x8fb6cf
callstd MSG_KEEPOPEN
closeonkeypress
setflag FELSIGE_ODNIS_TM_STEEL_WING
release
end


.global ow_script_0x8fb752
ow_script_0x8fb752:
loadpointer 0x0 str_0x8fb75c
callstd MSG_FACE
end
