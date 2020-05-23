.include "callstds.s"
.include "overworld_script.s"
.include "movements.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_person_pokeball
.global ow_script_person_egg
.global ow_script_person_pokemon
.global ow_script_aggressive_wild
.global ow_script_aggressive_wild_do_battle

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