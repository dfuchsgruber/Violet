.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"
.include "pathfinding.s"

.macro npc_face_npc person_idx:req npc_target:req
    setvar 0x8004 \person_idx
    setvar 0x8005 \npc_target
    special SPECIAL_NPC_FACE_TO_NPC
    waitmovement 0
.endm


.global ow_script_route_3_may

mov_exclam:
    .byte SAY_EXCLAM, STOP
mov_fu:
    .byte LOOK_UP, STOP
mov_cam_down:
    .byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_cam_up:
    .byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_fd:
    .byte LOOK_DOWN, STOP
mov_fl:
    .byte LOOK_LEFT, STOP
mov_fr:
    .byte LOOK_RIGHT, STOP
mov_say_smile:
    .byte SAY_SMILE, STOP
mov_exclam_and_fu:
    .byte LOOK_UP, SAY_EXCLAM, STOP
mov_1u:
    .byte STEP_UP, STOP
mov_1r_fu:
    .byte STEP_RIGHT, LOOK_UP, STOP
mov_jump_right:
    .byte JUMP_RIGHT, STOP

.equ PERSON_MAY, 12
.equ PERSON_LARISSA, 60

ow_script_route_3_may:
    lock
    faceplayer
    loadpointer 0x0 str_may_1
    show_mugshot MUGSHOT_MAY MUGSHOT_LEFT message_type=MSG_KEEPOPEN hide_mugshot=0
    update_mugshot_emotion MUGSHOT_SAD
    loadpointer 0 str_may_2
    callstd MSG_KEEPOPEN
    multichoice 8 8 0 1
    compare LASTRESULT 1
    gotoif EQUAL said_no
accept_challange:
    update_mugshot_emotion MUGSHOT_NORMAL
    compare STARTER_SELECTED 0x0
    gotoif EQUAL starter_plant
    compare STARTER_SELECTED 0x1
    gotoif EQUAL starter_fire
starter_water:
    trainerbattlecont 0x1 0x2b 0x0 str_may_before str_may_after may_later
starter_fire:
    trainerbattlecont 0x1 0x2a 0x0 str_may_before str_may_after may_later
starter_plant:
    trainerbattlecont 0x1 0x29 0x0 str_may_before str_may_after may_later

may_later:
    loadpointer 0 str_may_4
    show_mugshot MUGSHOT_MAY MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_SAD
    pause 64
    clearflag (12 | 0x8000)
    showsprite PERSON_LARISSA
    sound 118
    checksound 
    pause 32
    sound 10
    applymovement PERSON_LARISSA mov_jump_right
    waitmovement 0
    checksound
    pause 16
    applymovement PERSON_LARISSA mov_fd
    waitmovement 0
    loadpointer 0 str_larissa_1
    show_mugshot MUGSHOT_LARISSA MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_HAPPY
    sound 0x15
    applymovement 0xFF mov_exclam_and_fu
    applymovement PERSON_MAY mov_exclam_and_fu
    waitmovement 0
    checksound
    pause 16
    getplayerpos 0x8005 0x8006
    addvar 0x8006 0xFFFF
    compare 0x8005 0x2d
    gotoif NOT_EQUAL not_occupied
    compare 0x8006 0x38
    gotoif NOT_EQUAL not_occupied
    addvar 0x8006 0xFFFF
not_occupied:
    npc_move_to PERSON_LARISSA 0xFFFF 0xFFFF
    applymovement PERSON_LARISSA mov_fd
    waitmovement 0
    /*
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    applymovement 0xFF mov_1u
    applymovement PERSON_MAY mov_1r_fu
    applymovement 0x7F mov_cam_up
    waitmovement 0
    pause 16
    applymovement 0x7F mov_cam_down
    npc_move_to_player PERSON_LARISSA
    setvar LASTTALKED PERSON_LARISSA
    faceplayer
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    */
    loadpointer 0 str_larissa_2
    show_mugshot MUGSHOT_LARISSA MUGSHOT_LEFT message_type=MSG_KEEPOPEN
    npc_face_npc PERSON_MAY 0xFF
    loadpointer 0 str_may_5
    show_mugshot MUGSHOT_MAY MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_ANNOYED
    npc_face_npc PERSON_MAY PERSON_LARISSA
    loadpointer 0 str_larissa_3
    show_mugshot MUGSHOT_LARISSA MUGSHOT_LEFT message_type=MSG
    loadpointer 0 str_may_6
    show_mugshot MUGSHOT_MAY MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_SAD
    loadpointer 0 str_may_7
    show_mugshot MUGSHOT_MAY MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_SAD
    loadpointer 0 str_larissa_4
    show_mugshot MUGSHOT_LARISSA MUGSHOT_LEFT message_type=MSG_KEEPOPEN hide_mugshot=0 emotion=MUGSHOT_ANGRY
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_larissa_5
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    loadpointer 0 str_larissa_6
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    pause 16
    fanfare 0x13E
    loadpointer 0 str_karte
    callstd MSG_KEEPOPEN
    waitfanfare
    pause 16
    loadpointer 0 str_larissa_7
    show_mugshot MUGSHOT_LARISSA MUGSHOT_LEFT message_type=MSG_KEEPOPEN hide_mugshot=0 emotion=MUGSHOT_NORMAL
    update_mugshot_emotion MUGSHOT_HAPPY
    loadpointer 0 str_larissa_8
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    pause 32
    sound 0x15
    applymovement PERSON_LARISSA mov_say_smile
    waitmovement 0
    checksound
    loadpointer 0 str_larissa_9
    show_mugshot MUGSHOT_LARISSA MUGSHOT_LEFT message_type=MSG hide_mugshot=1 emotion=MUGSHOT_HAPPY
    pause 16
    npc_move_to PERSON_LARISSA 0x2D 0x3F waitmovement=0
    pause 48
    applymovement 0xFF mov_fd
    applymovement PERSON_MAY mov_fd
    waitmovement PERSON_LARISSA
    hidesprite PERSON_LARISSA
    pause 32
    npc_face_npc 0xFF PERSON_MAY
    npc_face_npc PERSON_MAY 0xFF
    loadpointer 0 str_may_8
    show_mugshot MUGSHOT_MAY MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY hide_mugshot=0
    update_mugshot_emotion MUGSHOT_ANNOYED
    loadpointer 0 str_may_9
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    loadpointer 0 str_may_10
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_may_11
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    npc_move_to PERSON_MAY 0x2d 0x2f
    hidesprite PERSON_MAY
    addvar STORY_PROGRESS 1
    releaseall
    end    

said_no:
    update_mugshot_emotion MUGSHOT_SHOCKED
    loadpointer 0 str_may_decline
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    release
    end


.ifdef LANG_GER

str_may_0:
    .string "PLAYER!"
str_may_1:
    .autostring 34 2 "Es ist wirklich schön, dich endlich wiederzusehen.\pSeit wir die Trainerschule abgeschlossen haben, ist einiges passiert, was?\pDu bist bestimmt sehr stark geworden!"
str_may_2:
    .autostring 34 2 "Ich habe wirklich hart an mir gearbeitet, PLAYER.\pIch habe viel trainiert, um endlich zu dir und all den anderen aufzuholen.\pIch würde gerne gegen dich kämpfen, was sagst du, PLAYER?"
str_may_decline:
    .autostring 34 2 "Was, wirklich?\pEs würde mir wirklich viel bedeuten, wenn du gegen mich antreten könntest, PLAYER.\pAber ich verstehe das natürlichDOTS"
str_may_before:
    .autostring 35 2 "Auweia!\nEin Teil von mir hatte wohl gehofft, dass du ablehnstDOTS\pAber jetzt muss ich mich beweisen!\pIch schaffe das!"
str_may_after:
    .autostring 35 2 "DOTS DOTS DOTS\nEine NiederlageDOTS"
str_may_3:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pTrotz meiner harten Arbeit habe ich gegen dich verlorenDOTS"
str_may_4:
    .autostring 34 2 "VerlorenDOTS\pIch tauge einfach nicht zum Trainer, meinst du nicht auch?\pMit RIVAL, Felix oder dir kann ich einfach nicht mithaltenDOTS"

str_larissa_1:
    .autostring 34 2 "Fantastisch\pWirklich fantastisch!"
str_larissa_2:
    .autostring 34 2 "Wie ihr beiden da gekämpft habtDOTS\pMan hat wirklich eure Leidenschaft sehen können!\pIhr habt alles gegeben, obwohl ihr ganz offensichtlich eng befreundet seid.\pIch bin von eurer Einstelllung schwer beeindruckt!"
str_may_5:
    .autostring 34 2 "Wer ist das, PLAYER?\pKennst du die Frau?"
str_larissa_3:
    .autostring 34 2 "Ach, wie unhöflich von mir!\pMein Name ist Larissa!\pDie meiste Zeit ist mir sehr langweilig in dieser RegionDOTS\pAlso freut es mich immer sehr, wenn Trainer treffe, die mit ganzem Herzen bei der Sache sind.\pUnd ihr beide habt wirklich fantastisch gekämpft, wenn ich das nocheinmal so sagen darf!"
str_may_6:
    .autostring 34 2 "Na, zumindest einer von unsDOTS"
str_may_7:
    .autostring 34 2 "Immerhin habe ich ja wiedermal einen meiner Kämpfe in den Sand gesetztDOTS"
str_larissa_4:
    .autostring 34 2 "Hör gefälligst auf, dich so selbst zu bemitleiden."
str_larissa_5:
    .autostring 34 2 "Wenn du ein wenig mehr Vertrauen in dich und deine Pokémon setzten würdest, könntest du ganz leicht von einem Sieg zum nächsten hüpfen!\pIhr beiden!\pIhr fordert doch die Arenaleiter dieser Region heraus, nicht?\pAn ihnen müssen sich alle aufstrebenden Trainer messen."
str_larissa_6:
    .autostring 34 2 "Kranzdorf liegt zum Beispiel ganz in der Nähe, da hat Rosalie ihre Arena.\pAllerdingsDOTS\pDen Farmern hier sind einige Pokémon ausgebüchst und es könnte etwas dauern, bis sie ihre Voltilamm-Herde wieder zusammengescheucht haben.\pWarum versucht ihr nicht stattdessen nach Bruchfels zu gelangen?"
str_karte:
    .autostring 34 2 "PLAYER hat eine Karte erhalten."
str_larissa_7:
    .autostring 34 2 "Hier habt ihr beide eine Karte.\pWie ihr sehen könnt, liegt Bruchfels weit im Norden.\pUm dorthinzugelangen müsst ihr irgendwie das Meer überwinden."
str_larissa_8:
    .autostring 34 2 "Aber keine Sorge, dieses Rätsel zu lösen, ist nicht gerade schwerDOTS\pIch lasse euch aber trotzdem den Spaß, es selbst herauszufinden!"
str_larissa_9:
    .autostring 34 2 "Ach!\nIch bin froh, euch beide hier getroffen zu haben.\pJetzt ist mein Tag nicht mehr ganz so langweilig.\pAber lasst euch von mir nicht weiter aufhalten, ja?"
str_may_8:
    .autostring 34 2 "Diese Frau hat wirklich Nerven!"
str_may_9:
    .autostring 34 2 "Geht einfach so auf uns zu, fängt an uns zu belehrten und erteilt dann auch noch Anweisungen, irgendwelche Arenaleiter herauszufordern!"
str_may_10:
    .autostring 34 2 "Aber meinst du.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT"
str_may_11:
    .autostring 34 2 "Dass wir uns vielleicht diesen Ort genauer ansehen sollten?\pIch rede von Bruchfels.\pWenn man auf die Karte schaut, die sie uns gegeben hatDOTS\pDann müssen wir einen Weg finden, über das Meer nach Norden zu gelangen.\pVielleicht finden wir ja hier jemanden, der uns sagen kann, wie wir das am Besten bewerkstelligen, meinst du nicht?\pWir sollten uns hier einmal umsehen."
.elseif LANG_EN

.endif