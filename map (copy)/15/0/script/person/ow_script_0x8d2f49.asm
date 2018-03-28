.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8d2f49
ow_script_0x8d2f49:
copyvarifnotzero 0x8000 ITEM_VM05
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
