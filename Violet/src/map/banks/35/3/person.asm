.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "mugshot.s"
.include "species.s"
.include "specials.s"
.include "pathfinding.s"

.global ow_script_sonnaufeld_clouds_icarus
.global ow_script_sonnaufeld_clouds_person_0
.global ow_script_sonnaufeld_clouds_person_1
.global ow_script_sonnaufeld_clouds_person_2
.global ow_script_sonnaufeld_clouds_person_3
.global ow_script_sonnaufeld_clouds_person_4

ow_script_sonnaufeld_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_sonnaufeld_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_sonnaufeld_clouds_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_sonnaufeld_clouds_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_sonnaufeld_clouds_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end

ow_script_sonnaufeld_clouds_icarus:
    checkflag FLAG_SONNAUFELD_SHRINE_VISIBLE
    gotoif EQUAL icarus_shrine_visible
    loadpointer 0 str_icarus_0
    show_mugshot MUGSHOT_ICARUS message_type=MSG_FACE emotion=MUGSHOT_RUMINATIVE
    end

icarus_shrine_visible:
    lock
    faceplayer
    loadpointer 0 str_icarus_1
    show_mugshot MUGSHOT_ICARUS message_type=MSG emotion=MUGSHOT_SHOCKED
    pause 16
    cry POKEMON_ICOGNITO 0
    waitcry
    pause 24
    sound 0x15
    applymovement 0xFF mov_fu
    applymovement 4 mov_fu
    waitmovement 0
    applymovement 0xFF mov_question
    applymovement 4 mov_question
    waitmovement 0
    checksound
    pause 16
    cry POKEMON_ICOGNITO 0
    waitcry
    pause 24
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    setvar 0x8004 0x1d
    setvar 0x8005 0xa
    special SPECIAL_OVERWORLD_VIEWPOINT_MOVE_TO
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    pause 48
    callasm map_sonnaufeld_clouds_create_unowns
    waitstate
    pause 16
    loadpointer 0 str_icarus_2
    show_mugshot MUGSHOT_ICARUS message_type=MSG emotion=MUGSHOT_SHOCKED
    pause 16
    cry POKEMON_ICOGNITO 0
    pause 20
    cry POKEMON_ICOGNITO 0
    waitcry
    callasm map_sonnaufeld_clouds_unowns_fly
    waitstate
    pause 48
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    setvar 0x8004 0xFF
    special SPECIAL_PERSON_GET_POSITION
    special SPECIAL_OVERWORLD_VIEWPOINT_MOVE_TO
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    pause 24
    loadpointer 0 str_icarus_3
    show_mugshot MUGSHOT_ICARUS message_type=MSG_KEEPOPEN hide_mugshot=0 emotion=MUGSHOT_SHOCKED
	setvar 0x8004 0xFF
	setvar 0x8005 4
	special SPECIAL_NPC_FACE_TO_NPC
	waitmovement 0
    loadpointer 0 str_icarus_4
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    callstd MSG_KEEPOPEN
    loadpointer 0 str_icarus_5
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_icarus_6
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    callstd MSG_KEEPOPEN
    loadpointer 0 str_icarus_7
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_icarus_8
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_icarus_9
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    pause 16
    npc_move_to 4 0x1d 0x10 waitmovement=1
    applymovement 4 mov_fu
    waitmovement 0
    pause 16
    sound 0x15
    applymovement 3 mov_fd
    waitmovement 0
    applymovement 3 mov_exclam
    waitmovement 0
    checksound
    applymovement 3 mov_2d
    waitmovement 0
    applymovement 4 mov_6d
    applymovement 3 mov_6d
    waitmovement 0
    hidesprite 3
    hidesprite 4
    setflag FLAG_UNOWN_ENABLED
    releaseall
    end



.ifdef LANG_GER
str_0:
    .autostring 34 2 "Diese Türme sind zwar antik, aber jemand hat sich erst vor wenigen Jahren daran zu schaffen gemacht.\pDas lässt sich an den vergleichsweise gut erhaltenen Abdrücken im Stein erkennen.\pIrgendwer hat etwas aus den Türmen hier oben entferntDOTS\pIch frage mich, wiesoDOTS"
str_1:
    .autostring 34 2 "Siehst du diese Steinbauten hier?\pDabei handelt es sich nach meinen Erkenntnissen um eine Art antikes Siegel.\pWas hier versiegelt wurde?\pDa frägst du den Falschen!"
str_2:
    .autostring 34 2 "Es ist wirklich ein befreiendes Gefühl, hier oben den Blick über die Weiten der Region streifen zu lassenDOTS"
str_3:
    .autostring 34 2 "Für viele Jahrhunderte war die Natur hier oben praktisch unberührt.\pJetzt, wo der ehemalige Champion das Wolkenreiten populär gemacht hat, verkommt diese einzigartige FloraDOTS"
str_4:
    .autostring 34 2 "Hier oben ist es so cool!\pMeinst du, ich finde einige starke Drachen-Pokémon?"

str_icarus_0:
    .autostring 34 2 "Dieser Ort ist wirklich seltsamDOTS\pWarum wächst hier kein Gras auf dem Boden?"
str_icarus_1:
    .autostring 34 2 "H-Hast du das gesehen, PLAYER?\pDa ist ein Schrein einfach so erschienen!\pWie aus dem Nichts!"
str_icarus_2:
    .autostring 34 2 "W-Was sind das für Pokémon?"
str_icarus_3:
    .autostring 34 2 "D-Das war wirklichDOTS"
str_icarus_4:
    .autostring 34 2 "MerkwürdigDOTS\nFindest du nicht?"
str_icarus_5:
    .autostring 34 2 "Auf mich wirkt es so, als wären diese Pokémon im Schrein gefangen gewesenDOTS"
str_icarus_6:
    .autostring 34 2 "Wer sie wohl darin versiegelt hat?\pUnd ich frage mich, wo sie jetzt hingeflogen sindDOTS"
str_icarus_7:
    .autostring 34 2 "Diese Himmelsinslen sind wirklich voller Geheimnisse."
str_icarus_8:
    .autostring 34 2 "Ich freue mich, dass ich das mit eigenen Augen gesehen habe!\pGeht es dir nicht so, PLAYER?"
str_icarus_9:
    .autostring 34 2 "Wir sollten uns auf die Suche nach diesen Pokémon machen!\pVielleicht finden wir so heraus, was es mit diesem seltsamen Schrein auf sich hat!"
.elseif LANG_EN
.endif