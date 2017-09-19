.include "overworld_script.s"

.include "std.s"

.global ow_script_mart0x71d78d
ow_script_mart0x71d78d:
.hword ITEM_AMRENABEERE
.hword ITEM_MARONBEERE
.hword ITEM_PIRSIFBEERE
.hword ITEM_FRAGIABEERE
.hword ITEM_WILBIRBEERE
.hword ITEM_SINELBEERE
.hword ITEM_PERSIMBEERE
.hword ITEM_NONE


.global ow_script_0x8e1b6d
ow_script_0x8e1b6d:
loadpointer 0x0 str_0x721f5f
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x71d7cf
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
preparemsg str_0x71d79e
waitmsg
pokemart ow_script_mart0x71d78d
loadpointer 0x0 str_0x71d3f1
callstd MSG_KEEPOPEN
closeonkeypress
clearflag TRANS_DISABLE
end


.global ow_script_0x71d7cf
ow_script_0x71d7cf:
loadpointer 0x0 str_0x721ed1
callstd MSG
end
