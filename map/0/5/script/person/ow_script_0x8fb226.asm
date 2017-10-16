.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb226
ow_script_0x8fb226:
copyvarifnotzero 0x8000 ITEM_EVOLITH
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
