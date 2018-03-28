.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x85f5dd
ow_script_0x85f5dd:
copyvarifnotzero 0x8000 ITEM_SUPERTRANK
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
