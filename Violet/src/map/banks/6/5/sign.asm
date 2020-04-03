.include "map_adjacency_types.s"
.include "callstds.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_map_6_5_sign_0

ow_script_mart0x95dfc7:
.hword ITEM_TIMERBALL
.hword ITEM_NONE


ow_script_map_6_5_sign_0:
setflag TRANS_DISABLE
lock
faceplayer
preparemsg str_mart_ask
waitmsg
pokemart3 ow_script_mart0x95dfc7
loadpointer 0x0 str_mart_exit
callstd MSG_KEEPOPEN
clearflag TRANS_DISABLE
release
end