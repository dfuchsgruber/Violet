.include "overworld_script.s"

.include "std.s"

.global ow_script_0x949cfd
ow_script_0x949cfd:
checkflag ROUTE_5_CLOUD_RECEIVED
gotoif EQUAL ow_script_0x94ba17
lock
faceplayer
loadpointer 0x0 str_0x94b8ae
callstd MSG_KEEPOPEN
checkflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
gotoif EQUAL ow_script_0x94bff4
loadpointer 0x0 str_0x949ddc
callstd MSG_KEEPOPEN
checkitem ITEM_ITEM_10B 0x1
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x94c10c
closeonkeypress
release
end


.global ow_script_movs_0x94c6c7
ow_script_movs_0x94c6c7:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x94c10c
ow_script_0x94c10c:
sound 0x15
applymovement 0x800f ow_script_movs_0x94c6c7
waitmovement 0x0
goto ow_script_0x949d36


.global ow_script_0x949d36
ow_script_0x949d36:
loadpointer 0x0 str_0x94c615
callstd MSG_KEEPOPEN
fanfare 0x13e
additem ITEM_FAHRRAD 0x1
loadpointer 0x0 str_0x94bc55
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
removeitem ITEM_ITEM_10B 0x1
loadpointer 0x0 str_0x94ba96
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94c596
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94ba21
callstd MSG
setflag ROUTE_5_CLOUD_RECEIVED
end


.global ow_script_0x94bff4
ow_script_0x94bff4:
fadesong MUS_CLOUDS
goto ow_script_0x94be7e


.global ow_script_movs_0x94be6d
ow_script_movs_0x94be6d:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x94bc7c
ow_script_movs_0x94bc7c:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x94be7e
ow_script_0x94be7e:
closeonkeypress
cry POKEMON_ALTARIA 0x0
waitcry
sound 0x15
applymovement 0xff ow_script_movs_0x94be6d
applymovement 0x800f ow_script_movs_0x94be6d
waitmovement 0x0
loadpointer 0x0 str_0x94be36
callstd MSG
cry POKEMON_ALTARIA 0x0
waitcry
clearflag PKMNMENU
showsprite 0xd
call ow_script_0x94be24
call ow_script_0x94be24
call ow_script_0x94be24
call ow_script_0x94be24
call ow_script_0x94be70
cry POKEMON_ALTARIA 0x0
waitcry
loadpointer 0x0 str_0x94bdbf
callstd MSG
cry POKEMON_ALTARIA 0x0
waitcry
cry POKEMON_ALTARIA 0x0
waitcry
loadpointer 0x0 str_0x94bd31
callstd MSG
cry POKEMON_ALTARIA 0x0
waitcry
cry POKEMON_ALTARIA 0x0
waitcry
loadpointer 0x0 str_0x94bc7f
callstd MSG
cry POKEMON_ALTARIA 0x0
waitcry
applymovement 0x800f ow_script_movs_0x94bc7c
waitmovement 0x0
fanfare 0x13e
additem ITEM_FAHRRAD 0x1
loadpointer 0x0 str_0x94bc55
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
cry POKEMON_ALTARIA 0x0
waitcry
loadpointer 0x0 str_0x94bf95
callstd MSG
fadescreen 0x1
cry POKEMON_ALTARIA 0x0
waitcry
cry POKEMON_ALTARIA 0x0
waitcry
hidesprite 0xd
fadescreen 0x0
goto ow_script_0x94c103


.global ow_script_0x94c103
ow_script_0x94c103:
fadesong MUS_ROUTE_3_10_AND_ROUTE_16_22
goto ow_script_0x94c5f5


.global ow_script_0x94c5f5
ow_script_0x94c5f5:
loadpointer 0x0 str_0x94bb88
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94c596
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94ba21
callstd MSG
setflag PKMNMENU
setflag ROUTE_5_CLOUD_RECEIVED
release
end


.global ow_script_movs_0x94c591
ow_script_movs_0x94c591:
.byte STEP_IN_PLACE_DOWN_FAST
.byte 0x1c
.byte 0x1c
.byte STEP_DOWN
.byte STOP


.global ow_script_0x94be70
ow_script_0x94be70:
sound 0x96
applymovement 0xd ow_script_movs_0x94c591
waitmovement 0x0
return


.global ow_script_movs_0x94be33
ow_script_movs_0x94be33:
.byte STEP_DOWN_VERY_SLOW
.byte STOP


.global ow_script_0x94be24
ow_script_0x94be24:
sound 0x96
applymovement 0xd ow_script_movs_0x94be33
waitmovement 0x0
return


.global ow_script_0x94ba17
ow_script_0x94ba17:
loadpointer 0x0 str_0x94ba21
callstd MSG_FACE
end
