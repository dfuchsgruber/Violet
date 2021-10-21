


.global str_field_move_usable_with_new_badge
.global str_field_move_return_to_healing_place
.global str_field_move_return_dig

.global str_field_move_description_flash
.global str_field_move_description_cut
.global str_field_move_description_fly
.global str_field_move_description_strength
.global str_field_move_description_surf
.global str_field_move_description_rock_smash
.global str_field_move_description_waterfall
.global str_field_move_description_rock_climb
.global str_field_move_description_teleport
.global str_field_move_description_dig
.global str_field_move_description_milk_drink
.global str_field_move_description_softboiled
.global str_field_move_description_sweet_scent
.global str_field_move_description_secret_power

.ifdef LANG_GER
	str_field_move_description_flash:
	.string "Erleuchte das Dunkel."
    str_field_move_description_cut:
        .string "Zerschneide Baum/Busch."
    str_field_move_description_fly:
        .string "Fliege in bekannte Stadt."
    str_field_move_description_strength:
        .string "Bewege schwere Felsen."
    str_field_move_description_surf:
        .string "Surfe auf dem Wasser."
    str_field_move_description_rock_smash:
        .string "Zerschmettere einen Fels."
    str_field_move_description_waterfall:
        .string "Besteige Wasserfälle."
    str_field_move_description_rock_climb:
        .string "Kraxle Felswände empor."
    str_field_move_description_teleport:
        .string "Gehe zu heilendem Ort."
    str_field_move_description_dig:
        .string "Fliehe von hier."
    str_field_move_description_milk_drink:
        .string "Teile Kp."
    str_field_move_description_softboiled:
        .string "Teile Kp."
    str_field_move_description_sweet_scent:
        .string "Locke wilde PKMN an."
    str_field_move_description_secret_power:
        .string "Erkunde verst. Areale"

	str_field_move_usable_with_new_badge:
		.autostring 34 2 "Erst einsetzbar, wenn ein neuer Orden errungen wurde.PAUSE_UNTIL_PRESS"
    
    str_field_move_return_to_healing_place:
        .autostring 34 2 "Zum heilenden Ort in BUFFER_1 zurückkehren?"

    str_field_move_return_dig:
        .autostring 34 2 "Von hier fliehen und nach BUFFER_1 zurückkehren?"

.elseif LANG_EN

	str_field_move_usable_with_new_badge:
		.autostring 34 2 "Requires a new badge to be used.PAUSE_UNTIL_PRESS"

    str_field_move_return_to_healing_place:
        .autostring 34 2 "Return to healing place in\nBUFFER_1?"

    str_field_move_return_dig:
        .autostring 34 2 "Flee from here and return to BUFFER_1?"
.endif
