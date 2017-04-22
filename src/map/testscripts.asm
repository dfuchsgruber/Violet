.include "overworld_script.s"

.global script_test

script_test:
givepokemon 0x195 50 0xEe 0 0 0
setflag 0x921
setflag 0x828
settrainerflag 0x1
trainerbattlecont 1 0x1 0 str_ability_description_r_kaiseraura str_ability_description_r_kaiseraura script_cont
script_cont:
end
