.include "overworld_script.s"

.include "std.s"

.global ow_script_0x810c53
ow_script_0x810c53:
copyvarifnotzero 0x8000 ITEM_SCHUTZ
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
