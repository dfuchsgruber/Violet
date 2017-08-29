.include "overworld_script.s"

.include "std.s"

.global ow_script_0x810c45
ow_script_0x810c45:
copyvarifnotzero 0x8000 0xd
copyvarifnotzero 0x8001 0x1
callstd ITEM_FIND
end
