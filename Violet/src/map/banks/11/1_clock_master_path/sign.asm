.include "callstds.s"
.include "overworld_script.s"

.global ow_script_pokemon_spotter_sign

ow_script_pokemon_spotter_sign:
	loadpointer 0 str
	callstd MSG_SIGN
	end

.ifdef LANG_GER
str:
	.autostring 34 2 "Haus des Pokémon-Beobachters"
.elseif LANG_EN
str:
	.autostring 34 2 "Pokémon Spotter's House"
.endif