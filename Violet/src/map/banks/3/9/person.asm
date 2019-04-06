.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "specials.s"
.include "movements.s"
.include "sav_keys.s"

.global ow_script_laubdorf_person_0
.global ow_script_laubdorf_person_1
.global ow_script_laubdorf_person_2
.global ow_script_laubdorf_person_3
.global ow_script_laubdorf_person_4
.global ow_script_laubdorf_person_5
.global ow_script_laubdorf_person_6
.global ow_script_laubdorf_assistant

ow_script_laubdorf_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_laubdorf_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

ow_script_laubdorf_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

ow_script_laubdorf_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end

ow_script_laubdorf_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end

ow_script_laubdorf_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end

ow_script_laubdorf_person_6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end
ow_script_laubdorf_assistant:
    checkflag FLAG_INCUBATOR
    gotoif 1 incubator_received
    lock
    faceplayer
    loadpointer 0 str_check_dex
    callstd MSG
    setvar 0x8004 1
    special2 LASTRESULT SPECIAL_POKEDEX_GET_STATS
    compare 0x8006 40
    gotoif LESS end_assistant
    buffernumber 0 0x8006
    sound 0x15
    applymovement LASTTALKED mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_has_enough_caught
    callstd MSG_KEEPOPEN
    fanfare 0x13E
    loadpointer 0 str_received_incubator
    callstd MSG_KEEPOPEN
    waitfanfare
    setflag FLAG_INCUBATOR
    setvar INCUBATOR_SLOTS 1
incubator_received:
    lock
    faceplayer
    loadpointer 0 str_explain_incubator
    callstd MSG_KEEPOPEN
check_incubator_slots:
    compare INCUBATOR_SLOTS 3
    gotoif LESS check_number_of_eggs_bred
end_assistant:
    release
    end

check_number_of_eggs_bred:
    compare INCUBATOR_SLOTS 1
    gotoif HIGHER two_slots_unlocked
    buffernumber 0 5
    savcomparekey SAV_KEY_EGGS_HATCHED 5
    gotoif LESS not_enough_eggs_bred
    goto unlock_new_slot
two_slots_unlocked:
    buffernumber 0 15
    savcomparekey SAV_KEY_EGGS_HATCHED 15
    gotoif LESS not_enough_eggs_bred
unlock_new_slot:
    loadpointer 0 str_enough_eggs_bred
    callstd MSG_KEEPOPEN
    fanfare 0x13E
    loadpointer 0 str_expanded_incubator
    callstd MSG_KEEPOPEN
    waitfanfare
    addvar INCUBATOR_SLOTS 1
    lock
    faceplayer
    loadpointer 0 str_after_expansion
    callstd MSG_KEEPOPEN
    goto check_incubator_slots

not_enough_eggs_bred:
    loadpointer 0 str_not_enough_eggs_bred
    callstd MSG_KEEPOPEN
    release
    end 
    

mov_exclam:
    .byte SAY_EXCLAM, STOP

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Laubdorf wirkt auf mich wie ein großes Nest.\pHier sind alle eine Familie, egal ob Mensch oder Pokémon."
str_1:
    .autostring 34 2 "Manche Pokémon lassen sich nur züchten, wenn ihre Eltern ein bestimmtes Item tragen."
str_2:
    .autostring 34 2 "Ich habe miterlebt, wie Lucius in dieser Region die Pokémon Liga errichtet hat.\pEr hat großen Eindruck auf uns alle gemacht, damals."
str_3:
    .autostring 34 2 "Oft blicke ich abends in den Himmel und starre die Sterne an.\pOb es noch andere Wesen da draußen gibt?"
str_4:
    .autostring 34 2 "Hast du schon einmal von der dunklen Königin gehört?\pEs ist eine sehr alte Legende.\pWegen ihrer Boshaftigkeit, wurde ihr Geist verbannt."
str_5:
    .autostring 34 2 "Für ein gesundes Leben ist körperliche Betätigung unerlässlich.\pUnd das Joggen ist hier am Strand gleich umso anstrengender!"
str_6:
    .autostring 34 2 "Der Traum eines jeden Anglers ist es, ein rotes Garados zu besitzen!\pUnd nur, wer immerzu seine Rute ins Wasser wirft, kann das schaffen!"
str_check_dex:
    .autostring 34 2 "Hallo PLAYER.\nIch bin ein Assistent von Professor Tann.\pWenn du 40 verschiedene Pokémon in deinem Pokédex als gefangen registriert hast, erhältst du von mir eine Belohnung."
str_has_enough_caught:
    .autostring 34 2 "Wunderbar, du hast bereits BUFFER_1 verschiedene Spezies registriert.\pAls Belohnung dafür werde ich dir einen Inkubator geben."
str_received_incubator:
    .autostring 34 2 "PLAYER erhält einen Inkubator.\pAußerdem wird die Inkubator-App auf dem Poképad installiert."
str_explain_incubator:
    .autostring 34 2 "Im Inkubator können Eier ausgebrütet werden.\pDamit sie schlüpfen können, musst du sie allerdings deinem Team hinzufügen.\pDer Inkubator brütet aufgrund seiner Temperatur die Eier schneller, als wenn du sie nur mit dir trägst.\pHältst du dich an heißen Orten auf, steigt die Temperatur und Eier schlüpfen früher."
str_not_enough_eggs_bred:
    .autostring 34 2 "Wenn du BUFFER_1 Eier ausgebrütet hast, werde ich deinem Inkubator einen weiteren Platz hinzufügen."
str_enough_eggs_bred:
    .autostring 34 2 "Du hast inzwischen einige Eier ausgebrütet.\pAls Belohnung werde ich deinem Inkubator einen weiteren Platz hinzufügen."
str_expanded_incubator:
    .autostring 34 2 "Dem Inkubator wurde ein weiterer Platz hinzugefügt."
str_after_expansion:
    .autostring 34 2 "Versuche auch weiter, fleißig Pokémon zu brüten."


.elseif LANG_EN
str_0:
    .autostring 34 2 "Leaf Village is like a large nest to me.\pHere, everyone is family, no matter if human or Pokémon."
str_1:
    .autostring 34 2 "Some Pokémon can only be bred if their parents hold a specific item."
str_2:
    .autostring 34 2 "I remember Lucius building the Pokémon League in this region.\pHe really made an impression on us all."
str_3:
    .autostring 34 2 "Often I stare in the skies when night has come and wonder about the stars.\pAre there other creatures out there?"
str_4:
    .autostring 34 2 "Did you ever hear about the dark queen?\pIt's a very old legend that says her ghost was banished because of her evilness."
str_5:
    .autostring 34 2 "For a healthy life sports is essential!\pAnd jogging at the beach is even more exhausting."
str_6:
    .autostring 34 2 "It's a fisherman's dream to own a red Gyarados.\pAnd only the one who keeps fishing can achieve this dream."

.endif