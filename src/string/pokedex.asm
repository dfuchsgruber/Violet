.ifdef LANG_GER
.global str_pokedex_none

str_pokedex_none:
	.string ""


.global str_pokedex_mamutel

str_pokedex_mamutel:
	.string "Die beeindruckenden Stoßzähne dieser\nPokémon sind aus Eis. Nach der Eiszeit\nnahm ihre Population ab."


.global str_pokedex_feature_0

str_pokedex_feature_0:
	.string "Scanner"


.global str_pokedex_feature_1

str_pokedex_feature_1:
	.string "Scanner"


.global str_pokedex_feature_2

str_pokedex_feature_2:
	.string "Scanner"


.global str_pokedex_feature_scanner_percent

str_pokedex_feature_scanner_percent:
	.string "%"


.global str_pokedex_feature_scanner_unseen

str_pokedex_feature_scanner_unseen:
	.string "??????????"


.global str_pokedex_feature_scanner_rod

str_pokedex_feature_scanner_rod:
	.string "Angel"


.global str_pokedex_feature_scanner_good_rod

str_pokedex_feature_scanner_good_rod:
	.string "Profiangel"


.global str_pokedex_feature_scanner_super_rod

str_pokedex_feature_scanner_super_rod:
	.string "Superangel"


.global str_pokedex_feature_scanner_none

str_pokedex_feature_scanner_none:
	.string "Keine Pokémon auffindbar"


.elseif LANG_EN
	.global str_pokedex_none

	str_pokedex_none:
		.string ""

	.global str_pokedex_mamutel

	str_pokedex_mamutel:
		.string "This Pokémon\s impressive\ntusks are fully made of ice.\nAfter the ice age their\npopulation decreased."

	.global str_pokedex_feature_0

	str_pokedex_feature_0:
		.string "Scanner"

	.global str_pokedex_feature_1

	str_pokedex_feature_1:
		.string "Scanner"

	.global str_pokedex_feature_2

	str_pokedex_feature_2:
		.string "Scanner"

	.global str_pokedex_feature_scanner_percent

	str_pokedex_feature_scanner_percent:
		.string "%"

	.global str_pokedex_feature_scanner_unseen

	str_pokedex_feature_scanner_unseen:
		.string "??????????"

	.global str_pokedex_feature_scanner_rod

	str_pokedex_feature_scanner_rod:
		.string "Rod"

	.global str_pokedex_feature_scanner_good_rod

	str_pokedex_feature_scanner_good_rod:
		.string "Good Rod"

	.global str_pokedex_feature_scanner_super_rod

	str_pokedex_feature_scanner_super_rod:
		.string "Super Rod"

	.global str_pokedex_feautre_scanner_none

	str_pokedex_feautre_scanner_none:
		.string "No Pokémon to find"

.endif
