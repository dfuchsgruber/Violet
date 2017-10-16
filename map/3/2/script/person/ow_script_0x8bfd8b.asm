.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8bfd8b
ow_script_0x8bfd8b:
checkflag AKTANIA_ROD
gotoif EQUAL ow_script_0x8bfdcb
lock
faceplayer
loadpointer 0x0 str_0x8c16a7
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c1233
loadpointer 0x0 str_0x8c1201
callstd MSG
copyvarifnotzero 0x8000 ITEM_ANGEL
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
setflag AKTANIA_ROD
loadpointer 0x0 str_0x8c1179
callstd MSG
release
end


.global ow_script_0x8c1233
ow_script_0x8c1233:
loadpointer 0x0 str_0x8c1638
callstd MSG
release
end


.global ow_script_0x8bfdcb
ow_script_0x8bfdcb:
loadpointer 0x0 str_0x8c1179
callstd MSG_FACE
end
