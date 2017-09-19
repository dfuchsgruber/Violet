.include "overworld_script.s"

.include "std.s"

.global ow_script_0x960331
ow_script_0x960331:
copyvarifnotzero 0x8000 ITEM_BELEBER
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
