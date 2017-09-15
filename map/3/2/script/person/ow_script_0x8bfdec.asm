.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8bfdec
ow_script_0x8bfdec:
copyvarifnotzero 0x8000 0x3
copyvarifnotzero 0x8001 0x1
callstd ITEM_FIND
end
