.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x938377
ow_script_0x938377:
copyvarifnotzero 0x8000 ITEM_SUPERTRANK
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
