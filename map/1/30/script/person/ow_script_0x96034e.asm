.include "overworld_script.s"

.include "std.s"

.global ow_script_0x96034e
ow_script_0x96034e:
copyvarifnotzero 0x8000 ITEM_FEUERHEILER
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_FIND
end
