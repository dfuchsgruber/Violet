.include "overworld_script.s"
.include "items.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "achievement.s"
.include "species.s"

.global ow_script_achievement_wondertrade_5_reward
.global ow_script_achievement_wondertrade_25_reward
.global ow_script_achievement_wondertrade_100_reward

ow_script_achievement_wondertrade_5_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_wondertrade_5_reward
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_WONDERTRADE_CHARGING_STEPS_REDUCED
    goto ow_script_end_achievement_reward

ow_script_achievement_wondertrade_25_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_wondertrade_25_reward
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_WONDERTRADE_REPLACE_CAUGHT_POKEMON
    goto ow_script_end_achievement_reward

ow_script_achievement_wondertrade_100_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_wondertrade_100_reward
    callstd MSG_KEEPOPEN
    callasm wondertrade_give_mew
    compare LASTRESULT 0x2
    gotoif EQUAL skip_set_reward_flag
    bufferpokemon 0 POKEMON_MEW
    call ow_script_set_nickname
    setflag WONDERTRADE_MEW_RECEIVED
skip_set_reward_flag:
    goto ow_script_end_achievement_reward


.ifdef LANG_GER
str_wondertrade_5_reward:
    .autostring 34 2 "Die Anzahl der Schritte, die zum Aufladen des Wundertauschs benötigt werden, wurde reduziert!"
str_wondertrade_25_reward:
    .autostring 34 2 "Pokémon, die du bereits im Pokédex registriert hast, werden seltener im Wundertausch auftauchen!"
str_wondertrade_100_reward:
    .autostring 34 2 "Du hast ein Mew erhalten!"
.elseif LANG_EN
str_wondertrade_5_reward:
    .autostring 34 2 "The number of steps required to charge Wonder Trade has been reduced!"
str_wondertrade_25_reward:
    .autostring 34 2 "Pokémon you've already registered in the Pokédex will be less likely to appear in Wonder Trade!"
str_wondertrade_100_reward:
    .autostring 34 2 "You received a Mew!"
.endif