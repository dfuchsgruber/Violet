.include "callstds.s"
.include "overworld_script.s"
.include "movements.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"
.include "specials.s"
.include "berry_stages.s"
.include "songs.s"

.global ow_script_person_pokeball
.global ow_script_person_egg
.global ow_script_person_pokemon
.global ow_script_aggressive_wild
.global ow_script_aggressive_wild_do_battle
.global ow_script_berry_tree

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

ow_script_aggressive_wild:
	lock
	faceplayer
ow_script_aggressive_wild_do_battle:
	bufferpokemon 0 0x8000
	cry 0x8000 0
	loadpointer 0 str_attacks
	callstd MSG_KEEPOPEN
	waitcry
	callasm aggressive_wild_pokemon_new
	setflag FLAG_IN_BATTLE
	callasm battle_initialize_aggressive_wild
	clearflag FLAG_IN_BATTLE
	waitstate
	fadescreen 1
	hidesprite LASTTALKED
	fadescreen 0
	release
	end

ow_script_berry_tree:
	special2 LASTRESULT SPECIAL_BERRY_TREE_GET_STAGE
	compare LASTRESULT BERRY_STAGE_NO_BERRY
	gotoif EQUAL plant_berries
	compare LASTRESULT BERRY_STAGE_BERRIES
	gotoif EQUAL harvest_berries
	end

plant_berries:
	loadpointer 0 str_want_to_plant
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_harvest
	special SPECIAL_BERRY_TREE_PLANT
	waitstate
	end

harvest_berries:
	loadpointer 0 str_want_to_harvest
	special2 0x8004 SPECIAL_BERRY_TREE_GET_ITEM
	special2 0x8005 SPECIAL_BERRY_TREE_GET_YIELD
	bufferitem 0 0x8004
	buffernumber 1 0x8005
	loadpointer 0 str_want_to_harvest
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_harvest
	fanfare SOUND_BERRY_PICKED
	special2 LASTRESULT SPECIAL_BERRY_TREE_PICK
	compare LASTRESULT 0
	gotoif EQUAL no_room_for_berries
	loadpointer 0 str_harvest
	callstd MSG_KEEPOPEN
	waitfanfare
	loadpointer 0 str_harvested
	callstd MSG_KEEPOPEN
	special SPECIAL_BERRY_TREE_UPDATE_GFX
	loadpointer 0 str_ground_muddy
	callstd MSG
	end
dont_harvest:
	closeonkeypress
	end
no_room_for_berries:
	loadpointer 0 str_no_room_for_berries
	callstd MSG
	end



.ifdef LANG_GER
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
	.autostring 34 2 "Dort wachsen BUFFER_2 BUFFER_1n!\pMöchtest du die BUFFER_1n pflücken?"
str_harvest:
	.autostring 34 2 "PLAYER pflückt die BUFFER_1n."
str_harvested:
	.autostring 34 2 "PLAYER packt die BUFFER_1n in die Beerentüte."
str_ground_muddy:
	.autostring 34 2 "Der Boden ist wieder weich und lehmig."
str_no_room_for_berries:
	.autostring 34 2 "Es scheint so, als hättest du keinen Platz für weitere Beeren!"
str_want_to_plant:
	.autostring 34 2 "Der Boden ist weich und lehmig.\pMöchtest du eine Beere pflanzen?"
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
.endif