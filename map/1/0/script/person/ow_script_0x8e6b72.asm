.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e6b72
ow_script_0x8e6b72:
copyvarifnotzero 0x8000 ITEM_TM09
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
