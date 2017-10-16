.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95f7c9
ow_script_0x95f7c9:
copyvarifnotzero 0x8000 ITEM_HYPERBALL
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
