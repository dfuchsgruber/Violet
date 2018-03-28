.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x810c8b
ow_script_0x810c8b:
copyvarifnotzero 0x8000 ITEM_BELEBER
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
