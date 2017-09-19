.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8ed1ad
ow_script_0x8ed1ad:
copyvarifnotzero 0x8000 ITEM_AETHER
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
