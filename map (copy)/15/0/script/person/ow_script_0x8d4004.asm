.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8d4004
ow_script_0x8d4004:
copyvarifnotzero 0x8000 ITEM_SEIDENSCHAL
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
