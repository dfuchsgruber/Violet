.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8e6b72
ow_script_0x8e6b72:
copyvarifnotzero 0x8000 ITEM_TM09
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
