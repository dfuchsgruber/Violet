.include "overworld_script.s"
.include "items.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "achievement.s"

.global ow_script_achievement_pokedex_catch_5_reward
.global ow_script_achievement_pokedex_catch_20_reward
.global ow_script_achievement_pokedex_catch_50_reward
.global ow_script_achievement_pokedex_catch_100_reward
.global ow_script_achievement_pokedex_catch_150_reward
.global ow_script_achievement_pokedex_catch_all_rerward

ow_script_achievement_pokedex_catch_all_rerward:
    copyvarifnotzero 0x8000 ITEM_SCHILLERPIN
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    setflag FLAG_SCHILLERPIN
    goto ow_script_end_achievement_reward

ow_script_achievement_pokedex_catch_5_reward:
    @copyvarifnotzero 0x8000 ITEM_POKEBALL
    @copyvarifnotzero 0x8001 1
    @callstd ITEM_OBTAIN
    @gotoif EQUAL no_room_for_giveitem
    @setflag FLAG_POKEDEX_ACHIVEMENT_CATCH_5_REWARD
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_catching_gives_exp
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_CATCHING_GIVES_EXP
    goto ow_script_end_achievement_reward

ow_script_achievement_pokedex_catch_20_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_added_pokeradar_app
    callstd MSG_KEEPOPEN
    waitfanfare
    setflag POKERADAR
    loadpointer 0 str_explain_pokeradar
    callstd MSG_KEEPOPEN
    closeonkeypress
    achievement_unlocked ACHIEVEMENT_POKERADAR
    goto ow_script_end_achievement_reward


ow_script_achievement_pokedex_catch_50_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_increased_catch_rate
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_INCREASED_CATCH_RATE
    goto ow_script_end_achievement_reward


ow_script_achievement_pokedex_catch_100_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_pokedex_scanner
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_POKEDEX_SCANNER
    goto ow_script_end_achievement_reward

ow_script_achievement_pokedex_catch_150_reward:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_rare_pokemon_more_likely
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_RARE_POKEMON_MORE_LIKELY
    goto ow_script_end_achievement_reward

.ifdef LANG_GER
str_added_pokeradar_app:
    .autostring 34 2 "Deinem Pokepad wurde die Pokeradar-App hinzugefügt!"
str_catching_gives_exp:
    .autostring 34 2 "Das Fangen von Pokémon gibt nun Erfahrungspunkte!"
str_increased_catch_rate:
    .autostring 34 2 "Die Fangrate wurde erhöht!"
str_rare_pokemon_more_likely:
    .autostring 34 2 "Seltene wilde Pokémon sind nun häufiger anzutreffen!"
str_explain_pokeradar:
    .autostring 34 2 "Der Pokeradar spürt seltene Pokémon in deiner Umgebung auf!"
str_pokedex_scanner:
    .autostring 34 2 "Das Scanner-Feature wurde in der Pokédex-App installiert!\pEs zeigt alle Pokémon in deiner Nähe an."
.elseif LANG_EN
str_added_pokeradar_app:
    .autostring 34 2 "The Pokeradar app has been added to your Pokepad!"
str_catching_gives_exp:
    .autostring 34 2 "Catching Pokémon now gives experience points!"
str_increased_catch_rate:
    .autostring 34 2 "The catch rate has been increased!"
str_rare_pokemon_more_likely:
    .autostring 34 2 "Rare wild Pokémon are now more likely to appear!"
str_explain_pokeradar:
    .autostring 34 2 "The Pokeradar detects rare Pokémon in your area!"
str_pokedex_scanner:
    .autostring 34 2 "The scanner feature has been installed in the Pokédex app!\pIt shows all Pokémon in your vicinity."
.endif