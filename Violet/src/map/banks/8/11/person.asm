.include "vars.s"
.include "map_adjacency_types.s"
.include "movements.s"
.include "specials.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "flags.s"
.include "species.s"
.include "items.s"
.include "pathfinding.s"

.global ow_script_kaskada_blackmarket_person_0
.global ow_script_kaskada_blackmarket_person_1
.global ow_script_kaskada_blackmarket_person_2
.global ow_script_kaskada_blackmarket_person_3
.global ow_script_kaskada_blackmarket_person_4
.global ow_script_kaskada_blackmarket_person_5
.global ow_script_kaskada_blackmarket_person_6
.global ow_script_kaskada_blackmarket_person_7
.global ow_script_kaskada_blackmarket_person_8
.global ow_script_kaskada_blackmarket_person_9
.global ow_script_kaskada_blackmarket_person_10
.global ow_script_kaskada_blackmarket_person_11
.global ow_script_kaskada_blackmarket_person_12
.global ow_script_kaskada_blackmarket_person_13
.global ow_script_kaskada_blackmarket_person_14
.global ow_script_kaskada_blackmarket_primus
.global ow_script_kaskada_blackmarket_coin_game
.global ow_script_kaskada_black_glasses
.global ow_script_kaskada_black_blaise
.global ow_script_black_market_igva_final

ow_script_kaskada_blackmarket_person_0:
	loadpointer 0 str_0
	callstd MSG
	end
ow_script_kaskada_blackmarket_person_1:
	loadpointer 0 str_1
	callstd MSG
	end
ow_script_kaskada_blackmarket_person_2:
	loadpointer 0 str_2
	callstd MSG_FACE
	end
ow_script_kaskada_blackmarket_person_3:
	loadpointer 0 str_3
	callstd MSG_FACE
	end
ow_script_kaskada_blackmarket_person_4:
	loadpointer 0 str_4
	callstd MSG_FACE
	end
ow_script_kaskada_blackmarket_person_5:
	loadpointer 0 str_5
	callstd MSG_FACE
	end
ow_script_kaskada_blackmarket_person_6:
	loadpointer 0 str_6
	callstd MSG_FACE
	end
ow_script_kaskada_blackmarket_person_7:
	loadpointer 0 str_7
	callstd MSG_FACE
	end
ow_script_kaskada_blackmarket_person_8:
	loadpointer 0 str_8
	callstd MSG_FACE
	end
ow_script_kaskada_blackmarket_person_9:
	loadpointer 0 str_9
	callstd MSG_FACE
	end
ow_script_kaskada_blackmarket_person_10:
	loadpointer 0 str_10
	callstd MSG_FACE
	end
ow_script_kaskada_blackmarket_person_11:
	loadpointer 0 str_11
	callstd MSG
	end
ow_script_kaskada_blackmarket_person_12:
	loadpointer 0 str_12
	callstd MSG
	end
ow_script_kaskada_blackmarket_person_13:
	loadpointer 0 str_13
	callstd MSG_FACE
	end
ow_script_kaskada_blackmarket_person_14:
	loadpointer 0 str_14
	callstd MSG_FACE
	end


ow_script_kaskada_black_glasses:
    lock
    faceplayer
    checkflag KASKADA_BLACKMARKET_SCHATTENGLAS
    gotoif EQUAL after_receiving_black_glasses
    loadpointer 0x0 str_intro_black_glasses
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_SCHATTENGLAS
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    loadpointer 0x0 str_after_receiving_black_glasses
    callstd MSG_KEEPOPEN
    closeonkeypress
    release
    setflag KASKADA_BLACKMARKET_SCHATTENGLAS
    end
after_receiving_black_glasses:
    loadpointer 0x0 str_after_receiving_black_glasses
    callstd MSG_FACE
    end

ow_script_kaskada_blackmarket_primus:
	lock
	faceplayer
	checkflag KASKADA_BLACKMARKET_PRIMUS
	gotoif EQUAL primus_done
	pause 32
	sound 0x15
	applymovement LASTTALKED mov_exclam
	waitmovement 0
	checksound
	loadpointer 0 str_primus_0
	show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT emotion=MUGSHOT_SCARED
	applymovement LASTTALKED mov_fu
	waitmovement 0
	pause 48
	setflag KASKADA_BLACKMARKET_PRIMUS
	faceplayer
primus_done:
	loadpointer 0 str_primus_1
	show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT emotion=MUGSHOT_SCARED
	releaseall
	end


blaise_all_face_to_warden:
	applymovement 39 mov_fr
	applymovement 0xFF mov_fr
	applymovement 38 mov_fu
	applymovement 20 mov_fu
	waitmovement 0
	return

blaise_all_face_igva:
	applymovement 37 mov_fl
	applymovement 38 mov_fl
	applymovement 20 mov_fl
	applymovement 0xFF mov_fl
	waitmovement 0
	return

blaise_all_face_blaise:
	applymovement 37 mov_fd
	applymovement 38 mov_fu
	applymovement 0xFF mov_fr
	applymovement 39 mov_fr
	waitmovement 0
	return


ow_script_kaskada_black_blaise:
	lockall
	loadpointer 0 str_blaise_0
	show_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT emotion=MUGSHOT_ANGRY message_type=MSG_KEEPOPEN
	msgbox_with_name str_warden_0 str_warden alignment=MUGSHOT_RIGHT message_type=MSG
	applymovement 20 mov_fu_fd_delayed
	waitmovement 0
	pause 16
	loadpointer 0 str_blaise_1
	show_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT emotion=MUGSHOT_ANGRY message_type=MSG
    clearflag (FLAG_KASKADA_BLAISE_EVENT_IGVA | 0x8000)
	showsprite 39
	applymovement 39 mov_7r
	waitmovement 0
	call blaise_all_face_igva
	sound 0x15
	applymovement 39 mov_exclam
	checksound
	pause 16
	loadpointer 0 str_blaise_igva_0
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=1 message_type=MSG
	applymovement 0xFF mov_fr
	waitmovement 0
	call blaise_all_face_blaise
	loadpointer 0 str_blaise_2
	show_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=1 message_type=MSG
	call blaise_all_face_igva
	loadpointer 0 str_blaise_igva_1
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=1 message_type=MSG
    call blaise_all_face_to_warden
	msgbox_with_name str_warden_1 str_warden alignment=MUGSHOT_RIGHT message_type=MSG
	call blaise_all_face_igva
	loadpointer 0 str_blaise_igva_1_2
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_blaise_igva_2
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	loadpointer 0 str_blaise_3
	show_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=1 message_type=MSG
	call blaise_all_face_to_warden
	msgbox_with_name str_warden_2 str_warden alignment=MUGSHOT_RIGHT message_type=MSG
	call blaise_all_face_igva
	loadpointer 0 str_blaise_igva_3
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_blaise_igva_4
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
    pause 32
	call blaise_all_face_to_warden
	msgbox_with_name str_warden_3 str_warden alignment=MUGSHOT_RIGHT message_type=MSG
	pause 16
	applymovement 37 mov_3r
	waitmovement 0
	pause 16
	applymovement 37 mov_fl
	waitmovement 0
	applymovement 38 mov_fr
	applymovement 39 mov_fr
	applymovement 0xFF mov_fr
	applymovement 20 mov_fr
	msgbox_with_name str_warden_4 str_warden alignment=MUGSHOT_RIGHT message_type=MSG
	sound 0x15
	applymovement 38 mov_exclam
	waitmovement 0
	checksound
	applymovement 37 mov_warden_away
	applymovement 38 mov_warden2_away
	waitmovement 0
	pause 24
	hidesprite 37
	hidesprite 38

@ // The wardens are gone
	call blaise_all_face_blaise
	loadpointer 0 str_blaise_4
	show_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT emotion=MUGSHOT_NORMAL hide_mugshot=1 message_type=MSG
	call blaise_all_face_igva
	loadpointer 0 str_blaise_igva_5
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_ANGRY hide_mugshot=1 message_type=MSG
	call blaise_all_face_blaise
	loadpointer 0 str_blaise_5
	show_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT emotion=MUGSHOT_RUMINATIVE hide_mugshot=1 message_type=MSG
	call blaise_all_face_igva
	sound 0x15
	applymovement 39 mov_exclam
	waitmovement 0
	checksound
	pause 16
	loadpointer 0 str_blaise_igva_6
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=1 message_type=MSG
	call blaise_all_face_blaise
	loadpointer 0 str_blaise_6
	show_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT emotion=MUGSHOT_ANGRY hide_mugshot=1 message_type=MSG
	call blaise_all_face_igva
	loadpointer 0 str_blaise_igva_7
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=1 message_type=MSG
	call blaise_all_face_blaise
	loadpointer 0 str_blaise_7
	show_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT emotion=MUGSHOT_ANGRY hide_mugshot=1 message_type=MSG
	call blaise_all_face_igva
	loadpointer 0 str_blaise_igva_8
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=1 message_type=MSG
	call blaise_all_face_blaise
	loadpointer 0 str_blaise_8
	show_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT emotion=MUGSHOT_ANGRY hide_mugshot=1 message_type=MSG
	call blaise_all_face_igva
	loadpointer 0 str_blaise_igva_9
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_HAPPY hide_mugshot=1 message_type=MSG
	call blaise_all_face_blaise
	loadpointer 0 str_blaise_9
	show_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT emotion=MUGSHOT_NORMAL hide_mugshot=1 message_type=MSG
	applymovement 20 mov_2r
	waitmovement 0
	pause 32
	applymovement 20 mov_fl
	waitmovement 0
	loadpointer 0 str_blaise_10
	show_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT emotion=MUGSHOT_NORMAL hide_mugshot=1 message_type=MSG
	applymovement 20 mov_blaise_away
	waitmovement 0
	hidesprite 20
	pause 32
	call blaise_all_face_igva
	loadpointer 0 str_blaise_igva_10
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_ANNOYED hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_blaise_igva_11
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	sound 0x15
	applymovement 39 mov_exclam
	waitmovement 0
	checksound
	pause 24
	loadpointer 0 str_blaise_igva_12
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_blaise_igva_13
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	npc_move_to 39 0x2f 0x1c
	hidesprite 39
	releaseall
	end

mov_fu_fd_delayed:
	.byte PAUSE_32, LOOK_DOWN_DELAYED, PAUSE_32, LOOK_UP_DELAYED, PAUSE_32, STOP
mov_warden_away:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_warden2_away:
	.byte STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_UP_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_UP_FAST, STEP_UP_FAST, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_blaise_away:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP



ow_script_kaskada_blackmarket_coin_game:
	showmoney 0x0 0x0 0x0
	loadpointer 0x0 str_coin_game_intro
	callstd MSG_YES_NO
	compare LASTRESULT 0x0
	gotoif EQUAL coin_game_dont_play
	loadpointer 0x0 str_coin_game_explain
	callstd MSG_YES_NO
	compare LASTRESULT 0x0
	gotoif EQUAL coin_game_dont_play
	checkmoney 5000 0x0
	compare LASTRESULT 0x0
	gotoif EQUAL coin_game_no_money
	loadpointer 0x0 str_coin_game_start
	callstd MSG
	setvar 0x8004 20
	hidemoney 0 0
coin_game_loop:
	buffernumber 0x0 0x8004
	loadpointer 0x0 str_coin_game_state
	callstd MSG_KEEPOPEN
	setvar DYN_MULTICHOICE_ITEM_CNT 0x3
	loadpointer 0x0 choice_coin_game
	multichoice 0x0 0x0 0x0 0x1
	compare LASTRESULT 0x0
	callif EQUAL coin_game_take_one
	compare LASTRESULT 0x1
	callif EQUAL coin_game_take_two
	compare LASTRESULT 0x2
	callif EQUAL coin_game_take_three
	special 0x25
	setvar DYN_MULTICHOICE_ITEM_CNT 0x0
	buffernumber 0x0 0x8005
	loadpointer 0x0 str_coin_game_take
	callstd MSG
	compare 0x8004 0x0
	gotoif EQUAL coin_game_end
	goto coin_game_loop
coin_game_end:
	showmoney 0 0 0
	loadpointer 0x0 str_coin_game_lost
	callstd MSG_KEEPOPEN
	paymoney 5000 0x0
	updatemoney 0 0 0
	sound 0x41
	checksound
	loadpointer 0 str_coin_game_payed
	callstd MSG_KEEPOPEN
	closeonkeypress
	hidemoney 0 0
	releaseall
	end
coin_game_take_three:
	subvar 0x8004 0x3
	return
coin_game_take_two:
	subvar 0x8004 0x2
	return
coin_game_take_one:
	subvar 0x8004 0x1
	return

coin_game_no_money:
	loadpointer 0x0 str_coin_game_no_money
	callstd MSG
	hidemoney 0 0
	end
coin_game_dont_play:
	loadpointer 0x0 str_coin_game_dont_play
	callstd MSG
	hidemoney 0 0
	end

.align 4
choice_coin_game:
    .word str_one, 0
    .word str_two, 0
    .word str_three, 0

ow_script_black_market_igva_final:
	lock
	faceplayer
	loadpointer 0 str_igva_0
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_igva_1
	update_mugshot_emotion MUGSHOT_RUMINATIVE
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	checkflag KASKADA_BLACKMARET_BB_SHIP
	gotoif EQUAL lucky_gone
	release
	end
lucky_gone:
	checkgender
    compare LASTRESULT 0x0
    callif EQUAL buffer_he
	compare LASTRESULT 0x1
	callif EQUAL buffer_she
	sound 0x15
	applymovement 32 mov_exclam
	waitmovement 0
	checksound
	loadpointer 0 str_igva_2
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_igva_3
	update_mugshot_emotion MUGSHOT_ANGRY
	callstd MSG_KEEPOPEN
	loadpointer 0 str_igva_4
	update_mugshot_emotion MUGSHOT_SCARED
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	applymovement 31 mov_3d
	waitmovement 0
	applymovement 29 mov_fu
	applymovement 30 mov_fu
	applymovement 32 mov_fu
	applymovement 31 mov_2d
	waitmovement 31
	loadpointer 0 str_albus_0
	show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT
	sound 0x15
	applymovement 31 mov_exclam
	waitmovement 0
	checksound
	loadpointer 0 str_albus_1
	show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
	loadpointer 0 str_igva_5
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SAD
	loadpointer 0 str_albus_2
	show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_albus_3
	update_mugshot_emotion MUGSHOT_SAD
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	applymovement 32 mov_fd
	waitmovement 0
	loadpointer 0 str_igva_6
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_HAPPY
	applymovement 32 mov_fu
	waitmovement 0
	loadpointer 0 str_igva_7
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
	loadpointer 0 str_albus_4
	show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT emotion=MUGSHOT_SAD
	applymovement 32 mov_fd
	waitmovement 0
	sound 0x15
	applymovement 32 mov_exclam
	waitmovement 0
	checksound
	loadpointer 0 str_igva_8
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
	applymovement 32 mov_fu
	waitmovement 0
	loadpointer 0 str_albus_5
	show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT emotion=MUGSHOT_SAD
	loadpointer 0 str_igva_9
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SAD
	loadpointer 0 str_albus_6
	show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT
	applymovement 32 mov_fd
	applymovement 30 mov_fd
	applymovement 29 mov_fd
	waitmovement 0
	loadpointer 0 str_albus_7
	show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT
	pause 48
	applymovement 31 mov_fl
	waitmovement 0
	pause 48
	applymovement 31 mov_fr
	waitmovement 0
	pause 48
	applymovement 31 mov_fd
	waitmovement 0
	applymovement 32 mov_fu
	applymovement 29 mov_fu
	applymovement 30 mov_fu
	loadpointer 0 str_albus_8
	show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT
	applymovement 31 mov_6u
	applymovement 29 mov_left_revo_away
	applymovement 30 mov_right_revo_away
	waitmovement 29
	hidesprite 31
	hidesprite 30
	hidesprite 29
	pause 32
	applymovement 32 mov_fd
	waitmovement 0
	loadpointer 0 str_igva_10
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SAD hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_igva_11
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	loadpointer 0 str_igva_12
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	loadpointer 0 str_igva_13
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	applymovement 32 mov_6u
	waitmovement 0
	hidesprite 32
	setflag KASKADA_BLACKMARKET_BLAISE
	setflag BLACK_MARKET_DONE
	clearflag (FLAG_KASKADA_FELIX_SOUTH | 0x8000)
	releaseall
	end

buffer_he:
	bufferstring 0 str_he
	return
buffer_she:
	bufferstring 0 str_she
	return

mov_right_revo_away:
	.byte STEP_UP, STEP_LEFT, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_left_revo_away:
	.byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP

.ifdef LANG_GER
str_0:
	.autostring 34 2 "A-Aber ich sage dir doch, ich kann das Geld auftreiben.\pGib mir einfach noch etwas mehr Zeit, ja?"
str_1:
	.autostring 34 2 "Ich lasse mich doch nicht zum Narren halten.\pDu hattest lange genug Zeit, mir mein Geld zurückzuzahlen.\pJetzt wirst du die Konsequenzen für deine Unverlässlichkeit tragen müssenDOTS"
str_2:
	.autostring 34 2 "Auf diesem Markt fühle ich mich immer ganz unwohlDOTS\pEs könnte ja jeden Moment die Decke auf uns herunterstürzen!"
str_3:
	.autostring 34 2 "Team Violet muss hier einige Einkäufe erledigen.\pAber das sind unsere Geschäfte, ja?\pDie gehen dich absolut gar nichts an, du Göre!"
str_4:
	.autostring 34 2 "Wenn man den richtigen Moment erwischt und der Verkäufer gerade nicht hinsiehtDOTS\pNun, dann kann man sich hier quasi selbst bedienen.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWas siehst du mich denn so an?\pWir sind hier an einem Untergrund-Schwarzmarkt.\pDa sind solche kleinen Diebstähle doch wohl noch erlaubtDOTS"
str_5:
	.autostring 34 2 "Ich verstehe wirklich nicht, warum wir den Professor hierher begleiten müssen.\pSeit wann gibt den ein Wissenschaftler in Team Violet den Ton an?"
str_6:
	.autostring 34 2 "Als Trainer habe ich einfach kein großes Talent.\pDeswegen kaufe ich mir hier die Pokémon, die die Blackbeard Piraten erbeutet haben.\pWobei ich zugeben muss, dass mir die Piratenbande doch ein wenig Angst einjagtDOTS"
str_7:
	.autostring 34 2 "Weißt du, was der wirkliche Nachteil an einem Schwarzmarkt ist?\pWenn man einmal von einem dieser Halunken hier abgezogen wird, kann man sich praktisch nicht mehr zur Wehr setzenDOTS"
str_8:
	.autostring 34 2 "Du fragst dich sicher, wie man so einen Markt direkt vor den Augen der Pokémon-Liga betreiben kann, was?\pNun, darauf habe ich bisher ehrlichgesagt auch keine sinnvolle Antwort gefundenDOTS"
str_9:
	.autostring 34 2 "Es ist doch irgendwie genial, diesen Markt mit einem Teehaus zu decken.\pIch meine, wer würde darauf kommen, dass ein Teehaus in irgendwelche dubiosen Geschäfte verwickelt ist?"
str_10:
	.autostring 34 2 "Mit meinen übersinnlichen Kräften kann ich deine Pokémon unbesiegbar machenDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDu bist ja noch ein Kind!\pN-NeinDOTS\pEinem Kind kann ich das Geld nicht aus der Tasche ziehen.\pZieh ab, bevor ich es mir anders überlege, ja?"
str_11:
	.autostring 34 2 "Und ich sage Ihnen, dieser alte Mann schummelt!\pDa ist irgendetwas faul an diesem Stand.\pDa können Sie doch nicht einfach so zusehen!"
str_12:
	.autostring 34 2 "Wir machen hier die Regeln, verstanden?\pUnd dieser alte Mann, den du da beschuldigstDOTS\pIch kann dir versichern, dass er sehr vertrauenswürdig ist.\pOder hast du irgendwelche Beweise für deine abenteuerlichen Anschuldigungen?"
str_13:
	.autostring 34 2 "Ich warte hier sicher schon seit StundenDOTS\pImmerhin Igva hat sich jetzt blicken lassenDOTS\pFehlen aber noch immer Lucky und der Boss, bis wir hier die Düse machen können."
str_14:
	.autostring 34 2 "Wo bleibt denn nur Lucky?\pIch hoffe, dass er wenigstens Blackbeard als Verbündeten gewinnen kann, wenn er sich schon so viel Zeit lässtDOTS"


str_igva_0:
	.autostring 34 2 "PLAYER!\pIch bin wirklich am verzweifelnDOTS"
str_igva_1:
	.autostring 34 2 "Hast du unseren Mitstreiter gefunden?\pLucky wollte uns hier eigentlich treffenDOTS"
str_igva_2:
	.autostring 34 2 "Was soll das heißen?\pDu hast ihn an Board eines Schiffs gehen sehen?\pUnd dann hat das Schiff direkt abgelegt?"
str_igva_3:
	.autostring 34 2 "Was denkt sich Lucky denn dabei!\pUnser Plan war doch unmissverständlich, Blackbeard für unsere Sache zu gewinnen.\pUnd jetzt verschwindet er einfach mit diesem PiratenpackDOTS"
str_igva_4:
	.autostring 34 2 "Das wird unseren Anführer wirklich nicht freuenDOTS"
str_albus_0:
	.autostring 34 2 "Igva!\nEntschuldige bitte, dass ich mich verspäte.\pIch hatte noch etwas mit einem altem Freund zu klärenDOTS"
str_albus_1:
	.autostring 34 2 "Was macht denn das Kind hier?\pUnd wo ist Lucky?"
str_igva_5:
	.autostring 34 2 "Nun jaDOTS\nDie Sache ist die, dass Lucky wohlDOTSTEXT_DELAY_SHORT\pEr ist wohl irgendwie mit den Blackbeard Piraten zusammen verschwundenDOTS"
str_albus_2:
	.autostring 34 2 "Wie bitte?\pEr ist gemeinsam mit Blackbeard verschwunden?"
str_albus_3:
	.autostring 34 2 "Dabei hat er mir doch versichert, mit dieser Bande nichts mehr am Hut zu habenDOTS"
str_igva_6:
	.autostring 34 2 "Und das hierDOTS\pDas ist PLAYER!"
str_igva_7:
	.autostring 34 2 "Ich glaube, er könnte ein toller Mitstreiter für unsere Sache werden!"
str_albus_4:
	.autostring 34 2 "IgvaDOTS\pIch glaube ehrlichgesagt kaum, dass sich PLAYER so einfach unserer Bewegung anschließen wird.\pIch habe ihn vorhin bereits flüchtig kennengelernt.\pEr ist ein ehemaliger Schüler vom alten Faun."
str_igva_8:
	.autostring 34 2 "W-was?\nDu bist ein Schüler vom Pinken Faun?\pD-Dann bist du auf der Seite der Pokémon-Liga?"
str_albus_5:
	.autostring 34 2 "IgvaDOTS\nDu lässt sich immer viel zu schnell mitreißenDOTS\pErinnerst du dich nicht, was mit dem letzten Mitglied passiert ist, das du für unsere Sache angeworben hast?"
str_igva_9:
	.autostring 34 2 "DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT"
str_albus_6:
	.autostring 34 2 "Wie dem auch sei.\pHör mir gut zu, PLAYER."
str_albus_7:
	.autostring 34 2 "Ich kann verstehen, dass du in mir einen Feind siehst.\pIch will das System verändern, für das dein ehemaliger Lehrer so verbissen eintritt.\pAber lass mich dir einen Ratschlag erteilen.\pUrteile nicht all zu schnell darüber, für wen und wessen Ansichten du kämpfen solltest.\pDieser Untergrundmarkt ist das perfekte Beispiel dafür, warum die Pokémon-Liga zu Fall gebracht werden muss.\pAber ich möchte dich nicht zu einer Entscheidung drängen.\pDu bist ein junger Trainer und hast einen weiten Weg vor dir.\pVielleicht kommst du eines Tages zu der gleichen Einsicht wie wir, die wir uns entschlossen haben, für ein besseres System zu kämpfen.\pVielleicht stehen wir uns aber auch als Gegner gegenüber.\pFolge stets deinem Sinn für Rechtschaffenheit, PLAYER.\pDas ist alles, worauf es ankommt."
str_albus_8:
	.autostring 34 2 "Gut.\nNachdem Lucky wohl auch nicht mehr auftauchen wirdDOTS\pSehe ich die potentielle Allianz mit den Blackbeard Piraten als gescheitert an.\pWir sollten wir uns zurückziehen."
str_igva_10:
	.autostring 34 2 "PLAYERDOTS\pEntschuldige bitte, wenn ich etwas zu aufdringlich gewesen binDOTS"
str_igva_11:
	.autostring 34 2 "Aber weißt duDOTS\pNur, weil unsere Mentoren im Zwist miteinander stehen, heißt das ja noch lange nicht, dass wir keine Freunde sein können, oder?\pUnd es zwingt dich auch niemand dazu, an der Seite deines alten Lehrers zu kämpfen.\pNiemand hindert dich daran, die richtige Seite in diesem Konflikt zu wählen."
str_igva_12:
	.autostring 34 2 "Ich muss mich jetzt aber wirklich beeilen.\pSonst verliere ich noch meine Mitstreiter."
str_igva_13:
	.autostring 34 2 "Halt die Ohren steif, PLAYER!\pIch bin mir sicher, dass wir uns bald wiedersehen werden!"
str_blaise_0:
	.autostring 34 2 "Lasst mich in Ruhe!\pFinger weg!"
str_warden_0:
	.autostring 34 2 "Nichts da!\pGlaubst du, dass du hier einfach Randale machen kannst und wir bloß zuschauen?"
str_blaise_1:
	.autostring 34 2 "Argh, euch werd' ich's zeigen!"
str_blaise_igva_0:
	.autostring 34 2 "Was ist hier denn los?"
str_blaise_2:
	.autostring 34 2 "PLAYER?!\pWas treibst du denn hier?"
str_blaise_igva_1:
	.autostring 34 2 "K-kennst du diesen Jungen, PLAYER?"
str_warden_1:
	.autostring 34 2 "Igva!\pGehört dieser Bengel zu euch?"
str_blaise_igva_1_2:
	.autostring 34 2 "Ä-ÄhmDOTS\nDOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT"
str_blaise_igva_2:
	.autostring 34 2 "J-Ja, er ist einer von unsDOTS"
str_blaise_3:
	.autostring 34 2 "W-Was?\nDas stimmt doch-"
str_warden_2:
	.autostring 34 2 "GrrDOTS\pDann bring deine Leute unter Kontrolle, ja?\pNur, weil er zur Revolutionsbewegung gehört, kann er hier noch lang nicht alles kurz und klein schlagen, verstanden?\pAuch für euch gelten hier Regeln!"
str_blaise_igva_3:
	.autostring 34 2 "J-Ja natürlich!"
str_blaise_igva_4:
	.autostring 34 2 "Ich werde mit ihm ein ernstes Wörtchen reden.\pIhr habt mein Wort!"
str_warden_3:
	.autostring 34 2 "Na gut, dann wäre hier ja alles geklärt."
str_warden_4:
	.autostring 34 2 "Was ist denn?\pKommst du nun?"
str_blaise_4:
	.autostring 34 2 "Was zum Teufel war das denn?"
str_blaise_igva_5:
	.autostring 34 2 "Wie wäre es mit etwas Dankbarkeit?\pIch hab dir gerade mächtig aus der Patsche geholfen.\pWas wollten die Aufseher eigentlich von dir?"
str_blaise_5:
	.autostring 34 2 "HmmDOTS\pVielleicht hat es ihnen nicht gefallen, dass ich im Begriff war, diesen Untergrundmarkt in Schutt und Asche zu legenDOTS"
str_blaise_igva_6:
	.autostring 34 2 "W-Was?\pIst das dein Ernst?\pWeißt du denn nicht, wer hinter diesem Untergrundmarkt steht?"
str_blaise_6:
	.autostring 34 2 "Und wie ich das weiß!\pGenau deswegen will ich ihn ja dem Erdboden gleichmachen."
str_blaise_igva_7:
	.autostring 34 2 "D-Du willst dich allen Ernstes mit den Top Vier anlegen?\pGanz alleine?"
str_blaise_7:
	.autostring 34 2 "Mein Vater ist der Kopf hinter diesem Schwarzmarkt.\pUnd ich werde ihm einen dicken Strich durch die Rechnung machen!"
str_blaise_igva_8:
	.autostring 34 2 "DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT\nDOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT\pH-hör mal zu, Kleiner.\pDu kannst unmöglich alleine jemanden von den Top Vier direkt herausfordern.\pDu hättest keine ChanceDOTS"
str_blaise_8:
	.autostring 34 2 "Ach ja?\nWer sagt das?\pDu etwa?\pIch lasse mir doch von einer Revoluzzerin nicht sagen, was ich nicht kann.\pUnd überhaupt, was soll ich sonst tun?\pMich in einen grünen Mantel werfen und eurer niederträchtigen Vereinigung beitreten?"
str_blaise_igva_9:
	.autostring 34 2 "Wieso nicht?\pWir haben das gleiche Ziel.\pUnsere Gruppe will die Top Vier auch stürzen, weißt du?\pUnd wir haben jemanden auf unserer Seite, der es mit ihnen aufnehmen kann."
str_blaise_9:
	.autostring 34 2 "Pah.\nNein danke!\pSo tief bin ich noch nicht gesunken.\pIch erledige die Dinge auf meine Weise.\pAdieu!"
str_blaise_10:
	.autostring 34 2 "Ach, und PLAYER.\pAn deiner Stelle würde ich dringend überdenken, mit wem ich mich abgebe.\pNur ein gut gemeinter Rat eines alten Klassenkammeraden."
str_blaise_igva_10:
	.autostring 34 2 "Du hast ja nette Freunde, PLAYER.\pWas für ein undankbarer Bengel."
str_blaise_igva_11:
	.autostring 34 2 "Aber immerhin kämpft er für die richtige Sache.\pOrte wie diesen, sollte es nicht geben dürfen.\pDOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT"
str_blaise_igva_12:
	.autostring 34 2 "Ach du Schande!\pDiese ganze Geschichte hier hat uns wirklich lange aufgehalten."
str_blaise_igva_13:
	.autostring 34 2 "Wir sollten schnellstens nach meinem Freund Lucky suchen, ja PLAYER?"




str_warden:
	.string "Aufseher"

str_primus_0:
	.autostring 34 2 "O-Oh!\nPLAYER, wie unerwartet!\pW-Was ich hier treibe?\pÄhm, ja, das ist eine gute FrageDOTS\pIchDOTS\pIch muss bloß einige Besorgungen anstellenDOTS\pF-Für meine ForschungDOTS\pAlso nichts, worüber du dir den Kopf zerbrechen solltestDOTS"
str_primus_1:
	.autostring 34 2 "Du behältst das hier doch für dich, ja?\pNicht, dass man mir noch unangenehme Fragen stelltDOTS"
str_coin_game_intro:
	.autostring 34 2 "Na, sieh mal ein, ein Jungspund!\pIch kann dich doch sicher dazu überreden, mit einem alten Herren ein kleines Spielchen zu spielen, oder?"
str_coin_game_explain:
	.autostring 34 2 "Die Regeln sind ganz einfach.\pIch habe hier 20 Murmeln.\pWir beide nehmen abwechselnd entweder eine, zwei oder drei Murmeln.\pDie Person, die die letzte Murmel nimmt, gewinnt das Spiel.\pAlles klar?\pDu kannst gegen mich ganze 50.000POKEDOLLAR gewinnen.\pWenn du aber verlierstDOTS\pNaja, dann schuldest du mir 5.000POKEDOLLAR.\pWas sagst du?"
str_coin_game_start:
    .autostring 34 2 "Gut!\nIch bin so freundlich und lasse dir den Vortritt."
str_coin_game_state:
    .string "BUFFER_1 Murmeln verbleiben.\nWie viele möchtest du nehmen?"
str_one:
    .string "Eine"
str_two:
    .string "Zwei"
str_three:
    .string "Drei"
str_coin_game_take:
    .string "Na dann werde ichDOTS ähmDOTS\nBUFFER_1 Murmeln nehmen, ja?"
str_coin_game_lost:
	.autostring 34 2 "Was für ein Pech!\pSiehst so aus, als hättest du verloren.\pDann musst du jetzt wohl deine Schulden begleichen, KindchenDOTS"
str_coin_game_payed:
	.autostring 34 2 "Das ist einfach blöd gelaufen.\pVielleicht hast du ja bei der nächsten Partie mehr Glück?"
str_coin_game_no_money:
    .autostring 34 2 "Pah!\nWillst du mich für dumm verkaufen?\pDu hast ja nicht einmal 5.000POKEDOLLARDOTS\pWie willst du mich denn dann ausbezahlen?"
str_coin_game_dont_play:
	.autostring 34 2 "Huh?\nHast du etwa Angst, gegen einen alten Mann zu verlieren?\pJammerschade, wirklichDOTS"
str_intro_black_glasses:
	.autostring 34 2 "Ich hasse es, wenn meine Accessiores aus der Mode kommen.\pDiese Brille zum BeispielDOTS\pWer würde jetzt noch so etwas tragen?\pDu kannst sie gerne habenDOTS"
str_after_receiving_black_glasses:
	.autostring 34 2 "Dieses Schattenglas war mir sowieso viel zu dunkelDOTS\pUnd unmodisch ist es dazu auch noch."
str_he:
	.string "er"
str_she:
	.string "sie"
.elseif LANG_EN
.endif
