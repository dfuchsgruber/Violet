.include "overworld_script.s"

.include "std.s"

.global ow_script_0x88ae6a
ow_script_0x88ae6a:
copyvarifnotzero 0x8000 ITEM_GEGENGIFT
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
