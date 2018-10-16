.global fp_menu_names

.align 4
fp_menu_names:
    .word str_fp_menu_kp
    .word str_fp_menu_atk
    .word str_fp_menu_def
    .word str_fp_menu_init
    .word str_fp_menu_satk
    .word str_fp_menu_sdef

@ // Strings

.ifdef LANG_GER
.global str_fp_menu_kp

	str_fp_menu_kp:
		.string "KP"

	str_fp_menu_atk:
		.string "Angr."

	str_fp_menu_def:
		.string "Vert."

	str_fp_menu_init:
		.string "Init."

	str_fp_menu_satk:
		.string "SP. Angr."

	str_fp_menu_sdef:
		.string "SP. Vert."

	str_fp_menu_plus:
		.string "+"

	str_fp_menu_minus:
		.string "-"

.elseif LANG_EN

	str_fp_menu_kp:
		.string "HP"

	str_fp_menu_atk:
		.string "Atk."

	str_fp_menu_def:
		.string "Def."

	str_fp_menu_init:
		.string "Speed"

	str_fp_menu_satk:
		.string "SP. Atk."

	str_fp_menu_sdef:
		.string "SP. Def."

	str_fp_menu_plus:
		.string "+"

	str_fp_menu_minus:
		.string "-"

.endif
