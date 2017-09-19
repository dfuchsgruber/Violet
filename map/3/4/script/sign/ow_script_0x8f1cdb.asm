.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f1cdb
ow_script_0x8f1cdb:
loadpointer 0x0 str_0x8f1d5b
callstd MSG
setvar DYN_MULTICHOICE_ITEM_CNT 0x1
checkflag KASKADA_BLACKMARKET_RECEIVED_PAROLE
callif EQUAL ow_script_0x8f1d54
loadpointer 0x0 str_0x8f1d80
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8f1d32
loadpointer 0x0 str_0x8f1d1f
callstd MSG
warp 0x8 0xb 0x0 0x0 0x0
waitstate
end


.global ow_script_0x8f1d32
ow_script_0x8f1d32:
loadpointer 0x0 str_0x8f1d3c
callstd MSG
end


.global ow_script_0x8f1d54
ow_script_0x8f1d54:
addvar DYN_MULTICHOICE_ITEM_CNT 0x1
return
