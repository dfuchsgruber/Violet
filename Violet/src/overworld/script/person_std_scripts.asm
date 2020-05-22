.include "callstds.s"
.include "overworld_script.s"
.include "movements.s"
.include "vars.s"

.global ow_script_person_pokeball
.global ow_script_person_egg
.global ow_script_person_pokemon

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
	cry 0x8000 0
	showpokepic 0x8000 11 2
	loadpointer 0 str_mon
	callstd MSG_KEEPOPEN
	waitcry
	hidepokepic
	
	release
	end


.ifdef LANG_GER
str_mon:
	.autostring 34 2 "BUFFER_1! BUFFER_1!"
.elseif LANG_EN
str_mon:
	.autostring 34 2 "BUFFER_1! BUFFER_1!"

.endif