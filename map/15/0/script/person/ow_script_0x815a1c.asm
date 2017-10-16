.include "overworld_script.s"

.include "std.s"

.global ow_script_0x815a1c
ow_script_0x815a1c:
copyvarifnotzero 0x8000 ITEM_AETHER
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
