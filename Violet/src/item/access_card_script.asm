.include "overworld_script.s"



.global access_card_element_names

.align 4
access_card_element_names:
    .word access_card_element_names_r

.align 4
access_card_element_names_r:
    .word str_access_card_cyber
    .word str_access_card_fossil
    .word str_access_card_geheimpower
    .word str_access_card_atrium

@ // Strings
.ifdef LANG_GER

	str_access_card_atrium:
	.string "EG Atrium"

	str_access_card_fossil:
		.string "3F Fossilien"

	str_access_card_cyber:
		.string "8F Cybernetik"

	str_access_card_geheimpower:
		.string "2F Geheimpower"

	str_access_card_already_there:
		.string "Du befindest dich bereits auf\ndieser Ebene."

.elseif LANG_EN

	str_access_card_atrium:
		.string "1F Atrium"

	str_access_card_fossil:
		.string "4F Fossils"

	str_access_card_cyber:
		.string "9F Cybernetics"

	str_access_card_geheimpower:
		.string "2F Secret Power"

	str_access_card_already_there:
		.string "But you are already on that\nfloor!"

.endif
