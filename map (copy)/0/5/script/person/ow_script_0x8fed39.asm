.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fed39
ow_script_0x8fed39:
copyvarifnotzero 0x8000 ITEM_HYPERTRANK
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
