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

.global map_meriana_city_gym_arena_levelscripts

map_meriana_city_gym_arena_levelscripts:
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
	spriteface 0xff 0x4
	end

lscr_fight:
	.hword 0x4001, 0x0
	.word ow_script_fight
	.hword 0x0

ow_script_fight:
	pause 0x10
	special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
	applymovement 0x7f mov_3r
	waitmovement 0x0
	special SPECIAL_OVERWORLD_VIEWPORT_LOCK
	pause 16

	setvar 0x8004 2
	setvar 0x8005 2
	special SPECIAL_BUFFER_BADGE_NAME
	loadpointer 0x0 str_referee
	callstd MSG

	applymovement 0x1 mov_1l
	applymovement 0xff mov_1r
	waitmovement 0x0
	draw_mugshot MUGSHOT_MANUS MUGSHOT_LEFT

	special SPECIAL_BATTLE_HANDICAP_CLEAR
	setvar 0x8004 BATTLE_HANDICAP_FOCUSED_FIGHTERS
	special SPECIAL_BATTLE_HANDICAP_SET
	compare DIFFICULTY DIFFICULTY_NORMAL
	gotoif EQUAL battle_difficulty_normal
	compare DIFFICULTY DIFFICULTY_HARD
	gotoif EQUAL battle_difficulty_hard

	@ DIFFICULTY_NORMAL : 
	trainerbattlecont 0x1 0x1cb 0x0 str_before str_after later
battle_difficulty_normal:
	trainerbattlecont 0x1 0xb8 0x0 str_before str_after later
battle_difficulty_hard:
	trainerbattlecont 0x1 0x1cc 0x0 str_before str_after later
later:
	setvar 0x8004 2
	setvar 0x8005 2
	special SPECIAL_BUFFER_BADGE_NAME
	loadpointer 0 str_0
	show_mugshot MUGSHOT_MANUS MUGSHOT_LEFT
	fanfare 0x104
	loadpointer 0x0 str_1
	callstd MSG
	waitfanfare
	loadpointer 0x0 str_2
	show_mugshot MUGSHOT_MANUS MUGSHOT_LEFT
	copyvarifnotzero 0x8000 ITEM_TM01
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
	loadpointer 0x0 str_3
	show_mugshot MUGSHOT_MANUS MUGSHOT_LEFT
	setflag FRBADGE_3
	cleartrainerflag 0x80
    cleartrainerflag 0x81
    cleartrainerflag 0x82
    cleartrainerflag 0x83
    cleartrainerflag 0x1cd
    cleartrainerflag 0x1ce
    cleartrainerflag 0x1cf
    cleartrainerflag 0x1d0
    setflag MERIANA_CITY_ELISE_VISIBLE
	warpmuted 0x3 0x1 0x2 0 0
	waitstate
	release

.ifdef LANG_GER
str_referee:
	.autostring 34 2 "Es beginnt nun der Kampf zwischen Manuel und PLAYER um den BUFFER_3!"
str_before:
    .autostring 34 2 "Kindchen!\pUm dir meinen Respekt zu verdienen, brauchst du nich bloß rohe Kraft.\pDein Geist muss im Einklang mit deinem Körper stehen.\pNur dann kann ein Trainer das wahre Potential seiner Pokémon entalften.\pBist du dazu im Stande?\pZeig es mir!"
str_after:
	.autostring 34 2 "Dein Fokus ist wirklich beeindruckend.\pJeder deiner Schläge hat perfekt gesessen."
str_0:
    .autostring 34 2 "Das nenne ich einen richtigen Kampf!\pNicht nur unsere Pokémon haben gegeinander gekämpftDOTS\pDas hier war ein Kräftemessen der Willenskraft!\pUnd du hast mich übertroffen, Kindchen.\pAls Auszeichnung dafür überreiche ich dir den BUFFER_3."
str_1:
	.autostring 34 2 "PLAYER hat den BUFFER_3 von Manuel erhalten."
str_2:
	.autostring 34 2 "Dieser Orden erlaubt es dir, die Versteckte Maschine Fliegen außerhalb des Kampfes einzusetzen.\pZudem gehorchen dir jetzt getauschte Pokémon bis Level 50.\pDOTS DOTS DOTS\pUnd als kleine Entschulding dafür, dass ich dich vorhin auf Route 4 unterschätzt habeDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pNaja, sieh' es als Wiedergutmachung, ja?"
str_3:
	.autostring 34 2 "Diese Technische Maschine enthält die Attacke Power-Punch.\pSie trifft mit einer unaufhaltsamen KraftDOTS\pAber für ihr Gelingen, bedarf es höchster Konzentration.\pNur jemand, dessen Geist den Körper beherrscht, kann diesen Angriff meistern.\pJemand wie du ist einer solchen Herausforderung sicherlich mehr als gewachsen!"
.elseif LANG_EN

.endif