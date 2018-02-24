.include "overworld_script.s"
.include "std.s"

.global ow_script_person_test

ow_script_person_test:
    givepokemon POKEMON_FORMEO 20 0 0 0 0
    @//setflag POKEDEX_FEATURE_0
    @//setflag POKEDEX_FEATURE_1
    @//setflag POKEDEX_FEATURE_2
    end