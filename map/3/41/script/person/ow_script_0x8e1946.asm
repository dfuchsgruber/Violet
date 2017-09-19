.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e1946
ow_script_0x8e1946:
copyvarifnotzero 0x8000 ITEM_PARA_HEILER
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
