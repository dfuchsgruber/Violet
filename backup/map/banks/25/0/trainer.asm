.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_11_trainer_0

ow_script_route_11_trainer_0:
    trainerbattlestd 0 0x12e 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Du frägst dich, ob hier oben überhaupt Pokémon anbeißen, nicht?\pDu wärst überrascht!"
str_trainer0_defeat:
    .autostring 34 2 "Vielleicht sind die Pokémon aus dem Ozean doch besser?"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "You may ask yourself if up here pokémon will even bite.\pYou would be amazed!"
str_trainer0_defeat:
    .autostring 34 2 "Maybe the pokémon from the ocean are better?"
.endif