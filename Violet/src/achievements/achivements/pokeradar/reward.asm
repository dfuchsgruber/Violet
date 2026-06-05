.include "overworld_script.s"
.include "items.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_achievement_pokeradar_catch_5_reward
.global ow_script_achievement_pokeradar_catch_20_reward
.global ow_script_achievement_pokeradar_catch_50_reward
.global ow_script_achievement_pokeradar_catch_100_reward

ow_script_achievement_pokeradar_catch_5_reward:
    copyvarifnotzero 0x8000 ITEM_SONDERBONBON
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    setflag FLAG_POKERADAR_REWARD_5
    goto ow_script_end_achievement_reward

ow_script_achievement_pokeradar_catch_20_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_pokeradar_pokemon_dont_flee
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_POKERADAR_POKEMON_DONT_FLEE
    goto ow_script_end_achievement_reward

ow_script_achievement_pokeradar_catch_50_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_pokeradar_pokemon_dont_spot_player
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_POKERADAR_POKEMON_DONT_SPOT_PLAYER
    goto ow_script_end_achievement_reward


ow_script_achievement_pokeradar_catch_100_reward:
    copyvarifnotzero 0x8000 ITEM_GOLDBONBON
    copyvarifnotzero 0x8001 3
    callstd ITEM_OBTAIN
    setflag FLAG_POKERADAR_REWARD_100
    goto ow_script_end_achievement_reward

.ifdef LANG_GER
str_pokeradar_pokemon_dont_flee:
    .autostring 34 2 "Pokémon, die mit dem Pokéradar aufgespürt werden, fliehen im Kampf nicht länger."
str_pokeradar_pokemon_dont_spot_player:
    .autostring 34 2 "Pokémon, die mit dem Pokéradar aufgespürt werden, entdecken den Spieler nicht mehr, wenn dieser sich anschleicht."
.elseif LANG_EN
str_pokeradar_pokemon_dont_flee:
    .autostring 34 2 "Pokéradar Pokémon no longer flee in battle."
str_pokeradar_pokemon_dont_spot_player:
    .autostring 34 2 "Pokéradar Pokémon no longer spot the player when sneaking up on them."
.endif