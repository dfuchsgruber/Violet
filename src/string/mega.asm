.ifdef LANG_GER
.global str_mega_reacts

str_mega_reacts:
	.string "BUFFER_2 von BUFFER_1\nreagiert auf PLAYER von BUFFER_3."


.global str_mega_opp

str_mega_opp:
	.string "(Gegner)"


.global str_mega_evolved

str_mega_evolved:
	.string "BUFFER_1 hat sich zu\nMega-KUN entwickelt!"


.global str_regent_evolved

str_regent_evolved:
	.string "BUFFER_1 umgibt die Aura\neines Kaisers!"


.global str_aura_pulses

str_aura_pulses:
	.string "Die Aura von BUFFER_1\npulsiert!"


.elseif LANG_EN
	.global str_mega_reacts

	str_mega_reacts:
		.string "BUFFER_1\s BUFFER_2\nreacts to BUFFER_3\s PLAYER."

	.global str_mega_opp

	str_mega_opp:
		.string "(foe)"

	.global str_mega_evolved

	str_mega_evolved:
		.string "BUFFER_1 evolved into\nMega-KUN!"

	.global str_regent_evolved

	str_regent_evolved:
		.string "BUFFER_1 is surrouned by\nthe aura of an emperor!"

	.global str_aura_pulses

	str_aura_pulses:
		.string "BUFFER_1\s aura begins\nto pulse!"

.endif
