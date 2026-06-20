.include "overworld_script.s"
.include "items.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "achievement.s"

.global ow_script_achievement_fishing_5_reward
.global ow_script_achievement_fishing_20_reward
.global ow_script_achievement_fishing_50_reward
.global ow_script_achievement_fishing_100_reward

ow_script_achievement_fishing_5_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_bite_frequently
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_FISHING_REWARD_5
    goto ow_script_end_achievement_reward

ow_script_achievement_fishing_20_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_hooked_easier
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_FISHING_REWARD_20
    goto ow_script_end_achievement_reward

ow_script_achievement_fishing_50_reward:
    copyvarifnotzero 0x8000 ITEM_LOTUS_KOEDER
    copyvarifnotzero 0x8001 5
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL no_room_for_item
    setflag FLAG_FISHING_REWARD_50
no_room_for_item:
    goto ow_script_end_achievement_reward

ow_script_achievement_fishing_100_reward:
    copyvarifnotzero 0x8000 ITEM_LEUCHTKOEDER
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL no_room_for_item_100
    setflag FLAG_FISHING_REWARD_100
no_room_for_item_100:
    goto ow_script_end_achievement_reward

.ifdef LANG_GER
str_bite_frequently:
    .autostring 34 2 "Pokémon beißen nun beim Angeln schneller und öfter an."
str_hooked_easier:
    .autostring 34 2 "Pokémon sind nun beim Angeln schneller am Haken."
.elseif LANG_EN
str_bite_frequently:
    .autostring 34 2 "Pokémon now bite faster and more often when fishing."
str_hooked_easier:
    .autostring 34 2 "Pokémon are now hooked faster when fishing."
.endif
