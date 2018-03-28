.include "overworld_script.s"

.include "std.s"

.global ow_script_0x96189e
ow_script_0x96189e:
lock
faceplayer
loadpointer 0x0 str_0x962c48
callstd MSG_KEEPOPEN
checkflag ASHBAG_RECEIVED
gotoif LESS ow_script_0x961ce9
buffernumber 0x0 0x50d0
loadpointer 0x0 str_0x961ca8
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x6
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x0
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x961913
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x96194d
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x961987
compare LASTRESULT 0x3
gotoif EQUAL ow_script_0x9619c1
compare LASTRESULT 0x4
gotoif EQUAL ow_script_0x9619fb
loadpointer 0x0 str_0x961baf
callstd MSG_FACE
end

.align 4
choice:
    .word str_aschhain_flute_choice_0, 0
    .word str_aschhain_flute_choice_1, 0
    .word str_aschhain_flute_choice_2, 0
    .word str_aschhain_flute_choice_3, 0
    .word str_aschhain_flute_choice_4, 0
    .word str_aschhain_flute_choice_5, 0

.global ow_script_0x9619fb
ow_script_0x9619fb:
compare ASH 0x3e8
gotoif LESS ow_script_0x961b55
checkitemroom ITEM_SCHW_FLOETE 0x1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x961af3
loadpointer 0x0 str_0x961ab8
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_SCHW_FLOETE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
subvar ASH 0x3e8
goto ow_script_0x961a35


.global ow_script_0x961a35
ow_script_0x961a35:
loadpointer 0x0 str_0x961a3f
callstd MSG_FACE
end


.global ow_script_0x961af3
ow_script_0x961af3:
loadpointer 0x0 str_0x961afd
callstd MSG_FACE
end


.global ow_script_0x961b55
ow_script_0x961b55:
loadpointer 0x0 str_0x961b67
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x961baf
callstd MSG_FACE
end


.global ow_script_0x9619c1
ow_script_0x9619c1:
compare ASH 0x3e8
gotoif LESS ow_script_0x961b55
checkitemroom ITEM_WEISSE_FLOETE 0x1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x961af3
loadpointer 0x0 str_0x961ab8
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_WEISSE_FLOETE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
subvar ASH 0x3e8
goto ow_script_0x961a35


.global ow_script_0x961987
ow_script_0x961987:
compare ASH 0x1f4
gotoif LESS ow_script_0x961b55
checkitemroom ITEM_GELBE_FLOETE 0x1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x961af3
loadpointer 0x0 str_0x961ab8
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_GELBE_FLOETE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
subvar ASH 0x1f4
goto ow_script_0x961a35


.global ow_script_0x96194d
ow_script_0x96194d:
compare ASH 0x1f4
gotoif LESS ow_script_0x961b55
checkitemroom ITEM_ROTE_FLOETE 0x1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x961af3
loadpointer 0x0 str_0x961ab8
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_ROTE_FLOETE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
subvar ASH 0x1f4
goto ow_script_0x961a35


.global ow_script_0x961913
ow_script_0x961913:
compare ASH 0xfa
gotoif LESS ow_script_0x961b55
checkitemroom ITEM_BLAUE_FLOETE 0x1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x961af3
loadpointer 0x0 str_0x961ab8
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_BLAUE_FLOETE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
subvar ASH 0xfa
goto ow_script_0x961a35


.global ow_script_0x961ce9
ow_script_0x961ce9:
loadpointer 0x0 str_0x961d40
callstd MSG_FACE
end

.global str_0x962c48

str_0x962c48:
    .string "Hallo, ich bin ein Meister der\nGlasbläserei.\pAus der vielen Asche kann ich\nFlöten fabrizieren, die heilsamen\lKlänge erzeugen können."
        
        
.global str_0x961ca8

str_0x961ca8:
    .string "Du hast mir BUFFER_1 Asche gebracht.\nWelche Flöte möchtest du haben?"
        
        
.global str_aschhain_flute_choice_0

str_aschhain_flute_choice_0:
    .string "Blaue Flöte / 250  Asche"
        
        
.global str_aschhain_flute_choice_1

str_aschhain_flute_choice_1:
    .string "Rote Flöte  / 500  Asche  "
        
        
.global str_aschhain_flute_choice_2

str_aschhain_flute_choice_2:
    .string "Gelbe Flöte / 500  Asche"
        
        
.global str_aschhain_flute_choice_3

str_aschhain_flute_choice_3:
    .string "Weiße Flöte / 1000 Asche"
        
        
.global str_aschhain_flute_choice_4

str_aschhain_flute_choice_4:
    .string "Schw. Flöte / 1000 Asche"
        
        
.global str_aschhain_flute_choice_5

str_aschhain_flute_choice_5:
    .string "Tschüss!"
        
        
.global str_0x961baf

str_0x961baf:
    .string "Wenn ich eine Flöte für dich\nherstellen soll, komm einfach\lwieder vorbei."
        
        
.global str_0x961ab8

str_0x961ab8:
    .string "So sei es denn, ich werde die\nFlöte für dich herstellen."
        
        
.global str_0x961a3f

str_0x961a3f:
    .string "Du kannst Flöten innerhalb und\naußerhalb des Kampfes benutzen.\pIhre Klänge haben verschiedenste\nWirkungen auf Pokémon."
        
        
.global str_0x961afd

str_0x961afd:
    .string "Es sieht so aus, als hättest du\nkeinen Platz für eine weitere\lFlöte in deinem Beutel."
        
        
.global str_0x961b67

str_0x961b67:
    .string "Es sieht so aus, als hättest du\nnicht genügend Asche für diese\lFlöte."
        
        
.global str_0x961d40

str_0x961d40:
    .string "Wenn du mir Asche bringst, kann\nich sie verarbeiten.\pDazu brauchst du aber eine\nAschetasche.\pRede doch mit meinem Sohn, er näht\ndiese Taschen."
        
        