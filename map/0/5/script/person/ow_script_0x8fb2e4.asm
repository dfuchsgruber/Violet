.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb2e4
ow_script_0x8fb2e4:
copyvarifnotzero 0x8000 ITEM_FLUCHTSEIL
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
