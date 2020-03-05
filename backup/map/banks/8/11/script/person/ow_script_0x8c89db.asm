.include "flags.s"
.include "map_connections.s"
.include "items.s"
.include "callstds.s"
.include "species.s"
.include "map_adjacency_types.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8c89db
ow_script_0x8c89db:
showmoney 0x0 0x0 0x0
loadpointer 0x0 str_0x8c8907
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x6
loadpointer 0x0 choice
multichoice 0xd 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL pkmn0
compare LASTRESULT 0x1
gotoif EQUAL pkmn1
compare LASTRESULT 0x2
gotoif EQUAL pkmn2
compare LASTRESULT 0x3
gotoif EQUAL pkmn3
compare LASTRESULT 0x4
gotoif EQUAL pkmn4
goto ow_script_0x8c8ac3



pkmn0:
checkmoney 35000 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_TROPIUS
call ow_script_0x8c86c2
paymoney 35000 0x0
setvar 0x8000 POKEMON_TROPIUS
goto ow_script_0x8c8651

pkmn1:
checkmoney 99999 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_DRATINI
call ow_script_0x8c86c2
paymoney 99999 0x0
setvar 0x8000 POKEMON_DRATINI
goto ow_script_0x8c8651

pkmn2:
checkmoney 15000 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_PERLU
call ow_script_0x8c86c2
paymoney 15000 0x0
setvar 0x8000 POKEMON_PERLU
goto ow_script_0x8c8651

pkmn3:
checkmoney 25000 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_NEBULAK
call ow_script_0x8c86c2
paymoney 25000 0x0
setvar 0x8000 POKEMON_NEBULAK
goto ow_script_0x8c8651

pkmn4:
checkmoney 55000 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_CHANEIRA
call ow_script_0x8c86c2
paymoney 55000 0x0
setvar 0x8000 POKEMON_CHANEIRA
goto ow_script_0x8c8651


.align 4
choice:
    .word str_blackmarket_pkmn0, 0
    .word str_blackmarket_pkmn1, 0
    .word str_blackmarket_pkmn2, 0
    .word str_blackmarket_pkmn3, 0
    .word str_blackmarket_pkmn4, 0
    .word str_blackmarket_back, 0



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
clearflag TRANS_DISABLE
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



.ifdef LANG_GER
.global str_0x8c8907

str_0x8c8907:
    .string "Hallo! Du siehst aus wie ein\nTrainer, nicht?\pWie wäre es, dein Team mit ein\npaar exklusiven Pokémon\laufzustocken?\pIch verkaufe dir die seltensten\nExemplare zu einem Spottpreis!\pSieh dir mein Sortiment\nruhig an."
        
        
.global str_blackmarket_pkmn0

str_blackmarket_pkmn0:
    .string "Topius     35.000POKEDOLLAR   "
        
        
.global str_blackmarket_pkmn1

str_blackmarket_pkmn1:
    .string "Dratini    99.999POKEDOLLAR"
        
        
.global str_blackmarket_pkmn2

str_blackmarket_pkmn2:
    .string "Perlu      15.000POKEDOLLAR"
        
        
.global str_blackmarket_pkmn3

str_blackmarket_pkmn3:
    .string "Nebulak    25.000POKEDOLLAR"
        
        
.global str_blackmarket_pkmn4

str_blackmarket_pkmn4:
    .string "Chaneira   55.000POKEDOLLAR"
        
        
.global str_blackmarket_back

str_blackmarket_back:
    .string "Zurück            "
        
        
.global str_0x8c86ac

str_0x8c86ac:
    .string "PLAYER hat BUFFER_1\nerhalten!"
        
        
.global str_0x8c8683

str_0x8c8683:
    .string "Vielen Dank! Beehre mich gerne\nwieder!"
        
        
.global str_0x8c8767

str_0x8c8767:
    .string "Das Pokémon BUFFER_1 soll\nes sein?"
        
        
.global str_0x8c86f0

str_0x8c86f0:
    .string "Du scheinst nicht genügend Platz\nin deinem Team zu haben.\pKomm wieder, wenn du Platz in\ndeinem Team geschaffen hast."
        
        
.global str_0x8c882b

str_0x8c882b:
    .string "Ganz wie du möchtest.\pKomm jederzeit wieder, falls du es\ndir anders überlegst."
        
        
.global str_0x8c8793

str_0x8c8793:
    .string "Oh, sieht so aus, als hättest du\nnicht genügend Geld bei dir, um\ldir das zu leisten.\pKomm wieder, wenn du dir das\nProdukt kaufen kannst."
        
        
.elseif LANG_EN

.endif
