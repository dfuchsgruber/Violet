.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"
.include "items.s"

.global ow_script_trainerschool_wildbattle

ow_script_trainerschool_wildbattle:
dowildbattle
compare LASTRESULT 0xff
gotoif EQUAL player_fainted
compare LASTRESULT 0x7
gotoif EQUAL caught_pkmn
checkitem ITEM_POKEBALL 1
compare LASTRESULT 0x1
gotoif LESS wasted_balls
call ow_script_0x89c5ee
applymovement 4 mov_face_up
waitmovement 0
loadpointer 0 str_whatya_doin
callstd MSG
special 7
releaseall
end

caught_pkmn:
setvar TRAINERSCHOOL_ALLOWED_TO_ENTER_GRASS 0
clearflag CAUGHT_POKEDEX_DISABLE
@ remove pokeballs
rm_pokeballs:
checkitem ITEM_POKEBALL 0x1
compare LASTRESULT 0x0
gotoif EQUAL no_more_balls
removeitem ITEM_POKEBALL 0x1
goto rm_pokeballs
no_more_balls:
applymovement 4 mov_face_up
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_caught
callstd MSG
special 7
setvar 0x8004 0xFF
setvar 0x8005 0x22
setvar 0x8006 0x10
special 0x24
waitmovement 0
applymovement 4 mov_face_down
applymovement 0xFF mov_face_up
waitmovement 0
pause 32
@ May does the test
call ow_script_0x89c5ee
loadpointer 0 str_call_rival
callstd MSG
special 7
applymovement 3 mov_rival_to_faun
waitmovement 0
call ow_script_0x89ba6e
loadpointer 0 str_rival_says_easy
callstd MSG
special 0x7
applymovement 0x3 mov_uinplace
waitmovement 0x0
applymovement 0x4 mov_face_up
applymovement 0x3 mov_into_grass
waitmovement 0
pause 40
sound 10
applymovement 0x3 mov_double_jump
waitmovement 0
checksound
sound 10
applymovement 0x3 mov_double_jump
waitmovement 0
checksound
pause 64
call ow_script_0x89c5ee
loadpointer 0 str_well_done_rival
callstd MSG
special 7
call ow_script_0x89ba6e
loadpointer 0 str_rival_says_was_easy
callstd MSG
special 0x7
applymovement 3 mov_rival_back
waitmovement 0
applymovement 0x4 mov_face_down
waitmovement 0
@ Maike does the catching test
call ow_script_0x89c5ee
loadpointer 0 str_mays_turn
callstd MSG
special 7
call ow_script_0x89db71
loadpointer 0x0 str_may_insecure
callstd MSG_FACE
special 0x7
applymovement 5 mov_may_to_faun
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_give_may_balls
callstd MSG
special 7
applymovement 0x5 mov_uinplace
waitmovement 0x0
applymovement 0x4 mov_face_up
applymovement 0x5 mov_into_grass
waitmovement 0
pause 40
call ow_script_0x89db71
loadpointer 0x0 str_may_screams
callstd MSG_KEEPOPEN
sound 10
applymovement 0x5 mov_double_jump
waitmovement 0
checksound
sound 10
applymovement 0x5 mov_double_jump
waitmovement 0
checksound
closeonkeypress
special 0x7
pause 64
call ow_script_0x89c5ee
loadpointer 0 str_may_done
callstd MSG
special 7
call ow_script_0x89db71
loadpointer 0x0 str_may_glad
callstd MSG
special 7
applymovement 5 mov_may_back
waitmovement 0
applymovement 0x4 mov_face_down
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_catching_test_done
callstd MSG
special 7
applymovement 3 mov_rival_to_battle_field
applymovement 7 mov_felix_to_battle_field
applymovement 4 mov_faun_to_battle_field
applymovement 5 mov_may_to_battle_field
waitmovement 0
addvar TRAINERSCHOOL_PROGRESS 1
releaseall
end

wasted_balls:
applymovement 4 mov_face_up
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_wasted
callstd MSG
special 7
subvar TRAINERSCHOOL_PROGRESS 1
releaseall
end


player_fainted:
applymovement 4 mov_face_up
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_fainted
callstd MSG
special 7
releaseall
@ Heal player
special 0
setvar 0x8004 0xFF
setvar 0x8005 0x22
setvar 0x8006 0xE
special 0x24
waitmovement 0
applymovement 0xFF mov_face_right
applymovement 0x4 mov_face_left
waitmovement 0
fadescreen 1
sound 0x119
checksound
pause 80
fadescreen 0
@ Might also have lost all balls
checkitem ITEM_POKEBALL 1
compare LASTRESULT 0x1
gotoif LESS wasted_balls_and_lost
call ow_script_0x89c5ee
loadpointer 0 str_healed
callstd MSG
special 7
releaseall
end

wasted_balls_and_lost:
call ow_script_0x89c5ee
loadpointer 0 str_wasted_balls_and_lost
callstd MSG
special 7
copyvarifnotzero 0x8000 ITEM_POKEBALL
copyvarifnotzero 0x8001 5
callstd ITEM_OBTAIN
releaseall
end

mov_faun_to_battle_field:
	.byte STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, LOOK_DOWN, STOP

mov_may_to_battle_field:
	.byte STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, LOOK_LEFT, STOP

mov_felix_to_battle_field:
	.byte STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP

mov_rival_to_battle_field:
	.byte STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STOP

mov_may_back:
	.byte STEP_DOWN, STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_DOWN, LOOK_UP, STOP

mov_may_to_faun:
	.byte STEP_UP, STEP_LEFT, STEP_LEFT, LOOK_UP, STOP

mov_rival_back:
	.byte STEP_DOWN, STEP_DOWN, STEP_LEFT, STEP_DOWN, LOOK_UP, STOP

mov_double_jump:
	.byte JUMP_IN_PLACE_FACE_UP, STOP

mov_into_grass:
	.byte STEP_LEFT, STEP_UP, STEP_UP, STOP

mov_rival_to_faun:
	.byte STEP_UP, STEP_RIGHT, STEP_RIGHT, LOOK_UP, STOP

mov_face_up:
	.byte LOOK_UP, STOP

mov_face_right:
	.byte LOOK_RIGHT, STOP

mov_face_left:
	.byte LOOK_LEFT, STOP

mov_uinplace:
	.byte STEP_IN_PLACE_UP, STEP_IN_PLACE_UP, STOP

mov_face_down:
	.byte LOOK_DOWN, STOP

.ifdef LANG_GER

str_whatya_doin:
	.autostring 35 2 "Was treibst du denn da, PLAYER?\pDu sollst das Pokémon einfangen! Gleich noch einmal!"

str_fainted:
	.autostring 35 2 "Das war ja eine schwache Vorstellung!\pIch bringe deine Pokémon wieder auf Vordermann, und du versuchst es erneut!"

str_healed:
	.autostring 35 2 "So, dein Pokémon ist wieder bei Kräften.\pEnttäusche mich kein zweites Mal, PLAYER!"

str_wasted:
	.autostring 35 2 "Du hast alle Pokébälle aufgebraucht?\pEine Schande ist das!\nKomm zu mir, ich werde dir ein paar neue geben."

str_wasted_balls_and_lost:
	.autostring 35 2 "Und deine Pokébälle hast du auch aufgebraucht?\pDas ist unerhört! Ich gebe dir ein paar neue und du siehst zu, dass du dich besser anstellst!"

str_caught:
	.autostring 35 2 "Sehr gut gemacht, PLAYER!\pZurück mit dir in die Reihe!"

str_call_rival:
	.autostring 35 2 "Als nächstes bist du an der Reihe, RIVAL.\pKomm zu mir, ich werde dir Pokébälle aushändigen."

str_rival_says_easy:
	.autostring 35 2 "Immer her damit!\nDas wird ein Kinderspiel!"

str_well_done_rival:
	.autostring 35 2 "Gut gemacht, RIVAL!\pSo muss das sein. Komm zurück in die Reihe."

str_rival_says_was_easy:
	.autostring 35 2 "Wie ich gesagt habe:\nEin Kinderspiel!"

str_mays_turn:
	.autostring 35 2 "Fein! Dann fehlst du nur noch du, Maike!\pKomm zu mir!"

str_may_insecure:
	.autostring 35 2 "Uh, ähm - okay!\nIch komme schonDOTS"

str_give_may_balls:
	.autostring 35 2 "Auch du erhältst von mir fünf Pokébälle.\pGib dein Bestes!"

str_may_screams:
	.autostring 35 2 "Whaaa!"

str_may_done:
	.autostring 35 2 "Sehr gut gemacht, Maike!\pBravo!\nZurück mit dir in die Reihe."

str_may_glad:
	.autostring 35 2 "Ta-Tatsächlich?\nHabe ich es geschafft?\pSuper! Das hätte ich ehrlich nicht gedachtDOTS"

str_catching_test_done:
	.autostring 35 2 "Ausgezeichnet!\nDamit hättet ihr diesen Teil der Prüfung schon einmal hinter euch.\pNun müsst ihr noch euer Kampfgeschick auf die Probe stellen, indem ihr gegeneinander antretet.\pPLAYER, RIVAL! Ihr bildet das erste Gegnerpaar.\pMaike und Felix das zweite.\pFindet euch auf dem Kampfplatz zusammen, wir beginnen unverzüglich."

.elseif LANG_EN

.endif
