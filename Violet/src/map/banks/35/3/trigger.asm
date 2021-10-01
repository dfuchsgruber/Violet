.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "pathfinding.s"
.include "mugshot.s"
.include "specials.s"

.global ow_script_sonnaufeld_clouds_icarus_trigger

ow_script_sonnaufeld_clouds_icarus_trigger:
    lockall
    applymovement 0xFF mov_fd
    waitmovement 0
    clearflag (1 | 0x8000)
    showsprite 1
    showsprite 2
    applymovement 2 mov_5u
    npc_move_to_player 1 waitmovement=0
    waitmovement 0
    applymovement 2 mov_fu
    applymovement 1 mov_fu
    waitmovement 0
    loadpointer 0 str_0
    show_mugshot MUGSHOT_ICARUS hide_mugshot=0 message_type=MSG_KEEPOPEN
    loadpointer 0 str_1
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    npc_move_to 1 0x1e 0x14 waitmovement=0
    npc_move_to 2 0x1e 0x15 waitmovement=0
    waitmovement 0
    movesprite2 1 0x1e 0x14
    movesprite2 2 0x1e 0x15
    applymovement 1 mov_fu
    applymovement 2 mov_fu
    applymovement 0xFF mov_fu
    loadpointer 0 str_2
    show_mugshot MUGSHOT_ICARUS hide_mugshot=1 message_type=MSG emotion=MUGSHOT_RUMINATIVE
    pause 32
    fadescreen 1
    setvar 0x8004 1
    setvar 0x8005 0xc
    call ow_script_move_camera_at_position
    setvar 0x8004 0xd
    setvar 0x8005 0x3
    call ow_script_move_camera_at_position
    setvar 0x8004 0x29
    setvar 0x8005 0x3
    call ow_script_move_camera_at_position
    setvar 0x8004 0x35
    setvar 0x8005 0xc
    call ow_script_move_camera_at_position
	special SPECIAL_OVERWORLD_VIEWPORT_SET_TO_PLAYER_POSITION
	fadescreen 0
	pause 32
    applymovement 1 mov_fd
    applymovement 2 mov_fd
    waitmovement 0
    loadpointer 0 str_3
    show_mugshot MUGSHOT_ICARUS hide_mugshot=0 message_type=MSG_KEEPOPEN
    loadpointer 0 str_4
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    callstd MSG_KEEPOPEN
    loadpointer 0 str_5
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    applymovement 1 mov_5u
    applymovement 2 mov_5u
    waitmovement 0
    hidesprite 1
    hidesprite 2
    setvar VAR_SONNAUFELD_CLOUDS_ICARUS 1
    releaseall
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Oh, hallo PLAYER!\pDu hast wohl Gefallen daran gefunden, die schwebenden Inseln im Himmel zu erkunden?"
str_1:
    .autostring 34 2 "Aber bilde dir bloß nicht ein, dass du mir in dieser Hinsicht das Wasser reichen kannst!"
str_2:
    .autostring 34 2 "Was haben wir denn hier für einen merkwürdigen Ort?"
str_3:
    .autostring 34 2 "Hier scheint sich definitiv etwas Interessantes zu verbergenDOTS"
str_4:
    .autostring 34 2 "Was es mit diesen seltsamen Vorrichtungen wohl auf sich hat?"
str_5:
    .autostring 34 2 "Ich werde es auf jeden Fall vor dir herausfinden!"
.elseif LANG_EN
.endif
