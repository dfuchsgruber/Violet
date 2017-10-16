.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb3ad
ow_script_0x8fb3ad:
copyvarifnotzero 0x8000 ITEM_ELIXIER
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
