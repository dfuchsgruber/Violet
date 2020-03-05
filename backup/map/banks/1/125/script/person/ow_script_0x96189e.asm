.include "flags.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x96189e
ow_script_0x96189e:
lock
faceplayer

loadpointer 0 str_glas
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x962c48
callstd MSG_KEEPOPEN
checkflag ASHBAG_RECEIVED
gotoif LESS ow_script_0x961ce9
buffernumber 0x0 0x50d0
loadpointer 0x0 str_0x961ca8
callstd MSG_KEEPOPEN
special 0xF
pause 2
setvar DYN_MULTICHOICE_ITEM_CNT 0x6
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x0
loadpointer 0 str_glas
setvar 0x8000 0
special 0xE
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
special 0xF
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
special 0xF
end


.global ow_script_0x961af3
ow_script_0x961af3:
loadpointer 0x0 str_0x961afd
callstd MSG_FACE
special 0xF
end


.global ow_script_0x961b55
ow_script_0x961b55:
loadpointer 0x0 str_0x961b67
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x961baf
callstd MSG_FACE
special 0xF
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
special 0xF
end


.ifdef LANG_GER

str_glas:
	.string "Glasbläser"

.global str_0x962c48

str_0x962c48:
    .autostring 35 2 "Hallo, ich bin ein Meister der Glasbläserei.\pAus der vielen Asche kann ich Flöten fabrizieren, die heilsame Klänge erzeugen können."
        
        
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
    .autostring 35 2 "Tschüss!"
        
        
.global str_0x961baf

str_0x961baf:
    .autostring 35 2 "Wenn ich eine Flöte für dich herstellen soll, komm einfach\lwieder vorbei."
        
        
.global str_0x961ab8

str_0x961ab8:
    .autostring 35 2 "So sei es denn, ich werde die Flöte für dich herstellen."
        
        
.global str_0x961a3f

str_0x961a3f:
    .autostring 35 2 "Du kannst Flöten innerhalb und außerhalb des Kampfes benutzen.\pIhre Klänge haben verschiedenste Wirkungen auf Pokémon."
        
        
.global str_0x961afd

str_0x961afd:
    .autostring 35 2 "Es sieht so aus, als hättest du keinen Platz für eine weitere Flöte in deinem Beutel."
        
        
.global str_0x961b67

str_0x961b67:
    .autostring 35 2 "Es sieht so aus, als hättest du nicht genügend Asche für diese Flöte."
        
        
.global str_0x961d40

str_0x961d40:
    .autostring 35 2 "Wenn du mir Asche bringst, kann ich sie verarbeiten.\pDazu brauchst du aber eine Aschetasche.\pRede doch mit meinem Sohn, er näht solche Taschen."
        
        
.elseif LANG_EN

.endif
