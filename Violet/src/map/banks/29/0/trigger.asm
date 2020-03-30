.include "overworld_script.s"
.include "specials.s"
.include "mugshot.s"
.include "songs.s"
.include "vars.s"
.include "movements.s"
.include "flags.s"
.include "ordinals.s"

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

    special SPECIAL_CANT_DOUBLE_BATTLE
    compare LASTRESULT 0
    gotoif NOT_EQUAL cant_double_battle

    applymovement 7 mov_1r
    applymovement 10 mov_1r
    waitmovement 0
    settrainerflag 0x139
    settrainerflag 0x13a
    setvar LASTTALKED 0
    trainerbattletwotrainers 0x139 0x13a 0 str_challange_0 str_defeat_0 str_defeat_1 cont_both
cont_both:

    setvar LASTTALKED 10
    setvar 0x8004 10
    setvar 0x8005 0x5
    setvar 0x8006 0x3
    special SPECIAL_NPC_MOVE_TO
    setvar LASTTALKED 7
    setvar 0x8004 7
    setvar 0x8005 0x5
    setvar 0x8006 0x5
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    applymovement 7 mov_face_up
    waitmovement 0
    applymovement 10 mov_face_down
    waitmovement 0
    pause 32
    goto after_conts

cant_double_battle:

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
    goto after_conts

after_conts:
    applymovement 9 mov_face_right
    waitmovement 0
    
    loadpointer 0 str_6
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0

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
    waitmovement 0

    loadpointer 0 str_assistant
    setvar 0x8000 0
    special SPECIAL_NAME_SHOW
    loadpointer 0 str_7
    callstd MSG
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
mov_1r:
    .byte STEP_RIGHT, STOP


.ifdef LANG_GER
str_assistant:
    .autostring 34 2 "Professor Tann's Assistent"
str_0:
    .autostring 34 2 "Zehaha!\nWieso zitterst du denn?\pHast du etwa Angst, dass ich dich auch gefangen nehme?\pNein, nein!\nDer Professor reicht uns völlig.\pEine nette Expedition, die er da auf die Beine gestellt hat.\pUnd so erfolgreich obendrein!\pDass ihr die legendäre Alte Karte tatsächlich entdecktDOTS\pWer hätte das gedacht?\pAls wir euer Schiff gekarper haben, hatte ich gehofft, dass ich das güte Stück bald in meinen Händen halten würde.\pAber irgendwie hast du es wohl geschafft, damit zu entwischen, nicht?"

str_1:
    .autostring 34 2 "B-Bitte!\nDiese Karte ist doch völlig wertlos.\pIhr Wert ist rein wissenschaftlich.\pNiemand wird Ihnen dafür etwas bezahlen, das kann ich ihnen garantieren.\pL-Lassen Sie Professor Tann doch einfach freiDOTS\pUnd wir vergessen die Sache, ja?"
str_2:
    .autostring 34 2 "Zehaha!\nVöllig wertlos, was?\pDu hast keine Ahnung, zu welchem Schatz uns diese Karte führen wird.\pDen Professor brauchen wir leider noch eine Weile, tut mir wirklich leid.\pWer soll sonst die Alte Karte, die du mir gleich geben wirst, entziffern?"
str_3:
    .autostring 34 2 "D-Du da!\pBitte hilf mir!\pDas hier ist der gefürchtete Pirat Blackbeard.\pAls ich auf einer Expedition mit Professor Tann war, hat er unser Schiff gekarpert und den Professor entführt.\pUnd jetzt will er mir die Alte Karte, die wir auf der Expedition gefunden haben, stehlen!"
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
    .autostring 34 2 "Das ist ja eine Überraschung!\pDu bist stärker als du aussiehst.\pAber du kommst zu spät, dieser Trottel hier hat mir die Alte Karte schon ausgehändigt.\pIn diesem Sinne, habe ich mit dir rein gar nichts mehr am Hut, Kindchen!\pDu hast du aber wirklich Glück gehabt!\pZehahaha!\nZehahaha!"
str_7:
    .autostring 34 2 "Vielen Dank, dass du mir aus der Patsche helfen wolltest.\pDieser widerwärtige Pirat BlackbeardDOTS\pProfessor Tann war außer sich, als wir auf unserer Expedition die Alte Karte gefunden hatten.\pDann, wie aus dem Nichts, tauchte Blackbeards Piratenschiff vor uns auf.\pEs ging alles so schnellDOTS\pAuf einmal war der Professor fort und ich konnte mich auf ein Rettungsbot flüchten.\pNicht einmal die Alte Karte konnte ich beschützen.\pUnd wer weiß, wie es dem Professor gehtDOTS\pEr schwebt sicherlich in großer Gefahr!\pIch werde sehen, wie ich der Polizei behilflich sein kann, Blackbeards Schiff aufzuspüren.\pDanke vielmals, für deine Hilfe."

.elseif LANG_EN

.endif