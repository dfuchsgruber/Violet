.include "overworld_script.s"

.include "std.s"

.global ow_script_0x938377
ow_script_0x938377:
copyvarifnotzero 0x8000 ITEM_SUPERTRANK
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
