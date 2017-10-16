.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8ef6e2
ow_script_0x8ef6e2:
copyvarifnotzero 0x8000 ITEM_SUPERBALL
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
