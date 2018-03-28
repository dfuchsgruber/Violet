.ifdef LANG_GER
.global str_version_alpha_1_0

str_version_alpha_1_0:
	.string "Herzlichen Glückwunsch!\nDeine Version wurde von\lBUFFER_1.X auf BUFFER_2.X\lgeupdated.\pSetze dein Abenteuer im Osten\nder Felsigen Ödnis fort."


.elseif LANG_EN
	.global str_version_alpha_1_0

	str_version_alpha_1_0:
		.string "Congratulations!\nYour version was updated from\lBUFFER_1.X to BUFFER_2.X.\pContinue your adventure in the east\nof the Rocky Desolatuion."

.endif
