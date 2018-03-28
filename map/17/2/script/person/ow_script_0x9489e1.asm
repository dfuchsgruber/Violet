.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x9489e1
ow_script_0x9489e1:
copyvarifnotzero 0x8000 ITEM_HACKATTACK
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
