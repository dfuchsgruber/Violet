.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "specials.s"
.include "mugshot.s"
.include "ordinals.s"
.include "flags.s"

.global ow_script_whiteout_mother
.global ow_script_whiteout_tann
.global ow_script_whiteout_bbship
.global ow_script_healing_sequence
.global ow_script_whiteout_joy

ow_script_whiteout_mother:
lockall
applymovement 0x1 mov_look_down_delayed
waitmovement 0x0
loadpointer 0x0 str_mother
setvar 0x8000 0
special 0xe
loadpointer 0x0 str_mother_before
callstd MSG_KEEPOPEN
call ow_script_healing_sequence
loadpointer 0x0 str_mother_after
callstd MSG_KEEPOPEN
special 0xF
songfadedefault
releaseall
end

ow_script_whiteout_tann:
	lockall
	checkflag FLAG_PROFESSOR_TANN_GONE
	gotoif EQUAL tann_gone
	pause 32
	loadpointer 0x0 str_tann_before
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_SHOCKED message_type=MSG_KEEPOPEN
	call ow_script_healing_sequence
	loadpointer 0x0 str_tann_after
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY message_type=MSG_KEEPOPEN
	songfadedefault
	releaseall
	end

tann_gone:
	lockall
	special SPECIAL_HEAL
	songfadedefault
	releaseall
	end

ow_script_whiteout_bbship:
	lockall
	pause 32
	loadpointer 0 str_player
    show_mugshot MUGSHOT_PLAYER alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
	special SPECIAL_HEAL
	songfadedefault
	releaseall
	end

ow_script_healing_sequence:
fadescreen 0x1
fanfare 0x100
waitfanfare
special SPECIAL_HEAL
fadescreen 0x0
return



ow_script_whiteout_joy:
lockall
loadpointer 0x0 str_joy_before
callstd MSG_KEEPOPEN
call ow_script_joy_healing_sequence
loadpointer 0x0 str_joy_after
callstd MSG_KEEPOPEN
applymovement 0x800f mov_joy_bow_down
waitmovement 0x0
songfadedefault
releaseall
end

ow_script_joy_healing_sequence:
applymovement 0x800f mov_look_left_delayed
waitmovement 0x0
doanimation 0x19
nop
checkanimation 0x19
applymovement 0x800f mov_look_down_delayed
waitmovement 0x0
special SPECIAL_HEAL
return

mov_joy_bow_down:
	.byte 0x5b
	.byte 0x1a
	.byte STOP

mov_look_left_delayed:
	.byte LOOK_LEFT_DELAYED
	.byte STOP

mov_look_down_delayed:
	.byte LOOK_DOWN_DELAYED
	.byte STOP

.ifdef LANG_GER
str_mother_before:
	.autostring 35 2 "PLAYER!\pDu hast sicherlich viel erlebt!\pDu solltest dich kurz hier ausruhen."
str_mother_after:
	.autostring 35 2 "Fantastisch!\pDeine Pokémon sehen wieder fit aus!"
str_joy_before:
	.autostring 35 2 "Zunächst solltest du deine Pokémon vollständig heilen."
str_joy_after:
	.autostring 35 2 "Deine Pokémon wurden vollständig geheilt.\pWir hoffen, du kommst groß raus!"
str_player:
	.autostring 34 2 "Puh, das war knappDOTS\pHier in meiner Zelle sollten die Piraten mich nicht vermuten.\pIch sollte mich hier nicht zu lange ausruhenDOTS"
str_tann_before:
	.autostring 34 2 "PLAYER!\nDu siehst ja richtig mitgenommen aus!\pRuh dich hier am Besten etwas aus!"
str_tann_after:
	.autostring 34 2 "Das ist doch schon viel besser, oder?\pDu und deine Pokémon sehen wieder richtig fit aus!"
.global str_whiteout
str_whiteout:
	.string "PLAYER rannte zu einem Pokéstop\nund beschützte die\nerschöpften und besiegten\nPokémon vor weiterem SchadenDOTS\p"
.global str_whiteout_bbship
str_whiteout_bbship:
	.string "PLAYER rannte zurück zur Zelle,\num seinen Pokémon eine Pause zu\ngönnen.\p"
.global str_whiteout_tann
str_whiteout_tann:
	.string "PLAYER rannte zu Professor Tanns\nLabor, um seinen Pokémon eine\nPause zu gönnen.\p"
.elseif LANG_EN

str_mother_before:
	.autostring 35 2 "PLAYER!\pYou surely had a great adventure!\pGet some rest here, honey!"
str_mother_after:
	.autostring 35 2 "Fantastic!\pYour Pokémon look well rested."
str_joy_before:
	.autostring 35 2 "First we should heal your party entirely."
str_joy_after:
	.autostring 35 2 "Deine Pokémon were healed fully!\pWe wish you the best of luck!"
str_player:
	.autostring 34 2 "Well, that was close!\pBut the pirates won't suspect me here in my cell.\pNonetheless, I shouldn't rest here for too longDOTS"
str_tann_before:
	.autostring 34 2 "PLAYER!\nYou really look exhausted!\pBest take some rest here, ok?"
str_tann_after:
	.autostring 34 2 "Way better, right?\pYou and your Pokémon look well rested!"
.global str_whiteout
str_whiteout:
	.string "PLAYER ran towards a Pokéstop\nto protected their\nexhausted Pokémon from\nfurther damageDOTS\p"
.global str_whiteout_bbship
str_whiteout_bbship:
	.string "PLAYER ran back to his cell\nto get some rest for\ntheir Pokémon thereDOTS"
.global str_whiteout_tann
str_whiteout_tann:
	.string "PLAYER ran to Professor Fig's\nhouse to get some rest\nfor their Pokémon thereDOTS"
.endif
