.include "overworld_script.s"
.include "flags.s"
.include "vars.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "movements.s"
.include "species.s"
.include "ingame_trades.s"
.include "pathfinding.s"

.global ow_script_kaskada_tea_house_person_0
.global ow_script_kaskada_tea_house_person_1
.global ow_script_kaskada_tea_house_person_2
.global ow_script_kaskada_tea_house_person_3
.global ow_script_kaskada_tea_house_person_4
.global ow_script_kaskada_tea_house_person_5
.global ow_script_kaskada_tea_house_person_6
.global ow_script_kaskada_tea_house_person_7
.global ow_script_kaskada_tea_house_person_8
.global ow_script_kaskada_tea_house_igva
.global ow_script_kaskada_teahouse_ingame_trade

ow_script_kaskada_tea_house_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_7:
    loadpointer 0 str_7
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_8:
    checkflag FLAG_KASKADA_TEAHOUSE_BLACK_MARKET_UNLOCKED
    gotoif EQUAL unlocked
    loadpointer 0 str_8
    callstd MSG_FACE
    end
unlocked:
    loadpointer 0 str_9
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_igva:
    lock
    faceplayer
    checkflag FLAG_KASKADA_IGVA_TEAHOUSE_INITAL_TALK
    gotoif EQUAL igva_initial_talk_done
@ Have a talk with igva

    loadpointer 0 str_igva_2
    show_mugshot MUGSHOT_IGVA MUGSHOT_RIGHT message_type=MSG_KEEPOPEN hide_mugshot=0
    loadpointer 0 str_igva_3
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_4
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    pause 32
    fadescreen 1
    movesprite 0xFF 0x4 0x7
	special SPECIAL_OVERWORLD_VIEWPORT_SET_TO_PLAYER_POSITION
    pause 1
    applymovement 0xFF mov_fl
    applymovement 11 mov_fr
    waitmovement 0
    fadescreen 0
    pause 48
    loadpointer 0 str_igva_5
    show_mugshot MUGSHOT_IGVA MUGSHOT_RIGHT emotion=MUGSHOT_BLUSHING message_type=MSG_KEEPOPEN hide_mugshot=0
    loadpointer 0 str_igva_6
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_5
    update_mugshot_emotion MUGSHOT_BLUSHING
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_51
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_52
    update_mugshot_emotion MUGSHOT_SAD
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_53
    update_mugshot_emotion MUGSHOT_BLUSHING
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_54
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_55
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_56
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_57
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_58
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_59
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_60
    update_mugshot_emotion MUGSHOT_ANGRY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_61
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_62
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_63
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    applymovement 11 mov_igva_1
    waitmovement 0
    pause 32
    applymovement 11 mov_fl
    applymovement 0xFF mov_fr
    waitmovement 0
    loadpointer 0 str_igva_15
    show_mugshot MUGSHOT_IGVA MUGSHOT_RIGHT message_type=MSG
    lockall
    npc_move_to 11 0x6 0x4
    applymovement 11 mov_fu
    waitmovement 0
    setflag FLAG_KASKADA_IGVA_TEAHOUSE_INITAL_TALK
    releaseall
    end


igva_initial_talk_done:
    loadpointer 0 str_igva_0
    show_mugshot MUGSHOT_IGVA MUGSHOT_RIGHT message_type=MSG
    applymovement 11 mov_fu
    applymovement 1 mov_fd
    waitmovement 0
    pause 48
    applymovement 11 mov_step_inplace
    waitmovement 0
    pause 48
    applymovement 1 mov_1r
    waitmovement 0
    applymovement 1 mov_fl
    waitmovement 0
    pause 48
    faceplayer
    loadpointer 0 str_igva_1
    show_mugshot MUGSHOT_IGVA MUGSHOT_RIGHT message_type=MSG
    applymovement 11 mov_2u
    waitmovement 0
    sound 9
    hidesprite 11
    checksound
    setflag FLAG_KASKADA_TEAHOUSE_BLACK_MARKET_UNLOCKED
    setflag (FLAG_KASKADA_IGVA_TEAHOUSE | 0x8000)
    release
    end

ow_script_kaskada_teahouse_ingame_trade:
	lock
	faceplayer
	setvar 0x8008, INGAME_TRADE_MOLUNK
	call ow_script_ingame_trade_get_species_info
	checkflag FLAG_KASKADA_INGAME_TRADE
    gotoif 1 already_traded
    loadpointer 0 str_want_to_trade
    callstd MSG_YES_NO
	compare LASTRESULT, 0
	gotoif EQUAL decline_trade
	call ow_script_ingame_trade_choose_party_idx_to_trade
	compare 0x8004, 6
	gotoif HIGHER_OR_EQUAL decline_trade
	call ow_script_ingame_trade_get_trade_species
	comparevars LASTRESULT, 0x8009
	gotoif NOT_EQUAL wrong_species
	call ow_script_ingame_trade
	loadpointer 0 str_after_trade
	setflag FLAG_KASKADA_INGAME_TRADE
	release
	end

decline_trade:
	call ow_script_ingame_trade_get_species_info
	loadpointer 0 str_decline_trade
    callstd MSG
	release
	end

wrong_species:
	copyvar 0x8000, LASTRESULT
	call ow_script_ingame_trade_get_species_info
	bufferpokemon 1, 0x8000
	loadpointer 0 str_wrong_species
	callstd MSG
	release
	end

already_traded:
	loadpointer 0 str_already_traded
	callstd MSG
	release
	end

mov_step_inplace:
    .byte STEP_IN_PLACE_UP, STEP_IN_PLACE_UP, STOP
mov_igva_1:
    .byte STEP_UP, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP


.ifdef LANG_GER
str_igva_0:
    .autostring 34 2 "Ich werde dir jetzt ein Geheimnis verraten, PLAYER!\pHinter dem Teehaus hier steckt viel mehr, als der Anschein verraten mag.\pDu musst nämlich wissen, dass es im Untergrund der Stadt einen Handelsplatz gibt.\pNatürlich kommt man da nicht einfach so hinein.\pAber mit mir zusammen ist das gar kein Problem.\pPass mal auf!"
str_igva_1:
    .autostring 34 2 "Siehst du?\nGanz leicht, oder?\pBeeilen wir uns am Besten, PLAYER."
str_igva_2:
    .autostring 34 2 "PLAYER!"
str_igva_3:
    .autostring 34 2 "Toll, dass du gekommen bist!"
str_igva_4:
    .autostring 34 2 "Setz' dich doch zu mirDOTS"
str_igva_5:
    .autostring 34 2 "N-Na gutDOTS\pÄhmDOTS\pDOTS DOTS DOTS"
str_igva_6:
    .autostring 34 2 "Tut mir leid, dass ich dich so überrumpelt habe."
str_igva_6_5:
    .autostring 34 2 "Aber du hast mich an jemanden erinnert, der mir einmal sehr wichtig warDOTS"
str_igva_6_51:
    .autostring 34 2 "Du hast dieses Feuer in den Augen."
str_igva_6_52:
    .autostring 34 2 "Genau wie erDOTS"
str_igva_6_53:
    .autostring 34 2 "Entschuldige bitte, PLAYER!"
str_igva_6_54:
    .autostring 34 2 "Du bist ein Trainer, oder?\pUnd ein außerordentlich guter, möchte ich wetten!\pDas sieht man dir an!\pDu hast definitiv das Zeug dazu, etwas zu verändern!"
str_igva_6_55:
    .autostring 34 2 "Ich weiß, das klingt jetzt alles sehr seltsam.\pAber du bist doch auch die Art Mensch, die nicht wegsehen kann, wenn irgendwo Unrecht passiert, habe ich Recht?"
str_igva_6_56:
    .autostring 34 2 "Dachte ich es mir doch!"
str_igva_6_57:
    .autostring 34 2 "Du hast sicher schon bemerkt, dass in Theto sehr viel Unrecht geschieht, nicht wahr?"
str_igva_6_58:
    .autostring 34 2 "Und ich habe mich der Sache verschrieben, etwas dagegen zu unternehmen!"
str_igva_6_59:
    .autostring 34 2 "Die Top VierDOTS"
str_igva_6_60:
    .autostring 34 2 "Sie sind diejenigen, die etwas unternehmen sollten!\pStattdessenDOTS"
str_igva_6_61:
    .autostring 34 2 "Müssen wir selbst die Sache in die Hand nehmen!"
str_igva_6_62:
    .autostring 34 2 "PLAYER!"
str_igva_6_63:
    .autostring 34 2 "Das ist bestimmt alles etwas verwirrend für dich.\pAber ich möchte, dass du meinen Mentor kennelernst!\pEr ist ein großer Mann, der Theto zum Besseren verändern wird.\pEr wird dir alles erklären, ja?"
str_igva_15:
    .autostring 34 2 "Folge mir, PLAYER!"

str_0:
    .autostring 34 2 "Im Teehaus ist immer sehr viel los.\pAn manchen Wochenenden bekommt man nicht einmal mehr einen Platz.\pAber das ist kaum verwunderlich bei all dem guten Tee hier!"
str_1:
    .autostring 34 2 "Es gibt wirklich keinen besseren Ort für ein Date als das Teehaus in Kaskada.\pDa fühlt man sich so richtig wohl."
str_2:
    .autostring 34 2 "Ich führe alle Mädchen, die ich kennenlerne ins Teehaus aus.\pDas ist eine narrensichere Masche.\pKannst du mir ruhig glauben."
str_3:
    .autostring 34 2 "Meine Arbeit als Polizist ist sehr hart.\pWir haben mächtig Probleme mit der RevolutionsbewegungDOTS\pUnd jetzt tauchen auch noch diese Team Violet Leute überall auf.\pDa freut man sich umso mehr darüber, seinen Feierabend im Teehaus verbringen zu können."
str_4:
    .autostring 34 2 "Herzlich willkommen im Teehaus von Kaskada.\pWir sind das beliebteste Geschäft der ganzen Stadt.\pDu solltest wirklich einmal unser großartiges Angebot verschiedener Teesorten betrachten."
str_5:
    .autostring 34 2 "Nach der Schule treffen wir uns öfter hier im Teehaus, um gemütlich einen heißen Tee zu schlürfen.\pDas lässt einen auch über schlechte Tage hinwegsehen."
str_6:
    .autostring 34 2 "Früher mal, bevor Devin von den Top Vier diesen Laden gekauft hat, war es deutlich ruhiger.\pJetzt tauchen hier immer wieder ganz seltsame Leute auf und verschwinden in den LagerraumDOTS"
str_7:
    .autostring 34 2 "Du kannst dir gar nicht vorstellen, wie anstrengend es ist, in einem so belebten Geschäft der einzige Kellner zu seinDOTS"
str_8:
    .autostring 34 2 "Hey, im Lagerraum hast du nichts zu suchen, verstanden?\pDer ist nämlich nur für besondere Gäste zugänglichDOTS"
str_9:
    .autostring 34 2 "Wenn man den ganzen Tag hier den Lagerraum bewachen muss, wird man sehr durstig.\pWas für ein Zufall, dass ich gerade in einem Teehaus arbeite."
str_want_to_trade:
    .autostring 34 2 "Ich liebe es, an einem solchen Tag einen Tee zu trinken.\pNoch mehr aber liebe ich das Pokémon BUFFER_1.\pIch würde dafür sogar mein BUFFER_2 hergeben.\pWas meinst du dazu?"
str_decline_trade:
    .autostring 34 2 "Wie schade.\pVielleicht kann ich dich aber trotzdem zu einem Tee überreden?"
str_wrong_species:
    .autostring 34 2 "Das ist aber nicht sehr höflich, zu versuchen mir ein falsches Pokémon unterzujubeln.\pIch habe doch explizit nach einem BUFFER_1 gefragt!"
str_already_traded:
    .autostring 34 2 "Hach, dieses BUFFER_1 ist wirklich toll.\pMöchtest du einen Tee, mein Kleines?"
str_after_trade:
    .autostring 34 2 "Wahnsinn!\pMit BUFFER_1 an meiner Seite schmeckt mir mein Tee doch gleich viel besser."
.elseif LANG_EN
.endif