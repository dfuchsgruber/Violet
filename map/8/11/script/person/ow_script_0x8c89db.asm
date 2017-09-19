.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c89db
ow_script_0x8c89db:
showmoney 0x0 0x0 0x0
loadpointer 0x0 str_0x8c8907
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x6
loadpointer 0x0 str_0x8c8a39
multichoice 0xd 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x5
gotoif EQUAL ow_script_0x8c881e
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c85d0
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x8c85fb
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x8c8626
compare LASTRESULT 0x3
gotoif EQUAL ow_script_0x8c85a5
goto ow_script_0x8c857a


.global ow_script_0x8c857a
ow_script_0x8c857a:
checkmoney 0x124f8 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_BARSCHWA
call ow_script_0x8c86c2
paymoney 0x124f8 0x0
setvar 0x8000 0x148
goto ow_script_0x8c8651


.global ow_script_0x8c8651
ow_script_0x8c8651:
updatemoney 0x0 0x0 0x0
sound 0x41
checksound
bufferpokemon 0x0 0x8000
fanfare 0x13e
loadpointer 0x0 str_0x8c86ac
callstd MSG_KEEPOPEN
waitfanfare
givepokemon 0x8000 0x5 ITEM_NONE 0x0 0x0 0x0
call ow_script_0x880b64
goto ow_script_0x8c8ac3


.global ow_script_0x8c8ac3
ow_script_0x8c8ac3:
loadpointer 0x0 str_0x8c8683
callstd MSG
hidemoney 0x0 0x0
end


.global ow_script_0x880b64
ow_script_0x880b64:
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x880b86
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x880ba0
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x880be5
end


.global ow_script_0x8c86c2
ow_script_0x8c86c2:
loadpointer 0x0 str_0x8c8767
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c881e
countpokemon
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x8c86e3
return


.global ow_script_0x8c86e3
ow_script_0x8c86e3:
hidemoney 0x0 0x0
loadpointer 0x0 str_0x8c86f0
callstd MSG
end


.global ow_script_0x8c881e
ow_script_0x8c881e:
hidemoney 0x0 0x0
loadpointer 0x0 str_0x8c882b
callstd MSG
end


.global ow_script_0x8c8786
ow_script_0x8c8786:
hidemoney 0x0 0x0
loadpointer 0x0 str_0x8c8793
callstd MSG
end


.global ow_script_0x8c85a5
ow_script_0x8c85a5:
checkmoney 0x61a8 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_TROPIUS
call ow_script_0x8c86c2
paymoney 0x61a8 0x0
setvar 0x8000 0x171
goto ow_script_0x8c8651


.global ow_script_0x8c8626
ow_script_0x8c8626:
checkmoney 0xc350 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_DRATINI
call ow_script_0x8c86c2
paymoney 0xc350 0x0
setvar 0x8000 0x93
goto ow_script_0x8c8651


.global ow_script_0x8c85fb
ow_script_0x8c85fb:
checkmoney 0x88b8 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_GRAMOKLES
call ow_script_0x8c86c2
paymoney 0x88b8 0x0
setvar 0x8000 0x3c
goto ow_script_0x8c8651


.global ow_script_0x8c85d0
ow_script_0x8c85d0:
checkmoney 0xafc8 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_EVOLI
call ow_script_0x8c86c2
paymoney 0xafc8 0x0
setvar 0x8000 0x85
goto ow_script_0x8c8651
