.include "callstds.s"
.include "overworld_script.s"
.include "movements.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"
.include "specials.s"
.include "berry_stages.s"
.include "songs.s"
.include "items.s"
.include "overworld/misc.s"

.global ow_script_person_pokeball
.global ow_script_person_egg
.global ow_script_person_pokemon
.global ow_script_aggressive_wild
.global ow_script_aggressive_wild_do_battle
.global ow_script_berry_tree
.global ow_script_fertilize_berry_tree
.global ow_script_mushroom
.global ow_script_shell
.global ow_script_trash_can
.global ow_script_person_pokemon_non_facing
.global ow_script_person_accessible_move_tutor
.global ow_script_static_berry_tree
.global ow_script_recipe

ow_script_person_pokeball:
	callstd ITEM_FIND
	end

ow_script_person_egg:
	call ow_script_find_egg
	end

ow_script_person_pokemon:
	lock
	faceplayer
	bufferpokemon 0 0x8000
	showpokepic 0x8000 11 2
	copyvar 0x8004 0x8000
    special SPECIAL_SET_AS_SEEN
	random 4
	compare LASTRESULT 0
	callif EQUAL print_mon_string0 
	compare LASTRESULT 1
	callif EQUAL print_mon_string1 
	compare LASTRESULT 2
	callif EQUAL print_mon_string2
	compare LASTRESULT 3
	callif EQUAL print_mon_string3  
	callstd MSG_KEEPOPEN
	waitcry
	hidepokepic
	release
	end

print_mon_string0:
	loadpointer 0 str_mon0
	return
print_mon_string1:
	loadpointer 0 str_mon1
	return
print_mon_string2:
	loadpointer 0 str_mon2
	return
print_mon_string3:
	loadpointer 0 str_mon3
	return

ow_script_person_pokemon_non_facing:
	lock
	bufferpokemon 0 0x8000
	showpokepic 0x8000 11 2
	copyvar 0x8004 0x8000
    special SPECIAL_SET_AS_SEEN
	random 4
	compare LASTRESULT 0
	callif EQUAL print_mon_string0 
	compare LASTRESULT 1
	callif EQUAL print_mon_string1 
	compare LASTRESULT 2
	callif EQUAL print_mon_string2
	compare LASTRESULT 3
	callif EQUAL print_mon_string3  
	callstd MSG_KEEPOPEN
	waitcry
	hidepokepic
	releaseall
	end

ow_script_aggressive_wild:
	lock
	faceplayer
ow_script_aggressive_wild_do_battle:
	callasm aggressive_wild_setup_by_person
	special2 LASTRESULT SPECIAL_AGGRESSIVE_WILD_GET_APPROACHING_SPECIES
    bufferpokemon 0 LASTRESULT
    cry LASTRESULT 0
    loadpointer 0 str_aggressive_wild_challange
    callstd MSG_KEEPOPEN
    waitcry
	goto ow_script_aggressive_wild_pokemon_start_battle

ow_script_static_berry_tree:
	bufferitem 0 0x8000
	buffernumber 1 0x8001
	compare 0x8001 1
	gotoif EQUAL load_str_want_to_harvest_single_static
	loadpointer 0 str_want_to_harvest
	goto loaded_str_want_to_harvest_single_static
load_str_want_to_harvest_single_static:
	loadpointer 0 str_want_to_harvest_single
loaded_str_want_to_harvest_single_static:
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_harvest
	fanfare 262
	additem 0x8000 0x8001
	compare LASTRESULT 0
	gotoif EQUAL no_room_for_berries
	compare 0x8001 1
	gotoif EQUAL load_str_harvest_single_static
	loadpointer 0 str_harvest
	goto loaded_str_harvest_static
load_str_harvest_single_static:
	loadpointer 0 str_harvest_single
loaded_str_harvest_static:
	callstd MSG_KEEPOPEN
	waitfanfare
	compare 0x8001 1
	gotoif EQUAL load_str_harvested_single_static
	loadpointer 0 str_harvested
	goto loaded_str_harvested_single_static
load_str_harvested_single_static:
	loadpointer 0 str_harvested_single
loaded_str_harvested_single_static:
	callstd MSG_KEEPOPEN
	hidesprite LASTTALKED
	closeonkeypress
	end


ow_script_berry_tree:
	special2 LASTRESULT SPECIAL_BERRY_TREE_GET_STAGE
	compare LASTRESULT BERRY_STAGE_NO_BERRY
	gotoif EQUAL plant_berries
	special2 0x8004 SPECIAL_BERRY_TREE_GET_ITEM
	special2 0x8005 SPECIAL_BERRY_TREE_GET_YIELD
	special2 0x8006 SPECIAL_BERRY_TREE_GET_YIELDS_FLOWER
	bufferitem 0 0x8004
	buffernumber 1 0x8005
	compare LASTRESULT BERRY_STAGE_DIRT_PILE
	gotoif EQUAL dirt_pile
	compare LASTRESULT BERRY_STAGE_SPROUT
	gotoif EQUAL sprout
	compare LASTRESULT BERRY_STAGE_TALLER
	gotoif EQUAL taller
	compare LASTRESULT BERRY_STAGE_BLOSSOM
	gotoif EQUAL blossom
	compare LASTRESULT BERRY_STAGE_BERRIES
	gotoif EQUAL harvest_berries
	end

ow_script_fertilize_berry_tree:
	special SPECIAL_BERRY_TREE_SET_FERTILIZED
	special SPECIAL_BERRY_TREE_UPDATE_GFX
	sound 23
	checksound
	pause 24
	removeitem ITEM_MULCH 1
	return

plant_berries:
	// Display fertilization state of ground
	special2 LASTRESULT SPECIAL_BERRY_TREE_IS_FERTILIZED
	compare LASTRESULT 1
	gotoif EQUAL ground_fertilized
	loadpointer 0 str_ground_not_fertilized
	callstd MSG_KEEPOPEN
	checkitem ITEM_MULCH 1
	compare LASTRESULT 1
	gotoif NOT_EQUAL ask_planting // no mulch to fertilize
	loadpointer 0 str_ask_fertilize
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL ask_planting // don't want to fertilize
	closeonkeypress
	checksound
	// Fertilize
	call ow_script_fertilize_berry_tree
ground_fertilized:
	loadpointer 0 str_ground_fertilized
	callstd MSG_KEEPOPEN
ask_planting:
	loadpointer 0 str_want_to_plant
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_harvest
	special SPECIAL_BERRY_TREE_PLANT
	waitstate
	end

dirt_pile:
	compare 0x8004 ITEM_ANTIKER_SAMEN
	gotoif EQUAL load_str_dirt_pile_male
	compare 0x8004 ITEM_UNBEKANNTER_SAMEN
	gotoif EQUAL load_str_dirt_pile_male
	loadpointer 0 str_dirt_pile
	goto loaded_str_dirt_pile
load_str_dirt_pile_male:
	loadpointer 0 str_dirt_pile_male
	goto loaded_str_dirt_pile
loaded_str_dirt_pile:
	callstd MSG_KEEPOPEN
	checkitem ITEM_WUNDERSTAUB 1
	compare LASTRESULT 0x1
	gotoif 1 ask_use_wonder_dust
	goto dont_harvest
sprout:
	compare 0x8004 ITEM_ANTIKER_SAMEN
	gotoif EQUAL load_str_sprout_pile_male
	compare 0x8004 ITEM_UNBEKANNTER_SAMEN
	gotoif EQUAL load_str_sprout_pile_male
	loadpointer 0 str_sprout
	goto loaded_str_sprout
load_str_sprout_pile_male:
	loadpointer 0 str_sprout_male
	goto loaded_str_sprout
loaded_str_sprout:
	callstd MSG_KEEPOPEN
	checkitem ITEM_WUNDERSTAUB 1
	compare LASTRESULT 0x1
	gotoif 1 ask_use_wonder_dust
	goto dont_harvest
taller:
	compare 0x8004 ITEM_ANTIKER_SAMEN
	gotoif EQUAL load_str_taller_male
	compare 0x8004 ITEM_UNBEKANNTER_SAMEN
	gotoif EQUAL load_str_taller_male
	loadpointer 0 str_taller
	goto loaded_str_taller
load_str_taller_male:
	loadpointer 0 str_taller_male
	goto loaded_str_taller
loaded_str_taller:
	callstd MSG_KEEPOPEN
	checkitem ITEM_WUNDERSTAUB 1
	compare LASTRESULT 0x1
	gotoif 1 ask_use_wonder_dust
	goto dont_harvest
blossom:
	compare 0x8004 ITEM_ANTIKER_SAMEN
	gotoif EQUAL load_str_blossom_male
	compare 0x8004 ITEM_UNBEKANNTER_SAMEN
	gotoif EQUAL load_str_blossom_male
	loadpointer 0 str_blossom
	goto loaded_str_blossom
load_str_blossom_male:
	loadpointer 0 str_blossom_male
	goto loaded_str_blossom
loaded_str_blossom:
	callstd MSG_KEEPOPEN
	checkitem ITEM_WUNDERSTAUB 1
	compare LASTRESULT 0x1
	gotoif 1 ask_use_wonder_dust
	goto dont_harvest
ask_use_wonder_dust:
	compare 0x8004 ITEM_ANTIKER_SAMEN
	gotoif EQUAL load_str_wonder_dust_single_male
	compare 0x8004 ITEM_UNBEKANNTER_SAMEN
	gotoif EQUAL load_str_wonder_dust_single_male
	loadpointer 0 str_ask_wonder_dust
	goto loaded_str_ask_wonder_dust
load_str_wonder_dust_single_male:
	loadpointer 0 str_ask_wonder_dust_single_male
	goto loaded_str_ask_wonder_dust
loaded_str_ask_wonder_dust:
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_harvest
	callasm berry_tree_option_all_wonderdust_enabled
	compare LASTRESULT 1
	gotoif EQUAL use_max_wonderdust
	removeitem ITEM_WUNDERSTAUB 1
	loadpointer 0 str_use_wonder_dust
	callstd MSG_KEEPOPEN
	special SPECIAL_BERRY_TREE_GROW
wonderdust_update_gfx:
	special SPECIAL_BERRY_TREE_UPDATE_GFX
	sound 188
	doanimation 23
	checkanimation 23
	checksound
	compare 0x8004 ITEM_ANTIKER_SAMEN
	gotoif EQUAL load_str_grown_single_male
	compare 0x8004 ITEM_UNBEKANNTER_SAMEN
	gotoif EQUAL load_str_grown_single_male
	loadpointer 0 str_grown
	goto loaded_str_grown
load_str_grown_single_male:
	loadpointer 0 str_grown_single_male
	goto loaded_str_grown
loaded_str_grown:
	callstd MSG
	end

use_max_wonderdust: // Use wonderdust as long as the tree can grow and wonderdust is available
	setvar 0x8005 0 // How many dusts were used so far
use_max_wonderdust_loop_head:
	checkitem ITEM_WUNDERSTAUB 1
	compare LASTRESULT 0
	gotoif 1 use_max_wonderdust_loop_end
	special2 LASTRESULT SPECIAL_BERRY_TREE_GET_STAGE
	compare LASTRESULT BERRY_STAGE_BERRIES
	gotoif EQUAL use_max_wonderdust_loop_end
	removeitem ITEM_WUNDERSTAUB 1
	addvar 0x8005 1
	special SPECIAL_BERRY_TREE_GROW
	goto use_max_wonderdust_loop_head
use_max_wonderdust_loop_end:
	buffernumber 1 0x8005
	loadpointer 0 str_use_wonder_dust_multiple
	callstd MSG_KEEPOPEN
	goto wonderdust_update_gfx
harvest_berries:
	compare 0x8005 1
	gotoif EQUAL load_str_want_to_harvest_single
	loadpointer 0 str_want_to_harvest
	goto loaded_str_want_to_harvest_single
load_str_want_to_harvest_single:
	compare 0x8004 ITEM_ANTIKER_SAMEN
	gotoif EQUAL load_str_want_to_harvest_single_male
	compare 0x8004 ITEM_UNBEKANNTER_SAMEN
	gotoif EQUAL load_str_want_to_harvest_single_male
	loadpointer 0 str_want_to_harvest_single
	goto loaded_str_want_to_harvest_single
load_str_want_to_harvest_single_male:
	loadpointer 0 str_want_to_harvest_single_male
	goto loaded_str_want_to_harvest_single
loaded_str_want_to_harvest_single:
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_harvest 
    special SPECIAL_ITEM_OBTAIN_SHOW_DESCRIPTION
	fanfare 262
	special2 LASTRESULT SPECIAL_BERRY_TREE_PICK
	compare LASTRESULT 0
	gotoif EQUAL no_room_for_berries
	compare 0x8005 1
	gotoif EQUAL load_str_harvest_single
	loadpointer 0 str_harvest
	goto loaded_str_harvest
	loadpointer 0 str_harvest
load_str_harvest_single:
	compare 0x8004 ITEM_ANTIKER_SAMEN
	gotoif EQUAL load_str_harvest_single_male
	compare 0x8004 ITEM_UNBEKANNTER_SAMEN
	gotoif EQUAL load_str_harvest_single_male
	loadpointer 0 str_harvest_single
	goto loaded_str_harvest
load_str_harvest_single_male:
	loadpointer 0 str_harvest_single_male
	goto loaded_str_harvest
loaded_str_harvest:
	callstd MSG_KEEPOPEN
	waitfanfare
    special SPECIAL_ITEM_OBTAIN_DELETE_DESCRIPTION
	compare 0x8005 1
	gotoif EQUAL load_str_harvested_single
	loadpointer 0 str_harvested
	goto loaded_str_harvested_single
load_str_harvested_single:
	compare 0x8004 ITEM_ANTIKER_SAMEN
	gotoif EQUAL load_str_harvested_single_male
	compare 0x8004 ITEM_UNBEKANNTER_SAMEN
	gotoif EQUAL load_str_harvested_single_male
	loadpointer 0 str_harvested_single
	goto loaded_str_harvested_single
load_str_harvested_single_male:
	loadpointer 0 str_harvested_single_male
	goto loaded_str_harvested_single
loaded_str_harvested_single:
	callstd MSG_KEEPOPEN
	special SPECIAL_BERRY_TREE_UPDATE_GFX
	compare 0x8006 1
	callif EQUAL harvest_flower
	loadpointer 0 str_ground_muddy
	callstd MSG
	end
dont_harvest:
	closeonkeypress
	end
no_room_for_berries:
	special SPECIAL_ITEM_OBTAIN_DELETE_DESCRIPTION
	loadpointer 0 str_no_room_for_berries
	callstd MSG
	end
harvest_flower:
	closeonkeypress
	sound 0x15
	applymovement 0xFF mov_exclam
	waitmovement 0
	checksound
	loadpointer 0 str_harvest_flower
	callstd MSG_KEEPOPEN
	copyvarifnotzero 0x8000 ITEM_LOTUSBLUETE
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif NOT_EQUAL harvest_flower_return
	loadpointer 0 str_harvest_flower_no_space
	callstd MSG_KEEPOPEN
harvest_flower_return:
	return

ow_script_mushroom:
	lockall
	special2 LASTRESULT SPECIAL_MUSHROOM_GET_STAGE
	compare LASTRESULT MUSHROOM_TYPE_PLUCKED
	gotoif EQUAL mushroom_plucked
	compare LASTRESULT MUSHROOM_TYPE_TINY_MUSHROOM
	gotoif EQUAL mushroom_tiny
	compare LASTRESULT MUSHROOM_TYPE_LARGE_MUSHROOM
	gotoif EQUAL mushroom_large 
	compare LASTRESULT MUSHROOM_TYPE_ENCOUNTER
	gotoif EQUAL mushroom_encounter
	compare LASTRESULT MUSHROOM_TYPE_ENCOUNTER_LARGE
	gotoif EQUAL mushroom_encounter
	releaseall
	end
mushroom_plucked:
	loadpointer 0 str_mushroom_plucked
	callstd MSG_KEEPOPEN
	releaseall
	end
mushroom_tiny:
	setvar 0x8000 ITEM_MINIPILZ
	goto mushroom_plucking
mushroom_encounter:
	setvar 0x8004 1
	special2 0x8004 SPECIAL_MUSHROOM_GET_ENCOUNTER
	call misc_encounter
	callasm mushroom_pluck
	special SPECIAL_BERRY_TREE_UPDATE_GFX
	bufferpokemon 0 0x8004
	loadpointer 0 str_mushroom_no_pluck
	callstd MSG_KEEPOPEN
	releaseall
	end


mushroom_large: 
	setvar 0x8000 ITEM_RIESENPILZ
mushroom_plucking:
	bufferitem 0 0x8000
	loadpointer 0 str_mushrooms_are_growing
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_pluck_mushrooms
	checkitemroom 0x8000 0x1
	compare LASTRESULT 0
	gotoif EQUAL no_room_for_mushroom
	setvar 0x8004 0
	special2 0x8004 SPECIAL_MUSHROOM_GET_ENCOUNTER
	compare 0x8004 0
	callif NOT_EQUAL misc_encounter
	setvar 0x8001 1
	callstd ITEM_OBTAIN
	callasm mushroom_pluck
	special SPECIAL_BERRY_TREE_UPDATE_GFX
	releaseall
	end
no_room_for_mushroom:
	loadpointer 0 str_no_room_for_mushroom
	callstd MSG_KEEPOPEN
dont_pluck_mushrooms:
	closeonkeypress
	releaseall
	end

misc_encounter:
	sound 0x15
	cry 0x8004 0
	callasm special_misc_encounter_overworld_new
	applymovement 0xFF mov_exclam
	waitmovement 0
	checksound
	waitcry
	callasm misc_encounter_setup
	setflag FLAG_IN_BATTLE
	callasm battle_initialize_misc_ecounter
	clearflag FLAG_IN_BATTLE
	waitstate
	return

mov_exclam:
	.byte SAY_EXCLAM, STOP

ow_script_shell:
	lockall
	special2 LASTRESULT SPECIAL_SHELL_GET_STAGE
	compare LASTRESULT SHELL_TYPE_EMPTY
	gotoif EQUAL shell_empty
	compare LASTRESULT SHELL_TYPE_PEARL
	gotoif EQUAL shell_pearl
	compare LASTRESULT SHELL_TYPE_LARGE_PEARL
	gotoif EQUAL shell_large_pearl
	compare LASTRESULT SHELL_TYPE_HEART_SCALE
	gotoif EQUAL shell_heart_scale
	compare LASTRESULT SHELL_TYPE_SHOAL_SALT
	gotoif EQUAL shell_shoal_salt
	compare LASTRESULT SHELL_TYPE_SHOAL_SHELL
	gotoif EQUAL shell_shoal_shell
	compare LASTRESULT SHELL_TYPE_ENCOUNTER
	gotoif EQUAL shell_encounter
	releaseall
	end
shell_empty:
	loadpointer 0 str_shell_empty
	callstd MSG_KEEPOPEN
	releaseall
	end
shell_pearl:
	setvar 0x8000 ITEM_PERLE
	goto shell_opening
shell_large_pearl:
	setvar 0x8000 ITEM_RIESENPERLE
	goto shell_opening
shell_heart_scale:
	setvar 0x8000 ITEM_HERZSCHUPPE
	goto shell_opening
shell_shoal_salt:
	setvar 0x8000 ITEM_KUESTENSALZ
	goto shell_opening
shell_shoal_shell:
	setvar 0x8000 ITEM_KUESTENSCHALE
shell_opening:
	bufferitem 0 0x8000
	loadpointer 0 str_shell_to_be_opened
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_open_shell
	bufferitem 0 0x8000
	checkitemroom 0x8000 0x1
	compare LASTRESULT 0
	gotoif EQUAL no_room_for_shell
	setvar 0x8001 1
	callstd ITEM_OBTAIN
	callasm shell_open
	special SPECIAL_BERRY_TREE_UPDATE_GFX
	releaseall
	end
shell_encounter:
	loadpointer 0 str_shell_to_be_opened
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_open_shell
	special2 0x8004 SPECIAL_SHELL_GET_ENCOUNTER
	compare 0x8004 0
	callif NOT_EQUAL misc_encounter
	callasm shell_open
	special SPECIAL_BERRY_TREE_UPDATE_GFX
	bufferpokemon 0 0x8004
	loadpointer 0 str_pokemon_was_hiding_in_shell
	callstd MSG_KEEPOPEN
	releaseall
	end
	
no_room_for_shell:
	loadpointer 0 str_no_room_for_mushroom
	callstd MSG_KEEPOPEN
dont_open_shell:
	closeonkeypress
	releaseall
	end

ow_script_trash_can:
	lockall
	special2 0x8004 SPECIAL_TRASH_GET_TYPE
	compare 0x8004 TRASH_TYPE_EMPTY
	gotoif EQUAL trash_empty
	loadpointer 0 str_trash_to_be_opened
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_open_trash
	compare 0x8004 TRASH_TYPE_WIND
	gotoif EQUAL trash_wind
	compare 0x8004 TRASH_TYPE_ITEM
	gotoif EQUAL trash_item
	compare 0x8004 TRASH_TYPE_ENCOUNTER
	gotoif EQUAL trash_encounter
	releaseall
	end
trash_empty:
	loadpointer 0 str_trash_empty
	callstd MSG_KEEPOPEN
	releaseall
	end
trash_wind:
	loadpointer 0 str_trash_wind
	callstd MSG_KEEPOPEN
	callasm trash_set_empty
	special SPECIAL_BERRY_TREE_UPDATE_GFX
	releaseall
	end
trash_item:
	special2 0x8000 SPECIAL_TRASH_GET_ENCOUNTER_OR_ITEM
	setvar 0x8001 1
	bufferitem 0 0x8000
	checkitemroom 0x8000 0x1
	compare LASTRESULT 0
	gotoif EQUAL no_room_for_trash_item
	callstd ITEM_OBTAIN
	callasm trash_set_empty
	special SPECIAL_BERRY_TREE_UPDATE_GFX
	releaseall
	end
trash_encounter:
	special2 0x8004 SPECIAL_TRASH_GET_ENCOUNTER_OR_ITEM
	compare 0x8004 0
	callif NOT_EQUAL misc_encounter
	callasm trash_set_empty
	special SPECIAL_BERRY_TREE_UPDATE_GFX
	bufferpokemon 0 0x8004
	loadpointer 0 str_pokemon_was_hiding_oin_trash
	callstd MSG_KEEPOPEN
	releaseall
	end
no_room_for_trash_item:
	loadpointer 0 str_no_room_for_mushroom
	callstd MSG_KEEPOPEN
dont_open_trash:
	closeonkeypress
	releaseall
	end

ow_script_person_accessible_move_tutor:
	//setvar VAR_ACCESIBLE_MOVE_TUTOR_TYPE, 0
	callasm accessible_move_tutor_set_flag
	loadpointer 0 str_quarz_intro
	callstd MSG_KEEPOPEN
	checkitem ITEM_ENERGIEQUARZ, 1
	compare LASTRESULT 1
	gotoif NOT_EQUAL no_quarz_in_bag
	loadpointer 0 str_ask_quarz
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL no_quarz
	copyvar 0x8004 VAR_ACCESIBLE_MOVE_TUTOR_TYPE
	subvar 0x8004 1
	setvar 0x8005 2
	special SPECIAL_BUFFER_TYPE_NAME
	loadpointer 0 str_crystal_ask_mon
	callstd MSG_KEEPOPEN
	special SPECIAL_SELECT_PARTY_POKEMON_ACCESSIBLE_MOVE_TUTOR @ SPECIAL_MOVE_RELEARNER_SELECT_POKEMON
	waitstate
	compare 0x8004 6
	gotoif EQUAL accessible_move_tutor_end
	compare 0x8004 7
	gotoif EQUAL accessible_move_tutor_end
	special SPECIAL_PARTY_POKEMON_IS_EGG
	compare LASTRESULT 1
	gotoif EQUAL accessible_move_tutor_is_egg
	callasm pokemon_get_number_of_accessible_moves_in_lastresult
	compare LASTRESULT 0
	gotoif EQUAL accessible_move_tutor_no_moves
	loadpointer 0 str_which_mon_to_tutor
	callstd MSG_KEEPOPEN
	special SPECIAL_MOVE_RELEARNER_MENU
	waitstate
	compare 0x8004 0
	gotoif EQUAL accessible_move_tutor_end
	loadpointer 0 str_quarz_used
	callstd MSG_KEEPOPEN
	closeonkeypress
	removeitem ITEM_ENERGIEQUARZ, 1
accessible_move_tutor_end:
	setvar VAR_ACCESIBLE_MOVE_TUTOR_TYPE, 0
	end
accessible_move_tutor_is_egg:
	loadpointer 0 str_crystal_is_egg
	callstd MSG_KEEPOPEN
	goto no_quarz
accessible_move_tutor_no_moves:
	loadpointer 0 str_crystal_no_moves
	callstd MSG_KEEPOPEN
	goto no_quarz
no_quarz:
	closeonkeypress
	goto accessible_move_tutor_end
no_quarz_in_bag:
	loadpointer 0 str_no_quarz
	callstd MSG_KEEPOPEN
	goto no_quarz

ow_script_recipe:
	copyvar 0x8004 0x8000
	callasm overworld_recipe_buffer_name
	hidesprite LASTTALKED
	fanfare 261
	loadpointer 0 str_player_found_recipe
	callstd MSG_KEEPOPEN
	waitfanfare
	loadpointer 0 str_recipe_can_be_used
	callstd MSG_KEEPOPEN
	releaseall
	end

.ifdef LANG_GER
str_which_mon_to_tutor:
	.autostring 34 2 "Welchen Angriff soll BUFFER_1 erlernen?"
str_quarz_intro:
	.autostring 34 2 "Eine mysteriöse Energie scheint diesen Kristall zu umgebenDOTS"
str_no_quarz:
	.autostring 34 2 "Das Leuchten errinnert an einen EnergiequarzDOTS"
str_ask_quarz:
	.autostring 34 2 "Möchtest du Energiequarz in den Kristall einsetzen?"
str_crystal_ask_mon:
	.autostring 34 2 "Eine strahlende Aura geht von dem Kristall aus!\pEs scheint, als ob eines deiner Pokémon eine BUFFER_3-Attacke lernen kann.\pWelches Pokémon soll eine neue Attacke lernen?"
str_crystal_is_egg:
	.autostring 34 2 "Ein Ei kann keine Attacken lernen!"
str_crystal_no_moves:
	.autostring 34 2 "Die Aura scheint mit deinem Pokémon nicht kompatibel zu seinDOTS"
str_quarz_used:
	.autostring 34 2 "Die strahlende Aura ist erloschenDOTS\pEs scheint, als wäre der Energiequarz aufgebrauchtDOTS"
str_mon0:
	.autostring 34 2 "BUFFER_1! BUFFER_1!"
str_mon1:
	.autostring 34 2 "BUFFER_1?"
str_mon2:
	.autostring 34 2 "BUFFER_1DOTS"
str_mon3:
	.autostring 34 2 "BUFFER_1!\nBUFFER_1?"
str_attacks:
	.autostring 34 2 "BUFFER_1 greift an!"
str_want_to_harvest:
	.string "Dort wachsen BUFFER_2 BUFFER_1n!\pMöchtest du die BUFFER_1n\npflücken?"
str_want_to_harvest_single:
	.string "Dort wächst eine BUFFER_1!\pMöchtest du die BUFFER_1\npflücken?"
str_want_to_harvest_single_male:
	.string "Dort wächt ein BUFFER_1!\pMöchtest du den BUFFER_1\npflücken?"
str_harvest:
	.autostring 34 2 "PLAYER pflückt die BUFFER_1n."
str_harvest_single:
	.autostring 34 2 "PLAYER pflückt die BUFFER_1."
str_harvest_single_male:
	.autostring 34 2 "PLAYER pflückt den BUFFER_1."
str_harvested:
	.autostring 34 2 "PLAYER packt die BUFFER_1n in die Beerentasche."
str_harvested_single:
	.autostring 34 2 "PLAYER packt die BUFFER_1 in die Beerentasche."
str_harvested_single_male:
	.autostring 34 2 "PLAYER packt den BUFFER_1 in die Beerentasche."
str_ground_muddy:
	.autostring 34 2 "Der Boden ist wieder weich und lehmig."
str_no_room_for_berries:
	.autostring 34 2 "Es scheint so, als hättest du keinen Platz für weitere Beeren!"
str_ground_not_fertilized:
	.autostring 34 2 "Der Boden ist weich und lehmig."
str_ground_fertilized:
	.autostring 34 2 "Der Boden ist mit Mulch gedüngt."
str_ask_fertilize:
	.autostring 34 2 "Möchtest du ihn mit Mulch düngen?"
str_want_to_plant:
	.autostring 34 2 "Möchtest du eine Beere pflanzen?"
str_dirt_pile:
	.autostring 34 2 "Hier wurde eine BUFFER_1 angepflanzt."
str_dirt_pile_male:
	.autostring 34 2 "Hier wurde ein BUFFER_1 angepflanzt."
str_sprout:
	.autostring 34 2 "Es scheint, als wäre die BUFFER_1 ausgetrieben!"
str_sprout_male:
	.autostring 34 2 "Es scheint, als wäre der BUFFER_1 ausgetrieben!"
str_taller:
	.autostring 34 2 "Die BUFFER_1 scheint gut zu gedeihen!"
str_taller_male:
	.autostring 34 2 "Der BUFFER_1 scheint gut zu gedeihen!"
str_blossom:
	.autostring 34 2 "Die BUFFER_1 steht in voller Blüte!"
str_blossom_male:
	.autostring 34 2 "Der BUFFER_1 steht in voller Blüte!"
str_ask_wonder_dust:
	.autostring 34 2 "Möchtest du Wunderstaub benutzen, um die BUFFER_1n wachsen zu lassen?"
str_ask_wonder_dust_single_male:
	.autostring 34 2 "Möchtest du Wunderstaub benutzen, um den BUFFER_1 wachsen zu lassen?"
str_use_wonder_dust:
	.autostring 34 2 "PLAYER benutzt Wunderstaub."
str_use_wonder_dust_multiple:
	.autostring 34 2 "PLAYER benutzt BUFFER_2-Mal Wunderstaub."
str_grown:
	.autostring 34 2 "Die BUFFER_1n sind gewachsen!"
str_grown_single_male:
	.autostring 34 2 "Der BUFFER_1 ist gewachsen!"
str_harvest_flower:
	.autostring 34 2 "Was ist das?"
str_harvest_flower_no_space:
	.autostring 34 2 "Du hast keinen Platz mehr dafürDOTS"
str_mushroom_plucked:
	.autostring 34 2 "Es scheint, als wären hier einmal Plize gewachsen, aber irgendwer muss sie gepflückt habenDOTS\pEs dauert wohl noch, bis wieder neue Pilze gewachsen sind."
str_mushrooms_are_growing:
	.autostring 34 2 "Dort wächst ein BUFFER_1!\pMöchtest du den BUFFER_1 pflücken?"
str_no_room_for_mushroom:
	.autostring 34 2 "Es scheint so, als hättest du dafür keinen Platz!"
str_shell_empty:
	.autostring 34 2 "Die Muschel wurde aufgebrochen und scheint leer zu sein.\pOb wohl bald eine neue Muschel angespült wird?"
str_shell_to_be_opened:
	.autostring 34 2 "Etwas funkelt im Inneren der Muschel!\pMöchtest du die Muschel aufbrechen?"
str_pokemon_was_hiding_in_shell:
	.autostring 34 2 "Ein BUFFER_1 hatte sich in der Muschel versteckt!"
str_trash_to_be_opened:
	.autostring 34 2 "Irgendetwas scheint diese Mülltonne zum Klappern zu bringen.\pMöchtest du sie öffnen?"
str_trash_empty:
	.autostring 34 2 "Die Mülltonne ist leer."
str_trash_wind:
	.autostring 34 2 "Die Mülltonne ist leer.\pEs scheint, als hätte jemand den Deckel nicht richtig verschlossen.\pPLAYER schließt den Deckel der Mülltonne."
str_pokemon_was_hiding_oin_trash:
	.autostring 34 2 "Ein BUFFER_1 hatte sich in der Mülltonne versteckt!"
str_player_found_recipe:
	.autostring 34 2 "Rezept zur Herstellung von BUFFER_1 gefunden!"
str_recipe_can_be_used:
	.autostring 34 2 "Das Rezept kann an einem Laz. Kessel in einem Pokéstop verwendet werden."
str_mushroom_no_pluck:
	.autostring 34 2 "Schade!\nDas BUFFER_1 hat den Pilz bereits gegegessenDOTS"
.elseif LANG_EN
str_mon0:
	.autostring 34 2 "BUFFER_1! BUFFER_1!"
str_mon1:
	.autostring 34 2 "BUFFER_1?"
str_mon2:
	.autostring 34 2 "BUFFER_1DOTS"
str_mon3:
	.autostring 34 2 "BUFFER_1!\nBUFFER_1?"
str_attacks:
	.autostring 34 2 "BUFFER_1 greift an!"
str_mushroom_plucked:
	.autostring 34 2 "It seems like mushrooms were growing here but somebody must have picked themDOTS\pIt probably takes some time until new mushrooms have grown."
str_mushrooms_are_growing:
	.autostring 34 2 "A BUFFER_1 is growing here!\pDo you want to pluck the BUFFER_1?"
str_no_room_for_mushroom:
	.autostring 34 2 "It seems like you don't have room for that!"
str_shell_empty:
	.autostring 34 2 "The shell has been broken open and seems to be empty inside.\pIf the tides will wash another one ashore?"
str_shell_to_be_opened:
	.autostring 34 2 "Something is sparkling inside the shell!\pDo you want to break the shell open?"
str_pokemon_was_hiding_in_shell:
	.autostring 34 2 "A BUFFER_1 was hiding inside the shell!"
.endif