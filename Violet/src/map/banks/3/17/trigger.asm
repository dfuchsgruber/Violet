.include "overworld_script.s"
.include "specials.s"
.include "vars.s"
.include "callstds.s"
.include "movements.s"
.include "songs.s"

.global ow_script_haweiland_pirates_trigger

ow_script_haweiland_pirates_trigger:
    lockall
    setvar LASTTALKED 5
    special SPECIAL_COMPUTE_PLAYER_FACING
    playsong MUS_PIRATE 0
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    setvar 0x8004 0x3a
    setvar 0x8005 0x10
    special SPECIAL_OVERWORLD_VIEWPOINT_MOVE_TO
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK

    loadpointer 0 str_pirate
    setvar 0x8000 0
    special SPECIAL_NAME_SHOW
    loadpointer 0 str_0
    callstd MSG_KEEPOPEN
    special SPECIAL_NAME_DELETE

    loadpointer 0 str_sailor
    setvar 0x8000 1
    special SPECIAL_NAME_SHOW
    loadpointer 0 str_1
    callstd MSG_KEEPOPEN
    special SPECIAL_NAME_DELETE

    loadpointer 0 str_pirate
    setvar 0x8000 0
    special SPECIAL_NAME_SHOW
    loadpointer 0 str_2
    callstd MSG_KEEPOPEN
    special SPECIAL_NAME_DELETE

    applymovement 1 mov_up1
    applymovement 2 mov_up1
    applymovement 3 mov_up1
    applymovement 4 mov_up1
    waitmovement 0
    hidesprite 1
    hidesprite 2
    sound 9
    applymovement 3 mov_up1
    applymovement 4 mov_up1
    waitmovement 0
    hidesprite 3
    hidesprite 4
    sound 9
    checksound
    pause 32

    applymovement 5 mov_face_up
    waitmovement 0

    loadpointer 0 str_sailor
    setvar 0x8000 1
    special SPECIAL_NAME_SHOW
    loadpointer 0 str_3
    callstd MSG_KEEPOPEN
    special SPECIAL_NAME_DELETE
    closeonkeypress


    applymovement 5 mov_sailor
    waitmovement 0
    hidesprite 5
    sound 9
    checksound

    pause 64
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    setvar 0x8004 0xFF
    special SPECIAL_PERSON_GET_POSITION
    special SPECIAL_OVERWORLD_VIEWPOINT_MOVE_TO
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    addvar STORY_PROGRESS 1
    fadesong MUS_HAWEILAND
    releaseall
    end

mov_up1:
    .byte STEP_UP, STOP

mov_sailor:
    .byte STEP_LEFT, STEP_UP, STEP_UP, STOP

mov_face_up:
    .byte LOOK_UP, STOP

.ifdef LANG_GER
str_pirate:
    .string "Pirat"
str_sailor:
    .string "Matrose"
str_0:
    .autostring 34 2 "Keke!\nDa schlottern dir die Knie, was du Landratte?\pUnd ihr wollt Matrosen sein!\pWenn Kapitän Blackbeard mit euch fertig ist, dann setzt keiner von euch je wieder einen Fuß auf ein Schiff!"
str_1:
    .autostring 34 2 "Bitte!\pUnsere Fracht ist doch für Leute wie euch völlig uninteressant!\pWir haben auf unserer Expedition weder Schätze noch andere Reichtümer gefunden.\pNur uralte Relikte, die außerhalb eines Museums völlig unnütz sindDOTS"
str_2:
    .autostring 34 2 "Es macht doch gleich viel mehr Spaß, wenn sie wimmern, findet ihr nicht?\pBlackbeard weiß genau, was er tut.\pUnd wenn eure Funde so wertlos sind, warum liegt dir dann so viel an ihnen?\pKeke!\pAuf geht's!\nDas wird ein Spaß!"
str_3:
    .autostring 34 2 "Halt!\pBitte, aufhören!"

.elseif LANG_EN
str_pirate:
    .string "Priate"
str_sailor:
    .string "Sailor"
str_0:
    .autostring 34 2 "Keke!\pLook how your knees are shaking!\pAnd you want to be a sailor?\pOnce captain Blackbeard is done with all of you, none of you will ever set a foot on a ship!"
str_1:
    .autostring 34 2 "Please!\pOur cargo is all but valuable for your folks.\pOn our expedition we neither found any treasues nor other riches.\pOnly ancient relicts that are totally worthless outside a museumDOTS"
str_2:
    .autostring 34 2 "Isn't it way more fun when they're all whiny?\pBlackbeard knows exactly what he's doing.\pAnd if your foundings are so worthless, why do you care so much about them?\pKeke!\pLet's go!\nIt's gonna be fun!"
str_3:
    .autostring 34 2 "Stop!\pPlease stop!"

.endif

