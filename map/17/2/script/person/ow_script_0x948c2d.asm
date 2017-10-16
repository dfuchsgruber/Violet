.include "overworld_script.s"

.include "std.s"

.global ow_script_0x948c2d
ow_script_0x948c2d:
copyvarifnotzero 0x8000 ITEM_FUNKELSTEIN
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
