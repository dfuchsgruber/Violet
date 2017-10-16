.include "overworld_script.s"

.include "std.s"

.global ow_script_0x85bbb7
ow_script_0x85bbb7:
copyvarifnotzero 0x8000 ITEM_BELEBER
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
