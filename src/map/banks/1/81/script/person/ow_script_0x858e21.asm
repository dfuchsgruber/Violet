.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x858e21
ow_script_0x858e21:
copyvarifnotzero 0x8000 ITEM_FEUERHEILER
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
