.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "specials.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_map_3_1_trigger_larissa

ow_script_map_3_1_trigger_larissa:
    lockall
    applymovement 0xFF mov_fl
    waitmovement 0
    pause 32
    sound 9
    clearflag (1 | 0x8000)
    showsprite 5
    checksound
    setvar 0x8004 5
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0
    applymovement 5 mov_fr
    waitmovement 0
    loadpointer 0 str_0
    show_mugshot MUGSHOT_LARISSA message_type=MSG mask_name=1 
    pause 16
    sound 0x15
    applymovement 5 mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_1
    show_mugshot MUGSHOT_LARISSA message_type=MSG mask_name=1 
    pause 32
    loadpointer 0 str_2
    show_mugshot MUGSHOT_LARISSA message_type=MSG_KEEPOPEN emotion=MUGSHOT_HAPPY hide_mugshot=0
    loadpointer 0 str_3
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    setvar 0x8004 5
    setvar 0x8005 0x14
    setvar 0x8006 0x1a
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    hidesprite 5
    setvar STORY_PROGRESS 12
    releaseall
    end 

mov_exclam:
    .byte SAY_EXCLAM, STOP
mov_fr:
    .byte LOOK_RIGHT, STOP
mov_fl:
    .byte LOOK_LEFT, STOP

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Entschuldige bitteDOTS"
str_1:
    .autostring 34 2 "Mir gefällt die Entschlossenheit in deinem Blick!\pDu bist ein Trainer, nicht?\pDu machst zwar noch keinen sehr erfahrenen Eindruck, aber man sieht dir ohne Zweifel an, dass du sehr ehrgeizig bist!\pWie lautet dein Name?"
str_2:
    .autostring 34 2 "PLAYER also?\pFreut mich, dich kennenzulernen!\pMein Name ist Larissa und ich bin ebenfalls ein Trainer."
str_3:
    .autostring 34 2 "Es muss dir ein wenig seltsam erscheinen, dass ich dich hier einfach so angesprochen habe.\pAber ich streife seit einier Zeit durch die Region, um die Menschen, die darin leben, genauer zu verstehen.\pUnd irgendetwas war da an dir, das mich interessiert hat.\pDu hast dieses Funkeln in den Augen, das man normalerweise nur bei großen Trainern beobachten kann.\pVielleicht liegt ja eine ruhmreiche Zukunft vor dir?\pIn diesem Fall werden wir uns sicherlich wieder begegnen.\pPLAYER!\nDeinen Namen werde ich mir merken!\pAuf Wiedersehen!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Excuse me, pleaseDOTS"
str_1:
    .autostring 34 2 "I like the determination in your face!\pEven though you don't seem to be very experienced I can clearly see the ambition you have.\pWhat is your name?"
str_2:
    .autostring 34 2 "PLAYER, eh?\pNice to meet you!\pMy name is Larissa and I too am a trainer."
str_3:
    .autostring 34 2 "It must seem weird to you that I just approached you like this.\pBut I have been traveling through this region for some time now in order to get to know the people that live here.\pAnd there was something quite fascinating about you.\pYou have this sparkle in your eye that one usually only great trainers have.\pMaybe, there is a bright future ahead of you?\pIn this case I am sure we will meet again.\pPLAYER!\nI will remember your name!\pGood bye!"
.endif