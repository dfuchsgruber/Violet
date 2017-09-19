.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e1d8c
ow_script_0x8e1d8c:
copyvarifnotzero 0x8000 ITEM_LINKKABEL
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
