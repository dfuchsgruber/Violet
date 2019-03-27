.include "overworld_script.s"
.include "callstds.s"

.global ow_script_map_12_0_laubdorf_pokemon_center_person_0
.global ow_script_map_12_0_laubdorf_pokemon_center_person_1
.global ow_script_map_12_0_laubdorf_pokemon_center_person_2

ow_script_map_12_0_laubdorf_pokemon_center_person_0:
	loadpointer 0 str_0
	callstd MSG_FACE
	end
ow_script_map_12_0_laubdorf_pokemon_center_person_1:
	loadpointer 0 str_1
	callstd MSG_FACE
	end
ow_script_map_12_0_laubdorf_pokemon_center_person_2:
	loadpointer 0 str_2
	callstd MSG_FACE
	end

.ifdef LANG_GER
str_0:
	.autostring 34 2 "Wusstest du, dass ein Pokémon stets die besten Gene seiner Eltern erbt?\pSo wird jede Generation an Pokémon immer stärker.\pAllerdings können auch ganz zufällig noch effektivere Mutationen auftreten!"
str_1:
	.autostring 34 2 "Als ich meine beiden Pokémon in die Pension gegeben habe, fand man am nächsten Tag ein EiDOTS"
str_2:
	.autostring 34 2 "Manchmal kommt ein Sen-Long hierher!\pIch liebe es, mit ihm zu spielen.\pEs ist so ein lustiges Pokémon!"

.elseif LANG_EN
str_0:
	.autostring 34 2 "Did you know that a Pokémon always inherits the best genes from its parents?\pThus, each generation of Pokémon improves upon the previous one.\pAlthough there also is some randomness involved, as there can be even more effective mutations at any time."
str_1:
	.autostring 34 2 "When I put my two Pokémon into the daycare, the next day they found an eggDOTS"
str_2:
	.autostring 34 2 "Sometimes, a Drampa comes here!\pI love playing with it.\pIt's such a funny Pokémon!"


.endif
