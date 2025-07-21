.include "overworld_script.s"
.include "callstds.s"
.include "specials.s"
.include "constants/block_arguments.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"

.global ow_script_pc

ow_script_pc:
    setflag TRANS_DISABLE
    setvar 0x8004 PC_POKESTOP
    special SPECIAL_PC_ANIMATION_TURN_ON
    sound 0x4
    loadpointer 0x0 str_booted_pc
pc_main_menu:
    loadpointer 0x0 str_access_which_pc
    callstd MSG_KEEPOPEN
    special SPECIAL_PC_MAIN_MENU
    waitstate
pc_main_menu_choose:
    compare LASTRESULT 0
    gotoif EQUAL pc_pokemon_storage
    compare LASTRESULT 1
    gotoif EQUAL pc_players
    compare LASTRESULT 2
    gotoif EQUAL pc_oaks
    compare LASTRESULT 3
    gotoif EQUAL pc_hall_of_fame
    compare LASTRESULT 4
    gotoif EQUAL pc_turn_off
    compare LASTRESULT 127
    gotoif EQUAL pc_turn_off
    end

pc_pokemon_storage:
    loadpointer 0 str_access_pokemon_storage
	special SPECIAL_POKEMON_STORAGE_SYSTEM_INITIALIZE
	waitstate
	goto pc_main_menu
	end

pc_players:
	sound 2
	loadpointer 0 str_access_player_pc
	special SPECIAL_PLAYERS_PC
	waitstate
	goto pc_main_menu

pc_turn_off:
    sound 3
    setvar 0x8004 PC_POKESTOP
    special SPECIAL_PC_ANIMATION_TURN_OFF
    clearflag TRANS_DISABLE
    releaseall
    end

pc_hall_of_fame:
    loadpointer 0 str_access_hall_of_fame
    special SPECIAL_PC_HALL_OF_FAME_INITIALIZE
    waitstate
    goto pc_main_menu

pc_oaks:
    // Not a part of Violet
    goto pc_turn_off

.ifdef LANG_GER
str_booted_pc:
    .autostring 34 2 "PLAYER schaltet den PC ein."
str_access_which_pc:
    .autostring 34 2 "Auf welchen PC willst du zugreifen?"
str_access_pokemon_storage:
    .autostring 34 2 "Zugriff auf das Pokémon-Lagerumsystem.\pWas möchtest du tun?"
str_access_player_pc:
    .autostring 34 2 "Zugriff auf den PC von PLAYER.\pWas möchtest du tun?"
str_access_hall_of_fame:
    .autostring 34 2 "Zugriff auf die Ruhmeshalle."
.elseif LANG_EN
str_booted_pc:
    .autostring 34 2 "PLAYER turns on the PC."
str_access_which_pc:
    .autostring 34 2 "Which PC would you like to access?"
str_access_pokemon_storage:
    .autostring 34 2 "Accessing the Pokémon Storage System.\pWhat would you like to do?"
str_access_player_pc:
    .autostring 34 2 "Accessing PLAYER's PC.\pWhat would you like to do?"
str_access_hall_of_fame:
    .autostring 34 2 "Accessing the Hall of Fame."
.endif