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
.include "healingplaces.s"

.global map_blackbeard_ship_deck_levelscripts
.global ow_script_blackbeard_ship_deck_open_captain_cabin

.align 4

map_blackbeard_ship_deck_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
	.word lscr_frame_table
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word setmaptile_script
	.byte 0x0

setmaptile_script:
    checkflag FLAG_BBSHIP_CAPTAIN_ROOM_UNLOCKED
    callif EQUAL ow_script_blackbeard_ship_deck_open_captain_cabin
    end

ow_script_blackbeard_ship_deck_open_captain_cabin:
    setmaptile 0x48 0x28 0x2ca 1
    return

lscr_frame_table:
	.hword STORY_PROGRESS, 0x42
	.word ow_script_tann_plank
    .hword 0
    
ow_script_tann_plank:
    lockall
    pause 16
    applymovement 0xFF mov_fu
    waitmovement 0
    playsong MUS_PIRATE 0
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    getplayerpos 0x8008 0x8009
    setvar 0x8004 0x14
    setvar 0x8005 0x26
    special SPECIAL_OVERWORLD_VIEWPOINT_MOVE_TO
    waitmovement 0
    pause 32
    loadpointer 0 str_0
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    loadpointer 0 str_1
    show_mugshot MUGSHOT_TANN alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    loadpointer 0 str_2
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    pause 16
    applymovement 3 mov_pirate_to_tann
    waitmovement 0
    loadpointer 0 str_3
    show_mugshot MUGSHOT_TANN alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    sound 13
    applymovement 3 mov_pirate_up
    applymovement 2 mov_tann_up
    waitmovement 0
    fadescreen 3

    hidesprite 2
    checksound
    pause 32
    sound 119
    pause 8
    sound 119
    pause 32
    fadescreen 2

    applymovement 3 mov_pirate_back
    waitmovement 0
    pause 16
    loadpointer 0 str_4
    show_mugshot MUGSHOT_BLACKBEARD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    loadpointer 0 str_pirate
    setvar 0x8000 1
    special SPECIAL_NAME_SHOW
    loadpointer 0 str_5
    callstd MSG_FACE
    special SPECIAL_NAME_DELETE
    fadescreen 1
    hidesprite 1
    hidesprite 3
    hidesprite 4
    pause 32
    fadescreen 0
    copyvar 0x8004 0x8008
    copyvar 0x8005 0x8009
    special SPECIAL_OVERWORLD_VIEWPOINT_MOVE_TO
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    fadesong MUS_BBSHIP
    addvar STORY_PROGRESS 1
    releaseall
    end

mov_fu:
    .byte LOOK_UP, STOP
mov_pirate_to_tann:
    .byte STEP_UP, STEP_RIGHT, STEP_UP, STOP
mov_pirate_up:
    .byte STEP_UP_FAST, STOP
mov_tann_up:
    .byte PAUSE_16, LIFT_UP, STOP
mov_pirate_back:
    .byte STEP_DOWN, STEP_DOWN, STEP_LEFT, STEP_DOWN, LOOK_RIGHT, STOP


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich muss sagen, dass Sie mir wirklich ans Herz gewachsen sind, Professor Tann.\pIch meine das ernst.\pSie waren wirklich einer meiner interessantesten Gefangenen.\pAber ich kann es nicht ausstehen, wenn man in meiner Kabine herumschnüffelt.\pSie wollten wohl ihre Alte Karte zurückholen, was?\pTja, das kann ich erst recht nicht gebrauchen!\pUnd Ihnen ist sicher klar, dass ich so ein Verhalten auch bestrafen muss.\pWenn ich einfach nichts unternehme und Sie wieder in Ihre Zelle sperreDOTS\pNaja, dann zettelt hier einer aus meiner Bande bald eine Meuterei an.\pNichts für ungut, Professor!"
str_1:
    .autostring 34 2 "Nein, bitte!\nDas muss wirklich nicht sein.\pEs tut mir leid, dass ich in Ihre Kabine eingebrochen bin.\pEhrlich!\nLassen Sie uns darüber reden.\pIchDOTS\nDOTSbitte!\pWie wollen Sie ohne mich die versunkene Stadt Atlantea finden?"
str_2:
    .autostring 34 2 "Ihr Wimmern macht mir die Sache leichter, Professor!\pIch kann es nicht ausstehen, wenn jemand zu winseln beginnt.\pIch habe Ihnen doch längst Ihre Alte Karte abgenommen.\pDie wird mich nach Atlantea führen.\pSie brauche ich dann nicht mehr, richtig?\pTut mir leid, Professor.\pSie gehen über Board!\nZehahaha!"
str_3:
    .autostring 34 2 "Nein!\nBitte nicht!\pSie haben doch von mir alles, was Sie wollen.\pIch flehe Sie an!\pIchDOTS"
str_4:
    .autostring 34 2 "Was für ein Jammer!\pAber man muss manchmal eben Opfer bringen.\pEinen Unruhestifter können wir hier an Board nicht gebrauchen.\pMänner!\nWir setzen unverzüglich Kurs auf Atlantea.\pEndlich werde ich die versunkene Stadt mit eigenen Augen sehen!"
str_pirate:
    .string "Piraten"
str_5:
    .autostring 34 2 "Aye, Kapitän!"
.elseif LANG_EN
.endif