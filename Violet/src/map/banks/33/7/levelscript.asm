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
.include "pathfinding.s"


.global map_blackbeard_ship_captain_room_levelscripts

.align 4

map_blackbeard_ship_captain_room_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
	.word lscr_frame_table
	.byte 0x0

lscr_frame_table:
	.hword STORY_PROGRESS, 0x43
	.word ow_script_lucky
    .hword 0
    
ow_script_lucky:
    lockall
    pause 32
    sound 0x15
    applymovement 2 mov_exclam
    waitmovement 0
    checksound
    pause 16
    npc_move_to_player 2
    applymovement 2 mov_fd
    waitmovement 0
    loadpointer 0 str_0
    show_mugshot MUGSHOT_LUCKY alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    npc_move_to 2 6 7
    applymovement 2 mov_fr
    waitmovement 0
    addvar STORY_PROGRESS 1
    releaseall
    end


mov_exclam:
    .byte LOOK_LEFT, SAY_EXCLAM, STOP
mov_fd:
    .byte LOOK_DOWN, STOP
mov_fr:
    .byte LOOK_RIGHT, STOP

.ifdef LANG_GER
str_0:
    .autostring 34 2 "PLAYER!\nWie um alles in der Welt bist du hier 'rein gekommen?\pHeh!\nDu hast es wirklich faustig hinter den Ohren.\pDu hoffst doch wohl nicht, deine Arena-Orden und dein Geld hier wieder zu bekommen?\pIch kann dir nicht genau sagen wieso, aber ich habe so das Gefühl, dass du sie hier nicht finden wirst.\pSieh' dich nicht zu lange hier um.\pWenn uns jemand erwischt, sind wir geliefert!"

.elseif LANG_EN
str_0:
    .autostring 34 2 "PLAYER!\nHow on earth did you get in here?\pHeh!\nYou really are some brat, aren't ya?\pYou better don't hope to get your Gym-Badges and money back here, do you?\pI can't tell you while, but I got a feeling you won't find them here.\pSo don't ponder here for too long.\pIf we get caught, we are in serious trouble!"
.endif