.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "pathfinding.s"

.global ow_script_0x958ba3
.global ow_script_map_9_16_trigger_0
.global ow_script_0x958a9b
.global ow_script_0x958d18
.global ow_script_0x959e29
.global ow_script_0x958d28
.global ow_script_0x958ca6
.global ow_script_0x958bfa
.global ow_script_map_9_16_trigger_1
.global ow_script_0x958b36

ow_script_map_9_16_trigger_0:
    checkflag ORINA_CITY_MISTRALS_GRUNTS
    gotoif EQUAL ow_script_0x958a9b
    special2 LASTRESULT 0x1aa
    compare LASTRESULT 0x1
    gotoif EQUAL ow_script_0x958ca6
    showmoney 0x0 0x0 0x0
    loadpointer 0x0 str_0x958c0b
    callstd MSG_YES_NO
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_0x958bfa
    checkmoney 500 0x0
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_0x958ba3
    closeonkeypress
    sound 0x41
    paymoney 500 0x0
    updatemoney 0x0 0x0 0x0
    checksound
    loadpointer 0x0 str_0x958b7e
    callstd MSG_KEEPOPEN
    hidemoney 0x0 0x0
    goto ow_script_0x958d28

ow_script_0x958d28:
    closeonkeypress
    applymovement 0xff mov_1u
    waitmovement 0x0
    end

ow_script_0x958ba3:
    hidemoney 0x0 0x0
    loadpointer 0x0 str_0x958bb4
    callstd MSG_KEEPOPEN
    goto ow_script_0x958d18

ow_script_0x958d18:
    closeonkeypress
    applymovement 0xff mov_1d
    waitmovement 0x0
    end

ow_script_0x958bfa:
    hidemoney 0x0 0x0
    loadpointer 0x0 str_0x958cc7
    callstd MSG_KEEPOPEN
    goto ow_script_0x958d18

ow_script_0x958ca6:
    loadpointer 0x0 str_0x958d38
    callstd MSG_YES_NO
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_0x958d28
    loadpointer 0x0 str_0x958cc7
    callstd MSG_KEEPOPEN
    goto ow_script_0x958d18

ow_script_0x958a9b:
    special2 LASTRESULT 0x1aa
    compare LASTRESULT 0x1
    gotoif EQUAL ow_script_0x958b36
    loadpointer 0x0 str_0x958ab9
    callstd MSG_KEEPOPEN
    goto ow_script_0x958d28

ow_script_0x958b36:
    loadpointer 0x0 str_0x958b44
    callstd MSG_KEEPOPEN
    goto ow_script_0x958d18


.ifdef LANG_GER

str_0x958c0b:
    .autostring 34 2 "Willkommen im Orina City Museum.\pWir verfügen über die größte Ausstellung antiker Objekte in der ganzen Region.\pDer Eintritt kostet 500POKEDOLLAR.\pMöchtest du eine Karte kaufen?"
str_0x958b7e:
    .autostring 34 2  "Viel Freude bei deinem Aufenthalt."
str_0x958bb4:
    .autostring 34 2  "Entschuldigung, aber mir scheint, du hast nicht genügend POKEDOLLAR bei dir."
str_0x958cc7:
    .autostring 34 2  "Komm jederzeit wieder, falls du dir weitere Austellungsstücke ansehen möchtest."
str_0x958d38:
    .autostring 34 2  "Möchtest du das Museum schon wieder verlassen?"
str_0x958ab9:
    .autostring 34 2  "Bitte hilf uns!\pEin Kommandant von Team Violet ist hier eingedrungen und wir fürchten, dass er es auf unsere Ausstellungsstücke abgesehen hat."
str_0x958b44:
    .autostring 34 2 "W-Wo willst du hin?\pBitte, wir brauchen deine Hilfe, um mit dem Team Violet Kommandanten hier fertig zu werden."


.elseif LANG_EN

.endif


ow_script_movs_0x959dfe:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x959a08:
.byte LOOK_UP
.byte STOP


ow_script_map_9_16_trigger_1:
    lockall
    fadesong 0
    loadpointer 0x0 str_mistral_0
    show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT mask_name=1
    applymovement 0xFF mov_fd
    waitmovement 0
    sound 0x15
    applymovement 0xFF mov_exclam
    waitmovement 0
    checksound
    clearflag (1 | 0x8000)
    showsprite 0xd
    showsprite 0xe
    npc_move_to_player 0xd waitmovement=0
    npc_move_to 0xe 0x9 0x8 waitmovement=0
    waitmovement 0x0
    applymovement 0xd mov_fu
    applymovement 0xe mov_fu
    waitmovement 0x0
    pause 24
    loadpointer 0 str_mistral_1
    show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT mask_name=1
    pause 16
    setvar 0x8004 3
    special SPECIAL_CUTSCENE_SHOW
    waitstate
    pause 64
    playsong MUS_MISTRAL 0x0
    loadpointer 0x0 str_mistral_2
    show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT mask_name=1 emotion=MUGSHOT_SHOCKED hide_mugshot=0 message_type=MSG_KEEPOPEN
    loadpointer 0 str_mistral_3
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    pause 32
    sound 0x15
    applymovement 0xd mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_mistral_4
    show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT mask_name=1 message_type=MSG_KEEPOPEN
    loadpointer 0 str_mistral_5
    show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
    npc_move_to 0xd 0x9 0x4
    applymovement 0xd mov_fu
    waitmovement 0x0
    npc_move_to_player 0xe
    setvar LASTTALKED 0xe
    setvar SONG_OVERRIDE MUS_MISTRAL
    trainerbattlecont 0x1 0x91 0x0 str_before str_after after_battle
after_battle:
    setvar SONG_OVERRIDE 0
    loadpointer 0x0 str_mistral_6
    callstd MSG
    applymovement 0xff mov_fu
    applymovement 0xd mov_fd
    waitmovement 0x0
    loadpointer 0x0 str_mistral_7
    show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
    applymovement 0xd mov_fu
    waitmovement 0x0
    sound 0x14
    setmaptile 0x9 0x2 0x2d2 0x1
    setmaptile 0xa 0x2 0x2d3 0x1
    setmaptile 0x9 0x3 0x2da 0x1
    setmaptile 0xa 0x3 0x2db 0x1
    special 0x8e
    pause 0x1c
    loadpointer 0x0 str_mistral_8
    show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT emotion=MUGSHOT_HAPPY
    pause 24
    npc_move_to_player 0xd
    faceplayer
    loadpointer 0x0 str_mistral_9
    show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT hide_mugshot=0 message_type=MSG_KEEPOPEN
    loadpointer 0 str_mistral_10
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    pause 24
    fadescreen 0x1
    hidesprite 0xd
    hidesprite 0xe
    hidesprite 0x9
    hidesprite 0xa
    hidesprite 0xb
    hidesprite 0xc
    applymovement 0xff mov_fd
    waitmovement 0x0
    fadesong MUS_AZURIA_CITY_AND_FEUERHOHLE_AND_FUCHSANIA_CITY
    fadescreen 0x0
    pause 32
    showsprite 0xf
    npc_move_to_player 0xf
    faceplayer
    loadpointer 0 str_director
    setvar 0x8000 0
    special SPECIAL_NAME_SHOW
    loadpointer 0x0 str_0x9595b1
    callstd MSG_KEEPOPEN
    special SPECIAL_NAME_DELETE
    fanfare 0x13e
    loadpointer 0x0 str_0x95957f
    callstd MSG_KEEPOPEN
    waitfanfare
    loadpointer 0 str_director
    setvar 0x8000 0
    special SPECIAL_NAME_SHOW
    loadpointer 0x0 str_0x9594d2
    callstd MSG
    special SPECIAL_NAME_DELETE
    setflag PKMNMENU
    setflag ORINA_CITY_VIOLET_GRUNTS
    addvar STORY_PROGRESS 0x1
    warpmuted 0x3 0x5 0x2 0x0 0x0
    waitstate
    releaseall
    end


.ifdef LANG_GER

str_mistral_0:
    .autostring 34 2 "Hey du da!\pKeinen Schritt weiter!"
str_mistral_1:
    .autostring 34 2 "Geh beiseite, du-"
str_mistral_2:
    .autostring 34 2 "W-Was war das?\pH-Habe ich mir das eben eingebildet?"
str_mistral_3:
    .autostring 34 2 "Wer bist du?\pWas hast du hier zu suchen?"
str_mistral_4:
    .autostring 34 2 "PLAYER also?\pDann bist du das Kind, das unsere Pläne im Kranzwald durchkreuzt hat.\pDu hast Rin eine üble Blamage verpasst, oder?"
str_mistral_5:
    .autostring 34 2 "Mein Name ist Mistral und ich bin Kommandant der zweiten Division von Team Violet.\pWir haben hier im Museum etwas zu erledigenDOTS\pAber es scheint so, als würdest du dich uns wieder einmal in den Weg stellen wollen.\pSo sehr ich auch gegen dich kämpfen möchte, habe ich es sehr eilig.\pAber in meiner Division kämpfen wir ohnehin auf einem anderen Level, als in Rins Gruppe.\pMal sehen, ob du etwas gegen meine besten Leute ausrichten kannst."
str_before:
    .autostring 34 2 "Du bist also das Kind, das Rin besiegt hat, oder?\pWenn ich dich also schlage, dann steige ich bestimmt zum Kommandanten auf."
str_after:
    .autostring 34 2 "UffDOTS\pDas war so aber nicht geplant.\pEs tut mir leid, MistralDOTS"
str_mistral_6:
    .autostring 34 2 "I-Ich konnte das Kind leider nicht aufhalten, MistralDOTS"
str_mistral_7:
    .autostring 34 2 "Das ist auch gar nicht nötig.\pDu hast mir genügend Zeit verschafft."
str_mistral_8:
    .autostring 34 2 "Endlich!\pDas Magmaherz gehört nun mirDOTS"
str_mistral_9:
    .autostring 34 2 "Scheint wohl so, als wärst du wirklich ein ernstzunehmender Gegner.\pAber obwohl du deinen Kampf gewonnen hast, bin ich derjenige, der siegreich davongeht.\pIch habe bekommen, was ich wollte."
str_mistral_10:
    .autostring 34 2 "Und bei unserem nächsten Aufeinandertreffen, werde ich dich mit einer Macht vernichten, wie sie die Welt seit Urzeiten nicht mehr gesehen hat."
str_director:
	.string "Museumsdirektor"
str_0x9595b1:
	.autostring 35 2 "Meine Güte!\nIch hatte Todesangst!\pEin Kommandant von Team Violet DOTS\pDOTS in meinem Museum!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pVerzeih bitte, ich habe mich noch nicht vorgestellt.\pIch bin der Direktor des Museums und stehe wohl tief in deiner Schuld.\pEin Artefakt wurde zwar entwendet, aber sonst scheint dem Museum nichts weiter geschehen zu sein.\pTausendfachen Dank!\nWie kann ich mich nur erkenntlich zeigen?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pOh, ich weiß!\nDu bist ein Trainer, nicht wahr?\pSeit einiger Zeit arbeiten wir mit der Laz. Corp. an der Restauration ausgestorbener Pokémon durch Fossilien.\pIch werde deine Zugangsberechtigungen entsprechend erweitern, sodass du deine Fossilien dort wiederherstellen lassen kannst."
str_0x95957f:
    .autostring 35 2 "PLAYER wurde der Zugang zum\nFossilienlabor gewährt!"
str_0x9594d2:
    .autostring 35 2 "Es ist natürlich ein schwerer Schlag, dass wir das Magmaherz verloren haben.\pNichtsdestotrotz bist du der Held des Tages!\pIch stehe auf ewig tief in deiner Schuld."

.elseif LANG_EN

.endif