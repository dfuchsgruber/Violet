.include "overworld_script.s"

.include "std.s"

.global ow_script_0x866fd0
ow_script_0x866fd0:
copyvarifnotzero 0x8000 ITEM_HYPERTRANK
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
