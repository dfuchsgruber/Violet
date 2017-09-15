.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f71c3
ow_script_0x8f71c3:
copyvarifnotzero 0x8000 0x6e
copyvarifnotzero 0x8001 0x1
callstd ITEM_FIND
end
