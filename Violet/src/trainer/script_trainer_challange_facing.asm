.include "overworld_script.s"
.include "constants/vars.s"
.include "constants/movements.s"
.include "constants/specials.s"
.include "constants/ordinals.s"

.global ow_script_trainerbattle_challange_spotted
.global ow_script_trainerbattle_start_battle
.global ow_script_trainerbattle_double_dont_check_enough_pokemon

challange_loop:
    closeonkeypress
ow_script_trainerbattle_challange_spotted:
    callasm trainer_get_current_npc_idx
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
