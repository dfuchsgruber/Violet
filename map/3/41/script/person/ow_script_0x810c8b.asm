.include "overworld_script.s"

.include "std.s"

.global ow_script_0x810c8b
ow_script_0x810c8b:
copyvarifnotzero 0x8000 ITEM_BELEBER
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
