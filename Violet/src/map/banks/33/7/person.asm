.include "overworld_script.s"
.include "callstds.s"
.include "mugshot.s"
.include "vars.s"
.include "flags.s"
.include "movements.s"
.include "specials.s"
.include "songs.s"
.include "ordinals.s"
.include "movements.s"
.include "items.s"

.global ow_script_bbship_captain_room_lucky
.global ow_script_bbship_captain_room_map

ow_script_bbship_captain_room_lucky:
    loadpointer 0 str_0
    show_mugshot MUGSHOT_LUCKY alignment=MUGSHOT_RIGHT message_type=MSG_FACE mask_name=0
    end

ow_script_bbship_captain_room_map:
    setvar 0x8000 ITEM_ALTE_KARTE
	callstd ITEM_FIND
    applymovement 0xFF mov_fr
    waitmovement 0
    setvar 0x8004 2
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0
    applymovement 2 mov_fl
    waitmovement 0
    loadpointer 0 str_1
    show_mugshot MUGSHOT_LUCKY alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0 emotion=MUGSHOT_SHOCKED
    showsprite 3
    sound 8
    checksound
    pause 32

    goto after

    applymovement 0xFF mov_fd_exclam
    applymovement 2 mov_fd_exclam
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    applymovement 0x7f mov_3d
    waitmovement 0
    loadpointer 0 str_2
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0 emotion=MUGSHOT_SHOCKED
    applymovement 3 mov_3u
    applymovement 0x7f mov_3u
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    pause 16
    loadpointer 0 str_3
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0 emotion=MUGSHOT_ANGRY
    sound 10
    applymovement 2 mov_lucky_side
    waitmovement 0
    checksound

    pause 32

    loadpointer 0 str_4
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0 emotion=MUGSHOT_HAPPY
    sound 0x15
    applymovement 2 mov_fd_exclam
    waitmovement 0
    checksound
    pause 32
    sound 10
    applymovement 2 mov_jr
    waitmovement 0
    checksound
    pause 16
    loadpointer 0 str_5
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0 emotion=MUGSHOT_SCARED
    loadpointer 0 str_6
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0 emotion=MUGSHOT_ANGRY
    applymovement 3 mov_1u
    waitmovement 0
    loadpointer 0 str_7
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    applymovement 3 mov_fr
    waitmovement 0
    loadpointer 0 str_8
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0 emotion=MUGSHOT_ANGRY
    applymovement 3 mov_fu
    waitmovement 0
    loadpointer 0 str_9
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    trainerbattlenointrotext 0x199 3 str_defeat
after:
    loadpointer 0 str_10
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0 emotion=MUGSHOT_SHOCKED
    loadpointer 0 str_11
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    applymovement 3 mov_4d
    waitmovement 0
    pause 16
    sound 9
    pause 16
    hidesprite 3
    checksound
    pause 32
    applymovement 2 mov_fl
    applymovement 0xFF mov_fr
    waitmovement 0
    loadpointer 0 str_12
    show_mugshot MUGSHOT_LUCKY alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0 emotion=MUGSHOT_SHOCKED
    loadpointer 0 str_13
    show_mugshot MUGSHOT_LUCKY alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    applymovement 0xFF mov_5d
    applymovement 2 mov_5d
    pause 32
    clearflag (FLAG_BBSHIP_DECK_LUCKY2 | 0x8000)
    addvar STORY_PROGRESS 1
    warp 33 4 3 0 0
    waitstate
    releaseall
    end


mov_lucky_side:
    .byte JUMP_LEFT, STOP
mov_jr:
    .byte JUMP_RIGHT, LOOK_DOWN, STOP
mov_5d:
    .byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_4d:
    .byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_fd_exclam:
    .byte LOOK_DOWN, SAY_EXCLAM, STOP
mov_3d:
    .byte STEP_DOWN, STEP_DOWN, STEP_DOWN,STOP
mov_3u:
    .byte STEP_UP, STEP_UP, STEP_UP, STOP
mov_1u:
    .byte STEP_UP, STOP
mov_fr:
    .byte LOOK_RIGHT, STOP
mov_fl:
    .byte LOOK_LEFT, STOP
mov_fu:
    .byte LOOK_UP, STOP

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Kein Glück bei der Suche nach deinen Orden und dem Geld?\pMach dir nichts draus.\pDu findest sie bestimmt irgendwo anders auf dem SchiffDOTS"
str_1:
    .autostring 34 2 "Hei!\nWas hast du da denn Schönes gefunden?\pDas sieht aus wie eine Schatzkarte!\pUnd wenn sie auf Blackbeards Tisch liegt, heißt dasDOTS"
str_2:
    .autostring 34 2 "Huh?\nWas zum Teufel ist hier los?"
str_3:
    .autostring 34 2 "Was habt ihr in meiner Kabine zu suchen?\pWieso seit ihr nicht in euren Zellen!"
str_4:
    .autostring 34 2 "Denkst du ernsthaft, jemand mit deinen Ausmaßen kann sich vor mir verstecken, Lucky?"
str_5:
    .autostring 34 2 "Kapitän!\nWie erfreulich, Euch zu sehen!"
str_6:
    .autostring 34 2 "Spar dir den Unsinn, Lucky!\pMit dir dreckigem Verräter werde ich mich gleich befassen!"
str_7:
    .autostring 34 2 "Aber nun erstmal zu dir, du Rötzgöre!\pPLAYER war dein Name, richtig?\pAls wir dich aufgesammelt haben, hatte ich gehofft, einen ganz großen Fang gemacht zu haben.\pAber jetzt hat es mir dieses Theater hier beschert!\pUnd dass du dann auch noch die Frechheit besitzt, in meiner Kabine herzumstöbern!\pDachtest du, dass es eine gute Idee ist, von einem Piraten zu stehlen?"
str_8:
    .autostring 34 2 "Frag doch unseren lieben Lucky hier, was passiert, wenn man sich mit mir anlegt!"
str_9:
    .autostring 34 2 "Dieser Hund war einmal Mitglied in meiner Bande!\pUnd eines schönen Tages hat er sich gedacht, dass es doch nett wäre, einmal selbst der Kapitän auf diesem wundervollen Schiff zu sein!\pHat einfach eine Meuterei angezettelt, dieser Mistkerl!\pHa!\nAber wir sind Piraten, da hab ich mit sowas selbstverständlich schon lange gerechnet.\pIch werde dir zeigen, was ich meine.\pMit mir ist nicht zu spaßen, Kindchen!"
str_defeat:
    .autostring 34 2 "Unmöglich!\nDOTS DOTS DOTS"
str_10:
    .autostring 34 2 "Was?!\nIch habe gegen dich verloren?"
str_11:
    .autostring 34 2 "Ich hätte dich absaufen lassen sollenDOTS\pAber das hier ist mein Schiff.\pDu wirst schon sehen, was du davon hast, dich gegen mich zu stellen!"
str_12:
    .autostring 34 2 "Das war wirklich beeindruckend, Kindchen.\pDu hast den alten Blackbeard ganz schön alt aussehen lassen!"
str_13:
    .autostring 34 2 "Das hat uns hoffentlich etwas Zeit verschafft.\pAber nun, da wir entdeckt worden sind, sollten wir schleunigst hier rausDOTS"

.elseif LANG_EN
str_0:
    .autostring 34 2 "No luck looking for your badges and money, eh?\pDon't be sad.\pYou'll most likely find them somewhere else on this shipDOTS"
.endif