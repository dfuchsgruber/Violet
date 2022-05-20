.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "overworld_script.s"
.include "levelscript_types.s"
.include "specials.s"

.global map_kaskada_black_market_levelscripts

map_kaskada_black_market_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
	.word lscr_on_frame_table
	.byte 0x0

lscr_on_frame_table:
	.hword STORY_PROGRESS, 0x21
	.word ow_script_on_frame_table
	.hword 0x0

ow_script_on_frame_table:
	lockall
	addvar STORY_PROGRESS 0x1
	pause 32
	loadpointer 0 str_0
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT hide_mugshot=1 message_type=MSG
	pause 32
	fadescreen 1
    setvar 0x8004 0x12
    setvar 0x8005 0x29
	call ow_script_move_camera_at_position
	setvar 0x8004 0x22
    setvar 0x8005 0x29
	call ow_script_move_camera_at_position
	setvar 0x8004 0x2c
    setvar 0x8005 0x16
	call ow_script_move_camera_at_position
	special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
	special SPECIAL_OVERWORLD_VIEWPORT_SET_TO_PLAYER_POSITION
	special SPECIAL_OVERWORLD_VIEWPORT_LOCK
	fadescreen 0
	pause 32
	loadpointer 0 str_1
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_2
	update_mugshot_emotion MUGSHOT_RUMINATIVE
	callstd MSG_KEEPOPEN
	loadpointer 0 str_3
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	applymovement 1 mov_6d
	waitmovement 0x0
	hidesprite 1
	releaseall
	end

ow_script_move_camera_at_position:
	callasm pal_set_all_to_black
	special SPECIAL_OVERWORLD_VIEWPORT_SET_POSITION
	callasm pal_set_all_to_black
	pause 1
	callasm pal_set_all_to_black
	special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
	applymovement 0x7f mov_rslow
	pause 1
	fadescreen 0
	waitmovement 0
	applymovement 0x7f mov_rslow2
	fadescreen 1
	waitmovement 0
	special SPECIAL_OVERWORLD_VIEWPORT_LOCK
	return

mov_11u:
	.byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_rslow:
	.byte STEP_RIGHT_VERY_SLOW, STEP_RIGHT_VERY_SLOW, STEP_RIGHT_VERY_SLOW, STEP_RIGHT_VERY_SLOW, STOP
mov_rslow2:
	.byte STEP_RIGHT_VERY_SLOW, STOP 


.ifdef LANG_GER
str_0:
	.autostring 34 2 "Da wären wir!"
str_1:
	.autostring 34 2 "Da staunst du was?\pWir sind hier auf dem Untergrundmarkt von Theto.\pHier werden alle Geschäfte abgewickelt, die unter dem Radar bleiben müssen.\pVersuch am Besten, keine Aufmerksamkeit zu erregenDOTS"
str_2:
	.autostring 34 2 "Das könnte sonst nämlich ganz schön gefährlich werdenDOTS\pDOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT"
str_3:
	.autostring 34 2 "Wie dem auch sei!\pIch sind hier, weil einer unserer Leute hier neue Mitstreiter für unsere Sache anwirbt.\pSein Name ist Lucky und er muss sich hier irgendwo herumtreiben.\pWährend wir hier nach ihm Ausschau halten, kannst du dir ein Bild davon machen, was im Untergrund dieser Region vor sich geht."
.elseif LANG_EN
.endif