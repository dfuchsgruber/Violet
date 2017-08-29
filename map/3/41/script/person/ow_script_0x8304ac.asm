.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8304ac
ow_script_0x8304ac:
goto ow_script_0x877bed


.global ow_script_0x877bed
ow_script_0x877bed:
lock
faceplayer
loadpointer 0x0 str_0x8305dd
callstd MSG_YES_NO
compare LASTRESULT 0x0
callif EQUAL ow_script_0x8305ae
showmoney 0x0 0x0 0x0
callasm 0x9181e01
loadpointer 0x0 str_0x83069c
callstd MSG_YES_NO
compare LASTRESULT 0x0
callif EQUAL ow_script_0x8305a5
countpokemon
compare LASTRESULT 0x6
callif EQUAL ow_script_0x830543
sound 0x41
paymoney 0xfa 0x0
updatemoney 0x0 0x0 0x0
checksound
fanfare 0x13e
loadpointer 0x0 str_0x8305b9
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
givepokemon POKEMON_NINCADA 0x5 ITEM_NONE 0x0 0x0 0x0
bufferpokemon 0x0 POKEMON_NINCADA
hidemoney 0x0 0x0
loadpointer 0x0 str_0x830520
callstd MSG
release
end


.global ow_script_0x830543
ow_script_0x830543:
hidemoney 0x0 0x0
loadpointer 0x0 str_0x830551
callstd MSG
release
end


.global ow_script_0x8305a5
ow_script_0x8305a5:
hidemoney 0x0 0x0
goto ow_script_0x8305ae


.global ow_script_0x8305ae
ow_script_0x8305ae:
loadpointer 0x0 str_0x8306cd
callstd MSG
release
end
