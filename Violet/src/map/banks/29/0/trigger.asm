.include "overworld_script.s"
.include "specials.s"
.include "mugshot.s"
.include "songs.s"
.include "vars.s"
.include "movements.s"
.include "flags.s"

.global ow_script_haweiland_cargo_hall_trigger

ow_script_haweiland_cargo_hall_trigger:
    lockall
    setvar SONG_OVERRIDE MUS_PIRATE
    playsong MUS_PIRATE 0

    loadpointer 0 str_0
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    
    loadpointer 0 str_assistant
    setvar 0x8000 0
    special SPECIAL_NAME_SHOW
    loadpointer 0 str_1
    callstd MSG_KEEPOPEN
    special SPECIAL_NAME_DELETE

    loadpointer 0 str_2
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0

    sound 0x15
    applymovement 10 mov_exclamation_face_right
    applymovement 7 mov_exclamation_face_right
    applymovement 8 mov_exclamation_face_right
    applymovement 9 mov_exclamation_face_right
    waitmovement 0
    checksound

    loadpointer 0 str_assistant
    setvar 0x8000 0
    special SPECIAL_NAME_SHOW
    loadpointer 0 str_3
    callstd MSG_KEEPOPEN
    special SPECIAL_NAME_DELETE

    loadpointer 0 str_4
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0

    applymovement 9 mov_face_left
    waitmovement 0

    loadpointer 0 str_5
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0

    setvar LASTTALKED 10
    setvar 0x8004 10
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0
    settrainerflag 0x139
    trainerbattlecont 0x1 0x139 0x0 str_challange_0 str_defeat_0 cont_0
cont_0:
    setvar LASTTALKED 10
    setvar 0x8004 10
    setvar 0x8005 0x5
    setvar 0x8006 0x3
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    applymovement LASTTALKED mov_face_down
    waitmovement 0

    setvar LASTTALKED 7
    setvar 0x8004 7
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0
    settrainerflag 0x13a
    trainerbattlecont 0x1 0x13a 0x0 str_challange_1 str_defeat_1 cont_1
cont_1:
    setvar LASTTALKED 7
    setvar 0x8004 7
    setvar 0x8005 0x5
    setvar 0x8006 0x5
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    applymovement LASTTALKED mov_face_up
    waitmovement 0
    
    applymovement 9 mov_face_right
    waitmovement 0
    
    loadpointer 0 str_6
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0

    fadescreen 1
    hidesprite 1
    hidesprite 2
    hidesprite 6
    hidesprite 7
    hidesprite 9
    hidesprite 10
    fadescreen 0

    pause 0x40
    setvar SONG_OVERRIDE 0
    fadesong MUS_HAWEILAND

    setvar LASTTALKED 8
    setvar 0x8004 8
    special SPECIAL_NPC_MOVE_TO_PLAYER

    loadpointer 0 str_assistant
    setvar 0x8000 0
    special SPECIAL_NAME_SHOW
    loadpointer 0 str_7
    callstd MSG_KEEPOPEN
    special SPECIAL_NAME_DELETE

    fadescreen 1
    hidesprite 8
    fadescreen 0

    clearflag (FLAG_HAWEILAND_MAIKE | 0x8000)
    addvar STORY_PROGRESS 1
    releaseall
    end


mov_exclamation_face_right:
    .byte LOOK_RIGHT, SAY_EXCLAM, STOP
mov_face_right:
    .byte LOOK_RIGHT, STOP
mov_face_left:
    .byte LOOK_LEFT, STOP
mov_face_down:
    .byte LOOK_DOWN, STOP
mov_face_up:
    .byte LOOK_UP, STOP



.ifdef LANG_GER
str_assistant:
    .autostring 34 2 "Professor Tann's Assistent"
str_0:
    .autostring 34 2 "Ich möchte dir meine Glückwünsche ausrichten!\pEure Expedition war wirklich sehr erfolgreich.\pProfessor Tann muss außer sich gewesen sein, als ihr die Alte Karte entdeckt habt.\pWer weiß, zu welchen Orten und Schätzen sie führt?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pAch ja!\nIch weiß das!\pAber solche Fragen sind jetzt ohnehin nicht mehr dein Problem."
str_1:
    .autostring 34 2 "B-Bitte!\nDiese Karte ist doch völlig wertlos.\pNiemand wird Ihnen dafür etwas bezahlen, das kann ich Ihnen versprechen.\pUnsere Reise wurde von der Laz. Corp gesponsort, nennen Sie mir einen Preis und ich bin sicher, man wird Ihnen entgegenkommen."
str_2:
    .autostring 34 2 "Hahaha!\pMit keinem Gold der Welt könnte man das aufwiegen, zu dem die Alte Karte führt.\pIch fürchte, dass wir uns hier nicht einigen können."
str_3:
    .autostring 34 2 "D-Du da!\nBitte hilf mir!\pDas hier ist der gefürchtete Pirat Blackbeard.\pEr will mich eines seltenen Fundes, in dessen Besitz ich eben erst gelangt bin, berauben!"
str_4:
    .autostring 34 2 "Nichts da!\pEin Kind, wie lächerlich!\pIhr beiden, zeigt diesem Gör, dass man sich mit unserer Crew nicht anzulegen hat!"
str_5:
    .autostring 34 2 "Und du rückst gefälligst die Alte Karte heraus.\pSofort!"
str_challange_0:
    .autostring 34 2 "Ein Pirat schreckt vor nichts zurück.\pWenn es hart auf hart kommt, erledigen wir auch ein Kind!"
str_defeat_0:
    .autostring 34 2 "Was?\pEin Kind legt sich erfolgreich mit uns an?"
str_challange_1:
    .autostring 34 2 "Vielleicht hast du ja was auf dem Kasten, wenn du meinen Kameraden besiegen konntestDOTS\pWollen wir mal sehen!"
str_defeat_1:
    .autostring 34 2 "Nicht schlecht!\pAber gegen unseren Kapitän hast du keine Chance!"
str_6:
    .autostring 34 2 "Das ist ja eine Überraschung!\pDu bist stärker als du aussiehst.\pAber du kommst zu spät, dieser Trottel hier hat mir die Alte Karte schon ausgehändigt.\pIn diesem Sinne, habe ich mit dir rein gar nichts mehr am Hut, Kindchen!\pDu kannst bloß hoffen, mich nie wieder zu sehen!\pHahaha!\nHahaha!"
str_7:
    .autostring 34 2 "Vielen Dank, dass du mir aus der Patsche helfen wolltest.\pAber leider ist dieser schreckliche Pirat Blackbeard mit der Alten Karte davon gekommen.\pVor einiger Zeit war ich Teil einer von der Laz. Corp initiierten Expedition, an der auch Professor Tann teilgenommen hat.\pZiel dieser Unternehmung war es, eine antike Ozenruine zu erkunden.\pDort haben wir die Alte Karte gefunden.\pProfessor Tann war außer sich!\pStändig hat er davon gesprochen, dass er die Karte übersetzten wolle.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch traue mich gar nicht recht, ihm nun mit leeren Händen wieder entgegenzutreten.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pAber es war nicht meine Schuld, findest du nicht?\pNur Zeit sollte ich keine mehr verlierenDOTS\pVielen Dank noch einmal für deine Hilfe.\pSolltest du, wenn der Zufall es so möchte, irgendwie diese Karte von Blackbeard zurückholen können, lass es Professor Tann wissen.\pEr wird es dir sicher danken!"

.elseif LANG_EN

str_assistant:
    .autostring 34 2 "Professor Fir's assistant"
str_0:
    .autostring 34 2 "I really must congratulate you!\pYour expedition really was extraordinarily successful.\pProfessor Fir must have been overwhelmed when you finally found the Old Map.\pWho knows to which places and treasures it may have led you?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pOh yes!\nI do know that!\pBut this kind of questions won't bother you anymore, I suppose."
str_1:
    .autostring 34 2 "P-Please!\nThis map is all but valuable.\pNobody will pay you anything for it, I can assure you.\pOur journey was sponsored by the Laz. Corp, so if you tell me a price I am they will see to it that you receive a noteworthy amount of money."
str_2:
    .autostring 34 2 "Hahaha!\pNo gold in the wide world could amount for the treasure this Old Map leads to.\pI fear that we won't come to an agreement here."
str_3:
    .autostring 34 2 "Y-You over there!\nPlease help me!\pThis here is the infamous pirate Blackbeard.\pHe wants to steal a very rare finding which I only very recently got in possesion of."
str_4:
    .autostring 34 2 "As if!\pA child, how ridiculous.\pHey, you two, show that brat that you don't wanna mess with our crew!"
str_5:
    .autostring 34 2 "And you hand over this Old Map.\pNow!"
str_challange_0:
    .autostring 34 2 "A pirate doesn't shy away from anything.\pWhen the going gets tough we even battle a child!"
str_defeat_0:
    .autostring 34 2 "Come again?\pA child successfully opposes us?"
str_challange_1:
    .autostring 34 2 "Maybe you are not that bad if you managed to defeat my crewmateDOTS\pLet's see!"
str_defeat_1:
    .autostring 34 2 "Not bad!\pBut you don't stand a chance against our captain."
str_6:
    .autostring 34 2 "Now that is a suprise!\pYou are stronger than you look!\pBut you are too late, this nimrod here already gave me the Old Map.\pSo to make that clear, I don't have any buisiness with you anymore.\pYou can only hope to never meet me again!\pHahaha!\nHahaha!"
str_7:
    .autostring 34 2 "Thank you so much that you wanted to help me out of my misery.\pBut unfortunately this terrifying pirate Blackbeard got away with the Old Map.\pYou know, some time ago I was part of an expedition initiated by the Laz. Corp.\pEven Professor Fir was part of it.\pThe goal of this journey was to explore some ancient ocean ruins.\pThere we found the Old Map.\pProfessor Fir was so excited!\pHe wouldn't stop talking about translating the map.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pI am almost scared to face him with empty hands now.\pBut it wasn't my fault, right?\pAnyway, I shouldn't lose any more time.\pThank you again for your help.\pAnd should you ever, if fortune wants it, get back this map from Blackbeard, bring it to Professor Fir, ok?\pHe will be most grateful to you!"

.endif