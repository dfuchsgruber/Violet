.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x92d95a
ow_script_0x92d95a:
copyvarifnotzero 0x8000 ITEM_SUPERBALL
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
