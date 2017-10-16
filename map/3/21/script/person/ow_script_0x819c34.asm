.include "overworld_script.s"

.include "std.s"

.global ow_script_0x819c34
ow_script_0x819c34:
copyvarifnotzero 0x8000 ITEM_TM17
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
end
