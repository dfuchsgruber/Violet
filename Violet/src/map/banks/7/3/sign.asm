.include "map_adjacency_types.s"
.include "callstds.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_map_7_3_sign_0

ow_script_mart0x95dfa5:
.hword ITEM_NESTBALL
.hword ITEM_NONE


ow_script_map_7_3_sign_0:
setflag TRANS_DISABLE
lock
faceplayer
preparemsg str_mart_ask
waitmsg
pokemart3 ow_script_mart0x95dfa5
loadpointer 0x0 str_mart_exit
callstd MSG_KEEPOPEN
clearflag TRANS_DISABLE
release
end