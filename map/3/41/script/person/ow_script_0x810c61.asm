.include "overworld_script.s"

.include "std.s"

.global ow_script_0x810c61
ow_script_0x810c61:
copyvarifnotzero 0x8000 0xe
copyvarifnotzero 0x8001 0x1
callstd ITEM_FIND
end
