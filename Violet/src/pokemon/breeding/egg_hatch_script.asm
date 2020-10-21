.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "specials.s"

.global ow_script_egg_hatch
ow_script_egg_hatch:
	lockall
	compare 0x8004 6
	gotoif HIGHER_OR_EQUAL incubator_hatchable
	setflag TRANS_DISABLE
	loadpointer 0 str_wie
	callstd MSG_KEEPOPEN
	special 0xC2
	waitstate
	clearflag TRANS_DISABLE
incubator_slots_update:
	// Check if this hatching enables more slots in the incubator
	special2 LASTRESULT SPECIAL_INCUBATOR_ATTEMPT_ADD_SLOT
	compare LASTRESULT 0
	gotoif EQUAL no_slots_enabled
	buffernumber 0 INCUBATOR_SLOTS
	buffernumber 1 0x8004
	fanfare 0x13e
	loadpointer 0 str_new_slot
	callstd MSG_KEEPOPEN
	waitfanfare
	closeonkeypress
no_slots_enabled:
	releaseall
	end

incubator_hatchable:
	// Hatch the egg in the first party slot of the player
	special SPECIAL_INCUBATOR_HATCH_EGG_BACKUP_PLAYER_PARTY_FIRST_MON
	setvar 0x8004 0
	setflag TRANS_DISABLE
	loadpointer 0 str_wie
	callstd MSG_KEEPOPEN
	special 0xC2
	waitstate
	clearflag TRANS_DISABLE
	bufferpartypokemon 0x0 0
	special2 LASTRESULT SPECIAL_INCUBATOR_HATCH_EGG_SAVE_EGG_AND_RESTORE_PLAYER_PARTY_FIRST_MON
	compare LASTRESULT 1
	gotoif NOT_EQUAL not_sent_to_box
	bufferboxname 0x1 0x8010
	loadpointer 0 str_sent_to_box
	callstd MSG_KEEPOPEN
not_sent_to_box:
	closeonkeypress
	goto incubator_slots_update

.ifdef LANG_GER
str_wie:
	.autostring 35 2 "Wie?"
str_sent_to_box:
	.autostring 34 2 "BUFFER_1 wurde in\nBUFFER_2 abgelegt."
str_incubator_hatchable:
	.autostring 34 2 "Ein Ei im Inkubator scheint bald soweit zu sein!\pFüge es deinem Team hinzu, damit es schlüpfen kann."
str_new_slot:
	.string "Glückwunsch!\nDu hast BUFFER_2 Eier ausgebrütet!\pDu kannst nun BUFFER_1 Eier im\nInkubator platzieren."
.elseif LANG_EN
str_wie:
	.autostring 35 2 "Huh?"
str_incubator_hatchable:
	.autostring 34 2 "An egg inside the incubator seems to be ready soon!\pAdd it to your team for it to be able to hatch."
str_sent_to_box:
	.autostring 34 2 "BUFFER_1 was put into\nBUFFER_2."
str_new_slot:
	.autostring 34 2 "Congratulations!\pYou hatched BUFFER_2 eggs!\pYou can not place BUFFER_1 eggs\nin the incubator."
.endif

