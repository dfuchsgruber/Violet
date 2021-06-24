.include "vars.s"
.include "movements.s"
.include "specials.s"
.include "songs.s"
.include "callstds.s"
.include "flags.s"
.include "roamers.s"
.include "overworld_script.s"
.include "species.s"

.global ow_script_power_plant_zapdos

ow_script_power_plant_zapdos:
    lockall
    applymovement 0xff mov_fu
    waitmovement 0x0
    cry POKEMON_ZAPDOS 0x0
    fadesong 0
    pause 0x40
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    applymovement 0x7f mov_6u
    waitmovement 0x0
    showpokepic POKEMON_ZAPDOS 0x8 0x2
    loadpointer 0x0 str_growl_0
    callstd MSG
    hidepokepic
    call move_down_with_flap_sound
    call move_down_with_flap_sound
    call move_down_with_flap_sound
    call move_down_with_flap_sound
    call move_down_with_flap_sound
    call move_down_with_flap_sound
    cry POKEMON_ZAPDOS 0x0
    showpokepic POKEMON_ZAPDOS 0x8 0x2
    loadpointer 0x0 str_growl_1
    callstd MSG
    hidepokepic
    pause 0x40
    sound 0x80
    applymovement 1 mov_fly_away
    waitmovement 0x0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    setvar 0x8004 POKEMON_ZAPDOS
    special SPECIAL_SET_AS_SEEN
    setvar 0x8004 ROAMER_ZAPDOS
    special SPECIAL_ROAMER_RESET_AND_INITIALIZE
    hidesprite 1
    setvar VAR_POWER_PLANT_ZAPDOS 0x1
    playsong MUS_ROUTE_24_25 0x0
    releaseall
    end

move_down_with_flap_sound:
    sound 0x96
    applymovement 0x7f mov_step_down_very_slow
    applymovement 1 mov_step_down_very_slow
    waitmovement 0x0
    return

mov_fly_away:
    .byte 0xa4, STOP

mov_step_down_very_slow:
    .byte STEP_DOWN_VERY_SLOW, STOP

.ifdef LANG_GER
str_growl_0:
    .autostring 34 2 "Kyekyekye!"
str_growl_1:
    .autostring 34 2 "Kyekye! Kyekyekye!"
.elseif LANG_EN
.endif
