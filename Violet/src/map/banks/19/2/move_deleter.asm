.include "overworld_script.s"
.include "callstds.s"
.include "specials.s"
.include "ordinals.s"
.include "vars.s"

.global ow_script_ceometria_indoor_1_move_deleter

ow_script_ceometria_indoor_1_move_deleter:
    lock
    faceplayer
    loadpointer 0 str_intro
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif EQUAL ask_deletion
no_deletion:
    loadpointer 0 str_no_deletion
    callstd MSG_KEEPOPEN
    release
    end

ask_deletion:
    loadpointer 0 str_ask_deletion
    callstd MSG_KEEPOPEN
    special SPECIAL_SELECT_PARTY_POKEMON
    waitstate
    compare 0x8004 6
    gotoif HIGHER_OR_EQUAL no_deletion
    special SPECIAL_PARTY_POKEMON_IS_EGG
    compare LASTRESULT 1
    gotoif EQUAL is_egg
    special SPECIAL_PARTY_POKEMON_COUNT_MOVES
    compare LASTRESULT 1
    gotoif EQUAL one_move
    loadpointer 0 str_ask_move
    callstd MSG_KEEPOPEN
    fadescreen 1
    special SPECIAL_PARTY_POKEMON_SELECT_MOVE
    fadescreen 0
    compare 0x8005 4
    gotoif HIGHER_OR_EQUAL ask_deletion
    special SPECIAL_PARTY_POKEMON_BUFFER_MOVE
    loadpointer 0 str_confirm_deletion
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL no_deletion
    special SPECIAL_PARTY_POKEMON_DELETE_MOVE
    fanfare 0x10E
    waitfanfare
    loadpointer 0 str_move_deleted
    callstd MSG_KEEPOPEN
    release
    end

is_egg:
    loadpointer 0 str_is_egg
    callstd MSG_KEEPOPEN
    release
    end

one_move:
    loadpointer 0 str_one_move
    callstd MSG_KEEPOPEN
    release
    end

.ifdef LANG_GER
str_intro:
    .autostring 34 2 "UffDOTS\nDOTSwer ich bin?\pNunja, wer bin ich?\nDOTSDOTSDOTS\pIch hab's!\pIch bin der Attacken-Verlerner.\pIch sorge dafür, dass deine Pokémon Attacken vergessen.\pSoll ich dir helfen?"
str_no_deletion:
    .autostring 34 2 "Das ist aber schade!\pVielleicht erinnere ich mich schon bald nicht mehr daran, wie ich deinen Pokémon helfen kann, Attacken zu verlernenDOTS"
str_ask_deletion:
    .autostring 34 2 "Welches deiner Pokémon soll eine Attacke verlernen?"
str_is_egg:
    .autostring 34 2 "Du bist vielleicht vergesslich!\pEin Ei kann doch keine Attacken lernen!"
str_one_move:
    .autostring 34 2 "BUFFER_1 scheint nur einen Angriff zu kennen.\pWürde er diesen auch noch vergessen, wäre es völlig hilflos!"
str_ask_move:
    .autostring 34 2 "Welche Attacke soll vergessen werden?"
str_confirm_deletion:
    .autostring 34 2 "ÄhmDOTS\nAlso BUFFER_1 soll BUFFER_2 vergessen?"
str_move_deleted:
    .autostring 34 2 "Sehr gut!\nDein BUFFER_1 hatDOTS\lDOTSDOTSDOTSnunDOTS\pAh ja!\nBUFFER_1 hat BUFFER_2 vergessen!"

.elseif LANG_EN
str_intro:
    .autostring 34 2 "UffDOTS\nDOTSwho I am?\pUhm, who am I?\nDOTSDOTSDOTS\pI got it!\pI am the Move-Deleter.\pI can make your Pokémon forget their moves.\pDo you want my help?"
str_no_deletion:
    .autostring 34 2 "That's a pity.\pMaybe I won't remember how to help your Pokémon forget their moves sooner than you would likeDOTS"
str_ask_deletion:
    .autostring 34 2 "Which of your Pokémon should forget a move?"
str_is_egg:
    .autostring 34 2 "Oh my!\nYou are forgetful.\pAn egg can't learn any moves!"
str_one_move:
    .autostring 34 2 "BUFFER_1 seems to know only one move.\pIf it would forget this one as well it would be helpless!"
str_ask_move:
    .autostring 34 2 "Which move should be forgotten?"
str_confirm_deletion:
    .autostring 34 2 "UhmDOTS\nSo BUFFER_1 should forget BUFFER_2?"
str_move_deleted:
    .autostring 34 2 "Nice!\nYour BUFFER_1 forgotDOTS\lDOTSDOTSDOTSwellDOTS\pOh yes!\nBUFFER_1 forgot how to use BUFFER_2!"

.endif
