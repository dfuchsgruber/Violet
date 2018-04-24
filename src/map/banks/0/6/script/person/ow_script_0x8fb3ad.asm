.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8fb3ad
ow_script_0x8fb3ad:
copyvarifnotzero 0x8000 ITEM_ELIXIER
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
