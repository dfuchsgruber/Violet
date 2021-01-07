.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "overworld_script.s"
.include "levelscript_types.s"

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
	pause 64
	loadpointer 0 str_0
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_1
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	loadpointer 0 str_2
	update_mugshot_emotion MUGSHOT_RUMINATIVE
	callstd MSG_KEEPOPEN
	loadpointer 0 str_3
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	applymovement 2 mov_6d
	waitmovement 0x0
	hidesprite 2
	addvar STORY_PROGRESS 0x1
	releaseall
	end


.ifdef LANG_GER
str_0:
	.autostring 34 2 "Habe ich zu viel versprochen?\pHier, unter der Erde, treibt sich das Gesindel dieser Region herum.\pAn diesem Markt findest du alles, was unter dem Radar verkauft werden muss."
str_1:
	.autostring 34 2 "Du solltest also schauen, dass du hier kein großes Aufsehen erregst, ja?"
str_2:
	.autostring 34 2 "Das könnte sonst nämlich ganz schön gefährlich werdenDOTS\pDOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT"
str_3:
	.autostring 34 2 "Hier sollten wir Albus treffen.\pEr ist der Anführer der Revolutionsbewegung und so etwas wie mein Mentor.\pFolge mir, ja?"
.elseif LANG_EN
.endif