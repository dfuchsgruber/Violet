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
    setvar 0x8000 2
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0
    applymovement 2 mov_fl
    waitmovement 0
    loadpointer 0 str_1
    show_mugshot MUGSHOT_LUCKY alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    showsprite 3
    sound 8
    checksound
    pause 32
    applymovement 0xFF mov_fd_exclam
    applymovement 2 mov_fd_exclam
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    applymovement 0x7f mov_3d
    waitmovement 0
    loadpointer 0 str_2
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    applymovement 3 mov_3u
    applymovement 0x7f mov_3u
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    pause 16
    loadpointer 0 str_3
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    getplayerpos 0x8000 0x8001
lucky_side_jump_loop:
    compare 0x8000 5
    gotoif HIGHER_OR_EQUAL exit_lucky_side_jump_loop
    applymovement 2 mov_lucky_side
    waitmovement 0
    addvar 0x8000 1
exit_lucky_side_jump_loop:
    loadpointer 0 str_4
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    sound 15
    applymovement 2 mov_fd_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_5
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    loadpointer 0 str_6
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    setvar 0x8000 3
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0
    applymovement 3 mov_fu
    waitmovement 0
    loadpointer 0 str_7
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    applymovement 3 mov_fr
    waitmovement 0
    loadpointer 0 str_8
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    applymovement 3 mov_fu
    waitmovement 0
    loadpointer 0 str_9
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0

    addvar STORY_PROGRESS 1
    releaseall
    end


mov_lucky_side:
    .byte JUMP_LEFT, STOP

mov_fd_exclam:
    .byte LOOK_DOWN, SAY_EXCLAM
mov_3d:
    .byte STEP_DOWN, STEP_DOWN, STEP_DOWN,STOP
mov_3u:
    .byte STEP_UP, STEP_UP, STEP_UP, STOP
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
    .autostring 34 2 "Zehaha!\nLucky, du verdammter Mistkerl!\pGlaub ja nicht, dass ich dich nicht bemerkt hätte."
str_5:
    .autostring 34 2 "Kapitän!\nWie erfreulich, Euch zu sehen!"
str_6:
    .autostring 34 2 "Spar dir den Unfug von wegen Kapitän, Lucky!\pDass du dich immer noch traust, mir ins Gesicht zu blicken.\pIch hätte dich ersaufen sollen, nachdem du mir eine Meuterei angezettelt hast!\pAber noch ist es dafür ja noch nicht zu spät!"
str_7:
    .autostring 34 2 "Aber nun erstmal zu dir, du Rötzgöre!\pPLAYER war dein Name, richtig?\pDass du etwas auf dem Kasten hast, war mir schon in Haweiland klar.\pAls wir dich aufgesammelt haben, hatte ich gehofft, einen ganz großen Fang gemacht zu haben.\pAber jetzt hat es mir das hier beschert!\pUnd dass du dann auch noch die Frechheit besitzt, in meiner Kabine herzumstöbern!\pDachtest du, dass es eine gute Idee ist, von einem Piraten zu stehlen?"
str_8:
    .autostring 34 2 "Frag doch unseren lieben Lucky hier, was passiert, wenn man sich mit mir anlegt!"
str_9:
    .autostring 34 2 "Dieses ehrenlose Fiffyen war einmal Mitglied in meiner Bande!\pUnd eines schönen Tages hat er sich gedacht, dass es doch nett wäre, einmal selbst der Kapitän auf diesem wundervollen Schiff zu sein!\pHat einfach eine Meuterei angezettelt, dieser Mistkerl!\pHa!\nAber wir sind Piraten, da hab ich mit sowas selbstverständlich schon lange gerechnet.\pIch werde dir zeigen, was ich meine.\pMit mir ist nicht zu spaßen, Kindchen!"

.elseif LANG_EN
str_0:
    .autostring 34 2 "No luck looking for your badges and money, eh?\pDon't be sad.\pYou'll most likely find them somewhere else on this shipDOTS"
.endif