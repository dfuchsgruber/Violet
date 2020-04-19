.include "vars.s"
.include "levelscript_types.s"
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

.global map_ardeal_clouds_levelscripts

.align 4

map_ardeal_clouds_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
	.word lscr_frame_table
    .byte LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE
    .word lscr_warp
	.byte 0x0

lscr_frame_table:
	.hword STORY_PROGRESS, 0x3d
	.word ow_script_frame_table
	.hword 0x0

lscr_warp:
	.hword STORY_PROGRESS, 0x3d
	.word ow_script_warp
	.hword 0x0

ow_script_warp:
    spriteface 0xFF 1
    end


ow_script_frame_table:
    callasm animation_ardeal_tower_warp
    waitstate

    lockall
    fadesong 0
    pause 64
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    applymovement 0x7F mov_cdown
    waitmovement 0
    pause 32
    applymovement 3 mov_face_up
    waitmovement 0
    playsong MUS_LUCIUS 0
    loadpointer 0 str_0
    show_mugshot MUGSHOT_LUCIUS alignment=MUGSHOT_RIGHT message_type=MSG mask_name=1
    applymovement 3 mov_3up
    applymovement 0x7F mov_cup
    waitmovement 0
    loadpointer 0 str_1
    show_mugshot MUGSHOT_LUCIUS alignment=MUGSHOT_RIGHT message_type=MSG mask_name=1
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    pause 32
    sound 0x9
    showsprite 4
    checksound
    applymovement 0xFF mov_face_left
    applymovement 3 mov_face_left
    waitmovement 0
    loadpointer 0 str_2
    show_mugshot MUGSHOT_HARRENFELD alignment=MUGSHOT_LEFT message_type=MSG mask_name=0
    applymovement 0xFF mov_face_down
    waitmovement 0
    loadpointer 0 str_3
    show_mugshot MUGSHOT_LUCIUS alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    applymovement 0xFF mov_face_left
    waitmovement 0
    loadpointer 0 str_4
    show_mugshot MUGSHOT_HARRENFELD alignment=MUGSHOT_LEFT message_type=MSG mask_name=0
    applymovement 0xFF mov_face_down
    waitmovement 0
    loadpointer 0 str_5
    show_mugshot MUGSHOT_LUCIUS alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    applymovement 3 mov_1leftfaceup
    waitmovement 0
    applymovement 0xFF mov_face_left
    waitmovement 0
    loadpointer 0 str_6
    show_mugshot MUGSHOT_HARRENFELD alignment=MUGSHOT_LEFT message_type=MSG mask_name=0
    sound 13
    applymovement 4 mov_lift_up
    callasm ow_script_fadescreen_palette_backup
    fadescreen 2
    waitmovement 0
    checksound
    applymovement 0xFF mov_3upfaceleft
    waitmovement 0
    pause 32
    loadpointer 0 str_7
    show_mugshot MUGSHOT_HARRENFELD alignment=MUGSHOT_LEFT message_type=MSG mask_name=0
    pause 64
    applymovement 0xFF mov_face_down
    waitmovement 0
    loadpointer 0 str_8
    show_mugshot MUGSHOT_LUCIUS alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    pause 16
    draw_mugshot MUGSHOT_PLAYER alignment=MUGSHOT_RIGHT mask_name=0
    loadpointer 0 str_9
    callstd MSG_KEEPOPEN
    setvar DYN_MULTICHOICE_ITEM_CNT 2
    loadpointer 0 choice
    multichoice 0x0 0x0 0x0 0x0
    setvar DYN_MULTICHOICE_ITEM_CNT 0x0
    compare LASTRESULT 0
    gotoif EQUAL say_nothing
say_fight:
    loadpointer 0 str_say_fight
    callstd MSG
    hide_mugshot
    loadpointer 0 str_reply_fight
    show_mugshot MUGSHOT_LUCIUS alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    goto after_choice
say_nothing:
    loadpointer 0 str_say_nothing
    callstd MSG
    hide_mugshot
    loadpointer 0 str_reply_nothing
    show_mugshot MUGSHOT_LUCIUS alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    goto after_choice
after_choice:
    applymovement 3 mov_to_player
    waitmovement 0
    draw_mugshot MUGSHOT_LUCIUS alignment=MUGSHOT_RIGHT mask_name=0
    loadpointer 0 str_10
    callstd MSG_KEEPOPEN
	setvar BATTLE_SONG_OVERRIDE MUS_LUCIUS_BATTLE
    trainerbattlelosable 0x9 0x15e 0x5 str_won str_lost
    @ Should never be reached, the rival flag 0x4 for lucius automatically triggers the "falling from the tower" cutscene
    @ That warps the player to blackbeards ship
    releaseall
    end

.align 4
choice:
    .word str_nothing, 0
    .word str_fight, 0

mov_3upfaceleft:
    .byte STEP_UP, STEP_UP, STEP_UP, LOOK_LEFT, STOP
mov_face_up:
    .byte LOOK_UP, STOP
mov_cdown:
    .byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_cup:
    .byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_3up:
    .byte STEP_UP, STEP_UP, STEP_UP, STOP
mov_1d:
    .byte STEP_DOWN, STOP
mov_face_down:
    .byte LOOK_DOWN, STOP
mov_face_left:
    .byte LOOK_LEFT, STOP
mov_1leftfaceup:
    .byte STEP_LEFT, LOOK_UP, STOP
mov_lift_up:
    .byte LIFT_UP, LIFT_UP, LIFT_UP, FACE_DOWN, STOP
mov_to_player:
    .byte STEP_UP, STEP_RIGHT, STEP_UP, STEP_UP, STOP

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Wer bist du denn?\pBist du mit Narzissa hierher gekommen, um mich herauszufordern?"
str_1:
    .autostring 34 2 "Ich habe Trainer wie dich zuhauf gesehen.\pKinder, die sich einbilden, die ganze Welt besiegen zu können.\pArrogante kleine Gören, denen ein paar unbedeutende Erfolge zu Kopf gestiegen sind."
str_2:
    .autostring 34 2 "PLAYER!\nBist du verrückt?\pDu musst hier sofort weg!\pWeißt du nicht, wer hier vor dir steht?\pDas ist Lucius, der ehemalige Champion der Theto Region.\pOffenbarDOTS DOTS DOTS\nDOTS DOTS DOTS\pHat er sich nun Team Violet angeschlossenDOTS"
str_3:
    .autostring 34 2 "Noch ein Kind?\pIst euch nicht bewusst, dass das hier kein Spiel ist?\pDass ihr überhaupt nicht das Recht habt, euch in Angelegenheiten einzumischen, die eure Fähigkeiten um ein Weites übersteigen?"
str_4:
    .autostring 34 2 "Ich bin nicht bloß ein Kind!\pMein Name ist Harrenfeld und ich bin Komissar bei der Polizei von Theto.\pEs mag sein, dass ich nicht stark genug bin, euch zu besiegen!\pAber es ist meine Pflicht, die Bürger dieser Region zu beschützen.\pAlso werde ich alles daran setzten, euch solange zu beschäftigen, bis zumindest PLAYER entkommen ist!\pPLAYER, tritt zur Seite!"
str_5:
    .autostring 34 2 "Hmpf!\nDas respektiere ich!\pAlso dann, kleiner Harrenfeld.\pMach dich bereit, alles zu verlieren!"
str_6:
    .autostring 34 2 "Ich hab keine Angst!\pPLAYER, lauf bitte so schn-"
str_7:
    .autostring 34 2 "Urgh!\nDOTS DOTS DOTS\pIch DOTS ich DOTS\pUrghDOTS"
str_8:
    .autostring 34 2 "Hast du es nun begriffen?\pIhr seid mir nicht gewachsen.\pNimm deinen kleinen Freund hier, und verschwindet aus meiner Burg!"
str_9:
    .autostring 34 2 "Ich werde DOTS"
str_say_fight:
    .autostring 34 2 "Jemand, der den Komissar Harrenfeld so skrupellos attackiert, muss gestoppt werden.\pIch werde tun, was ich tun muss!"
str_reply_fight:
    .autostring 34 2 "Du hattest deine Chance, zu entkommen.\pGegenüber jemandem, der sich so maßlos selbst überschätzt, werde ich keine Gnade zeigen."
str_say_nothing:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS"
str_reply_nothing:
    .autostring 34 2 "Hat es dir die Sprache verschlagen?\pDu hattest deine Chance, zu entkommen.\pJetzt wirst du selbst lernen, dass man sich nicht mit Leuten anlegt, die in einer weitaus höheren Liga spielen."
str_won:
    .autostring 34 2 "Das war erst der Anfang!"
str_lost:
    .autostring 34 2 "Du bist ein Nichts!"
str_10:
    .autostring 34 2 "Dir ist nicht bewusst, wie mächtig ein Trainer werden kann.\pDu stehst noch ganz am Anfang Kindchen!\pUnd für deinen Hochmut, wirst du nun teuer bezahlen!"


str_nothing:
    .string "DOTS DOTS DOTS"
str_fight:
    .string "Kämpfen"


.elseif LANG_EN
str_0:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pUrghDOTS\nHow could IDOTS DOTS DOTS\pI myself lose!\pDOTS DOTS DOTS\pImpossibleDOTS DOTS DOTS"
str_1:
    .autostring 34 2 "Narcissa of the Elite Four defeated.\pThat is insaneDOTS\pBut to win against this manDOTS DOTS DOTS"
.endif