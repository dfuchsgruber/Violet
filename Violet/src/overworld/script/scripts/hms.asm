.include "ordinals.s"
.include "vars.s"
.include "attacks.s"
.include "move_tutor.s"
.include "movements.s"
.include "map_adjacency_types.s"
.include "specials.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"

.global ow_script_cut_tree
.global ow_script_rock_smash

ow_script_cut_tree:
    special 0x187
    compare LASTRESULT 0x2
    gotoif EQUAL end_cut_tree
    lockall
    checkflag FRBADGE_2
    gotoif LESS cut_tree_no_cut_available
    checkattack ATTACK_ZERSCHNEIDER
    compare LASTRESULT 0x6
    gotoif EQUAL cut_tree_no_cut_available
    setanimation 0x0 0x800d
    bufferpartypokemon 0x0 0x800d
    bufferattack 0x1 ATTACK_ZERSCHNEIDER
    special2 LASTRESULT SPECIAL_AUTOMATIC_HM_USAGE_ACTIVE
    compare LASTRESULT 1
    gotoif EQUAL skip_ask_cut
    loadpointer 0x0 str_ask_cut
    callstd MSG_YES_NO
    compare LASTRESULT 0x0
    gotoif EQUAL end_cut_tree_close_box
skip_ask_cut:
    loadpointer 0x0 str_use_move
    callstd MSG_KEEPOPEN
    closeonkeypress
    doanimation 0x2
    waitstate
    goto cut_tree_animation_and_hidesprite
cut_tree_animation_and_hidesprite:
    applymovement LASTTALKED mov_cut_tree
    waitmovement 0x0
    hidesprite LASTTALKED
    releaseall
    end

cut_tree_no_cut_available:
    loadpointer 0x0 str_cut_tree_no_cut_available
    callstd MSG_SIGN
    releaseall
    end

end_cut_tree_close_box:
    closeonkeypress
end_cut_tree:
    release
    end

mov_cut_tree:
    .byte 0x69, STOP


ow_script_rock_smash:
    special 0x187
    compare LASTRESULT 0x2
    gotoif EQUAL end_cut_tree
    lockall
    checkflag FRBADGE_6
    gotoif LESS rock_smash_not_avilable
    checkattack ATTACK_ZERTRUEMMERER
    compare LASTRESULT 0x6
    gotoif EQUAL rock_smash_not_avilable
    setanimation 0x0 0x800d
    bufferpartypokemon 0x0 0x800d
    bufferattack 0x1 ATTACK_ZERTRUEMMERER
    special2 LASTRESULT SPECIAL_AUTOMATIC_HM_USAGE_ACTIVE
    compare LASTRESULT 1
    gotoif EQUAL skip_ask_rock_smash
    loadpointer 0x0 str_ask_rock_smash
    callstd MSG_YES_NO
    compare LASTRESULT 0x0
    gotoif EQUAL end_cut_tree_close_box
skip_ask_rock_smash:
    loadpointer 0x0 str_use_move
    callstd MSG_KEEPOPEN
    closeonkeypress
    doanimation 0x25
    waitstate
    goto rock_smash_animation_and_hidesprite


rock_smash_animation_and_hidesprite:
    applymovement LASTTALKED mov_rock_smash
    waitmovement 0x0
    hidesprite LASTTALKED
    releaseall
    end

rock_smash_not_avilable:
    loadpointer 0x0 str_rock_smash_not_avilable
    callstd MSG_SIGN
    end

mov_rock_smash:
    .byte 0x68, STOP



.ifdef LANG_GER
str_ask_cut:
    .autostring 34 2 "Du kannst den Zerschneider hier einsetzen!\pMöchtest du den Zerschneider einsetzen?"
str_cut_tree_no_cut_available:
    .autostring 34 2 "Der Zerschneider kann hier eingesetzt werden."
str_rock_smash_not_avilable:
    .autostring 34 2 "Ein großer Felsen.\nEin Pokémon könnte ihn vielleicht zertrümmern."
str_ask_rock_smash:
    .autostring 34 2 "Dieser Fels sieht zerbrechlich aus.\pSoll Zertrümmerer eingesetzt werden?"
str_use_move:
    .autostring 34 2 "BUFFER_1 setzt\nBUFFER_2 ein."
.elseif LANG_EN
str_ask_cut:
    .autostring 34 2 "Cut can be used to cut down this tree.\pDo you want to use cut?"
str_cut_tree_no_cut_available:
    .autostring 34 2 "Cut can be used to cut down this tree."
str_rock_smash_not_avilable:
    .autostring 34 2 "A large rock.\pA Pokémon might be able to smash it."
str_ask_rock_smash:
    .autostring 34 2 "This rock looks fragile.\pDo you want to use Rock Smash?"
str_use_move:
    .autostring 34 2 "BUFFER_1 uses\nBUFFER_2."
.endif


.global ow_script_rock_climb
.global ow_script_execute_rock_climb

ow_script_rock_climb:
	special 0x187
	compare LASTRESULT 2
	gotoif EQUAL end_rock_climb
	checkflag FRBADGE_8
	gotoif 0 rock_climb_not_available
	checkattack ATTACK_KRAXLER
	compare LASTRESULT 0x6
	gotoif EQUAL rock_climb_not_available

	setanimation 0x0 LASTRESULT
	bufferpartypokemon 0x0 LASTRESULT
	bufferattack 0x1 ATTACK_KRAXLER

    special2 LASTRESULT SPECIAL_AUTOMATIC_HM_USAGE_ACTIVE
    compare LASTRESULT 1
    gotoif EQUAL skip_ask_rock_climb
	loadpointer 0 str_enter
	callstd MSG_KEEPOPEN
	loadpointer 0 str_use_rock_climb
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_rock_climb
skip_ask_rock_climb:
	loadpointer 0 str_uses_rock_climb
	callstd MSG
	doanimation 0x2
	waitstate
	goto rock_climb_step_head

ow_script_execute_rock_climb:
	setanimation 0x0 LASTRESULT
	bufferpartypokemon 0x0 LASTRESULT
	bufferattack 0x1 ATTACK_KRAXLER
	doanimation 0x2
	waitstate
rock_climb_step_head:
	special2 LASTRESULT SPECIAL_ROCK_CLIMB_BLOCK_IS_CLIMBABLE
	compare LASTRESULT 0
	gotoif EQUAL rock_climb_last_step
	@ Execute another step of rock climb
	call rock_climb_do_step
	goto rock_climb_step_head
	rock_climb_last_step:
	call rock_climb_do_step
end_rock_climb:
	end
rock_climb_not_available:
    loadpointer 0 str_enter
    callstd MSG_KEEPOPEN
dont_rock_climb:
	closeonkeypress
	end

rock_climb_do_step:
	special2 0x8004 SPECIAL_PLAYER_GET_FACING @//get player facing
	compare 0x8004 1
	callif EQUAL move_down
	compare 0x8004 2
	callif EQUAL move_up
	compare 0x8004 3
	callif EQUAL move_left
	compare 0x8004 4
	callif EQUAL move_right
	return

move_down:
    applymovement 0xFF mov_down
    waitmovement 0
    return

move_up:
    applymovement 0xFF mov_up
    waitmovement 0
    return

move_left:
    applymovement 0xFF mov_left
    waitmovement 0
    return

move_right:
    applymovement 0xFF mov_right
    waitmovement 0
    return

mov_down:
    .byte STEP_DOWN_FAST, STOP
mov_up:
    .byte STEP_UP_FAST, STOP
mov_right:
    .byte STEP_RIGHT_FAST, STOP
mov_left:
    .byte STEP_LEFT_FAST, STOP

.ifdef LANG_GER
str_enter:
    .autostring 35 2 "Die Felswand sieht so aus, als könne ein Pokémon sie erklimmen DOTS"
str_use_rock_climb:
    .autostring 35 2 "Möchtest du Kraxler einsetzten, um die Felswand zu erklimmen?"
str_uses_rock_climb:
    .autostring 35 2 "BUFFER_1 setzt BUFFER_2 ein!"
.elseif LANG_EN
str_enter:
    .autostring 35 2 "The rock face looks like a Pokémon could climb it DOTS"
str_use_rock_climb:
    .autostring 35 2 "Do you want to use Rock Climb to climb the face rock?"
str_uses_rock_climb:
    .autostring 35 2 "BUFFER_1 uses BUFFER_2!"
.endif


.global ow_script_flash

ow_script_flash:
    callasm overworld_get_flash_level
    compare LASTRESULT 0
    gotoif EQUAL flash_level_0
    compare LASTRESULT 1
    gotoif EQUAL flash_level_1
    compare LASTRESULT 2
    gotoif EQUAL flash_level_2
    compare LASTRESULT 3
    gotoif EQUAL flash_level_3
    end

flash_level_0:
    lighten 0
    darken 0
    end
flash_level_1:
    lighten 1
    darken 1
    end
flash_level_2:
    lighten 2
    darken 2
    end
flash_level_3:
    lighten 3
    darken 3
    end


.global ow_script_automatic_flash_usage

ow_script_automatic_flash_usage:
	bufferattack 0x1 ATTACK_BLITZ
    special2 LASTRESULT SPECIAL_PLAYER_PARTY_GET_HIGHEST_LEVEL_FLASH_USER
	setanimation 0x0 LASTRESULT
	bufferpartypokemon 0x0 LASTRESULT
    loadpointer 0 str_uses_rock_climb
    callstd MSG
    special2 LASTRESULT SPECIAL_PLAYER_PARTY_GET_HIGHEST_LEVEL_FLASH_USER
	setanimation 0x0 LASTRESULT
	bufferpartypokemon 0x0 LASTRESULT
	doanimation 0x2
	waitstate
    setflag FLASH_USED
    goto ow_script_flash


.global ow_script_strength_boulder
.global ow_script_strength_use
.global ow_script_strength_use_hay
.global ow_script_boulder_gym_puzzle
.global ow_script_boulder_hay_bale

ow_script_strength_boulder:
    special 0x187
    compare LASTRESULT 2
    gotoif EQUAL end_script_strength
    checkflag STRENGTH_USED
    gotoif EQUAL strength_used
    checkflag FRBADGE_5
    gotoif NOT_EQUAL strength_can_not_be_used
    checkattack ATTACK_STAERKE
    compare LASTRESULT 6
    gotoif EQUAL strength_can_not_be_used
    setanimation 0 LASTRESULT

    special2 LASTRESULT SPECIAL_AUTOMATIC_HM_USAGE_ACTIVE
    compare LASTRESULT 1
    gotoif EQUAL skip_ask_strength
    
    loadpointer 0 str_could_move
    callstd MSG_KEEPOPEN
    loadpointer 0 str_ask_strength
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL strength_can_not_be_used
skip_ask_strength:
    closeonkeypress
    doanimation 0x28
    waitstate
    setflag 0x805
    special2 LASTRESULT SPECIAL_AUTOMATIC_HM_USAGE_ACTIVE
    compare LASTRESULT 1
    gotoif EQUAL end_script_strength
strength_used:
    loadpointer 0 str_strength_used
    callstd MSG_SIGN
    end

ow_script_strength_use:
    doanimation 0x28
    waitstate
    setflag 0x805
    goto strength_used

strength_can_not_be_used:
    loadpointer 0 str_could_move
    callstd MSG_KEEPOPEN
    goto badge_needed


ow_script_boulder_hay_bale:
    special 0x187
    compare LASTRESULT 2
    gotoif EQUAL end_script_strength
    checkflag STRENGTH_USED
    gotoif EQUAL strength_used_hay
    checkflag FRBADGE_5
    gotoif NOT_EQUAL strength_can_not_be_used_hay
    checkattack ATTACK_STAERKE
    compare LASTRESULT 6
    gotoif EQUAL strength_can_not_be_used_hay
    setanimation 0 LASTRESULT

    special2 LASTRESULT SPECIAL_AUTOMATIC_HM_USAGE_ACTIVE
    compare LASTRESULT 1
    gotoif EQUAL skip_ask_strength_hay

    loadpointer 0 str_could_move_hay
    callstd MSG_KEEPOPEN
    loadpointer 0 str_ask_strength
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL strength_can_not_be_used_hay
skip_ask_strength_hay:
    closeonkeypress
    doanimation 0x28
    waitstate
    setflag 0x805
    special2 LASTRESULT SPECIAL_AUTOMATIC_HM_USAGE_ACTIVE
    compare LASTRESULT 1
    gotoif EQUAL end_script_strength
strength_used_hay:
    loadpointer 0 str_strength_used_hay
    callstd MSG_SIGN
    end

ow_script_strength_use_hay:
    doanimation 0x28
    waitstate
    setflag 0x805
    goto strength_used_hay

strength_can_not_be_used_hay:
    loadpointer 0 str_could_move_hay
    callstd MSG_KEEPOPEN
    goto badge_needed

badge_needed:
    closeonkeypress
end_script_strength:
    releaseall
    end

ow_script_boulder_gym_puzzle:
    loadpointer 0 str_boulder_gym_puzzle
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_strength_used:
    .autostring 34 2 "Stärke ermöglicht es, den Felsen zu bewegen."
str_could_move:
    .autostring 34 2 "Ein Pokémon kann diesen Felsen vielleicht bewegen."
str_ask_strength:
    .autostring 34 2 "Möchtest du Stärke einsetzten?"
str_boulder_gym_puzzle:
	.autostring 34 2 "Der Felsen lässt sich ganz leicht auf den Bodenschienen bewegen."
str_could_move_hay:
    .autostring 34 2 "Ein Pokémon kann diesen Heuballen vielleicht bewegen."
str_strength_used_hay:
    .autostring 34 2 "Stärke ermöglicht es, den Heuballen zu bewegen."
.elseif LANG_EN
str_strength_used:
    .autostring 34 2 "Strength makes it possible to move the boulder."
str_could_move:
    .autostring 34 2 "A Pokémon may be able to move this boulder."
str_ask_strength:
    .autostring 34 2 "Do you want to use Strength?"
str_boulder_gym_puzzle:
	.autostring 34 2 "The boulder can be moved easily along the rails."
str_could_move_hay:
    .autostring 34 2 "A Pokémon may be able to move this hay bale."
str_strength_used_hay:
    .autostring 34 2 "Strength makes it possible to move the hay bale."
.endif