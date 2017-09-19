.include "overworld_script.s"

.include "std.s"

.global ow_script_0x810c7d
ow_script_0x810c7d:
copyvarifnotzero 0x8000 ITEM_POKEBALL
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
