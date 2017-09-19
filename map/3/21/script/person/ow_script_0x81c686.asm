.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81c686
ow_script_0x81c686:
copyvarifnotzero 0x8000 ITEM_VM05
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
