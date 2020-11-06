.include "vars.s"

.global lscr_0x8f511d
.global ow_script_player_face_left

lscr_0x8f511d:
	.byte 0x4
.word lscr_0x8f5134
	.byte 0x2
.word lscr_0x8f5129
	.byte 0x0


.align 4
.global lscr_0x8f5134

lscr_0x8f5134:
	.hword STORY_PROGRESS, 0x13
	.word ow_script_player_face_left
	.hword 0x0


.align 4
.global lscr_0x8f5129

lscr_0x8f5129:
	.hword STORY_PROGRESS, 0x13
	.word ow_script_0x89472b
	.hword 0x0


.include "battle/battle_handicaps.s"
.include "vars.s"
.include "movements.s"
.include "specials.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"
.include "difficulties.s"
.include "ordinals.s"

.global ow_script_0x8947e3
.global ow_script_0x8f5b84
.global ow_script_0x89472b
ow_script_movs_0x897e33:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


ow_script_movs_0x83093d:
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x830940:
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x830943:
.byte STEP_LEFT
.byte STOP


ow_script_0x89472b:
special 0x113
applymovement 0x7f ow_script_movs_0x897e33
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x83093d
waitmovement 0x0
loadpointer 0x0 str_0x8cae89
callstd MSG
applymovement 0x1 ow_script_movs_0x830940
applymovement 0xff ow_script_movs_0x830943
waitmovement 0x0
draw_mugshot MUGSHOT_LESTER MUGSHOT_LEFT
special SPECIAL_BATTLE_HANDICAP_CLEAR
setvar 0x8004 BATTLE_HANDICAP_FLOATING_ROCKS
special SPECIAL_BATTLE_HANDICAP_SET
compare DIFFICULTY DIFFICULTY_NORMAL
gotoif EQUAL battle_difficulty_normal
compare DIFFICULTY DIFFICULTY_HARD
gotoif EQUAL battle_difficulty_hard
@ DIFFICULTY_NORMAL : 
trainerbattlecont 0x1 0xb6 0x0 str_0x8cafb5 str_0x8cb08b ow_script_0x8947e3

battle_difficulty_normal:
	trainerbattlecont 0x1 0x1a1 0x0 str_0x8cafb5 str_0x8cb08b ow_script_0x8947e3
battle_difficulty_hard:
	trainerbattlecont 0x1 0x1a2 0x0 str_0x8cafb5 str_0x8cb08b ow_script_0x8947e3

ow_script_0x8947e3:

setvar 0x8004 0
setvar 0x8005 2
special SPECIAL_BUFFER_BADGE_NAME
loadpointer 0x0 str_0x8cb101
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT
fanfare 0x104
loadpointer 0x0 str_0x897c8a
callstd MSG
waitfanfare
loadpointer 0x0 str_0x8cb1cc
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT
copyvarifnotzero 0x8000 ITEM_TM39
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x8cb281
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT
setflag FRBADGE_1
setflag FLAG_BRUCHFELS_MAY_1
setflag FLAG_BRUCHFELS_MAY_2 | 0x8000
setvar STORY_PROGRESS 0x14
warpmuted 0x3 0x2 0x4 0x2d 0x22
release
end


.ifdef LANG_GER


str_0x8cae89:
	.autostring 35 2 "Es beginnt nun der Kampf zwischen Lester und PLAYER um den Antikorden.\pIch erwarte einen fairen Kampf!"
str_0x8cafb5:
	.autostring 35 2 "Meine Stadt mag in Trümmern liegen, aber mein Kampfgeist ist weiterhin ungebrochen!\pZeig mir, was du auf dem Kasten hast!"
str_0x8cb08b:
    .autostring 35 2 "Beeindruckend gekämpft!\pSelbst meine felsenharten Gestein-Pokémon konnten dir nichts entgegensetzen."
str_0x8cb101:
	.autostring 35 2 "Du hast hervorragend gekämpft!\pDen BUFFER_3 hast du dir redlich verdient!"
str_0x897c8a:
    .autostring 35 2 "PLAYER hat den BUFFER_3 von Lester erhalten!"
str_0x8cb1cc:
	.autostring 35 2 "Dieser Orden erlaubt es dir, die Versteckte Maschine Blitz außerhalb des Kampfes zu nutzen.\pZudem gehorchen dir getauschte Pokémon bis Level 30.\pDOTS DOTS DOTS\pDarüber hinaus will ich dir noch etwas als Symbol meiner persönlichen Wertschätzung überreichen.\pDu hast diesen Kampf mit großer Würde bestritten."
str_0x8cb281:
	.autostring 35 2 "Diese Technische Maschine enthält die Attacke Felsgrab.\pSie ist eine meiner Lieblingsattacken, weil sie den Gegner schadet und gleichzeitig verlangsamt.\pEin idealer Angriff für langsamere Pokémon, wie etwa meine Gestein-Typen.\pIch hoffe, sie wird dir auf deiner Reise nützen.\pBegleite mich nun bitte aus der Untergrund-Arena hinaus."

.elseif LANG_EN

.endif


ow_script_0x8f5b84:
spriteface 0xff 0x3
end