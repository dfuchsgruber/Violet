.include "overworld_script.s"

.include "std.s"

.global ow_script_0x87f98b
ow_script_0x87f98b:
checkflag SILVANIA_BERRY_JUICE
gotoif EQUAL ow_script_0x8deb07
lock
faceplayer
loadpointer 0x0 str_0x8dee30
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8deafd
loadpointer 0x0 str_0x8deadb
callstd MSG
copyvarifnotzero 0x8000 ITEM_BEERENSAFT
copyvarifnotzero 0x8001 ITEM_TOP_BELEBER
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
loadpointer 0x0 str_0x8dec8a
callstd MSG
setflag SILVANIA_BERRY_JUICE
release
end


.global ow_script_0x8deafd
ow_script_0x8deafd:
loadpointer 0x0 str_0x8decc8
callstd MSG_FACE
end


.global ow_script_0x8deb07
ow_script_0x8deb07:
loadpointer 0x0 str_0x8dec8a
callstd MSG_FACE
end
