.ifdef LANG_GER
.global str_fp_menu_kp

str_fp_menu_kp:
	.string "Kp"


.global str_fp_menu_atk

str_fp_menu_atk:
	.string "Angr."


.global str_fp_menu_def

str_fp_menu_def:
	.string "Vert."


.global str_fp_menu_init

str_fp_menu_init:
	.string "Init."


.global str_fp_menu_satk

str_fp_menu_satk:
	.string "Sp. Angr."


.global str_fp_menu_sdef

str_fp_menu_sdef:
	.string "Sp. Vert."


.global str_fp_menu_plus

str_fp_menu_plus:
	.string "+"


.global str_fp_menu_minus

str_fp_menu_minus:
	.string "-"


.global str_fp_menu

str_fp_menu:
	.string "Fleiß-Punkte"


.elseif LANG_EN
	.global str_fp_menu_kp

	str_fp_menu_kp:
		.string "Hp"

	.global str_fp_menu_atk

	str_fp_menu_atk:
		.string "Atk."

	.global str_fp_menu_def

	str_fp_menu_def:
		.string "Def."

	.global str_fp_menu_init

	str_fp_menu_init:
		.string "Speed"

	.global str_fp_menu_satk

	str_fp_menu_satk:
		.string "Sp. Atk."

	.global str_fp_menu_sdef

	str_fp_menu_sdef:
		.string "Sp. Def."

	.global str_fp_menu_plus

	str_fp_menu_plus:
		.string "+"

	.global str_fp_menu_minus

	str_fp_menu_minus:
		.string "-"

	.global str_fp_menu

	str_fp_menu:
		.string "Effort Values"

.endif
