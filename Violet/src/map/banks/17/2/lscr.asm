.include "levelscript_types.s"
.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "items.s"
.include "movements.s"
.include "specials.s"

.global route_5_clouds_levelscripts

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
	callstd MSG
    setvar 0x8004 0x18
    setvar 0x8005 0xa
	call move_camera_at_position
	setvar 0x8004 0x12
    setvar 0x8005 0x1b
	call move_camera_at_position
	setvar 0x8004 0x5
    setvar 0x8005 0x7
	call move_camera_at_position
	fadescreen 1
	special SPECIAL_OVERWORLD_VIEWPORT_SET_TO_PLAYER_POSITION
	fadescreen 0
	pause 32
	loadpointer 0 str_1
	callstd MSG
	pause 16
	special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
	applymovement 0x7F mov_11u
	waitmovement 0
	special SPECIAL_OVERWORLD_VIEWPORT_LOCK
	loadpointer 0 str_2
	callstd MSG
	fadescreen 1
	special SPECIAL_OVERWORLD_VIEWPORT_SET_TO_PLAYER_POSITION
	fadescreen 0
	loadpointer 0 str_3
	callstd MSG
	setvar VAR_ROUTE_5_CLOUD_LEVELSCRIPT, 2
	releaseall
	end

move_camera_at_position:
	fadescreen 1
	special SPECIAL_OVERWORLD_VIEWPORT_SET_POSITION
	pause 1
	special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
	applymovement 0x7f mov_rslow
	pause 1
	fadescreen 0
	waitmovement 0
	special SPECIAL_OVERWORLD_VIEWPORT_LOCK
	return

mov_11u:
	.byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_rslow:
	.byte STEP_RIGHT_VERY_SLOW, STEP_RIGHT_VERY_SLOW, STEP_RIGHT_VERY_SLOW, STEP_RIGHT_VERY_SLOW, STEP_RIGHT_VERY_SLOW, STOP




.ifdef LANG_GER
str_0:
	.autostring 34 2 "Sieh dir einmal an, wo wir sind!"
str_1:
	.autostring 34 2 "Du kannst deinen Augen kaum trauen, habe ich recht?\pKaum zu fassen, dass wir uns auf einer schwebenden Insel befinden, oder?\pUnd von denen gibt es unzählige mehr, glaub mir!\pAber du musst auf einer Wolke reiten, um sie erkunden zu können.\pDOTSTEXT_DELAY_LONG DOTSTEXT_DELAY_LONG DOTSTEXT_DELAY_LONG\pWas sagst du da?\pDu möchtest so eine Wolke haben?\pAlso meine kann ich dir unmöglich überlassen.\pAber ich könnte dir eine Wolke weben, was sagst du dazu?\pNurDOTSTEXT_DELAY_LONG\pNaja, es ist nicht ganz einfach, an den nötigen Faden dafür zu kommen.\pMan kann ja schließlich nicht einfach irgendwelchen Garn verwenden.\pDafür braucht man ganz speziellen Wolkenfaden."
str_2:
	.autostring 34 2 "In dieser Höhle leben eine Menge angsteinflößender Käfer-Pokémon.\pUnd manche von ihnen produzieren diesen speziellen Wolkenfaden."
str_3:
	.autostring 34 2 "Ich geh' da aber sicher nicht rein, verstanden?\pWenn du willst, dass ich dir eine Wolke webe, musst du den Himmelsfaden wohl oder übel selbst besorgen."
.elseif LANG_EN

.endif

