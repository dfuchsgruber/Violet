.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8df30f
ow_script_0x8df30f:
copyvarifnotzero 0x8000 ITEM_KING_STEIN
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
