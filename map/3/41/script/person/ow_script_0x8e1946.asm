.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e1946
ow_script_0x8e1946:
copyvarifnotzero 0x8000 0x12
copyvarifnotzero 0x8001 0x1
callstd ITEM_FIND
end
