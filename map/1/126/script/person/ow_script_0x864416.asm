.include "overworld_script.s"

.include "std.s"

.global ow_script_0x864416
ow_script_0x864416:
copyvarifnotzero 0x8000 ITEM_HYPERTRANK
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
