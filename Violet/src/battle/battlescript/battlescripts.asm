.include "battlescript.s"
.include "constants/battle/battle_flags.s"
.include "constants/battle/battle_positions.s"
.include "constants/battle/battle_animations.s"
.include "constants/battle/battle_communication.s"
.include "constants/battle/battle_statuses.s"

.global battlescript_trainer_battle_won
battlescript_trainer_battle_won:
    jumpifword COMMON_BITS battle_flags BATTLE_TWO_TRAINERS print_won_against_two_trainers
    printstring 0x141 // First trainer beaten
    goto after_trainer_battle_won_printstring
print_won_against_two_trainers:
    printstring 0x1A0
after_trainer_battle_won_printstring:

    trainerslidein BATTLE_POSITION_OPPONENT_LEFT
    waitstate
    printstring 0xC // Trainer defeat text
    jumpifword NO_COMMON_BITS battle_flags BATTLE_TWO_TRAINERS _pricemoney
    trainerslideout BATTLE_POSITION_OPPONENT_LEFT
    waitstate
    trainerslidein BATTLE_POSITION_OPPONENT_RIGHT
    waitstate
    printstring 0x1A1 // TrainerB defeat text
_pricemoney:
    pricemoney .+4
    printstring 0x1E
    waitmessage 0x40
    // Second trainer
    goto battlescript_payday_money_and_pickup

.global battlescript_itemdrop
.global battlescript_itemdrop_picked_up
.global battlescript_itemdrop_picked_up_no_space

battlescript_itemdrop:
    printstring 0x1b2
    playanimation BANK_SCRIPTING BATTLE_ANIM_ITEM_DROP 0
    waitanimation
    return

battlescript_itemdrop_picked_up:
    pause 8
    printstring 0x1b3
    waitmessage 0x40
    return

battlescript_itemdrop_picked_up_no_space:
    pause 8
    printstring 0x1b3
    printstring 0x1b4
    waitmessage 0x40
    return


.global battlescript_handicap_extreme_heat

battlescript_handicap_extreme_heat:
    playanimation BANK_SCRIPTING BATTLE_ANIM_EXTREME_HEAT_INTRODUCTION 0
    printstring 0x1A2
    waitmessage 64
    end3

.global battlescript_handicap_extreme_heat_apply

battlescript_handicap_extreme_heat_apply:
    playanimation BANK_SCRIPTING BATTLE_ANIM_EXTREME_HEAT 0
    printstring 0x1a3
    waitmessage 64
    call battlescript_apply_status1
    end3


.global battlescript_handicap_floating_rocks

battlescript_handicap_floating_rocks:
    playanimation BANK_TARGET BATTLE_ANIM_FLOATING_ROCKS_INTRODUCTION 0
    printstring 0x1a4
    waitmessage 64
    end3

.global battlescript_handicap_floating_rocks_apply

battlescript_handicap_floating_rocks_apply:
    printstring 0x1a5
    playanimation BANK_TARGET BATTLE_ANIM_FLOATING_ROCKS 0
    return

.global battlescript_handicap_grassy_field

battlescript_handicap_grassy_field:
    printstring 0x1a6
    playanimation BANK_TARGET BATTLE_ANIM_GRASSY_FIELD_INTRODUCTION 0
    end3

.global battlescript_handicap_grassy_field_apply

battlescript_handicap_grassy_field_apply:
    printstring 0x1a7
    playanimation BANK_TARGET BATTLE_ANIM_GRASSY_FIELD 0
    end3

.global battlescript_handicap_terrifying_atmosphere

battlescript_handicap_terrifying_atmosphere:
    printstring 0x1a8
    playanimation BANK_TARGET BATTLE_ANIM_TERRIFYING_ATMOSPHERE_INTRODUCTION 0
    end3

.global battlescript_handicap_terrifying_atmosphere_apply

battlescript_handicap_terrifying_atmosphere_apply:
    ppreduce
    printstring 0x1a9
    playanimation BANK_USER BATTLE_ANIM_TERRIFYING_ATMOSPHERE 0
    goto 0x81DABDE

.global battlescript_handicap_arena_encouragement

battlescript_handicap_arena_encouragement:
    printstring 0x1aa
    playanimation BANK_TARGET BATTLE_ANIM_ARENA_ENCOURAGEMENT_INTRODUCTION 0
    end3

.global battlescript_handicap_arena_encouragement_apply

battlescript_handicap_arena_encouragement_apply:
    printstring 0x1ab
    playanimation BANK_USER BATTLE_ANIM_ARENA_ENCOURAGEMENT 0
    printstring 0x1ac
    waitmessage 40
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0xF | MOVE_EFFECT_AFFECTS_USER
    seteffectprimary
    end3

.global battlescript_handicap_groudon_magnitude

battlescript_handicap_groudon_magnitude:
    printstring 0x1ad
    playanimation BANK_USER BATTLE_ANIM_GROUDON_MAGNITUDE 0
    waitmessage 20
    end3


.global battlescript_handicap_groudon_magnitude_hit

battlescript_handicap_groudon_magnitude_hit:
    printstring 0x1ae
    waitmessage 0x40
    // Basically what happens is the magintude attack, skipping some things
    selectnexttarget
    callasm battle_handicap_groudon_calculate_damage
    printstring 0x9a
    waitmessage 0x40
groudon_magnitude_loop:
    movevaluescleanup
    jumpifstatus3 BANK_TARGET STATUS3_UNDERGROUND 1 groudon_magnitude_not_underground
    orword bsc_status_flags 0x20000
    setbyte battle_scripting + 0xE, 2 // Multiplier is 2
    goto groudon_magnitude_hit
groudon_magnitude_not_underground:
    bicword bsc_status_flags 0x20000
    setbyte battle_scripting + 0xE, 1 // Multiplier is 2
groudon_magnitude_hit:
    // No accuracy or critcalc
    damagecalc
    typecalc
    adjustnormaldamage
    // playanimation BANK_USER BATTLE_ANIM_GROUDON_MAGNITUDE 0 // Instead of attack animation
    attackanimation
    waitanimation
    missmessage
    hitanimation BANK_TARGET
    waitstate
    graphicalhpupdate BANK_TARGET
    datahpupdate BANK_TARGET
    critmessage
    waitmessage 0x40
    resultmessage
    waitmessage 0x40
    printstring 0xe3 // ""
    waitmessage 1
    faintpokemon BANK_TARGET, 0, 0
    // No move done effects
    jumpwhiletargetvalid groudon_magnitude_loop
    end2

.global battlescript_before_attack

battlescript_before_attack: // Triggers effects before attack
    beforeattack
    return


.global battlescript_introduce_aggresive_battler

battlescript_introduce_aggresive_battler:
    printstring 0x1b5
    playanimation BANK_USER BATTLE_ANIM_POKEMON_IS_AGGRESIVE 0
    waitmessage 0x40
    waitanimation
    end3

.global battlescript_gem_used

battlescript_gem_used:
    playanimation BANK_USER BATTLE_ANIM_ITEM_EFFECT 0
    printstring 0x1b6
    waitmessage 0x40
    removeitem BANK_USER
    return
