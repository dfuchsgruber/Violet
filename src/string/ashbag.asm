.ifdef LANG_GER
.global str_item_ashbag

str_item_ashbag:
	.string "In der Aschetasche befindet\nsich BUFFER_1 Asche.PAUSE_UNTIL_PRESS"


.global str_ashbag_not_received

str_ashbag_not_received:
	.string "Zu Schade!\nDu besitzt keinen Aschebeutel!"


.global str_ashbag_full

str_ashbag_full:
	.string "Zu Schade!\nDeine Aschetasche ist voll!"


.global str_ashbag_picked_up

str_ashbag_picked_up:
	.string "PLAYER findet\nBUFFER_1 Asche!"


.elseif LANG_EN
	.global str_item_ashbag

	str_item_ashbag:
		.string "The ashbag containsBUFFER_1\nashes.PAUSE_UNTIL_PRESS"

	.global str_ashbag_not_received

	str_ashbag_not_received:
		.string "What a shame!\nYou do not own an ashbag!"

	.global str_ashbag_full

	str_ashbag_full:
		.string "What a shame!\nYour ashbag seems to be full."

	.global str_ashbag_picked_up

	str_ashbag_picked_up:
		.string "PLAYER obtains\nBUFFER_1 ashes!"

.endif
