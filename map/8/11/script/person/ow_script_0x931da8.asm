.include "overworld_script.s"

.include "std.s"

.global ow_script_0x931da8
ow_script_0x931da8:
checkflag KASKADA_BLACKMARKET_SCHATTENGLAS
gotoif EQUAL ow_script_0x931ddf
compare KARMA_VALUE 0x7fff
gotoif LESS_OR_EQUAL ow_script_0x931e91
lock
faceplayer
setflag KASKADA_BLACKMARKET_SCHATTENGLAS
loadpointer 0x0 str_0x931e57
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_SCHATTENGLAS
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x931e1e
callstd MSG_FACE
end


.global ow_script_0x931e91
ow_script_0x931e91:
loadpointer 0x0 str_0x931e9b
callstd MSG_FACE
end


.global ow_script_0x931ddf
ow_script_0x931ddf:
loadpointer 0x0 str_0x931de9
callstd MSG_FACE
end
