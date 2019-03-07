.include "flags.s"

.global pokepad_items

.align 4
pokepad_items:
    .word items

.align 4
items:
    //Wondertrade
    .word 0x915
    .word str_pokepad_wondertrade
    .word wondertrade_init //should be initilaizer func
    .word str_pokepad_wondertrade_desc //should be descr
    //Pokedex
    .word 0x829
    .word str_pokepad_pokedex
    .word pokedex_init //should be initilaizer func
    .word str_pokepad_pokedex_desc //should be descr
    //Pokeradar
    .word 0x23c
    .word str_pokepad_pokeradar
    .word pokeradar_init //should be initilaizer func
    .word str_pokepad_pokeradar_desc //should be descr
    // Incubator
    .word 0x828//FLAG_INCUBATOR
    .word str_pokepad_incubator
    .word incubator_initialize
    .word str_pokepad_incubator_desc
    
    .word 0xFFFF
    .word 0
    .word 0
    .word 0

.ifdef LANG_GER
.global str_pokepad_description
	str_pokepad_description:
		.string "Nutze verschiedene Apps, die auf\ndem Poképad installiert wurden."

	str_pokepad_wondertrade:
		.string "Wundertausch"

	str_pokepad_wondertrade_desc:
		.string "Tausche Pokémon mit Trainern\naus aller Welt."

	str_pokepad_pokedex:
		.string "Pokédex"

	str_pokepad_pokedex_desc:
		.string "Betrachte Aufzeichnungen zu gefangenen\nund gesehenen Pokémon."

	str_pokepad_pokeradar:
		.string "Pokéradar"

	str_pokepad_pokeradar_desc:
		.string "Spüre seltene Pokémon in der\nNähe auf."

	str_pokepad_incubator:
		.string "Inkubator"

	str_pokepad_incubator_desc:
		.string "Brüte Eier aus und überprüfe\nderen Status."

.elseif LANG_EN

.global str_pokepad_description
	str_pokepad_description:
		.string "Use the various apps that were\ninstalled for the Poképad."

	str_pokepad_wondertrade:
		.string "Wondertrade"

	str_pokepad_wondertrade_desc:
		.string "Trade your Pokémon with\ntrainers worldwide."

	str_pokepad_pokedex:
		.string "Pokédex"

	str_pokepad_pokedex_desc:
		.string "View your records of caught and\nseen Pokémon."

	str_pokepad_pokeradar:
		.string "Pokéradar"

	str_pokepad_pokeradar_desc:
		.string "Traces rare Pokémon\nnearby."

	str_pokepad_incubator:
		.string "Incubator"

	str_pokepad_incubator_desc:
		.string "Hatch eggs and check their status."
.endif
