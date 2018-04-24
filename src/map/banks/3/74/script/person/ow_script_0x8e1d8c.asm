.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8e1d8c
ow_script_0x8e1d8c:
copyvarifnotzero 0x8000 ITEM_LINKKABEL
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
