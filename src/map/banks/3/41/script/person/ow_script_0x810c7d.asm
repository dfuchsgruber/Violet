.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x810c7d
ow_script_0x810c7d:
copyvarifnotzero 0x8000 ITEM_POKEBALL
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
