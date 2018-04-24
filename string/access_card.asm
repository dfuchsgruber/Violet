.ifdef LANG_GER
.global str_access_card_atrium

str_access_card_atrium:
	.string "EG Atrium"


.global str_access_card_fossil

str_access_card_fossil:
	.string "3F Fossilien"


.global str_access_card_cyber

str_access_card_cyber:
	.string "8F Cybernetik"


.global str_access_card_already_there

str_access_card_already_there:
	.string "Du befindest dich bereits auf\ndieser Ebene."


.elseif LANG_EN
	.global str_access_card_atrium

	str_access_card_atrium:
		.string "1F Atrium"

	.global str_access_card_fossil

	str_access_card_fossil:
		.string "4F Fossils"

	.global str_access_card_cyber

	str_access_card_cyber:
		.string "9F Cybernetics"

	.global str_access_card_already_there

	str_access_card_already_there:
		.string "But you are already on that\nfloor!"

.endif
