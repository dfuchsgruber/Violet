.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95fe5e
ow_script_0x95fe5e:
copyvarifnotzero 0x8000 ITEM_NUGGET
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
