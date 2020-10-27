
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "pathfinding.s"
.include "levelscript_types.s"
.include "mugshot.s"

.global lscr_0x719378

lscr_0x719378:
.byte LEVELSCRIPT_TYPE_ON_TRANSITION
.word ow_script_0x84c480
.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
.word lscr_0x719cab
.byte LEVELSCRIPT_TYPE_ON_LOAD
.word ow_script_0x81c52a
.byte 0x0

.align 4
.global lscr_0x719cab

lscr_0x719cab:
	.hword STORY_PROGRESS, 0x17
	.word ow_script_0x81c55e
	.hword 0x0

.global ow_script_0x84c480
.global ow_script_0x81c55e
.global ow_script_0x81c537
.global ow_script_0x81c52a

ow_script_0x81c52a:
	checkflag SILVANIA_FOREST_RIN
	callif NOT_EQUAL ow_script_0x81c537
	end

ow_script_0x81c537:
	setmaptile 0x23 0x1b 0x300 0x1
	return

ow_script_0x84c480:
	setworldmapflag WM_SILVANIA
	end

ow_script_0x81c55e:
	lockall
	npc_move_to_player 2 waitmovement=1
	applymovement 2 mov_fl
	waitmovement 0
	loadpointer 0 str_0
	show_mugshot MUGSHOT_FELIX alignment=MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_HAPPY hide_mugshot=0
	update_mugshot_emotion MUGSHOT_NORMAL
	loadpointer 0 str_1
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_RUMINATIVE
	loadpointer 0 str_2
	callstd MSG
	hide_mugshot

	pause 32
	sound 0x15
	applymovement 2 mov_exclam
	waitmovement 0
	checksound
	loadpointer 0 str_3
	show_mugshot MUGSHOT_FELIX alignment=MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_SHOCKED hide_mugshot=0
	update_mugshot_emotion MUGSHOT_ANGRY
	loadpointer 0 str_4
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_NORMAL
	loadpointer 0 str_5
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_HAPPY
	loadpointer 0 str_6
	callstd MSG
	hide_mugshot
	applymovement 2 mov_3r
	waitmovement 0
	pause 24
	applymovement 2 mov_run3l
	waitmovement 0
	loadpointer 0 str_7
	show_mugshot MUGSHOT_FELIX  alignment=MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_HAPPY
	applymovement 2 mov_8r
	waitmovement 0
	hidesprite 2
	addvar STORY_PROGRESS 0x1
	releaseall
	end

mov_fl:
	.byte LOOK_LEFT, STOP
mov_exclam:
	.byte SAY_EXCLAM, STOP
mov_8r:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP
mov_3r:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP
mov_run3l:
	.byte STEP_LEFT_FAST, STEP_LEFT_FAST, STEP_LEFT_FAST, STEP_LEFT_FAST, STOP


.ifdef LANG_GER
str_0:
	.autostring 34 2 "PLAYER!\nDas ist ja eine schöne Überraschung, dich hier zu treffen!"
str_1:
	.autostring 34 2 "Wie ist es dir auf deiner Reise ergangen?\pIch habe tatsächlich einen Weg gefunden, wie ich den Menschen in dieser Region helfen kannDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDOTSund habe mich der Polizei von Theto angeschlossen!\pWahnsinn, nicht?"
str_2:
	.autostring 34 2 "Aber ich muss zugeben, dass hier bei der Polizei nicht alles so läuft, wie ich es mir vorgestellt habe.\pDie Top Vier sind sich über sehr wenig einig und deshalb bekommen wir oft gar keine oder widersprüchliche AnweisungenDOTS\pHast du zum Beispiel schon von einer Organisation namens Team Violet gehört?"
str_3:
	.autostring 34 2 "Du hast sogar schon gegen sie gekämpft?"
str_4:
	.autostring 34 2 "Dann weißt du ja, was für ein Haufen von Wichten diese Bande ist."
str_5:
	.autostring 34 2 "Aber die Top Vier sehen sie nicht als Bedrohung anDOTS\pAber weißt du, diese Team Violet Leute gehen unschuldige Menschen an.\pBedrohung hin oder her, da muss man doch etwas machen, findest du nicht?\pUnd ich habe einige Hinweise erhalten, dass sich hier irgendwo einer der Kommandaten dieser Gruppe herumtreibtDOTS\pIch kann doch auf deine Hilfe zählen, wenn ich diesen Schurken stelle, ja?\pDOTS DOTS DOTS\nDOTS DOTS DOTS"
str_6:
	.autostring 34 2 "Prima!\nDann lass uns am Besten keine Zeit verlieren.\pWir sollten uns nach Team Violet umsehen."
str_7:
	.autostring 34 2 "Es ist wirklich toll, dich wiederzusehen, PLAYER!"
.elseif LANG_EN

.endif

