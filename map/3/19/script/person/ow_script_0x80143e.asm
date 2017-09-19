.include "overworld_script.s"

.include "std.s"

.global ow_script_0x80143e
ow_script_0x80143e:
copyvarifnotzero 0x8000 ITEM_TRANK
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
