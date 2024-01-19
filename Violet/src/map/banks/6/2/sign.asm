.include "overworld_script.s"
.include "callstds.s"
.include "specials.s"
.include "songs.s"

.global ow_script_aktania_city_gym_statue

ow_script_aktania_city_gym_statue:
    loadpointer 0 str_statue
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_statue:
    .autostring 34 2 "Antikarena.\nArenaleiterin: Lester."
.elseif LANG_EN
str_statue:
    .autostring 34 2 "Relic Gym.\pGym Leader: Lester."
.endif
