.ifdef LANG_GER
.global str_battle_actions

str_battle_actions:
	.string "PALETTEÈCOLOR_HIGHLIGHT_SHADOWÒÓÔKampfCLEAR_TOぎBeutel\nPokémonCLEAR_TOぎFlucht"


.elseif LANG_EN
	.global str_battle_actions

	str_battle_actions:
		.string "PALETTEÈCOLOR_HIGHLIGHT_SHADOWÒÓÔFightCLEAR_TOぎBag\nPokémonCLEAR_TOぎRun"

.endif
