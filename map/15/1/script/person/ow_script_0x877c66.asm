.include "overworld_script.s"

.include "std.s"

.global ow_script_0x877c66
ow_script_0x877c66:
lock
faceplayer
showmoney 0x0 0x0 0x0
loadpointer 0x0 str_0x8bfba9
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x846bee
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x89bdc5
end


.global ow_script_0x89bdc5
ow_script_0x89bdc5:
paymoney 0x96 0x0
loadpointer 0x0 str_0x812578
callstd MSG_FACE
sound 0x41
updatemoney 0x0 0x0 0x0
loadpointer 0x0 str_0x812509
callstd MSG_KEEPOPEN
closeonkeypress
loadpointer 0x0 str_0x81f8d2
callstd MSG_FACE
cry POKEMON_STARAPTOR 0x0
waitcry
setweather 0
doweather
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar 0x8004 0xE
special 0x19
waitstate
setflag MAP_BGN_AUTO_ALIGN_OFF
waitstate

clearflag TRANS_DISABLE
clearflag MAP_BGN_AUTO_ALIGN_OFF
warpmuted 0x3 0x2 0x5 0xa 0x4
waitstate
release
end


.global ow_script_0x846bee
ow_script_0x846bee:
hidemoney 0x0 0x0
loadpointer 0x0 str_0x812597
callstd MSG_FACE
release
end


.ifdef LANG_GER
.global str_0x8bfba9

str_0x8bfba9:
    .string "Hallo! Mein Name ist Rick.\nIch und mein Bruder Nick betreiben\ldiese Farm hier. Wir züchten\lMähikel, Voltilamm und\lVogelpokemon. Wenn du willst,\lbringt dich mein Staraptor von\lhier nach Aktania. Als\lGegenleistung verlange ich gerade\leinmal 150 POKEDOLLAR.\pWas sagst du? Willst du den\nService in Anspruch nehmen?"
        
        
.global str_0x812578

str_0x812578:
    .string "Toll! Also, 150 POKEDOLLAR, bitte!\n"
        
        
.global str_0x812509

str_0x812509:
    .string "PLAYER bezahlt 150 POKEDOLLAR."
        
        
.global str_0x81f8d2

str_0x81f8d2:
    .string "Dankeschön...\nKomm bitte mit, mein Staraptor wird\ldich jetzt nach Aktania fliegen."
        

        
.global str_0x812597

str_0x812597:
    .string "Ganz wie du willst. Solltest du\njedoch irgendwanneinmal nach\lAktania wollen, komm einfach zu\lmir."
        
        

.elseif LANG_EN

.endif
