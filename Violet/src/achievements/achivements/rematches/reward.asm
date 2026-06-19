.include "overworld_script.s"
.include "items.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_achievement_rematches_10_reward
.global ow_script_achievement_rematches_50_reward
.global ow_script_achievement_rematches_100_reward

ow_script_achievement_rematches_10_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_rematches_achievement_10_reward
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_REMATCHES_ACHIEVEMENT_10_REWARD
    goto ow_script_end_achievement_reward

ow_script_achievement_rematches_50_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_rematches_achievement_50_reward
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_REMATCHES_ACHIEVEMENT_50_REWARD
    goto ow_script_end_achievement_reward   

ow_script_achievement_rematches_100_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_rematches_achievement_100_reward
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_REMATCHES_ACHIEVEMENT_100_REWARD
    goto ow_script_end_achievement_reward

.ifdef LANG_GER
str_rematches_achievement_10_reward:
    .autostring 34 2 "Trainer sind nun häufiger bereit, sich täglich für einen Rückkampf zu entscheiden."
str_rematches_achievement_100_reward:
    .autostring 34 2 "In Rückkämpfen erhalten deine Pokémon nun mehr Erfahrungspunkte und Fleiß Punkte."
str_rematches_achievement_50_reward:
    .autostring 34 2 "Trainer zeigen nun an, ob sie bereit für einen Rückkampf sind, ohne dass du die Kampffahnder-App verwenden musst."
.elseif LANG_EN
str_rematches_achievement_10_reward:
    .autostring 34 2 "Trainers are now more likely to accept a rematch on a daily basis."
str_rematches_achievement_100_reward:
    .autostring 34 2 "Your Pokémon now receive more experience points and effort points from rematches."
str_rematches_achievement_50_reward:
    .autostring 34 2 "Trainers now indicate whether they are willing to have a rematch without you having to use the VS Seeker app."
.endif
