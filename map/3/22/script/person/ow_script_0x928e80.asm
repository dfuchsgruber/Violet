.include "overworld_script.s"

.include "std.s"

.global ow_script_0x928e80
ow_script_0x928e80:
copyvarifnotzero 0x8000 ITEM_ZAUBERWASSER
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
