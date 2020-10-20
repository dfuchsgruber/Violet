.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_2_east_trainer_0


ow_script_route_2_east_trainer_0:
    trainerbattlestd 0x0 0x162 0x0 str_challange_0 str_defeat_0
    loadpointer 0x0 str_defeat_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_challange_0:
    .autostring 34 2 "Ich habe einige nette Käfer-Pokémon gefangen!\pGegen die kannst du gar nichts ausrichten!"
str_defeat_0:
    .autostring 34 2 "Meine armen Pokémon wurden von dir regelrecht zerquetschtDOTS"
.elseif LANG_EN
str_challange_0:
    .autostring 34 2 "I caught some nice Bug-Type Pokémon!\pYou won't be able to do anything against them!"
str_defeat_0:
    .autostring 34 2 "My poor Pokémon have been crushedDOTS"


.endif