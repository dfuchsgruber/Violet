.include "flags.s"
.include "species.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_person_test

ow_script_person_test:
	additem ITEM_SONDERBONBON 99
    givepokemon POKEMON_FORMEO 20 0 0 0 0
    @//setflag POKEDEX_FEATURE_0
    @//setflag POKEDEX_FEATURE_1
    @//setflag POKEDEX_FEATURE_2
    end
