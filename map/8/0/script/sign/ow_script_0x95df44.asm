.include "flags.s"
.include "map_connections.s"
.include "items.s"
.include "callstds.s"
.include "map_adjacency_types.s"
.include "overworld_script.s"


.global ow_script_mart0x95df61
ow_script_mart0x95df61:
.hword ITEM_NETZBALL
.hword ITEM_NONE


.global ow_script_0x95df44
ow_script_0x95df44:
setflag TRANS_DISABLE
lock
faceplayer
preparemsg str_0x1a908b
waitmsg
pokemart3 ow_script_mart0x95df61
loadpointer 0x0 str_0x1a7e77
callstd MSG_KEEPOPEN
clearflag TRANS_DISABLE
release
end
