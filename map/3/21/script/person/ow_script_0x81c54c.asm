.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x81c54c
ow_script_0x81c54c:
copyvarifnotzero 0x8000 ITEM_HYPERHEILER
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
