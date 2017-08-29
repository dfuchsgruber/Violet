.include "overworld_script.s"

.include "std.s"

.global ow_script_0x867da9
ow_script_0x867da9:
copyvarifnotzero 0x8000 0x62
copyvarifnotzero 0x8001 0x1
callstd ITEM_FIND
end
