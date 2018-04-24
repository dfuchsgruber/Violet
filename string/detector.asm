.ifdef LANG_GER
.global str_detector

str_detector:
	.string "Der Detektor schlägt aus!\nIn der Nähe muss ein Item liegen!"


.elseif LANG_EN
	.global str_detector

	str_detector:
		.string "Your detector seems to have\nfound an item nearby!"

.endif
