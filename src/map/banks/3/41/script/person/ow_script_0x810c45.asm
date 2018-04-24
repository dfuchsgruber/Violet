.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x810c45
ow_script_0x810c45:
copyvarifnotzero 0x8000 ITEM_TRANK
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
