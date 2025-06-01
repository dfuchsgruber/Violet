.include "vars.s"
.include "movements.s"
.include "specials.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"
.include "pathfinding.s"

.global ow_script_0x89c06b
.global ow_script_map_3_57_trigger_1
.global ow_script_map_3_57_trigger_0
.global ow_script_0x8f6dec
.global ow_script_trainerschool_lock_grass
.global ow_script_trainerschool_battle_test
.global ow_script_trainerschool_lock_exit
.global ow_script_trainerschool_test_2

.equ PERSON_RIVAL, 3
.equ PERSON_FAUN, 4
.equ PERSON_MAY, 5
.equ PERSON_BLAISE, 6
.equ PERSON_FELIX, 7 

ow_script_trainerschool_test_2:
	lockall
	special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
	applymovement 0x7f mov_2u
	waitmovement 0
	special SPECIAL_OVERWORLD_VIEWPORT_LOCK
	loadpointer 0 str_faun_rant_0
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
	sound 0x15
	applymovement PERSON_FAUN mov_face_down_and_exclam
	applymovement PERSON_MAY mov_face_down_and_exclam
	applymovement PERSON_BLAISE mov_face_down_and_exclam
	applymovement PERSON_FELIX mov_face_down_and_exclam
	waitmovement 0
	loadpointer 0 str_faun_rant_1
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY message_type=MSG_KEEPOPEN hide_mugshot=0
	loadpointer 0 str_faun_rant_2
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
	loadpointer 0 str_faun_rant_3
    update_mugshot_emotion MUGSHOT_ANGRY
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	applymovement PERSON_RIVAL mov_1u
	npc_move_to 0xFF 46 18 waitmovement=0
	waitmovement 0x0
	applymovement 0xFF mov_fu
	applymovement PERSON_BLAISE mov_fu
	applymovement PERSON_MAY mov_fu
	applymovement PERSON_FELIX mov_fu
	applymovement PERSON_RIVAL mov_fu
	waitmovement 0x0
	loadpointer 0 str_faun_intro_0
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
	applymovement 0xFF mov_1u
	waitmovement 0x0
	@ Player receives their first Pokémon
	loadpointer 0 str_faun_give_pkmn
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
	callasm trainerschool_selection_init
	waitstate
	copyvar 0x8004 LASTRESULT
	bufferpokemon 0x0 LASTRESULT
	givepokemon 0x8004 0x5 ITEM_SINELBEERE 0x0 0x0 0x0
	fanfare 0x13e
	loadpointer 0x0 str_player_received_b1
	callstd MSG_KEEPOPEN
	waitfanfare
	closeonkeypress
	call ow_script_set_nickname
	setflag PKMNMENU
	special 0x16F
	applymovement 0xFF mov_1dfu
	waitmovement 0x0
	applymovement PERSON_RIVAL mov_1u1rfu
	waitmovement 0x0
	pause 32
	applymovement PERSON_FAUN mov_dinplace
	waitmovement 0
	loadpointer 0 str_rival_received_pkmn
	show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY
	applymovement PERSON_RIVAL mov_1l1dfu
	waitmovement 0
	loadpointer 0 str_faun_call_may
	applymovement PERSON_MAY mov_1u2lfu
	waitmovement 0
	pause 32
	applymovement PERSON_FAUN mov_dinplace
	waitmovement 0
	loadpointer 0 str_may_received_pkmn
	show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT
	applymovement PERSON_MAY mov_2r1dfu
	waitmovement 0
	loadpointer 0 str_faun_call_for_battle
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
	loadpointer 0 str_blaise_call_0
	show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT
	sound 0x15
	applymovement PERSON_FAUN mov_exclam
	applymovement PERSON_RIVAL mov_fl_exclam
	applymovement PERSON_MAY mov_fl_exclam
	applymovement PERSON_FELIX mov_fr_exclam
	applymovement 0xFF mov_fl_exclam
	waitmovement 0
	loadpointer 0 str_blaise_call_1
	show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT
	applymovement PERSON_BLAISE mov_1d1r1d
	waitmovement 0
	applymovement PERSON_FELIX mov_fd
	applymovement PERSON_MAY mov_fd
	applymovement PERSON_RIVAL mov_fd
	applymovement 0xFF mov_fd
	waitmovement 0
	sound 0x9
	hidesprite PERSON_BLAISE
	checksound
	pause 32
	loadpointer 0 str_felix_at_blaise
	show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT emotion=MUGSHOT_SCARED
	loadpointer 0 str_faun_angry_at_blaise
	show_mugshot MUGSHOT_FAUN MUGSHOT_RIGHT emotion=MUGSHOT_ANGRY
	applymovement PERSON_FELIX mov_fu
	waitmovement 0
	loadpointer 0 str_felix_prevents_faun
	show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
	applymovement PERSON_RIVAL mov_fu
	applymovement PERSON_MAY mov_fu
	applymovement 0xFF mov_fu
	waitmovement 0
	loadpointer 0 str_faun_angry_at_felix
	show_mugshot MUGSHOT_FAUN MUGSHOT_RIGHT emotion=MUGSHOT_ANGRY hide_mugshot=0
	loadpointer 0 str_faun_contemplates
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	applymovement PERSON_FELIX mov_3l1ufr
	applymovement PERSON_MAY mov_1u3l
	waitmovement 0
	loadpointer 0 str_faun_call_player_and_rival
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
	applymovement 0xFF mov_1u1r
	applymovement PERSON_RIVAL mov_5r1ufl
	waitmovement 0
	special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
	applymovement 0x7f mov_2r2d
	waitmovement 0
	special SPECIAL_OVERWORLD_VIEWPORT_LOCK
	loadpointer 0 str_rival_challange2
	show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY
	compare STARTER_SELECTED 0
	gotoif EQUAL plant_chosen
	compare STARTER_SELECTED 1
	gotoif EQUAL fire_chosen
	compare STARTER_SELECTED 2
	gotoif EQUAL water_chosen
	end

plant_chosen:
	trainerbattlelosable 0x9 0xb3 0x1 str_won2 str_lost2
	goto after_rival_battle
fire_chosen:
	trainerbattlelosable 0x9 0xb4 0x1 str_won2 str_lost2
	goto after_rival_battle
water_chosen:
	trainerbattlelosable 0x9 0xb5 0x1 str_won2 str_lost2
	goto after_rival_battle
after_rival_battle:
	compare LASTRESULT 1
	gotoif EQUAL lost_battle
	goto won_battle
lost_battle:
	loadpointer 0 str_after_battle_lost
	show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
	goto after_battle
won_battle:
	loadpointer 0 str_after_battle_won
	show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_SCARED
	goto after_battle
after_battle:
	special SPECIAL_HEAL
	special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
	applymovement 0x7f mov_7l
	waitmovement 0
	special SPECIAL_OVERWORLD_VIEWPORT_LOCK
	loadpointer 0 str_may_lost
	show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT emotion=MUGSHOT_SAD
	loadpointer 0 str_felix_won
	show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_HAPPY hide_mugshot=0
	update_mugshot_emotion MUGSHOT_NORMAL
	loadpointer 0 str_felix_won2
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
	applymovement 0x7f mov_6r
	waitmovement 0
	special SPECIAL_OVERWORLD_VIEWPORT_LOCK
	applymovement 0xFF mov_1lfu
	applymovement PERSON_RIVAL mov_4lfu
	applymovement PERSON_MAY mov_1rfu
	applymovement PERSON_FELIX mov_4rfu
	waitmovement 0
	loadpointer 0 str_announce_end
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
	applymovement PERSON_FAUN mov_2lfd
	waitmovement 0
	loadpointer 0 str_final_call_felix
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
	applymovement PERSON_FELIX mov_uinplace
	waitmovement 0
	loadpointer 0 str_final_call_felix_reply
	show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY
	applymovement PERSON_FAUN mov_1rfd
	waitmovement 0
	loadpointer 0 str_final_call_may
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
	applymovement PERSON_MAY mov_uinplace
	waitmovement 0
	loadpointer 0 str_final_call_may_reply
	show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY
	applymovement PERSON_FAUN mov_1rfd
	waitmovement 0
	loadpointer 0 str_final_call_player
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
	fanfare 0x13E
	applymovement 0xFF mov_uinplace
	waitmovement 0
	waitfanfare
	pause 32
	applymovement PERSON_FAUN mov_1rfd
	waitmovement 0
	loadpointer 0 str_final_call_rival
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
	applymovement PERSON_RIVAL mov_uinplace
	waitmovement 0
	loadpointer 0 str_final_call_rival_reply
	show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY
	applymovement PERSON_FAUN mov_1lfd
	waitmovement 0
	loadpointer 0 str_final_call_faun
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT hide_mugshot=0
	loadpointer 0 str_final_call_faun2
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	applymovement PERSON_FAUN mov_2r2d2l1d
	waitmovement 0
	sound 0x9
	hidesprite PERSON_FAUN
	checksound
	setflag TRAINERSCHOOL_FAUN_OUTSIDE
	clearflag (FLAG_TRAINERSCHOOL_FAUN_INSIDE | 0x8000)
	setvar TRAINERSCHOOL_PROGRESS 4 
	releaseall
	end

mov_face_down_and_exclam:
	.byte LOOK_DOWN, SAY_EXCLAM, STOP
mov_1dfu:
	.byte STEP_DOWN, LOOK_UP, STOP
mov_1u1rfu:
	.byte STEP_UP, STEP_RIGHT, LOOK_UP, STOP
mov_dinplace:
	.byte STEP_IN_PLACE_DOWN, STEP_IN_PLACE_DOWN, STOP
mov_1l1dfu:
	.byte STEP_LEFT, STEP_DOWN, LOOK_UP, STOP
mov_1u2lfu:
	.byte STEP_UP, STEP_LEFT, LOOK_UP, STOP
mov_2r1dfu:
	.byte STEP_RIGHT, STEP_DOWN, LOOK_UP, STOP
mov_fl_exclam:
	.byte LOOK_LEFT, SAY_EXCLAM, STOP
mov_fr_exclam:
	.byte LOOK_RIGHT, SAY_EXCLAM, STOP
mov_1d1r1d:
	.byte STEP_DOWN, STEP_RIGHT, STEP_DOWN, STOP
mov_3l1ufr:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_UP, LOOK_RIGHT, STOP
mov_1u3l:
	.byte STEP_UP, STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP
mov_5r1ufl:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT
	.byte STEP_UP, LOOK_LEFT, STOP
mov_1u1r:
	.byte STEP_UP, STEP_RIGHT, STOP
mov_2r2d:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_DOWN, STEP_DOWN, STOP
mov_1lfu:
	.byte STEP_LEFT, LOOK_UP, STOP
mov_4lfu:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, LOOK_UP, STOP
mov_1rfu:
	.byte STEP_RIGHT, LOOK_UP, STOP
mov_4rfu:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, LOOK_UP, STOP
mov_2lfd:
	.byte STEP_LEFT, STEP_LEFT, LOOK_DOWN, STOP
mov_uinplace:
	.byte STEP_IN_PLACE_UP, STEP_IN_PLACE_UP, STOP
mov_1rfd:
	.byte STEP_RIGHT, LOOK_DOWN, STOP
mov_1lfd:
	.byte STEP_LEFT, LOOK_DOWN, STOP
mov_2r2d2l1d:
	.byte STEP_RIGHT, STEP_RIGHT
	.byte STEP_DOWN, STEP_DOWN
	.byte STEP_LEFT, STEP_LEFT
	.byte STEP_DOWN, STEP_DOWN, STOP

.ifdef LANG_GER
str_faun_rant_0:
	.autostring 34 2 "Was für eine Unverschämtheit!\pAm Tag der Prüfung zu spät erscheinen!\pZu meinen Zeiten-"
str_faun_rant_1:
	.autostring 34 2 "PLAYER!\nWie überaus freundlich von dir, auch noch vorbei zu kommen!\pIch sollte euch für diese Frechheit, zu spät zu kommen, eigentlich gleich wieder nach Hause schicken!\pDann hättet ihr nochmal ein Jahr Zeit, etwas Anstand zu lernen!"
str_faun_rant_2:
	.autostring 34 2 "DOTSPAUSE\x3C DOTSPAUSE\x3C DOTSPAUSE\x3C"
str_faun_rant_3:
	.autostring 34 2 "Na wird's bald?\pKommt gefälligst her!"
str_faun_intro_0:
	.autostring 34 2 "Dann machen wir 'mal weiterDOTS\pWie ihr wisst, wird euer Abschlusstest aus einem Kampf gegen einen anderen Schüler bestehen.\pAber zuerst braucht ihr natürlich noch ein Pokémon.\pDiejenigen, die sich durch hervorragende Leistungen hervorgetan haben, dürfen sich zuerst ein Pokémon aussuchen.\pBlaise und Felix haben bereits ein Pokémon erhalten.\pPLAYER!\nDu bist als Nächstes an der Reihe."
str_faun_give_pkmn:
	.autostring 34 2 "Du solltest dich wirklich glücklich schätzen, dass du ein so vielversprechender Schüler bist!\pObwohl du zu spät gekommen bist, darfst du dir eines dieser erstklassigen Pokémon aussuchen."
str_player_received_b1:
    .string "PLAYER hat ein BUFFER_1\nerhalten!"
str_faun_call_rival:
	.autostring 34 2 "Rival, du bist als Nächstes an der Reihe.\pKomm zu mir!"
str_rival_received_pkmn:
	.autostring 34 2 "Spitze!\nDas ist ja ein tolles Pokémon!\pWie gemacht für den kommenden Champion der Theto Region!"
str_faun_call_may:
	.autostring 34 2 "May, du bist als Letzte dran."
str_may_received_pkmn:
	.autostring 34 2 "O-Oh!\nDanke, Herr Faun!\pAuch wenn ich nicht so gut bin wie die anderen, werde ich versuchen, mein Bestes zu geben.\pWenn ich als Schlusslicht der Klasse schon ein so starkes Pokémon bekomme, muss ich mich ganz besonders anstrengen."
str_faun_call_for_battle:
	.autostring 34 2 "Ausgezeichnet!\pJetzt, wo ihr alle ein Pokémon habt, können wir mit dem Test beginnen.\pIhr werdet gegeneinander antreten.\pReiht euch dafür-"
str_blaise_call_0:
	.autostring 34 2 "Herr Faun!"
str_blaise_call_1:
	.autostring 34 2 "Ich bin Ihnen wirklich dankbar für alles, was Sie für mich getan haben.\pAber ich kann meine Zeit nicht mit dieser albernen Prüfung verschwenden.\pWenn ich mein Ziel erreichen will, muss ich so schnell wie möglich stärker werden.\pMit diesem PokémonDOTS DOTS DOTS\pSie waren ein guter Lehrer.\pAber nun ist es an der Zeit, dass ich meinen eigenen Weg gehe."
str_felix_at_blaise:
	.autostring 34 2 "Blaise, warte!"
str_faun_angry_at_blaise:
	.autostring 34 2 "Blaise!\nWas fällt dir ein?\pDu kannst doch nicht einfach so gehen!\pDiese Dreistigkeit!\nMein Pokémon zu nehmen und dann einfach so zu verschwinden!\pDem werd' ich's passend machen!\pNa warte!"
str_felix_prevents_faun:
	.autostring 34 2 "Opi, bitte!\pWir müssen doch noch die Prüfung machen!"
str_faun_angry_at_felix:
	.autostring 34 2 "Felix!\pIch hab' dir schon hundert mal gesagt, dass du mich Herr Faun zu nennen hast!\pUnd ich kann doch Blaise diese Unverschämtheit nicht einfach so durchgehen lassen!"
str_faun_contemplates:
	.autostring 34 2 "DOTSPAUSE\x3C DOTSPAUSE\x3C DOTSPAUSE\x3C\pNa gutDOTS\pIch werde diesen Bengel später zur Rechenschaft ziehen.\pAber ihr vier habt euch eine ordentliche Prüfung verdient.\pWir fahren jetzt einfach fort.\pFindet euch auf dem Kampffeld ein.\pFelix, Maike!\pIhr seid das erste Paar!"
str_faun_call_player_and_rival:
	.autostring 34 2 "PLAYER, RIVAL!\pIhr seid das zweite Paar!"
str_rival_challange2:
	.autostring 34 2 "Endlich keine leeren Worte mehr!\pJetzt werden wir sehen, wer von uns beiden wirklich der Bessere ist!\pMach dich auf 'was gefasst, PLAYER!"
str_won2:
	.autostring 34 2 "Was?\nDas kann nicht sein!\pDu hast geschummelt, ich will nochmal!"
str_lost2:
	.autostring 34 2 "Das war's?\pMehr hast du nicht drauf?\pIch hab noch nicht 'mal angefangen!"
str_after_battle_lost:
	.autostring 34 2 "Hah!\nHab ich dir nicht gesagt, dass ich der bessere Trainer bin?\pMach dir nichts draus, gegen mich zu verlieren ist keine Schande!"
str_after_battle_won:
	.autostring 34 2 "Anfängerglück!\pIch war nicht ganz bei der Sache.\pAber ich gönne dir den Sieg natürlich.\pImmerhin wird es dein einziger gegen mich sein!"
str_may_lost:
	.autostring 34 2 "Ich wusste esDOTS\pIch tauge einfach nicht zum TrainerDOTS"
str_felix_won:
	.autostring 34 2 "Na das war doch 'was oder?\pWillst du nach einer Niederlage etwa schon aufgeben?\pDas würde Opi gar nicht gefallen!"
str_felix_won2:
	.autostring 34 2 "DOTS DOTS DOTS\pMach dir nichts draus, Maike!\pDu hast dich doch nicht schlecht geschlagen.\pBeim nächsten Mal gewinnst du, da bin ich mir sicher!"
str_may_lost2:
	.autostring 34 2 "J-Ja?\nMeinst du wirklich?"
str_announce_end:
	.autostring 34 2 "Ausgezeichnet!\pDas war's auch schon!\pIch werde euch jetzt die Ergebnisse mitteilen.\pMeinem kritischen Blick entgeht nichts, Kinder!"
str_final_call_felix:
	.autostring 34 2 "Felix, mein JungeDOTS\pDu bist zweifellos ein fleißiger Bursche.\pDu hast dir jede Lektion genaustens zu Herzen genommen.\pUnd folglich hast du deinen Kampf meisterhaft geführt.\pEs sollte dich nicht überraschen, dass du bestanden hast, Kleiner!"
str_final_call_felix_reply:
	.autostring 34 2 "Hihi!\nDanke, Opi!\pÄhm, ich meine natürlich Herr Faun!\pDu warst ein toller Lehrer!\pIch werde dich auch in Zukunft nicht enttäuschen, versprochen!"
str_final_call_may:
	.autostring 34 2 "MaikeDOTS\pEs steht außer Frage, dass du dich wirklich bemüht hast.\pDu hast dir ein umfassendes Wissen hart erarbeitet und auch deinen Kampf hervorragend geführt.\pAberDOTS\pDir fehlt der Glaube an dich selbst, Mädchen!\pVertrau deinen Fähigkeiten.\pDu hast das Zeug zu einer großartigen Trainerin.\pAuch du hast bestanden, Maike!\pKopf hoch!"
str_final_call_may_reply:
	.autostring 34 2 "O-Oh!\nW-Wirklich?\pDanke, Herr Faun!\pIch werde versuchen, mich zu bessern.\pIch werde hart an mir arbeiten!"
str_final_call_player:
	.autostring 34 2 "PLAYER!\nWas dir an Fleiß fehlt, machst du mit einem außerordentlichen Talent wett.\pDu hast dich hervorragend geschlagen.\pDu scheinst, eine ganz besondere Verbindung zu deinem Pokémon zu haben.\pUnd das, obwohl du es erst heute bekommen hast.\pDu bist zum Trainer berufen.\pBestanden, Kindchen!"
str_final_call_rival:
	.autostring 34 2 "RIVALDOTS\pDu bereitest mir wie immer Kopfzerbrechen.\pDu bist äußert talentiert.\pAber du bist auch ein Hitzkopf und handelst oft unüberlegt.\pEin Trainer muss zuallerst sich selbst unter Kontrolle haben.\pSonst kann er seine Pokémon auch nicht in den Griff bekommen.\pNach deinem Kampf gegen PLAYER bin ich überzeugt, dass du ein großer Trainer werden kannst.\pAuch du bestehst, RIVAL!"
str_final_call_rival_reply:
	.autostring 34 2 "Yippee!\nIch hab's geschafft!\pJetzt werde ich der größte Pokémon-Trainer aller Zeiten werden!"
str_final_call_faun:
	.autostring 34 2 "Sehr gut, Kinder!\pIhr habt mich alle sehr stolz gemacht!\pNoch nie hat ein ganzer Jahrgang bestanden!\pJetzt seid ihr alle Pokémon-Trainer.\pDas ist erst der Anfang.\pJetzt seid ihr auf euch gestellt.\pWo wird euch das Abenteuer hinführen?\pDas liegt jetzt ganz bei euch.\pAber in einem bin ich mir absolut sicher.\pIhr werdet alle großartige Trainer werden.\pIch wünsche euch alles Gute auf eurem Weg!\pVergesst nichtDOTS"
str_final_call_faun2:
	.autostring 34 2 "Dieser alte Herr hier hält euch immer den Rücken frei, komme was wolle!"
.elseif LANG_EN
str_faun_rant_0:
	.autostring 34 2 "What a nerve!\pShowing up late on the day of the exam!\pIn my day-"
str_faun_rant_1:
	.autostring 34 2 "PLAYER!\nHow nice of you to show up!\pI should send you home for your rudeness!\pYou should have one more year to learn some manners!"
str_faun_rant_2:
	.autostring 34 2 "DOTSPAUSE\x3C DOTSPAUSE\x3C DOTSPAUSE\x3C"
str_faun_rant_3:
	.autostring 34 2 "Well, are you coming or not?\pCome here!"
str_faun_intro_0:
	.autostring 34 2 "Let's continue.\pAs you know, your final exam will consist of a battle against another student.\pBut first, you need a Pokémon.\pThose who have excelled in their studies will be allowed to choose first.\pBlaise and Felix have already received their Pokémon.\pPLAYER!\nYou are next in line."
str_faun_give_pkmn:
	.autostring 34 2 "You should feel lucky to be such a promising student!\pEven though you showed up late, you are allowed to choose one of these top-notch Pokémon."
str_player_received_b1:
	.string "PLAYER received a BUFFER_1!"
str_faun_call_rival:
	.autostring 34 2 "Rival, you are next.\pCome to me!"
str_rival_received_pkmn:
	.autostring 34 2 "Great!\nThis is a wonderful Pokémon!\pIt is made for the future champion of the Theto Region!"
str_faun_call_may:
	.autostring 34 2 "May, you are last."
str_may_received_pkmn:
	.autostring 34 2 "O-Oh!\nThank you, Mr. Faun!\pEven though I am not as good as the others, I will try my best.\pIf I get such a strong Pokémon as the last one in class, I have to work extra hard."
str_faun_call_for_battle:
	.autostring 34 2 "Excellent!\pNow that you all have a Pokémon, we can start the test.\pYou will battle each other.\pPlease line up on the battlefield."
str_blaise_call_0:
	.autostring 34 2 "Mr. Faun!"
str_blaise_call_1:	
	.autostring 34 2 "I am really grateful for everything you have done for me.\pBut I cannot waste my time with this silly exam.\pIf I want to achieve my goal, I need to become stronger as fast as possible.\pWith this PokémonDOTS DOTS DOTS\pYou were a good teacher.\pBut now it is time for me to go my own way."
str_felix_at_blaise:
	.autostring 34 2 "Blaise, wait!"
str_faun_angry_at_blaise:
	.autostring 34 2 "Blaise!\nWhat do you think you are doing?\pYou cannot just leave like that!\pHow dare you take my Pokémon and then just disappear!\pI will make you pay for this!\pJust wait!"
str_felix_prevents_faun:
	.autostring 34 2 "Gramps, please!\pWe still need to do the exam!"
str_faun_angry_at_felix:
	.autostring 34 2 "Felix!\pI have told you a hundred times to call me Mr. Faun!\pAnd I cannot just let Blaise get away with this insolence!"
str_faun_contemplates:
	.autostring 34 2 "DOTSPAUSE\x3C DOTSPAUSE\x3C DOTSPAUSE\x3C\pWell, alrightDOTS\pI will deal with that brat later.\pBut you four deserve a proper exam.\pLet's just continue.\pLine up on the battlefield.\pFelix, May!\pYou are the first pair!"
str_faun_call_player_and_rival:
	.autostring 34 2 "PLAYER, RIVAL!\pYou are the second pair!"
str_rival_challange2:
	.autostring 34 2 "Finally, no more empty words!\pNow we will see who is really the better one of us!\pGet ready, PLAYER!"
str_won2:
	.autostring 34 2 "What?\nThis cannot be!\pYou cheated, I want a rematch!"
str_lost2:
	.autostring 34 2 "Is that it?\pYou are not even trying!\pI haven't even started yet!"
str_after_battle_lost:
	.autostring 34 2 "Hah!\nI told you I am the better trainer!\pDon't worry about losing to me, it is no shame!"
str_after_battle_won:
	.autostring 34 2 "Beginner's luck!\pI wasn't even trying.\pBut of course I let you win!\pIt will be your only victory against me!"
str_may_lost:
	.autostring 34 2 "I knew itDOTS\pI am just not cut out to be a trainerDOTS"
str_felix_won:
	.autostring 34 2 "Well, that was something, wasn't it?\pAre you going to give up after a defeat?\pThat would not please Gramps!"
str_felix_won2:
	.autostring 34 2 "DOTS DOTS DOTS\pDon't worry, May!\pYou did not do badly.\pNext time you will win, I am sure of it!"
str_may_lost2:
	.autostring 34 2 "R-Really?\pDo you really think so?"
str_announce_end:
	.autostring 34 2 "Excellent!\pThat is it!\pI will now announce the results.\pMy critical eye misses nothing, children!"
str_final_call_felix:
	.autostring 34 2 "Felix, my ladDOTS\pYou are undoubtedly a diligent lad.\pYou have taken every lesson to heart.\pAnd as a result, you have conducted your battle masterfully.\pIt should not surprise you that you passed, little one!"
str_final_call_felix_reply:
	.autostring 34 2 "Hehe!\nThank you, Gramps!\pI mean, thank you Mr. Faun!\pYou were a great teacher!\pI will not disappoint you in the future, I promise!"
str_final_call_may:
	.autostring 34 2 "MayDOTS\pThere is no doubt that you have really tried hard.\pYou have worked hard to acquire a comprehensive knowledge and also conducted your battle excellently.\pButDOTS\pYou lack confidence in yourself.\pTrust your abilities.\pYou have what it takes to be a great trainer.\pYou also passed, May!\pKeep your chin up!"
str_final_call_may_reply:
	.autostring 34 2 "O-Oh!\nR-Really?\pThank you, Mr. Faun!\pI will try to improve.\pI will work hard on myself!"
str_final_call_player:
	.autostring 34 2 "PLAYER!\nWhat you lack in diligence, you make up for with extraordinary talent.\pYou have conducted yourself excellently.\pYou seem to have a special bond with your Pokémon.\pAnd that, even though you just got it today.\pYou are destined to be a trainer.\pYou passed, kiddo!"
str_final_call_rival:
	.autostring 34 2 "RIVALDOTS\pYou always give me a headache.\pYou are extremely talented.\pBut you are also hot-headed and often act rashly.\pA trainer must first have control over himself.\pOtherwise, he cannot control his Pokémon either.\pAfter your battle against PLAYER, I am convinced that you can become a great trainer.\pYou also pass, RIVAL!"
str_final_call_rival_reply:
	.autostring 34 2 "Yippee!\nI did it!\pNow I will become the greatest Pokémon trainer of all time!"
str_final_call_faun:
	.autostring 34 2 "Very well, children!\pYou have all made me very proud!\pNever before has a whole class passed!\pNow you are all Pokémon trainers.\pThis is just the beginning.\pNow you are on your own.\pWhere will your adventure take you?\pThat is now entirely up to you.\pBut I am absolutely sure of one thing.\pYou will all become great trainers.\pI wish you all the best on your way!\pDo not forgetDOTS"
str_final_call_faun2:
	.autostring 34 2 "This old man will always have your back, no matter what!"
.endif



ow_script_trainerschool_battle_test:
@ lockall
@ applymovement 4 mov_face_down
@ applymovement 3 mov_LOOK_UP
@ applymovement 5 mov_LOOK_UP
@ applymovement 7 mov_LOOK_UP
@ applymovement 0xFF mov_LOOK_UP
@ waitmovement 0
@ loadpointer 0 str_announce_battle
@ show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
@ applymovement 3 mov_face_right
@ applymovement 7 mov_face_right
@ applymovement 0xFF mov_face_left
@ applymovement 5 mov_face_left
@ waitmovement 0
@ pause 32
@ draw_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
@ loadpointer 0 str_rival_challange
@ callstd MSG_KEEPOPEN
@ compare STARTER_SELECTED 0
@ gotoif EQUAL plant_chosen
@ compare STARTER_SELECTED 1
@ gotoif EQUAL fire_chosen
@ compare STARTER_SELECTED 2
@ gotoif EQUAL water_chosen
@ end

@ plant_chosen:
@ trainerbattlelosable 0x9 0xb3 0x1 str_won str_lost
@ goto after_battle

@ fire_chosen:
@ trainerbattlelosable 0x9 0xb4 0x1 str_won str_lost
@ goto after_battle

@ water_chosen:
@ trainerbattlelosable 0x9 0xb5 0x1 str_won str_lost
@ goto after_battle

@ after_battle:
@ compare LASTRESULT 1
@ gotoif EQUAL lost_battle
@ won_battle:
@ loadpointer 0 str_after_battle_won
@ show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_SCARED
@ may_felix_battle:
@ clearflag FLAG_SCRIPTED_WILD_BATTLES_LOSABLE
@ special 0x113
@ applymovement 0x7f mov_cam_to_may_felix
@ waitmovement 0x0
@ loadpointer 0 str_may_lost
@ show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT emotion=MUGSHOT_SAD
@ loadpointer 0 str_felix_won
@ show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY hide_mugshot=0
@ update_mugshot_emotion MUGSHOT_NORMAL
@ loadpointer 0 str_felix_won2
@ callstd MSG_KEEPOPEN
@ closeonkeypress
@ hide_mugshot
@ applymovement 0x7F mov_cam_back
@ waitmovement 0
@ special 0x114
@ @ Battles are over
@ loadpointer 0 str_announce_end
@ show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
@ applymovement 7 mov_LOOK_UP
@ applymovement 0xFF mov_player_row
@ applymovement 5 mov_may_row
@ applymovement 3 mov_rival_row
@ waitmovement 0
@ @ Award felix
@ loadpointer 0 str_final_call_felix
@ show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
@ applymovement 7 mov_felix_to_faun
@ waitmovement 0
@ loadpointer 0 str_award_felix
@ show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
@ fanfare 0x13E
@ waitfanfare
@ loadpointer 0 str_felix_awarded
@ show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
@ applymovement 7 mov_felix_back
@ waitmovement 0
@ loadpointer 0 str_final_call_player
@ show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
@ addvar TRAINERSCHOOL_PROGRESS 1
@ releaseall
@ end

@ lost_battle:
@ special SPECIAL_HEAL
@ loadpointer 0 str_after_battle_lost
@ show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
@ goto may_felix_battle

@ mov_felix_back:
@ 	.byte STEP_RIGHT, STEP_DOWN, LOOK_UP, STOP

@ mov_felix_to_faun:
@ 	.byte STEP_UP, STEP_LEFT, LOOK_UP, STOP

@ mov_player_row:
@ 	.byte STEP_RIGHT, STEP_RIGHT, LOOK_UP, STOP

@ mov_may_row:
@ 	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, LOOK_UP, STOP

@ mov_rival_row:
@ 	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, LOOK_UP, STOP

@ mov_cam_back:
@ 	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP

@ mov_cam_to_may_felix:
@ 	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP

@ mov_face_down:
@ 	.byte LOOK_DOWN, STOP

@ mov_LOOK_UP:
@ 	.byte LOOK_UP, STOP

@ mov_face_left:
@ 	.byte LOOK_LEFT, STOP

@ mov_face_right:
@ 	.byte LOOK_RIGHT, STOP

@ 	.ifdef LANG_GER

@ str_announce_battle:
@ 	.autostring 34 2 "Also dann, ihr Gören!\pEs geht ans Eingemachte!\pIhr tretet jetzt im Kampf gegeneinander an.\pWenn ihr diese Prüfung bestehen wollt, gebt ihr besser alles!"
@ str_rival_challange:
@ 	.autostring 35 2 "Man PLAYER!\nWie lange ich auf diesen Moment gewartet habe!\pKeine leeren Sticheleien mehr!\pJetzt sehen wir, wer der Bessere ist!"
@ str_won:
@ 	.autostring 35 2 "Moment!\nDas kann nicht sein!\pDu hast geschummelt, ich will nochmal!"
@ str_lost:
@ 	.autostring 35 2 "Bist du davon überrascht?"
@ str_after_battle_won:
@ 	.autostring 35 2 "Anfängerglück!\pIch war nicht ganz bei der Sache.\pAber ich gönne dir den Sieg natürlich.\pImmerhin wird es dein einziger gegen mich sein!"
@ str_after_battle_lost:
@ 	.autostring 35 2 "Hah!\nHab ich dir nicht gesagt, dass ich der bessere Trainer bin?\pMach dir nichts draus, gegen mich zu verlieren ist keine Schande!"
@ str_may_lost:
@ 	.autostring 35 2 "Ich wusste esDOTS\pIch tauge einfach nicht zum TrainerDOTS"
@ str_felix_won:
@ 	.autostring 35 2 "Willst du nach einer Niederlage etwa schon aufgeben?"
@ str_felix_won2:
@ 	.autostring 35 2 "Das würde Opi gar nicht gefallen!\pDu hast dich doch nicht schlecht geschlagen, Maike!"
@ str_announce_end:
@ 	.autostring 35 2 "Sehr gut.\pDas war's auch schon!\pEin Kinderspiel, was?\pIch werde euch die Ergebnisse mitteilen!"
@ str_final_call_felix:
@ 	.autostring 35 2 "Felix, du bist wieder als Erster an der Reihe.\pKomm zu mir, Junge!"
@ str_award_felix:
@ 	.autostring 35 2 "Der schriftliche Test war keine Meisterleistung, aber du hast deinen Kampf gewonnen.\pDas sollte reichen, was?\pLass dir das aber nicht zu Kopf steigen!"
@ str_felix_awarded:
@ 	.autostring 35 2 "Hihi!\nDanke, Opi!\pÄhm, ich meine natürlich Herr Faun!"
@ str_final_call_player:
@ 	.autostring 35 2 "Machen wir mit dir weiter, PLAYER!\pAngetreten!"

@ .elseif LANG_EN

@ str_announce_battle:
@ 	.autostring 34 2 "Well you brats!\pNow we get down to buisness!\pYou will battle each other!\pIf you plan to pass this exam I suggest you give it all!"
@ str_rival_challange:
@ 	.autostring 35 2 "Hey, PLAYER!\pCan you imagine how long I have waited for this moment?\pNo empty banter anymore!\pNow we will find out who really is the better trainer!"
@ str_won:
@ 	.autostring 35 2 "Wait a second!\nThat can't be!\pYou cheated!\nLet's repeat the fightDOTS"
@ str_lost:
@ 	.autostring 35 2 "Are you really suprised?"
@ str_after_battle_won:
@ 	.autostring 34 2 "Beginners luck!\pI just didn't focus that much.\pBut I will give you that victory, since it will be your only one against me!"
@ str_after_battle_lost:
@ 	.autostring 35 2 "Hah!\nDidn't I tell you I'd win?\pDon't take it too seriously, losing against me is nothing be ashamed of!"
@ str_may_lost:
@ 	.autostring 35 2 "Ich knew itDOTS\pI am just not good enough to be a trainerDOTS"
@ str_felix_won:
@ 	.autostring 35 2 "Do you really want to give up after a single defeat?"
@ str_felix_won2:
@ 	.autostring 35 2 "Grandpa surely wouldn't like that!\pYou didn't do bad at all, May!"
@ str_announce_end:
@ 	.autostring 35 2 "Very well.\nThat's it!\pPiece of cake, right?\pI will give you the results now."
@ str_final_call_felix:
@ 	.autostring 35 2 "Felix, you're first again.\pCome here, boy."
@ str_award_felix:
@ 	.autostring 35 2 "Well, the written test wasn't that great, but you won your battle.\pI suppose that is sufficient.\pBut don't let that get to your head!"
@ str_felix_awarded:
@ 	.autostring 35 2 "Hihi!\nThanks, grandpa!\pOh, I mean Mr. Faun, of course!"
@ str_final_call_player:
@ 	.autostring 35 2 "Let's continue with you, PLAYER!"
@ .endif

ow_script_trainerschool_lock_grass:
	lockall
	call lockout
	applymovement 0xFF mov_down
	waitmovement 0
	releaseall
	end

ow_script_trainerschool_lock_exit:
	lockall
	call lockout
	applymovement 0xFF mov_up
	waitmovement 0x0
	releaseall
	end

lockout:
	compare TRAINERSCHOOL_PROGRESS 3
	callif EQUAL faun_not_arrived
	compare TRAINERSCHOOL_PROGRESS 4
	callif EQUAL receive_pkmn
	compare TRAINERSCHOOL_PROGRESS 5
	callif EQUAL receive_pokeballs
	compare TRAINERSCHOOL_PROGRESS 6
	callif EQUAL fight_wild_pokemon
	compare TRAINERSCHOOL_PROGRESS 7 @// Go to battle field
	callif EQUAL receive_pkmn
	compare TRAINERSCHOOL_PROGRESS 8 @// Take results from faun
	callif EQUAL receive_pkmn
	compare TRAINERSCHOOL_PROGRESS 9 @// Good-bye from npcs
	callif EQUAL goodbye
	return


goodbye:
	loadpointer 0 str_trainerschool_say_goodbye
	show_mugshot MUGSHOT_PLAYER
	return

faun_not_arrived:
	loadpointer 0 str
	show_mugshot MUGSHOT_PLAYER
	return

receive_pkmn:
	loadpointer 0 str_receive_pkmn
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
	return

receive_pokeballs:
	loadpointer 0 str_receive_pkmn
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
	return

fight_wild_pokemon:
	loadpointer 0 str_fight_wild_pokemon
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
	return

mov_up:
	.byte STEP_UP, STOP

mov_down:
	.byte STEP_DOWN, STOP

.ifdef LANG_GER
str:
    .autostring 35 2 "Ich sollte nicht zuweit weggehen, Faun wird jeden Moment hier seinDOTS"

str_receive_pkmn:
	.autostring 35 2 "Wo willst du denn hin, PLAYER!\pKomm gefälligst hierher!"

str_fight_wild_pokemon:
	.autostring 35 2 "Was ist los, PLAYER?\nFürchtest du dich etwa vor den wilden Pokémon?\pMach' keinen Unsinn und komm her!"

str_trainerschool_say_goodbye:
	.autostring 35 2 "Ich sollte mich von meinen Mitschülern verabschieden."

.elseif LANG_EN
str:
    .autostring 35 2 "I shouldn't go too far away, Faun will be here any momentDOTS"

str_receive_pkmn:
	.autostring 35 2 "Where are you going, PLAYER?\pGet yourself right here!"

str_fight_wild_pokemon:
	.autostring 35 2 "What's the deal, PLAYER?\pAfraid of the wild Pokémon?\pStop this nonsense and come here!"

str_trainerschool_say_goodbye:
	.autostring 35 2 "I should say goodbye to my classmates."

.endif


ow_script_movs_0x899c63:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x899c67:
.byte LOOK_UP
.byte STOP


ow_script_map_3_57_trigger_0:
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
sound 0x15
applymovement 0x1 ow_script_movs_0x899c63
applymovement 0xff ow_script_movs_0x899c67
waitmovement 0x0
goto ow_script_0x89c06b


ow_script_movs_0x89bfe7:
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


ow_script_0x89c06b:
loadpointer 0x0 str_0x89bfed
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 0x1 ow_script_movs_0x89bfe7
waitmovement 0x0
sound 0x9
hidesprite 0x1
checksound
fadesong MUS_TRAINERSCHOOL
setflag TRAINERSCHOOL_RIVAL
setvar STORY_PROGRESS 0x5
end


.ifdef LANG_GER
str_0x89bfed:
	.autostring 34 2 "Na los!\nWas dauert da denn so lange?\pDie Prüfung hat bestimmt schon angefangen!\pFaun wird uns Feuer unterm Hintern machen, wenn wir uns nicht bald blicken lassen!"
.elseif LANG_EN
str_0x89bfed:
	.autostring 34 2 "Come on!\nWhat's taking you so long?\pThe exam most likely has already started and Faun won't like us coming late at all!"
.endif

ow_script_map_3_57_trigger_1:
lockall
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
pause 0x2c
goto ow_script_0x8f6dec


ow_script_movs_0x89c14d:
.byte LOOK_RIGHT
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x89c14a:
.byte LOOK_LEFT
.byte STOP


ow_script_0x8f6dec:
sound 0x15
applymovement 0x1 ow_script_movs_0x89c14d
applymovement 0xff ow_script_movs_0x89c14a
waitmovement 0x0
goto ow_script_0x89c06b