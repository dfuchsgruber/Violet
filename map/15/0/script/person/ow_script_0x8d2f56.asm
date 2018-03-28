.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8d2f56
ow_script_0x8d2f56:
copyvarifnotzero 0x8000 ITEM_AMPHAROSNIT
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
