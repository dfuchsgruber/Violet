.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x9584b7
ow_script_movs_0x9584b7:
.byte LOOK_UP
.byte STOP


.global ow_script_0x9588ed
ow_script_0x9588ed:
lockall
call ow_script_0x8a7f80
faceplayer
loadpointer 0x0 str_0x958549
callstd MSG_KEEPOPEN
setvar 0x4001 0x85
givepokemon POKEMON_PORYGON 0x1e ITEM_NONE 0x0 0x0 0x0
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x9584ba
special 0x7
applymovement 0x800f ow_script_movs_0x9584b7
waitmovement 0x0
pause 0x1c
faceplayer
fanfare 0x13e
loadpointer 0x0 str_0x958498
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
bufferpokemon 0x0 POKEMON_PORYGON
call ow_script_0x893bb5
call ow_script_0x8a7f80
loadpointer 0x0 str_0x95839d
callstd MSG
special 0x7
addvar STORY_PROGRESS 0x1
setflag ORINA_CITY_MISTRALS_GRUNTS
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
releaseall
end


.global ow_script_0x9584ba
ow_script_0x9584ba:
loadpointer 0x0 str_0x9584c8
callstd MSG
special 0x7
releaseall
end
