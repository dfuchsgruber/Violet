.include "overworld_script.s"
.include "items.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "achievement.s"
.include "species.s"

.global ow_script_achievement_breeding_1_reward
.global ow_script_achievement_breeding_3_reward
.global ow_script_achievement_breeding_10_reward
.global ow_script_achievement_breeding_20_reward
.global ow_script_achievement_breeding_50_reward

ow_script_achievement_breeding_1_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_breeding_1_reward
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_INCUBATOR
    goto ow_script_end_achievement_reward

ow_script_achievement_breeding_3_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_breeding_3_reward
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_INCUBATOR_ADDITIONAL_SLOT_1
    goto ow_script_end_achievement_reward

ow_script_achievement_breeding_10_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_breeding_10_reward
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_EGGS_HATCH_FASTER
    goto ow_script_end_achievement_reward

ow_script_achievement_breeding_20_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_breeding_20_reward
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_INCUBATOR_ADDITIONAL_SLOT_2
    goto ow_script_end_achievement_reward   

ow_script_achievement_breeding_50_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_breeding_50_reward
    callstd MSG_KEEPOPEN
    waitfanfare
    setflag FLAG_EGGS_IMPROVED_FEATURE_GENERATOR
    closeonkeypress
    goto ow_script_end_achievement_reward

.ifdef LANG_GER
str_breeding_1_reward:
    .autostring 34 2 "Die Inkubator-App wurde auf deinem Poképad installiert!"
str_breeding_3_reward:
    .autostring 34 2 "Du kannst jetzt 2 Pokémon gleichzeitig im Inkubator ausbrüten!"
str_breeding_10_reward:
    .autostring 34 2 "Pokémon-Eier schlüpfen jetzt schneller!"
str_breeding_20_reward:
    .autostring 34 2 "Du kannst jetzt 3 Pokémon gleichzeitig im Inkubator ausbrüten!"
str_breeding_50_reward:
    .autostring 34 2 "Pokémon, die aus einem Ei schlüpfen, sind nun stärker!"
.elseif LANG_EN
str_breeding_1_reward:
    .autostring 34 2 "The Incubator-App has been installed on your Poképad!"
str_breeding_3_reward:
    .autostring 34 2 "You can now incubate 2 Pokémon at the same time in the Incubator!"
str_breeding_10_reward:
    .autostring 34 2 "Pokémon eggs now hatch faster!"
str_breeding_20_reward:
    .autostring 34 2 "You can now incubate 3 Pokémon at the same time in the Incubator!"
str_breeding_50_reward:
    .autostring 34 2 "Pokémon that hatch from eggs are now stronger!"
.endif
