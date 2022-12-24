.include "overworld_script.s"
.include "movements.s"
.include "specials.s"
.include "ordinals.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"

.global ow_script_trainerbattle_challange_spotted
.global ow_script_trainerbattle_start_battle
.global ow_script_trainerbattle_double_dont_check_enough_pokemon
.global ow_script_trainerbattle_pirate_challange
.global ow_script_trainerbattle_pirate_challange_after_approach
.global ow_script_aggresive_wild_spotted
.global ow_script_aggressive_wild_pokemon_start_battle
.global str_aggressive_wild_challange

challange_loop:
    closeonkeypress
ow_script_trainerbattle_challange_spotted:
    callasm trainer_get_current_npc_idx
    lock
    special SPECIAL_TRAINER_PLAY_ENCOUNTER_MUSIC
    special SPECIAL_TRAINER_APPROACH
    waitstate
    special SPECIAL_TRAINER_CHALLANGE_PLAYER_FACING
    waitmovement 0
    special SPECIAL_TRAINER_SHOW_CHALLANGE_MESSAGE
    waitmsg
    waitkeypress
    callasm trainer_approach_second
    compare LASTRESULT 1
    gotoif EQUAL challange_loop
    releaseall
    goto 0x081a7c86 // start the battle

ow_script_trainerbattle_double_dont_check_enough_pokemon:
    lock
    faceplayer
    call 0x081A7C74
    special2 LASTRESULT SPECIAL_CHECK_LOADED_TRAINERFLAG
    compare LASTRESULT 0
    gotoif NOT_EQUAL 0x081A7BD4
    special SPECIAL_TRAINER_PLAY_ENCOUNTER_MUSIC
    special SPECIAL_TRAINER_SETUP_NPC_MOVEMENT
    special SPECIAL_TRAINER_CHALLANGE_PLAYER_FACING
    waitmovement 0
    special SPECIAL_TRAINER_SHOW_CHALLANGE_MESSAGE
    waitmsg
    waitkeypress
    repeattrainerbattle
    endtrainerbattle
    end

ow_script_trainerbattle_pirate_challange:
    lock
    sound 0x15
    special SPECIAL_TRAINER_APPROACH
    waitstate
    special SPECIAL_TRAINER_CHALLANGE_PLAYER_FACING
ow_script_trainerbattle_pirate_challange_after_approach:
    loadpointer 0 str_0
    callstd MSG
    clearflag (FLAG_BBSHIP_PIRATE_IN_PLAYER_CELL | 0x8000) // Makes the pirate in the cell appear
    setvar VAR_BBSHIP_THROWN_INTO_CELL 2
    warp 33 0 4 0 0
    waitstate
    end

challange_loop_aggresive_wild:
    closeonkeypress
ow_script_aggresive_wild_spotted:
    callasm trainer_get_current_npc_idx
    copyvar 0x8004 LASTTALKED
    special SPECIAL_NPC_DELETE_RAGE_SPRITE
    lock
    special SPECIAL_TRAINER_APPROACH
    waitstate
    special SPECIAL_TRAINER_CHALLANGE_PLAYER_FACING
    waitmovement 0
    special2 LASTRESULT SPECIAL_AGGRESSIVE_WILD_GET_APPROACHING_SPECIES
    bufferpokemon 0 LASTRESULT
    cry LASTRESULT 0
    loadpointer 0 str_aggressive_wild_challange
    callstd MSG_KEEPOPEN
    waitcry
    callasm trainer_approach_second
    compare LASTRESULT 1
    gotoif EQUAL challange_loop_aggresive_wild
    releaseall
ow_script_aggressive_wild_pokemon_start_battle:
    // Start the wild battle
	setflag FLAG_IN_BATTLE
	callasm battle_initialize_aggressive_wild 
	clearflag FLAG_IN_BATTLE
	waitstate
    fadescreen 1
    callasm aggressive_wild_hidesprites_after_battle
    fadescreen 0
    releaseall
    end



.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hey, was treibst du denn hier?\pDu solltest doch in deiner Zelle sein!\pDir werd ich helfen, du Rotzlöffel!"
str_aggressive_wild_challange:
    .autostring 34 2 "BUFFER_1!"
.elseif LANG_EN

.endif