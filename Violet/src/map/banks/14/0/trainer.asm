.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_10_trainer_8

ow_script_route_10_trainer_8:
    trainerbattlestd 0 0xe0 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Über den Wolken, sagt man, ist die Freiheit wohl grenzenlos!\pDa kann ich nur zustimmen!"
str_trainer0_defeat:
    .autostring 34 2 "Grenzenlose Freiheit bedeutet auch, dass man verlieren kann."
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "Over the clouds, they say, the freedom must be endless.\pI could not agree more."
str_trainer0_defeat:
    .autostring 34 2 "Infinite freedom also means you can lose."
.endif