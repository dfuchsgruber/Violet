.include "overworld_script.s"

.include "std.s"

.global ow_script_0x85f5dd
ow_script_0x85f5dd:
copyvarifnotzero 0x8000 ITEM_SUPERTRANK
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
