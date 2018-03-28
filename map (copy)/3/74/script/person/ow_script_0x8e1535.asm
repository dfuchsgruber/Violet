.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e1535
ow_script_0x8e1535:
copyvarifnotzero 0x8000 ITEM_TM28
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
