.include "overworld_script.s"

.include "std.s"

.global ow_script_0x92d95a
ow_script_0x92d95a:
copyvarifnotzero 0x8000 ITEM_SUPERBALL
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
