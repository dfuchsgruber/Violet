.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8df30f
ow_script_0x8df30f:
copyvarifnotzero 0x8000 ITEM_KING_STEIN
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
