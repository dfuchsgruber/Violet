.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8d2f56
ow_script_0x8d2f56:
copyvarifnotzero 0x8000 ITEM_AMPHAROSNIT
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
