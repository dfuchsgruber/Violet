.include "vars.s"
.include "battle/battle_handicaps.s"
.include "movements.s"
.include "specials.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"
.include "levelscript_types.s"
.include "mugshot.s"
.include "difficulties.s"
.include "ordinals.s"

.global map_silvania_gym_arena_levelscripts

map_silvania_gym_arena_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
	.word lscr_fight
	.byte LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE
	.word lsrc_facing
	.byte 0x0

lsrc_facing:
	.hword 0x4001, 0x0
	.word ow_script_facing
	.hword 0xffff

ow_script_facing:
	spriteface 0xff 0x3
	end

lscr_fight:
	.hword 0x4001, 0x0
	.word ow_script_fight
	.hword 0x0

ow_script_fight:
	pause 0x10
	special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
	applymovement 0x7f mov_4l
	waitmovement 0x0
	special SPECIAL_OVERWORLD_VIEWPORT_LOCK
	pause 16

	setvar 0x8004 1
	setvar 0x8005 2
	special SPECIAL_BUFFER_BADGE_NAME
	loadpointer 0x0 str_referee
	callstd MSG

	applymovement 0x3 mov_1r
	applymovement 0xff mov_1l
	waitmovement 0x0
	draw_mugshot MUGSHOT_ROSALIE MUGSHOT_LEFT

	special SPECIAL_BATTLE_HANDICAP_CLEAR
	setvar 0x8004 BATTLE_HANDICAP_GRASSY_FIELD
	special SPECIAL_BATTLE_HANDICAP_SET
	compare DIFFICULTY DIFFICULTY_NORMAL
	gotoif EQUAL battle_difficulty_normal
	compare DIFFICULTY DIFFICULTY_HARD
	gotoif EQUAL battle_difficulty_hard

	@ DIFFICULTY_NORMAL : 
	trainerbattlecont 0x1 0xb7 0x0 str_before str_after later
battle_difficulty_normal:
	trainerbattlecont 0x1 0x1a4 0x0 str_before str_after later
battle_difficulty_hard:
	trainerbattlecont 0x1 0x1a5 0x0 str_before str_after later
later:
	setvar 0x8004 1
	setvar 0x8005 2
	special SPECIAL_BUFFER_BADGE_NAME
	loadpointer 0 str_0
	show_mugshot MUGSHOT_ROSALIE MUGSHOT_LEFT
	fanfare 0x104
	loadpointer 0x0 str_1
	callstd MSG
	waitfanfare
	loadpointer 0x0 str_2
	show_mugshot MUGSHOT_ROSALIE MUGSHOT_LEFT
	copyvarifnotzero 0x8000 ITEM_TM19
	copyvarifnotzero 0x8001 ITEM_MEISTERBALL
	callstd ITEM_OBTAIN
	loadpointer 0x0 str_3
	show_mugshot MUGSHOT_ROSALIE MUGSHOT_LEFT
	setflag FRBADGE_2
	warpmuted 0x3 0x3 0x8 0x20 0x12
	waitstate
	release

.ifdef LANG_GER
str_referee:
	.autostring 34 2 "Es beginnt nun der Kampf zwischen Rosalie und PLAYER um den BUFFER_3!"
str_before:
	.autostring 34 2 "PLAYER!\nHier in meiner Arena habe ich den Heimvorteil!\pMeine Pflanzen und ich mögen harmlos aussehenDOTS\pAber in uns steckt weit mehr, als man auf den ersten Blick vermutet!\pWenn ich einmal in Fahrt komme, wirst du im Handumdrehen überwuchert!"
str_after:
	.autostring 34 2 "Ich wusste ja, dass du stark bistDOTS\pAber das hier hat mich wirklich überrascht!"
str_0:
	.autostring 34 2 "Du bist wirklich unglaublich, PLAYER!\pDu hast meine armen Pflanzen-Pokémon regelrecht niedergemähtDOTS\pIch kann dir den BUFFER_3 mit bestem Gewissen überreichen."
str_1:
	.autostring 34 2 "PLAYER hat den BUFFER_3 von Rosalie erhalten."
str_2:
	.autostring 34 2 "Dieser Orden erlaubt es dir, die Versteckte Maschine Zerschneider außerhalb des Kampfes einzusetzen.\pZudem gehorchen dir jetzt getauschte Pokémon bis Level 40.\pDOTS DOTS DOTS\pUnd eine Kleinigkeit möchte ich dir zum Dank für deine Hilfe im Kranzwald doch noch anvertrauen."
str_3:
	.autostring 34 2 "Diese Technische Maschine enthält die Attacke Gigasauger.\pSie richtet beim Gegner großen Schaden an und hilft deinem Pokémon gleichzeitig, wieder zu Kräften zu kommen.\pEine ideale Strategie für jedes widerspenstige Pflanzen-Pokémon, findest du nicht?\pIch bin mir sicher, dass diese Technische Maschine in deinen Händen gut aufgehoben ist.\pDamit wirst du diese ganze Team Violet Bande zur Strecke bringen.\pIch bin mir sicher, dass du das schaffen kannst, PLAYER!"
.elseif LANG_EN

.endif