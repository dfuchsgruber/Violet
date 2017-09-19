.include "overworld_script.s"

.include "std.s"

.global ow_script_0x937a8c
ow_script_0x937a8c:
lock
faceplayer
checkflag POKEDEX_FEATURE_HABITAT
gotoif EQUAL ow_script_0x937c8a
loadpointer 0x0 str_0x937bb1
callstd MSG_KEEPOPEN
setvar 0x8004 0x1
special2 0x800d 0xd4
buffernumber 0x2 0x8006
compare 0x8006 0xa
gotoif LESS ow_script_0x8f3bfd
sound 0x15
applymovement 0x800f ow_script_movs_0x8f3bfa
waitmovement 0x0
loadpointer 0x0 str_0x937ae9
callstd MSG_KEEPOPEN
fanfare 0x13e
lock
faceplayer
loadpointer 0x0 str_0x937b72
callstd MSG_KEEPOPEN
lock
faceplayer
waitfanfare
lock
faceplayer
setflag POKEDEX_FEATURE_HABITAT
goto ow_script_0x937c8a


.global ow_script_0x937c8a
ow_script_0x937c8a:
lock
faceplayer
loadpointer 0x0 str_0x9381b7
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x93814a
loadpointer 0x0 str_0x937ed4
callstd MSG_FACE
end


.global ow_script_0x93814a
ow_script_0x93814a:
loadpointer 0x0 str_0x938154
callstd MSG_FACE
end
