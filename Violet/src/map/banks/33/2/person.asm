.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "specials.s"

.global ow_script_blackbeard_ship_storage_player_party

ow_script_blackbeard_ship_storage_player_party:
    lockall
    checksound 
    hidesprite 8
    fanfare 0x13E
    loadpointer 0 str_0
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    clearflag FLAG_PLAYER_PARTY_STOLEN
    setflag PKMNMENU
    setflag POKEDEX
    callasm player_pokemon_recount_pokemon
    special SPECIAL_HEAL
    releaseall
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "PLAYER erhält seine Pokémon und das Poképad zurück!"
.elseif LANG_EN
.endif