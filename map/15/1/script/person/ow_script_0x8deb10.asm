.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8deb10
ow_script_0x8deb10:
copyvarifnotzero 0x8000 ITEM_SONDERBONBON
copyvarifnotzero 0x8001 ITEM_DUBIOSDISK
callstd ITEM_OBTAIN
copyvarifnotzero 0x8000 ITEM_MEISTERBALL
copyvarifnotzero 0x8001 ITEM_DUBIOSDISK
callstd ITEM_OBTAIN
end
