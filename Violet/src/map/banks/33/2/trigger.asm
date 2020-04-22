.include "vars.s"
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

.global ow_script_blackbeard_ship_storage_trigger

ow_script_blackbeard_ship_storage_trigger:
    lockall
    pause 32
    sound 23
    hidesprite 9
    checksound
    pause 16
    loadpointer 0 str_0
    show_mugshot MUGSHOT_LUCKY alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    sound 0x15
    applymovement 7 mov_exclam_fl
    waitmovement 0
    checksound
    pause 16
    setvar 0x8004 7
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0
    applymovement 7 mov_fl
    waitmovement 0
    loadpointer 0 str_1
    show_mugshot MUGSHOT_LUCKY alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    setvar 0x8004 7
    setvar 0x8005 0x1d
    setvar 0x8006 0x12
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    hidesprite 7
    addvar STORY_PROGRESS 1
    releaseall
    end

mov_exclam_fl:
    .byte LOOK_LEFT, SAY_EXCLAM, STOP 
mov_fl:
    .byte LOOK_LEFT, STOP

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Fühlt sich gut an, wieder im Besitz meiner Pokémon zu sein.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pUnd dieses Kind ist auch noch nicht hierDOTS\pDas ist der Jackpot!\pIch werde einfachDOTS"
str_1:
    .autostring 34 2 "PLAYER!\pSo ein Zufall!\nKommst genau im richtigen Moment.\pIch hab deine Sachen gefunden.\pVon deinen Arenaorden und deinem Zaster fehlen allerdings jede SpurDOTS\pScheint so, als hätten diese gierigen Piraten sich deine Orden und das Geld unter den Nagel gerissenDOTS\pFürchte, du musst sie denen gewaltsam wieder abnehmenDOTS\pIch für meinen Teil setzte meinen Hintern aber keinesfalls aufs Spiel.\pIch will so schnell wie möglich von diesem Schiff runter, nichts für ungut.\pViel Glück, Kindchen!"
.elseif LANG_EN
.endif