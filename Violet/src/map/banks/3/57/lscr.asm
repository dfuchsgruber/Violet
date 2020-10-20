.include "vars.s"
.include "movements.s"
.include "specials.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"
.include "battle/battle_results.s"
.include "pathfinding.s"

.global lscr_0x719224
.global ow_script_trainerschool_wildbattle

lscr_0x719224:
	.byte 0x4
	.word lscr_movesprites
	.byte 0x0



.align 4

lscr_movesprites:
	.hword STORY_PROGRESS, 7
	.word ow_script_trainerschool_movesprites
	.hword 0x0


ow_script_trainerschool_movesprites:
	compare TRAINERSCHOOL_PROGRESS 3
	gotoif EQUAL before_pokemon_received
	compare TRAINERSCHOOL_PROGRESS 4
	gotoif EQUAL receiving_pokemon
	compare TRAINERSCHOOL_PROGRESS 5
	gotoif EQUAL catching_pokemon
	compare TRAINERSCHOOL_PROGRESS 6
	gotoif EQUAL catching_pokemon
	compare TRAINERSCHOOL_PROGRESS 7
	gotoif EQUAL battling
	compare TRAINERSCHOOL_PROGRESS 8
	gotoif EQUAL results
	end

results:
	movesprite 0x3 0x28 0x11
	spriteface 0x3 0x2
	movesprite 0x4 0x29 0xF
	spriteface 0x4 0x1
	movesprite 0x5 0x2B 0x11
	spriteface 0x5 0x2
	movesprite 0x7 0x2A 0x11
	spriteface 0x7 0x2
	end

battling:
	movesprite 0x3 0x23 0x11
	spriteface 0x3 0x4
	movesprite 0x4 0x29 0xF
	spriteface 0x4 0x1
	movesprite 0x5 0x2E 0x11
	spriteface 0x5 0x3
	movesprite 0x7 0x2A 0x11
	spriteface 0x7 0x4
	end


before_pokemon_received:
	checkflag TRAINERSCHOOL_MAY_OUTSIDE
	callif EQUAL move_may_before_pokemon_received
	checkflag TRAINERSCHOOL_FELIX_OUTSIDE
	callif EQUAL move_felix_and_blaise_before_pokemon_received
	end

receiving_pokemon:
	@ Algin all in a row
	movesprite 0x3 0x26 0x12
	spriteface 0x3 0x1
	movesprite 0x5 0x2A 0x12
	spriteface 0x5 0x1
	movesprite 0x7 0x28 0x12
	spriteface 0x7 0x1
	movesprite 0x6 0x29 0x12
	spriteface 0x6 0x1
	movesprite 0x4 0x29 0x14
	spriteface 0x4 0x2
	end

catching_pokemon:
	@ Aling all in a row facing upwards
	movesprite 0x3 0x21 0x10
	spriteface 0x3 0x2
	movesprite 0x7 0x23 0x10
	spriteface 0x7 0x2
	movesprite 0x5 0x25 0x10
	spriteface 0x5 0x2
	movesprite 0x4 0x23 0xE
	spriteface 0x4 0x1
	end


move_may_before_pokemon_received:
	movesprite 0x5 0x2A 0x11
	spriteface 0x5 0x3
	return

move_felix_and_blaise_before_pokemon_received:
	movesprite 0x6 0x29 0x12
	spriteface 0x6 0x2
	movesprite 0x7 0x28 0x12
	spriteface 0x7 0x2
	return



ow_script_trainerschool_wildbattle:
dowildbattle
compare LASTRESULT BATTLE_RESULT_LOST
gotoif EQUAL player_fainted
compare LASTRESULT BATTLE_RESULT_CAUGHT
gotoif EQUAL caught_pkmn
checkitem ITEM_POKEBALL 1
compare LASTRESULT 0x1
gotoif LESS wasted_balls
applymovement 4 mov_face_up
waitmovement 0
loadpointer 0 str_whatya_doin
show_mugshot MUGSHOT_FAUN alignment=MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_ANGRY
releaseall
end

caught_pkmn:
special SPECIAL_HEAL
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
loadpointer 0 str_caught
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
npc_move_to 0xFF 0x22 0x10
applymovement 4 mov_face_down
applymovement 0xFF mov_face_up
waitmovement 0
pause 32
@ Rival does the catching test
loadpointer 0 str_call_rival
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 3 mov_rival_to_faun
waitmovement 0
loadpointer 0 str_rival_says_easy
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
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
loadpointer 0 str_well_done_rival
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0 str_rival_says_was_easy
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY
applymovement 3 mov_rival_back
waitmovement 0
applymovement 0x4 mov_face_down
waitmovement 0
@ May does the catching test
loadpointer 0 str_mays_turn
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0x0 str_may_insecure
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_SHOCKED
applymovement 5 mov_may_to_faun
waitmovement 0
loadpointer 0 str_give_may_balls
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x5 mov_uinplace
waitmovement 0x0
applymovement 0x4 mov_face_up
applymovement 0x5 mov_into_grass
waitmovement 0
pause 40
loadpointer 0x0 str_may_screams
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_KEEPOPEN emotion=MUGSHOT_SCARED
sound 10
applymovement 0x5 mov_double_jump
waitmovement 0
checksound
sound 10
applymovement 0x5 mov_double_jump
waitmovement 0
checksound
closeonkeypress
pause 64
loadpointer 0 str_may_done
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0x0 str_may_glad
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY
applymovement 5 mov_may_back
waitmovement 0
applymovement 0x4 mov_face_down
waitmovement 0
loadpointer 0 str_catching_test_done
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
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
loadpointer 0 str_wasted
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
subvar TRAINERSCHOOL_PROGRESS 1
releaseall
end


player_fainted:
applymovement 4 mov_face_up
waitmovement 0
loadpointer 0 str_fainted
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
releaseall
@ Heal player
npc_move_to 0xFF 0x22 0xE
applymovement 0xFF mov_face_right
applymovement 0x4 mov_face_left
waitmovement 0
call ow_script_healing_sequence
@ Might also have lost all balls
checkitem ITEM_POKEBALL 1
compare LASTRESULT 0x1
gotoif LESS wasted_balls_and_lost
loadpointer 0 str_healed
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
releaseall
end

wasted_balls_and_lost:
loadpointer 0 str_wasted_balls_and_lost
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
copyvarifnotzero 0x8000 ITEM_POKEBALL
copyvarifnotzero 0x8001 5
callstd ITEM_OBTAIN
releaseall
end

mov_faun_to_battle_field:
	.byte STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, LOOK_DOWN, STOP

mov_may_to_battle_field:
	.byte STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, LOOK_LEFT, STOP

mov_felix_to_battle_field:
	.byte STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP

mov_rival_to_battle_field:
	.byte STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STOP

mov_may_back:
	.byte STEP_DOWN, STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_DOWN, LOOK_UP, STOP

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
	.autostring 35 2 "Was treibst du denn da, PLAYER?\pDu sollst das Pokémon einfangen!\pGleich noch einmal!"
str_fainted:
	.autostring 35 2 "Das war ja eine schwache Vorstellung!\pIch bringe deine Pokémon wieder auf Vordermann, und du versuchst es nochmal!"
str_healed:
	.autostring 35 2 "So, dein Pokémon ist wieder bei Kräften.\pReiß dich zusammen, PLAYER!"
str_wasted:
	.autostring 35 2 "Du hast alle Pokébälle aufgebraucht?\pDas darf ja nicht sein!\pIch werde dir, ausnahmsweise, ein paar neue geben.\pHalt dich ran!"
str_wasted_balls_and_lost:
	.autostring 35 2 "Und deine Pokébälle hast du auch aufgebraucht?\pDas ist ja wirklich erbärmlich!\pIch gebe dir ein paar neue und du kriegst das Ganze in den Griff!"
str_caught:
	.autostring 35 2 "Gut gemacht, PLAYER!\pZurück mit dir in die Reihe!"
str_call_rival:
	.autostring 35 2 "Als nächstes bist du an der Reihe, RIVAL.\pKomm zu mir, ich werde dir Pokébälle geben."
str_rival_says_easy:
	.autostring 35 2 "Immer her damit!\nDas wird ein Kinderspiel!"
str_well_done_rival:
	.autostring 35 2 "Alles klar, RIVAL!\pGenauso will ich das sehen.\pKomm zurück in die Reihe."
str_rival_says_was_easy:
	.autostring 35 2 "Ob das Ganze hier so leicht bleibt?"
str_mays_turn:
	.autostring 35 2 "Ausgezeichnet.\pFehlst nur noch du, Maike!"
str_may_insecure:
	.autostring 35 2 "Uff, ähm, ja, ich komme!"
str_give_may_balls:
	.autostring 35 2 "Auch du erhältst von mir fünf Pokébälle.\pGib dein Bestes!"
str_may_screams:
	.autostring 35 2 "Whaaa!"
str_may_done:
	.autostring 35 2 "Sehr gut gemacht, Maike!\pBravo!\nZurück mit dir in die Reihe."
str_may_glad:
	.autostring 35 2 "Ta-Tatsächlich?\nHabe ich es geschafft?\pSuper!\nDas hätte ich ehrlich nicht gedachtDOTS"
str_catching_test_done:
	.autostring 35 2 "Perfekt!\nHätten wir das auch geschafft!\pJetzt müsst ihr noch euer Kampfgeschick beweisen.\pPLAYER, du kämpfst gegen RIVAL.\pUnd Felix wird gegen Maike antreten."
.elseif LANG_EN
str_whatya_doin:
	.autostring 34 2 "What the hell are you doing, PLAYER!\pYou are supposed to catch that Pokémon!\pTry again!"
str_fainted:
	.autostring 34 2 "Well, that was a poor performance.\pI will help your Pokémon and you try it right away!"
str_healed:
	.autostring 35 2 "Ok, your Pokémon is ready to battle.\pGet your stuff together, PLAYER!"
str_wasted:
	.autostring 34 2 "You used up all of the Pokéballs?\pThat's insane!\pJust once, I will give you another five.\pBut this time you better get it done!"
str_wasted_balls_and_lost:
	.autostring 35 2 "And you also used up all of your Pokéballs?\pThat's dreadful!\pI will give you another five and don't you dare to dissapoint me again!"
str_caught:
	.autostring 35 2 "Well done, PLAYER!\pGet back in line."
str_call_rival:
	.autostring 35 2 "You're next, RIVAL.\pI will give you some Pokéballs."
str_rival_says_easy:
	.autostring 35 2 "Keep them coming!\pThat's gonna be a piece of cake!"
str_well_done_rival:
	.autostring 35 2 "Very well, that's how you do it.\pGet back in line."
str_rival_says_was_easy:
	.autostring 35 2 "Too easy, right?"
str_mays_turn:
	.autostring 35 2 "Ok.\nNow its just you, May!"
str_may_insecure:
	.autostring 35 2 "Uh, er, yes, coming!"
str_give_may_balls:
	.autostring 35 2 "Five Pokéballs, here you go.\pGive it your best!"
str_may_screams:
	.autostring 35 2 "Whaaa!"
str_may_done:
	.autostring 35 2 "Very well done, May!\pBravo!\nYou can get back in line."
str_may_glad:
	.autostring 35 2 "R-Really?\nI did it?\pWow!\nI would have never thought that I could do it!"
str_catching_test_done:
	.autostring 35 2 "Splendid.\nThat's that.\pNow you will have to prove your abilities in a battle.\pPLAYER, you will fight against RIVAL.\pFelix, your opponent will be May."
.endif