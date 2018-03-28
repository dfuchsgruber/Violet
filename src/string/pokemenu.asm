.ifdef LANG_GER
.global str_pokemon

str_pokemon:
	.string "Pokémon"


.global str_menu_pokemon_desc

str_menu_pokemon_desc:
	.string "Überprüfe und organisiere die Pokémon,\ndie sich in deinem Team befinden."


.global str_bericht

str_bericht:
	.string "Bericht"


.global str_tausch

str_tausch:
	.string "Tausch"


.global str_geben

str_geben:
	.string "Geben"


.global str_nehmen

str_nehmen:
	.string "Nehmen"


.global str_aussenden

str_aussenden:
	.string "Aussenden"


.global str_eintragen

str_eintragen:
	.string "Eintragen"


.global str_austragen

str_austragen:
	.string "Austragen"


.global str_wahlen

str_wahlen:
	.string "Wählen"


.global str_choose_pokemon

str_choose_pokemon:
	.string "Wähle ein Pokémon."


.global str_choose_pkmn_or_back

str_choose_pkmn_or_back:
	.string "Wähle PKMN oder zurück."


.elseif LANG_EN
	.global str_pokemon

	str_pokemon:
		.string "Pokémon"

	.global str_menu_pokemon_desc

	str_menu_pokemon_desc:
		.string "Check and organize the Pokémon in your\nparty."

	.global str_bericht

	str_bericht:
		.string "Summary"

	.global str_tausch

	str_tausch:
		.string "Switch"

	.global str_geben

	str_geben:
		.string "Give"

	.global str_nehmen

	str_nehmen:
		.string "Take"

	.global str_aussenden

	str_aussenden:
		.string "Send out"

	.global str_eintragen

	str_eintragen:
		.string "Select"

	.global str_austragen

	str_austragen:
		.string "Deselect"

	.global str_wahlen

	str_wahlen:
		.string "Choose"

	.global str_choose_pokemon

	str_choose_pokemon:
		.string "Choose a Pokémon."

	.global str_choose_pkmn_or_back

	str_choose_pkmn_or_back:
		.string "Choose Pokémon or back."

.endif
