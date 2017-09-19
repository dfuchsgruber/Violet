.include "overworld_script.s"

.include "std.s"

.global ow_script_0x935dc2
ow_script_0x935dc2:
copyvarifnotzero 0x8000 ITEM_ELIXIER
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
