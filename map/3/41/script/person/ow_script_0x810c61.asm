.include "overworld_script.s"

.include "std.s"

.global ow_script_0x810c61
ow_script_0x810c61:
copyvarifnotzero 0x8000 ITEM_GEGENGIFT
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
