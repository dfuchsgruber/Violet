.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f7174
ow_script_0x8f7174:
copyvarifnotzero 0x8000 ITEM_SONDERBONBON
copyvarifnotzero 0x8001 ITEM_FINSTERSTEIN
callstd ITEM_OBTAIN
end
