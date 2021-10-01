.include "levelscript_types.s"
.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "items.s"
.include "movements.s"
.include "specials.s"
.include "mugshot.s"

.global route_5_clouds_levelscripts
.global ow_script_move_camera_at_position

route_5_clouds_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE
	.word levelscript_player_set_on_cloud
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
	.word lscr_on_frame_table
	.byte 0x0

lscr_on_frame_table:
	.hword VAR_ROUTE_5_CLOUD_LEVELSCRIPT, 1
	.word ow_script_explain_quest
	.hword 0

ow_script_explain_quest:
	lockall
	pause 20
	loadpointer 0 str_0
	show_mugshot MUGSHOT_ICARUS emotion=MUGSHOT_HAPPY message_type=MSG
	fadescreen 1
    setvar 0x8004 0x15
    setvar 0x8005 0xa
	call ow_script_move_camera_at_position
	setvar 0x8004 0x12
    setvar 0x8005 0x21
	call ow_script_move_camera_at_position
	setvar 0x8004 0x30
    setvar 0x8005 0xf
	call ow_script_move_camera_at_position
	special SPECIAL_OVERWORLD_VIEWPORT_SET_TO_PLAYER_POSITION
	fadescreen 0
	pause 32
	loadpointer 0 str_1
	show_mugshot MUGSHOT_ICARUS hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_1_2
	update_mugshot_emotion MUGSHOT_RUMINATIVE
	callstd MSG_KEEPOPEN
	loadpointer 0 str_1_3
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG
	hide_mugshot
	pause 16
	special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
	applymovement 0x7F mov_11u
	waitmovement 0
	special SPECIAL_OVERWORLD_VIEWPORT_LOCK
	loadpointer 0 str_2
	show_mugshot MUGSHOT_ICARUS message_type=MSG
	fadescreen 1
	special SPECIAL_OVERWORLD_VIEWPORT_SET_TO_PLAYER_POSITION
	fadescreen 0
	loadpointer 0 str_3
	show_mugshot MUGSHOT_ICARUS message_type=MSG_KEEPOPEN emotion=MUGSHOT_SCARED
	loadpointer 0 str_3_2
	update_mugshot_emotion MUGSHOT_ANNOYED
	callstd MSG_KEEPOPEN
	loadpointer 0 str_3_3
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG
	hide_mugshot
	setvar VAR_ROUTE_5_CLOUD_LEVELSCRIPT, 2
	releaseall
	end

ow_script_move_camera_at_position:
	special SPECIAL_OVERWORLD_VIEWPORT_SET_POSITION
	pause 1
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
	.autostring 34 2 "Sieh dir einmal an, wo wir sind!"
str_1:
	.autostring 34 2 "Das ist doch beeindruckend, oder?\pWir stehen hier tatsächlich auf einer schwebenden Insel.\pUnd ganz früher haben hier einmal Menschen gelebt.\pAber um hier sicher erkunden zu können, brauchst du eine Wolke, die dich von Insel zu Insel trägt."
str_1_2:
	.autostring 34 2 "DOTSTEXT_DELAY_LONG DOTSTEXT_DELAY_LONG DOTSTEXT_DELAY_LONG"
str_1_3:
	.autostring 34 2 "Weißt du, ich könnte dir so eine Wolke weben.\pIch habe das vor einiger Zeit gelernt.\pAber dafür brauche ich einen ganz speziellen Garn."
str_2:
	.autostring 34 2 "In dieser Höhle leben eine Menge angsteinflößender Käfer-Pokémon.\pUnd manche von ihnen produzieren diesen speziellen Faden."
str_3:
	.autostring 34 2 "Aber ich geh' da aber sicher nicht rein, verstanden?"
str_3_2:
	.autostring 34 2 "I-Ich hab' natürlich keine Angst oder soDOTS"
str_3_3:
	.autostring 34 2 "Nur musst duDOTS\pMusst du mir erst beweisen, dass du so eine Wolke überhaupt verdienst, ok?\pAlso musst du mir den Wolkengarn aus dieser Höhle beschaffen."
.elseif LANG_EN

.endif

