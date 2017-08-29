.include "overworld_script.s"

.include "std.s"

.global ow_script_0x810c53
ow_script_0x810c53:
copyvarifnotzero 0x8000 0x56
copyvarifnotzero 0x8001 0x1
callstd ITEM_FIND
end
