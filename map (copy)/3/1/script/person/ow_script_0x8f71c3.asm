.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f71c3
ow_script_0x8f71c3:
copyvarifnotzero 0x8000 ITEM_NUGGET
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
