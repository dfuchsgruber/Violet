.ifdef LANG_GER
.global str_item_pc_item_lager

str_item_pc_item_lager:
	.string "Item-Lager"


.global str_item_pc_briefbox

str_item_pc_briefbox:
	.string "Briefbox"


.global str_item_pc_ausschalten

str_item_pc_ausschalten:
	.string "Ausschalten"


.global str_item_pc_nehmen

str_item_pc_nehmen:
	.string "Item Nehmen"


.global str_item_pc_ablegen

str_item_pc_ablegen:
	.string "Item Ablegen"


.global str_zuruck

str_zuruck:
	.string "Zurück"


.global str_item_pc_no_mail

str_item_pc_no_mail:
	.string "Hier ist kein Brief."


.elseif LANG_EN
	.global str_item_pc_item_lager

	str_item_pc_item_lager:
		.string "Storage"

	.global str_item_pc_briefbox

	str_item_pc_briefbox:
		.string "Mailbox"

	.global str_item_pc_ausschalten

	str_item_pc_ausschalten:
		.string "Close"

	.global str_item_pc_nehmen

	str_item_pc_nehmen:
		.string "Take item"

	.global str_item_pc_ablegen

	str_item_pc_ablegen:
		.string "Store item"

	.global str_zuruck

	str_zuruck:
		.string "Back"

	.global str_item_pc_no_mail

	str_item_pc_no_mail:
		.string "There is no mail."

.endif
