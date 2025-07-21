.include "overworld_script.s"
.include "vars.s"
.include "callstds.s"

.global ow_script_pokemon_center_sign
.global ow_script_trash

ow_script_pokemon_center_sign:
    loadpointer 0 str_pokemon_center_sign
    callstd MSG_SIGN
    end

ow_script_trash:
	loadpointer 0 str_trash_empty
	callstd MSG_SIGN
	end

.ifdef LANG_GER
	str_trash_empty:
		.autostring 34 2 "Der Mülleimer ist leer."
	str_pokemon_center_sign:
		.autostring 34 2 "Pokéstops!\nAlles für Trainer und Pokémon."
.elseif LANG_EN
	str_trash_empty:
		.autostring 34 2 "The trash can is empty."
	str_pokemon_center_sign:
    	.autostring 34 2 "Poké Centers!\nEverything for Trainers and Pokémon."
.endif