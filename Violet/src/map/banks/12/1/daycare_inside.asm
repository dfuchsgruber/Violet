.include "overworld_script.s"
.include "callstds.s"
.include "ordinals.s"
.include "vars.s"
.include "flags.s"
.include "specials.s"
.include "sav_keys.s"
.include "movements.s"

.global ow_script_laubdorf_daycare_inside

ow_script_laubdorf_daycare_inside:
    special 0x187
    compare LASTRESULT 2
    gotoif EQUAL end_inside
    lock
    faceplayer
    special2 LASTRESULT SPECIAL_DAYCARE_GET_STATE
    compare LASTRESULT 1
    gotoif EQUAL egg_in_daycare
    compare LASTRESULT 2
    gotoif EQUAL one_pokemon_in_daycare
    compare LASTRESULT 3
    gotoif EQUAL two_pokemon_in_daycare
    // No pokemon yet in daycare
    loadpointer 0 str_no_pokemon_in_daycare
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif EQUAL add_pokemon_to_daycare
    loadpointer 0 str_dont_raise
    callstd MSG_KEEPOPEN
end_inside:
    release
    end

egg_in_daycare:
    loadpointer 0 str_egg_in_daycare
    callstd MSG_KEEPOPEN
    release
    end

one_pokemon_in_daycare:
    loadpointer 0 str_pokemon_doing_fine
    callstd MSG_KEEPOPEN
    setvar 0x8004 0
    call display_level_gained
    loadpointer 0 str_ask_second_pokemon
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif EQUAL add_pokemon_to_daycare
ask_if_pokemon_should_be_removed:
    loadpointer 0 str_remove_pokemon
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif EQUAL remove_pokemon_from_daycare
goodbye:
    loadpointer 0 str_goodbye
    callstd MSG_KEEPOPEN
    release
    end

two_pokemon_in_daycare:
    loadpointer 0 str_pokemon_doing_fine
    callstd MSG_KEEPOPEN
    setvar 0x8004 0
    call display_level_gained
    setvar 0x8004 1
    call display_level_gained
    goto ask_if_pokemon_should_be_removed

display_level_gained:
    special2 LASTRESULT SPECIAL_DAYCARE_BUFFER_POKEMON_LEVEL_GAINED
    compare LASTRESULT 0
    gotoif EQUAL no_level_gained
    loadpointer 0 str_level_gained
    callstd MSG_KEEPOPEN
no_level_gained:
    return

add_pokemon_to_daycare:
    special2 LASTRESULT SPECIAL_PLAYER_PARTY_RECOUNT
    compare LASTRESULT 1
    gotoif EQUAL last_pokemon
    loadpointer 0 str_select_pokemon
    callstd MSG_KEEPOPEN
    fadescreen 1
    special SPECIAL_DAYCARE_SELECT_PARTY_POKEMON
    waitstate
    compare 0x8004 6
    gotoif HIGHER_OR_EQUAL goodbye
    special2 0x8005 SPECIAL_PLAYER_PARTY_GET_SPECIES
    checksound
    cry 0x8005 0x0
    loadpointer 0 str_pokemon_added
    callstd MSG_KEEPOPEN
    waitcry
    special SPECIAL_DAYCARE_ADD_SELECTED_PARTY_POKEMON
    savincrementkey SAV_KEY_POKEMON_GIVEN_INTO_DAYCARE
    special2 LASTRESULT SPECIAL_DAYCARE_GET_STATE
    compare LASTRESULT 2
    gotoif EQUAL ask_if_second_pokemon_should_be_added
    release
    end

ask_if_second_pokemon_should_be_added:
    loadpointer 0 str_ask_second_pokemon
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif EQUAL add_pokemon_to_daycare
    goto goodbye

last_pokemon:
    loadpointer 0 str_last_pokemon
    callstd MSG_KEEPOPEN
    release
    end

remove_pokemon_from_daycare:
    special2 LASTRESULT SPECIAL_PLAYER_PARTY_RECOUNT
    compare LASTRESULT 6
    gotoif EQUAL player_party_full
    special2 LASTRESULT SPECIAL_DAYCARE_GET_STATE
    setvar 0x8004 0
    compare LASTRESULT 2
    gotoif EQUAL remove_selected_pokemon_from_daycare
    // Two pokemon are in daycare
    special SPECIAL_DAYCARE_SELECT_POKEMON_TO_TAKE
    waitstate
    copyvar 0x8004 LASTRESULT
    compare LASTRESULT 2
    gotoif EQUAL goodbye
remove_selected_pokemon_from_daycare:
    special SPECIAL_DAYCARE_GET_AND_BUFFER_COST
    loadpointer 0 str_offer_price_for_taking_pokemon
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL goodbye
    special2 LASTRESULT SPECIAL_CHECK_MONEY
    compare LASTRESULT 1
    gotoif NOT_EQUAL not_enough_money
    applymovement 1 mov_take_pokemon
    waitmovement 0
    special2 LASTRESULT SPECIAL_DAYCARE_GET_LEVEL_OF_SELECTED_INDEX_AND_COMPACTIFY
    special SPECIAL_REMOVE_MONEY
    sound 0x58
    loadpointer 0 str_receive_pokemon
    callstd MSG_KEEPOPEN
    checksound
    cry LASTRESULT 0
    loadpointer 0 str_received_pokemon
    callstd MSG_KEEPOPEN
    copyvar 0x8012 0x8013 // No idea why...
    waitcry
    special2 LASTRESULT SPECIAL_DAYCARE_GET_STATE
    compare LASTRESULT 2
    gotoif NOT_EQUAL goodbye
    loadpointer 0 str_ask_if_second_pokemon_should_be_taken
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif EQUAL remove_pokemon_from_daycare
    goto goodbye

player_party_full:
    loadpointer 0 str_player_party_full
    callstd MSG_KEEPOPEN
    release
    end

not_enough_money:
    loadpointer 0 str_not_enough_money
    callstd MSG_KEEPOPEN
    release
    end

.ifdef LANG_GER
str_no_pokemon_in_daycare:
    .autostring 34 2 "Ich bin die Pensionsleiterin.\pMein Mann und ich ziehen hier Pokémon für Trainer auf.\pSollen wir eines deiner Pokémon in unsere Obhut nehmen?"
str_dont_raise:
    .autostring 34 2 "Oh, na gut.\nKomm jederzeit wieder, falls wir eines deiner Pokémon aufziehen sollen."
str_egg_in_daycare:
    .autostring 34 2 "Mein Mann hat dich gesucht!"
str_pokemon_doing_fine:
    .autostring 34 2 "Ach, du bist es!\pDeinen Pokémon geht es hier einfach prächtig."
str_level_gained:
    .autostring 34 2 "Dein BUFFER_1 ist um BUFFER_2 Level gewachsen."
str_ask_second_pokemon:
    .autostring 34 2 "Wir können zwei deiner Pokémon in unsere Obhut nehmen.\pMöchtest du ein weiteres Pokémon hier lassen?"
str_remove_pokemon:
    .autostring 34 2 "Möchtest du dein Pokémon wieder mitnehmen?"
str_goodbye:
    .autostring 34 2 "Gut.\nKomm bald wieder!"
str_last_pokemon:
    .autostring 34 2 "Aber du hast ja nur ein einziges Pokémon bei dir.\pWenn du das hier abgibst, kannst du nicht mehr kämpfen!"
str_select_pokemon:
    .autostring 34 2 "Welches deiner Pokémon sollen wir aufziehen?"
str_pokemon_added:
    .autostring 34 2 "Toll.\nDann nehmen wir dein BUFFER_1 eine Weile in Pflege."
str_player_party_full:
    .autostring 34 2 "Oh, aber es scheint, dass du gar keinen Platz in deinem Team hast.\pKomm wieder, wenn du Platz geschaffen hast."
str_offer_price_for_taking_pokemon:
    .autostring 34 2 "Wenn du dein BUFFER_1 wieder mitnehmen möchtest, kostet das BUFFER_2POKEDOLLAR, in Ordnung?"
str_not_enough_money:
    .autostring 34 2 "Du hast nicht genügend GeldDOTS"
str_receive_pokemon:
    .autostring 34 2 "Sehr schön.\pHier hast du dein Pokémon."
str_received_pokemon:
    .autostring 34 2 "PLAYER hat BUFFER_1 von der Pensionsleiterin zurückerhalten."
str_ask_if_second_pokemon_should_be_taken:
    .autostring 34 2 "Möchtest du das andere Pokémon auch mitnehmen?"

.elseif LANG_EN
str_no_pokemon_in_daycare:
    .autostring 34 2 "I am the daycare lady.\pMy husband and I raise Pokémon for trainers.\pShould we look after one of your Pokémon?"
str_dont_raise:
    .autostring 34 2 "Oh, fine.\pCome again if you like us to raise one of your Pokémon."
str_egg_in_daycare:
    .autostring 34 2 "My husband was looking for you!"
str_level_gained:
    .autostring 34 2 "Your BUFFER_1 has grown BUFFER_2 levels."
str_ask_second_pokemon:
    .autostring 34 2 "We can raise two of your Pokémon.\pDo you want to give us another one of your Pokémon?"
str_goodbye:
    .autostring 34 2 "Fine.\nSee you soon."
str_last_pokemon:
    .autostring 34 2 "But you only have one Pokémon with you.\pIf you leave it here, how will you battle?"
str_select_pokemon:
    .autostring 34 2 "Which of your Pokémon should we raise?"
str_pokemon_added:
    .autostring 34 2 "Nice.\nWe will take of your BUFFER_1 for a while then."
str_player_party_full:
    .autostring 34 2 "Oh, but it seems you don't have room in your party.\pCome back, once you have room in your party."
str_offer_price_for_taking_pokemon:
    .autostring 34 2 "If you want to take your BUFFER_1 that will be BUFFER_2POKEDOLLAR, ok?"
str_not_enough_money:
    .autostring 34 2 "You don't have enough moneyDOTS"
str_receive_pokemon:
    .autostring 34 2 "Very nice.\pHere you get your Pokémon back."
str_received_pokemon:
    .autostring 34 2 "PLAYER has received BUFFER_1 from the daycare lady."
str_ask_if_second_pokemon_should_be_taken:
    .autostring 34 2 "Do you want the other Pokémon as well?"
.endif

mov_take_pokemon:
    .byte PAUSE_LONG, PAUSE_LONG, LOOK_RIGHT, PAUSE_LONG, PAUSE_LONG, LOOK_LEFT, PAUSE_LONG, PAUSE_LONG, PAUSE_LONG, LOOK_UP, STEP_UP_VERY_SLOW
    .byte HIDE_SPRITE, PAUSE_LONG, PAUSE_LONG, PAUSE_LONG, PAUSE_LONG, 0, SHOW_SPRITE, STEP_DOWN_VERY_SLOW, STOP