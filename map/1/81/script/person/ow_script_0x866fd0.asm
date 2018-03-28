.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x866fd0
ow_script_0x866fd0:
copyvarifnotzero 0x8000 ITEM_HYPERTRANK
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
