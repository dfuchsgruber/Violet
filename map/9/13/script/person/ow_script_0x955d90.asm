.include "overworld_script.s"

.include "std.s"

.global ow_script_0x955d90
ow_script_0x955d90:
checkflag ORINA_CITY_UP_GRADE
gotoif EQUAL ow_script_0x95809d
compare KARMA_VALUE 0x7fff
gotoif HIGHER ow_script_0x958032
lock
faceplayer
loadpointer 0x0 str_0x957fcc
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_UP_GRADE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x9580a7
callstd MSG
setflag ORINA_CITY_UP_GRADE
release
end


.global ow_script_0x958032
ow_script_0x958032:
loadpointer 0x0 str_0x95803c
callstd MSG_FACE
end


.global ow_script_0x95809d
ow_script_0x95809d:
loadpointer 0x0 str_0x9580a7
callstd MSG_FACE
end
