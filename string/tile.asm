.ifdef LANG_GER
.global str_trash_empty

str_trash_empty:
	.string "Der Mülleimer ist leer."


.global str_trash_full

str_trash_full:
	.string "Sieht so aus, als hättest du für\nBUFFER_2 keinen Platz!\pKomm wieder, wenn du das Item\naufnehmen kannst."


.elseif LANG_EN
.endif
