.ifdef LANG_GER
.global str_present_query

str_present_query:
	.string "Geschenkcode?"


.global str_present_0

str_present_0:
	.string "Na siehst du, ganz einfach!\pAls Geschenk erhältst du von mir\ndies hier."


.global str_present_already_received

str_present_already_received:
	.string "Es tut mir leid, aber diesen\nGeschenkcode hast du wohl schon\leingelöst!\pEin Geschenkcode kann nur ein\neinziges Mal benutzt werden."


.elseif LANG_EN
	.global str_present_query

	str_present_query:
		.string "Present Code?"

	.global str_present_0

	str_present_0:
		.string "Easy going!\pAs reward you will get this here!"

	.global str_present_already_received

	str_present_already_received:
		.string "I am afraid but it seems that you\nalready used this present code.\pEvery single present code can\nonly be used once however."

.endif
