.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x88ae6a
ow_script_0x88ae6a:
copyvarifnotzero 0x8000 ITEM_GEGENGIFT
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
