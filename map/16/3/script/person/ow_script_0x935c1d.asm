.include "overworld_script.s"

.include "std.s"

.global ow_script_0x935c1d
ow_script_0x935c1d:
copyvarifnotzero 0x8000 ITEM_SUPERTRANK
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
