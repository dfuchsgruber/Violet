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
	callasm aggressive_wild_setup_by_person
	special2 LASTRESULT SPECIAL_AGGRESSIVE_WILD_GET_APPROACHING_SPECIES
    bufferpokemon 0 LASTRESULT
    cry LASTRESULT 0
    loadpointer 0 str_aggressive_wild_challange
    callstd MSG_KEEPOPEN
    waitcry
	goto ow_script_aggressive_wild_pokemon_start_battle


ow_script_berry_tree:
	special2 LASTRESULT SPECIAL_BERRY_TREE_GET_STAGE
	compare LASTRESULT BERRY_STAGE_NO_BERRY
	gotoif EQUAL plant_berries
	special2 0x8004 SPECIAL_BERRY_TREE_GET_ITEM
	special2 0x8005 SPECIAL_BERRY_TREE_GET_YIELD
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

plant_berries:
	loadpointer 0 str_want_to_plant
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_harvest
	special SPECIAL_BERRY_TREE_PLANT
	waitstate
	end

dirt_pile:
	loadpointer 0 str_dirt_pile
	callstd MSG_KEEPOPEN
	checkitem ITEM_WUNDERSTAUB 1
	compare LASTRESULT 0x1
	gotoif 1 ask_fertilize
	goto dont_harvest
sprout:
	loadpointer 0 str_sprout
	callstd MSG_KEEPOPEN
	checkitem ITEM_WUNDERSTAUB 1
	compare LASTRESULT 0x1
	gotoif 1 ask_fertilize
	goto dont_harvest
taller:
	loadpointer 0 str_taller
	callstd MSG_KEEPOPEN
	checkitem ITEM_WUNDERSTAUB 1
	compare LASTRESULT 0x1
	gotoif 1 ask_fertilize
	goto dont_harvest
blossom:
	loadpointer 0 str_blossom
	callstd MSG_KEEPOPEN
	checkitem ITEM_WUNDERSTAUB 1
	compare LASTRESULT 0x1
	gotoif 1 ask_fertilize
	goto dont_harvest
ask_fertilize:
	loadpointer 0 str_ask_fertilize
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_harvest
	removeitem ITEM_WUNDERSTAUB 1
	loadpointer 0 str_fertilize
	callstd MSG_KEEPOPEN
	special SPECIAL_BERRY_TREE_GROW
	special SPECIAL_BERRY_TREE_UPDATE_GFX
	sound 188
	doanimation 23
	checkanimation 23
	checksound
	loadpointer 0 str_grown
	callstd MSG
	end

harvest_berries:
	compare 0x8005 1
	gotoif EQUAL load_str_want_to_harvest_single
	loadpointer 0 str_want_to_harvest
	goto loaded_str_want_to_harvest_single
load_str_want_to_harvest_single:
	loadpointer 0 str_want_to_harvest_single
loaded_str_want_to_harvest_single:
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_harvest
	fanfare 262
	special2 LASTRESULT SPECIAL_BERRY_TREE_PICK
	compare LASTRESULT 0
	gotoif EQUAL no_room_for_berries
	compare 0x8005 1
	gotoif EQUAL load_str_harvest_single
	loadpointer 0 str_harvest
	goto loaded_str_harvest
load_str_harvest_single:
	loadpointer 0 str_harvest_single
loaded_str_harvest:
	callstd MSG_KEEPOPEN
	waitfanfare
	compare 0x8005 1
	gotoif EQUAL load_str_harvested_single
	loadpointer 0 str_harvested
	goto loaded_str_harvested_single
load_str_harvested_single:
	loadpointer 0 str_harvested_single
loaded_str_harvested_single:
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
	.string "Dort wachsen BUFFER_2 BUFFER_1n!\pMöchtest du die BUFFER_1n\npflücken?"
str_want_to_harvest_single:
	.string "Dort wächst eine BUFFER_1!\pMöchtest du die BUFFER_1n\npflücken?"
str_harvest:
	.autostring 34 2 "PLAYER pflückt die BUFFER_1n."
str_harvest_single:
	.autostring 34 2 "PLAYER pflückt die BUFFER_1n."
str_harvested:
	.autostring 34 2 "PLAYER packt die BUFFER_1n in die Beerentüte."
str_harvested_single:
	.autostring 34 2 "PLAYER packt die BUFFER_1 in die Beerentüte."
str_ground_muddy:
	.autostring 34 2 "Der Boden ist wieder weich und lehmig."
str_no_room_for_berries:
	.autostring 34 2 "Es scheint so, als hättest du keinen Platz für weitere Beeren!"
str_want_to_plant:
	.autostring 34 2 "Der Boden ist weich und lehmig.\pMöchtest du eine Beere pflanzen?"
str_dirt_pile:
	.autostring 34 2 "Hier wurde eine BUFFER_1 angepflanzt."
str_sprout:
	.autostring 34 2 "Es scheint, als wäre die BUFFER_1 ausgetrieben!"
str_taller:
	.autostring 34 2 "Die BUFFER_1n scheinen gut zu gedeihen!"
str_blossom:
	.autostring 34 2 "Die BUFFER_1n stehen in voller Blüte!"
str_ask_fertilize:
	.autostring 34 2 "Möchtest du Wunderstaub benutzen, um die BUFFER_1n wachsen zu lassen?"
str_fertilize:
	.autostring 34 2 "PLAYER benutzt Wunderstaub."
str_grown:
	.autostring 34 2 "Die BUFFER_1n sind gewachsen!"
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