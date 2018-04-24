.ifdef LANG_GER
.global str_mart_kaufen

	str_mart_kaufen:
		.string "Kaufen"


	.global str_mart_verkaufen

	str_mart_verkaufen:
		.string "Verkaufen"


	.global str_mart_bye

	str_mart_bye:
		.string "Au revior!"


.elseif LANG_EN
	.global str_mart_kaufen

	str_mart_kaufen:
		.string "Buy"

	.global str_mart_verkaufen

	str_mart_verkaufen:
		.string "Sell"

	.global str_mart_bye

	str_mart_bye:
		.string "Au revior!"

.endif
