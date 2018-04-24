.include "items.s"
.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x93d6b3
ow_script_0x93d6b3:
copyvarifnotzero 0x8000 ITEM_SUPERSCHUTZ
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
