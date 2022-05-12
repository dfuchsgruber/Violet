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
    show_mugshot MUGSHOT_IGVA MUGSHOT_RIGHT emotion=MUGSHOT_RUMINATIVE message_type=MSG_KEEPOPEN hide_mugshot=0
    loadpointer 0 str_igva_6
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6_2
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_7
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_8
    update_mugshot_emotion MUGSHOT_SAD
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_9
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_10
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_11
    update_mugshot_emotion MUGSHOT_SCARED
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_12
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_13
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_14
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
    .autostring 34 2 "Siehst du?\nGanz leicht, oder?\pBeeilen wir uns am Besten, PLAYER"
str_igva_2:
    .autostring 34 2 "PLAYER!"
str_igva_3:
    .autostring 34 2 "Wie schön, dass du gekommen bist!"
str_igva_4:
    .autostring 34 2 "Setz' dich doch zu mirDOTS"
str_igva_5:
    .autostring 34 2 "AlsoDOTSTEXT_DELAY_SHORT\pWo fange ich bloß an?"
str_igva_6:
    .autostring 34 2 "Vielleicht sollte ich mich zuerst einmal entschuldigen, dich einfach so überrumpelt zu haben.\pEs ist normalerweise auch gar nicht meine Art, irgendwelche Menschen einfach so anzusprechenDOTS"
str_igva_6_2:
    .autostring 34 2 "Zumindest nichtDOTSTEXT_DELAY_SHORT\nDOTSTEXT_DELAY_SHORT immer!"
str_igva_7:
    .autostring 34 2 "Aber du hast dieses Feuer in den Augen!"
str_igva_8:
    .autostring 34 2 "Und das hat mich an einen ehemaligen Freund erinnertDOTS"
str_igva_9:
    .autostring 34 2 "Wir beide wollten damals etwas verändern!\pWeißt du, was ich meine?\pDieses ganze System der Pokémon-LigaDOTS\pEs dient doch schon lange nur noch denen, die ganz oben stehen und tut rein gar nichts mehr für die Menschen in dieser Region, oder?"
str_igva_10:
    .autostring 34 2 "Deswegen kämpfe ich für eine Veränderung!"
str_igva_11:
    .autostring 34 2 "DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT\pH-Habe ich zu viel gesagt?\pD-Du siehst mich so verurteilend a-anDOTS"
str_igva_12:
    .autostring 34 2 "Dabei kann ich deine Skepsis ja verstehen.\pEs hat auch für mich gedauert, bis ich eingesehen habe, dass wir Veränderung brauchen."
str_igva_13:
    .autostring 34 2 "Ich mache dir ein Angebot, PLAYER, ja?"
str_igva_14:
    .autostring 34 2 "Lass mich dir etwas zeigen, das dir die Augen öffnen wird.\pEin schmutziges Geheimnis dieser StadtDOTS\pUnd das nicht nur unter den Augen der Top Vier, sondern sogar von ihnen unterhalten!\pIch werde dir zeigen, in welche Machenschaften die Pokémon-Liga verstrickt ist!"
str_igva_15:
    .autostring 34 2 "Na mach schon, PLAYER!\pWorauf wartest du denn?"

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