.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x867da9
ow_script_0x867da9:
copyvarifnotzero 0x8000 ITEM_BLATTSTEIN
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
