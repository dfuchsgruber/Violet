.ifdef LANG_GER
.global str_tilescript_map

str_tilescript_map:
	.string "Eine Karte der Theto-Region!"


.global str_tilescript_bookshelf

str_tilescript_bookshelf:
	.string "Wow!\nSo viele Bücher über Pokémon!"


.elseif LANG_EN
	.global str_tilescript_map

	str_tilescript_map:
		.string "A map of the Theto region!"

	.global str_tilescript_bookshelf

	str_tilescript_bookshelf:
		.string "Wow!\nSo many books about Pokémon!"

.endif
