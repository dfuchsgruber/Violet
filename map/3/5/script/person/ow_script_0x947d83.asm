.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x95a473
ow_script_movs_0x95a473:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x947d83
ow_script_0x947d83:
loadpointer 0x0 str_0x95a476
callstd MSG
sound 0x15
faceplayer
applymovement 0x800f ow_script_movs_0x95a473
waitmovement 0x0
checkflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
gotoif EQUAL ow_script_0x95a390
showmoney 0x0 0x0 0x0
loadpointer 0x0 str_0x95a1e9
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95a0f6
checkmoney 0xc350 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95a030
sound 0x41
paymoney 0xc350 0x0
updatemoney 0x0 0x0 0x0
checksound
fadesong MUS_PIRATE
loadpointer 0x0 str_0x959ff5
callstd MSG
hidemoney 0x0 0x0
lockall
copyvar 0x8004 LASTTALKED
setvar 0x8005 0x1a
setvar 0x8006 0x2e
special 0x24
pause 0x30
fadescreen 0x1
waitmovement 0x0
loadpointer 0x0 str_0x959fdb
callstd MSG
copyvar 0x8004 LASTTALKED
special 0x1b
fadescreen 0x0
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x959fa0
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_ITEM_10B
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x959f24
callstd MSG
fadescreen 0x1
hidesprite 0x800f
setflag ORINA_CITY_WOLKENHERZ_STOLEN
fadesong MUS_AZURIA_CITY_AND_FEUERHOHLE_AND_FUCHSANIA_CITY
fadescreen 0x0
releaseall
end


.global ow_script_movs_0x95a10d
ow_script_movs_0x95a10d:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x95a030
ow_script_0x95a030:
hidemoney 0x0 0x0
loadpointer 0x0 str_0x95a047
callstd MSG
applymovement 0x800f ow_script_movs_0x95a10d
waitmovement 0x0
end


.global ow_script_0x95a0f6
ow_script_0x95a0f6:
hidemoney 0x0 0x0
loadpointer 0x0 str_0x95a110
callstd MSG
applymovement 0x800f ow_script_movs_0x95a10d
waitmovement 0x0
end


.global ow_script_0x95a390
ow_script_0x95a390:
loadpointer 0x0 str_0x95a3a2
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
releaseall
end
