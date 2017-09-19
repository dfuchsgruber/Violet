.include "overworld_script.s"

.include "std.s"

.global ow_script_0x864756
ow_script_0x864756:
copyvarifnotzero 0x8000 ITEM_MAGMAISIERER
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
