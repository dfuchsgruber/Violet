.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_aschhain_glas_guy
.global ow_script_aschhain_house_person_0
.global ow_script_aschhain_ash_bag_kid

ow_script_aschhain_house_person_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Mein Mann ist ein äußerst begabter Glasbläser.\pEr hat sein Handwerk damals in Hoenn gelernt.\pVor einigen Jahren haben wir uns dann hier niedergelassen."
.elseif LANG_EN
.endif


ow_script_aschhain_ash_bag_kid:
    checkflag ASHBAG_RECEIVED
    gotoif EQUAL received_ashbag
    lock
    faceplayer
    loadpointer 0x0 str_before_ashbag
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_ASCHETASCHE
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    loadpointer 0x0 str_received_ashbag
    callstd MSG
    setflag ASHBAG_RECEIVED
    release
    end

received_ashbag:
    loadpointer 0x0 str_received_ashbag
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_before_ashbag:
    .autostring 34 2 "Du bist ein Trainer oder?\pMein Papa ist Glasbläser und er stellt aus Asche Flöten her.\pWenn du ihm Asche bringst, kann er sie weiterverarbeiten.\pAber dafür musst du natürlich erst einmal Asche sammeln können, oder?"
str_received_ashbag:
    .autostring 34 2 "Jetzt bist du bestens ausgestattet!\pWenn du durch von Asche bedecktes hohes Gras läufst, fängt die Aschetasche den Staub auf.\pHast du genügend Asche gesammelt, bring sie zu meinem Vater und er stellt daraus eine Flöte her."
.elseif LANG_EN
.endif


ow_script_aschhain_glas_guy:
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

ow_script_0x961a35:
    loadpointer 0x0 str_0x961a3f
    callstd MSG_FACE
    special 0xF
    end

ow_script_0x961af3:
    loadpointer 0x0 str_0x961afd
    callstd MSG_FACE
    special 0xF
    end

ow_script_0x961b55:
    loadpointer 0x0 str_0x961b67
    callstd MSG_KEEPOPEN
    loadpointer 0x0 str_0x961baf
    callstd MSG_FACE
    special 0xF
    end

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

ow_script_0x961ce9:
    loadpointer 0x0 str_0x961d40
    callstd MSG_FACE
    special 0xF
    end


.ifdef LANG_GER

str_glas:
	.string "Glasbläser"
str_0x962c48:
    .autostring 35 2 "Hallo, ich bin ein Meister der Glasbläserei.\pAus der vielen Asche kann ich Flöten fabrizieren, die heilsame Klänge erzeugen können."
str_0x961ca8:
    .string "Du hast mir BUFFER_1 Asche gebracht.\nWelche Flöte möchtest du haben?"
str_aschhain_flute_choice_0:
    .string "Blaue Flöte / 250  Asche"
str_aschhain_flute_choice_1:
    .string "Rote Flöte  / 500  Asche  "
str_aschhain_flute_choice_2:
    .string "Gelbe Flöte / 500  Asche"
str_aschhain_flute_choice_3:
    .string "Weiße Flöte / 1000 Asche"
str_aschhain_flute_choice_4:
    .string "Schw. Flöte / 1000 Asche"
str_aschhain_flute_choice_5:
    .autostring 35 2 "Tschüss!"
str_0x961baf:
    .autostring 35 2 "Wenn ich eine Flöte für dich herstellen soll, komm einfach\lwieder vorbei."
str_0x961ab8:
    .autostring 35 2 "So sei es denn, ich werde die Flöte für dich herstellen."
str_0x961a3f:
    .autostring 35 2 "Du kannst Flöten innerhalb und außerhalb des Kampfes benutzen.\pIhre Klänge haben verschiedenste Wirkungen auf Pokémon."
str_0x961afd:
    .autostring 35 2 "Es sieht so aus, als hättest du keinen Platz für eine weitere Flöte in deinem Beutel."
str_0x961b67:
    .autostring 35 2 "Es sieht so aus, als hättest du nicht genügend Asche für diese Flöte."
str_0x961d40:
    .autostring 35 2 "Wenn du mir Asche bringst, kann ich sie verarbeiten.\pDazu brauchst du aber eine Aschetasche.\pRede doch mit meinem Sohn, er näht solche Taschen."

.elseif LANG_EN
.endif