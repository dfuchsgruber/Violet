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
gotoif EQUAL ow_script_0x8305ae
showmoney 0x0 0x0 0x0
loadpointer 0x0 str_0x83069c
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8305a5
countpokemon
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x830543
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

.global str_0x8305dd

str_0x8305dd:
    .string "Hallo und herzlich willkommen!\nIch bin der Käferhändler. Heute\lhabe ich ganz frische Ware\lreinbekommen, Nincada, soweit das\lAuge reicht. Du möchtest nicht\lzufällig eines kaufen?"
        
        
.global str_0x83069c

str_0x83069c:
    .string "Das Stück kostet 250POKEDOLLAR. Willst du\nzuschlagen?"
        
        
.global str_0x8305b9

str_0x8305b9:
    .string "PLAYER hat ein Nincada erhalten. "
        
        
.global str_0x830520

str_0x830520:
    .string "Danke! Viel Spaß mit dem Nincada!"
        
        
.global str_0x830551

str_0x830551:
    .string "Sorry, du hast bereits 6 Pokémon in\ndeinem Team. Komm wieder wenn du\lPlatz hast."
        
        
.global str_0x8306cd

str_0x8306cd:
    .string "Das ist eine sehr schlechte\nEntscheidung, aber gut, ich kann\ldich daran nicht hindern."
        
        