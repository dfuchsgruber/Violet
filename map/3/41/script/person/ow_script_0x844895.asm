.include "overworld_script.s"

.include "std.s"

.global ow_script_0x844895
ow_script_0x844895:
lock
faceplayer
checkflag MERIANA_CITY_EXPLANATION_IN_FRONT_OF_POKESTOP_DOOR
gotoif EQUAL ow_script_0x8448c2
loadpointer 0x0 str_0x8448cd
callstd MSG_FACE
copyvarifnotzero 0x8000 ITEM_FLINKKLAUE
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
setflag MERIANA_CITY_EXPLANATION_IN_FRONT_OF_POKESTOP_DOOR
loadpointer 0x0 str_0x844937
callstd MSG_FACE
release
end


.global ow_script_0x8448c2
ow_script_0x8448c2:
loadpointer 0x0 str_0x844937
callstd MSG_FACE
release
end
