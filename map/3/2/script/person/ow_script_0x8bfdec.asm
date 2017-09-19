.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8bfdec
ow_script_0x8bfdec:
copyvarifnotzero 0x8000 ITEM_SUPERBALL
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
