.include "battlescript.s"
.include "battle/battle_flags.s"
.include "battle/battle_positions.s"
.include "battle/battle_animations.s"
.include "battle/battle_communication.s"
.include "battle/battle_statuses.s"
.include "battle/bsc_status_flags.s"
.include "pokemon_stat_names.s"

.global bsc_life_orb

bsc_life_orb:
    orword bsc_status_flags 0x100100
    graphicalhpupdate 0x1
    datahpupdate 0x1
    printstring 0x183
    waitmessage 0x40
    faintpokemon BANK_USER 0x0, 0
    return

.global bsc_gunpowder

bsc_gunpowder:
    printstring 0x1af
    playanimation BANK_TARGET BATTLE_ANIM_GUNPOWDER 0
    orword bsc_status_flags 0x100100
    graphicalhpupdate 0x0
    datahpupdate 0x0
    faintpokemon BANK_TARGET 0x0 0,
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

.global bsc_energiequarz

bsc_energiequarz:
    printstring 0x1be
    playanimation BANK_SCRIPTING BATTLE_ANIM_ITEM_EFFECT 0
	statbuffchange 0x41, .+4
    setbyte battle_communication + BATTLE_COMMUNICATION_MULTISTRING_CHOOSER, 4
    call bsc_stat_up
    removeitem BANK_SCRIPTING
    end3

.global bsc_beulenhelm

bsc_beulenhelm:
    orword bsc_status_flags, (BSC_STATUS_FLAG_IGNORE_SUBSTITUTE | BSC_STATUS_FLAG_PASSIVE_DAMAGE)
    graphicalhpupdate 0x1
    datahpupdate 0x1
    printstring 0x1c3
    waitmessage 0x40
    faintpokemon BANK_USER, 0x0, 0
    return

.global bsc_deal_damage_by_item_end2

bsc_deal_damage_by_item_end2:
    printstring 0x1c6
	waitmessage 0x40
	orword bsc_status_flags, BSC_STATUS_FLAG_IGNORE_SUBSTITUTE
	graphicalhpupdate BANK_USER
	datahpupdate BANK_USER
	end2

.global bsc_status_orb

bsc_status_orb:
    playanimation BANK_USER BATTLE_ANIM_ITEM_EFFECT 0
    seteffectsecondary
    end2

.global bsc_attack_disabled_by_assault_vest

bsc_attack_disabled_by_assault_vest:
    printselectionstring 0x1c7
	endselectionscript

.global bsc_weakness_policy

bsc_weakness_policy:
    playanimation BANK_TARGET BATTLE_ANIM_ITEM_EFFECT 0
    printstring 0x1c8
	waitmessage 0x40
	setbyte battle_scripting + 0x1B, 0
	playstatchangeanimation BANK_TARGET, ((1 << STAT_ATTACK) | (1 << STAT_SPECIAL_ATTACK)), 0
	setstatchange STAT_ATTACK, 2, 0
    statbuffchange (STAT_BUF_CHANGE_FAILURE_CONTINUATION | STAT_BUF_CHANGE_AFFECTS_TARGET), weakness_policy_raise_spatk
	jumpifbyte EQUAL, battle_communication + BATTLE_COMMUNICATION_MULTISTRING_CHOOSER, 2, weakness_policy_raise_spatk
	printfromtable battle_strings_stat_changes
	waitmessage 0x40
weakness_policy_raise_spatk:
	setstatchange STAT_SPECIAL_ATTACK, 2, 0
    statbuffchange (STAT_BUF_CHANGE_FAILURE_CONTINUATION | STAT_BUF_CHANGE_AFFECTS_TARGET), weakness_policy_end
	jumpifbyte EQUAL, battle_communication + BATTLE_COMMUNICATION_MULTISTRING_CHOOSER, 2, weakness_policy_end
	printfromtable battle_strings_stat_changes
	waitmessage 0x40
weakness_policy_end:
    removeitem BANK_TARGET
    return
