.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c7ea9
ow_script_0x8c7ea9:
copyvarifnotzero 0x8000 ITEM_SCHOENSCHUPPE
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
