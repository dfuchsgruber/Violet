.include "overworld_script.s"

.global script_test

script_test:
givepokemon 0x15 26 0x3a 0 0 0
givepokemon 0x3e 50 0xEe 0 0 0
setflag 0x921
setflag 0x828
settrainerflag 0x1
trainerbattlecont 1 0x1 0 str_ability_descr_0x70 str_ability_descr_0x70 script_cont
script_cont:
end
