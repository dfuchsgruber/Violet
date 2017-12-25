.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8d4a06
ow_script_0x8d4a06:
copyvarifnotzero 0x8000 ITEM_SUPERBALL
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
