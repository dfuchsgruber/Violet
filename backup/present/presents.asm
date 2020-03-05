.include "overworld_script.s"
.include "items.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"
.include "species.s"

.global ow_script_present_0

present_already_received:
    loadpointer 0 str_present_already_received
    callstd 6
    release
    end

ow_script_present_0:
    checkflag PRESENT_0
    gotoif 1 present_already_received
    loadpointer 0 str_present_0
    callstd 6
    copyvarifnotzero 0x8000 ITEM_SONDERBONBON
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    closeonkeypress
    setflag PRESENT_0
    release
    end

.global ow_script_present_purple_kecleon

ow_script_present_purple_kecleon:
	bufferpokemon 0 POKEMON_KECLEON
	checkflag PRESENT_PURPLE_KECLEON
    gotoif EQUAL present_already_received
	loadpointer 0 str_present_kecleon
	callstd MSG_KEEPOPEN
	callasm present_give_purple_kecleon
	compare LASTRESULT 2
	gotoif EQUAL no_place_in_boxes
	fanfare 0x13E
	loadpointer 0 str_received_kecleon
	callstd MSG_KEEPOPEN
	waitfanfare
	call ow_script_set_nickname
	closeonkeypress
	setflag PRESENT_PURPLE_KECLEON
	release
	end

no_place_in_boxes:
	loadpointer 0 str_no_place_in_boxes
	callstd MSG
	release
	end


.ifdef LANG_GER

	.global str_present_0

	str_present_0:
		.string "Na siehst du, ganz einfach!\pAls Geschenk erhältst du von mir\ndies hier."

	str_present_kecleon:
		.autostring 35 2 "Ein Geschenk vom Entwickler persönlich!\pEs ist ein lilafarbenes Kecleon.\nSoweit ich weiß, sind diese Exemplare äußert selten DOTS"

	str_received_kecleon:
		.autostring 35 2 "PLAYER hat ein lilafarbenes Kecleon erhalten!"

	.global str_present_already_received

	str_present_already_received:
		.string "Es tut mir leid, aber diesen\nGeschenkcode hast du wohl schon\leingelöst!\pEin Geschenkcode kann nur ein\neinziges Mal benutzt werden."

	str_no_place_in_boxes:
		.autostring 35 2 "Es tut mir leid, aber es sieht so aus, als hättest du weder im Team noch auf deinen PC Boxen Platz für das Pokémon DOTS"

.elseif LANG_EN

	.global str_present_0

	str_present_0:
		.string "Easy going!\pAs reward you will get this here!"

	str_present_kecleon:
		.autostring 35 2 "A present form the developer himself!\pIt is a purple Kecleon!\nAs far as I know, those are pretty rare DOTS"

	str_received_kecleon:
		.autostring 35 2 "PLAYER received a purple Kecleon!"

	.global str_present_already_received

	str_present_already_received:
		.string "I am afraid but it seems that you\nalready used this present code.\pEvery single present code can\nonly be used once however."

	str_no_place_in_boxes:
		.autostring 35 2 "I am most sorry, but it appears that neither in your party nor your PC boxes you seem to have room for this Pokémon DOTS"
.endif
    
