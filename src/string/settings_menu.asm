.ifdef LANG_GER
.global str_settings_color

str_settings_color:
	.string "Farben"


.global str_settings_color_dn

str_settings_color_dn:
	.string "DNS"


.global str_settings_color_standard

str_settings_color_standard:
	.string "Standard"


.elseif LANG_EN
	.global str_settings_color

	str_settings_color:
		.string "Colors"

	.global str_settings_color_dn

	str_settings_color_dn:
		.string "DNS"

	.global str_settings_color_standard

	str_settings_color_standard:
		.string "Standard"

.endif
