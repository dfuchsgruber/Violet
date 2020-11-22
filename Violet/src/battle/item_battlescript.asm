.include "battlescript.s"
.include "battle/battle_flags.s"
.include "battle/battle_positions.s"
.include "battle/battle_animations.s"
.include "battle/battle_communication.s"
.include "battle/battle_statuses.s"


.global bsc_life_orb

bsc_life_orb:
    orword bsc_status_flags 0x100100
    graphicalhpupdate 0x1
    datahpupdate 0x1
    printstring 0x183
    waitmessage 0x40
    faintpokemon 0x1 0x0 0x8000000
    return

.global bsc_gunpowder

bsc_gunpowder:
    printstring 0x1af
    playanimation BANK_TARGET BATTLE_ANIM_GUNPOWDER 0
    orword bsc_status_flags 0x100100
    graphicalhpupdate 0x0
    datahpupdate 0x0
    faintpokemon 0x0 0x0 0x8000000
    return

.global bsc_blizzard_egg

bsc_blizzard_egg:
    printstring 0xe3 // clear box
    playanimation BANK_SCRIPTING BATTLE_ANIM_WEATHER_EGG 0
    printstring 0x1bc
    playanimation BANK_SCRIPTING BATTLE_ANIM_HAIL_CONTINUES 0
    waitmessage 0x40
    removeitem BANK_SCRIPTING
    end3

.global bsc_desert_egg

bsc_desert_egg:
    printstring 0xe3 // clear box
    playanimation BANK_SCRIPTING BATTLE_ANIM_WEATHER_EGG 0
    printstring 0x1bd
    playanimation BANK_SCRIPTING BATTLE_ANIM_SANDSTORM_CONTINUES 0
    waitmessage 0x40
    removeitem BANK_SCRIPTING
    end3

.global bsc_sun_egg

bsc_sun_egg:
    printstring 0xe3 // clear box
    playanimation BANK_SCRIPTING BATTLE_ANIM_WEATHER_EGG 0
    printstring 0x1ba
    playanimation BANK_SCRIPTING BATTLE_ANIM_SUN_CONTINUES 0
    waitmessage 0x40
    removeitem BANK_SCRIPTING
    end3

.global bsc_storm_egg

bsc_storm_egg:
    printstring 0xe3 // clear box
    playanimation BANK_SCRIPTING BATTLE_ANIM_WEATHER_EGG 0
    printstring 0x1bb
    playanimation BANK_SCRIPTING BATTLE_ANIM_RAIN_CONTINUES 0
    waitmessage 0x40
    removeitem BANK_SCRIPTING
    end3