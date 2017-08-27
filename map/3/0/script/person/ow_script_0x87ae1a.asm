.include "overworld_script.s"

.include "std.s"

.global ow_script_0x87ae1a
ow_script_0x87ae1a:
copyvarifnotzero 0x8000 0x161
copyvarifnotzero 0x8001 0x1
callstd ITEM_OBTAIN
end
