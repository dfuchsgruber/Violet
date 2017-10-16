.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f1f2b
ow_script_0x8f1f2b:
copyvarifnotzero 0x8000 ITEM_HYPERBALL
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
