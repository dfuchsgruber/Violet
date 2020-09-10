.include "vars.s"

.global lscr_0x726eac

lscr_0x726eac:
	.byte 0x2
.word lscr_0x71fe1a
	.byte 0x4
.word lscr_0x71fe2f
	.byte 0x0


.align 4
.global lscr_0x71fe1a

lscr_0x71fe1a:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_0x83103c
	.hword 0x0


.align 4
.global lscr_0x71fe2f

lscr_0x71fe2f:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_0x801080
	.hword 0xffff
.include "battle/battle_handicaps.s"
.include "movements.s"
.include "specials.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_0x85fc97
.global ow_script_0x83103c
.global ow_script_0x85f329
.global ow_script_0x801080
.global ow_script_0x83108d

ow_script_0x801080:
spriteface 0xff 0x3
end


ow_script_movs_0x8310cc:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


ow_script_movs_0x8310d3:
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x8310d6:
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8310d9:
.byte STEP_LEFT
.byte STOP


ow_script_0x83103c:
lock
pause 0x10
special 0x113
applymovement 0x7f ow_script_movs_0x8310cc
waitmovement 0x0
special 0x114
pause 0x10
applymovement 0x4 ow_script_movs_0x8310d3
waitmovement 0x0
loadpointer 0x0 str_0x8310dc
callstd MSG
applymovement 0x3 ow_script_movs_0x8310d6
applymovement 0xff ow_script_movs_0x8310d9
waitmovement 0x0
loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
special SPECIAL_BATTLE_HANDICAP_CLEAR
setvar 0x8004 BATTLE_HANDICAP_GRASSY_FIELD
special SPECIAL_BATTLE_HANDICAP_SET
trainerbattlecont 0x1 0xb7 0x0 str_0x83114c str_0x8311a8 ow_script_0x83108d


ow_script_0x83108d:

setvar 0x8004 1
setvar 0x8005 2
special SPECIAL_BUFFER_BADGE_NAME
loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8311c0
callstd MSG
special 0xF
fanfare 0x104
loadpointer 0x0 str_0x8f2a1f
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
setflag FRBADGE_2
call ow_script_0x85fc97
end


ow_script_0x85fc97:
loadpointer 0x0 str_0x8f36ad
callstd MSG
copyvarifnotzero 0x8000 ITEM_TM19
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
call ow_script_0x85f329
end


ow_script_0x85f329:
loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8f3750
callstd MSG
special 0xF
warpmuted 0x3 0x3 0x8 0x20 0x12
release
end


.ifdef LANG_GER

str_mia:
	.string "Rosalie"

str_0x8310dc:
    .autostring 35 2 "Es beginnt nun der Kampf zwischen Rosalie und PLAYER."



str_0x83114c:
    .autostring 35 2 "Auch wenn einiges auf dem Spiel steht DOTS\pDOTS werde ich alles geben!\pZeig mir, dass du in der Lage bist, es mit einem Kommandanten von Team Violet aufzunehmen!"



str_0x8311a8:
    .autostring 35 2 "Unglaublich!\nDu bist wirklich stark!"



str_0x8311c0:
    .autostring 35 2 "Du kämpfst wirklich besser als die meisten Anfänger, denen ich bisher begegnet bin.\pDen BUFFER_3 hast du dir auf jeden Fall verdient!"



str_0x8f2a1f:
    .autostring 35 2 "PLAYER hat den BUFFER_3 erhalten!"



str_0x8f36ad:
	.autostring 35 2 "Dieser Orden erlaubt dir, die Versteckte Maschine Zerschneider außerhalb des Kampfes anzuwenden.\pAußerdem gehorchen dir getauschte Pokémon nun bis Level 40.\pIch vertraue dir, dass du es mit einem Kommandanten von Team Violet aufnehmen kannst.\pLass mich dir noch etwas geben, das deine Pokémon noch stärker macht."



str_0x8f3750:
    .autostring 35 2 "Diese Technische Maschine enthält Gigasauger.\pSie fügt dem Gegner Schaden zu und regeneriert die eigenen KP.\pVielleicht kannst du sie im Kampf gegen Team Violet einsetzten.\pWir sollten jetzt aber keine Zeit mehr verlieren.\pAuf in den Kranzdorf-Wald DOTS"

.elseif LANG_EN

.endif