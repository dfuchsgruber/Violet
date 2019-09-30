.include "overworld_script.s"
.include "callstds.s"


.global ow_script_route_2_clouds_trainer_2
.global ow_script_route_2_clouds_trainer_3
.global ow_script_route_2_clouds_trainer_4


ow_script_route_2_clouds_trainer_2:
    trainerbattlestd 0 0x113 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_defeat
    callstd MSG_FACE
    end

ow_script_route_2_clouds_trainer_3:
    trainerbattlestd 0 0x114 0 str_trainer3_challange str_trainer3_defeat
    loadpointer 0 str_trainer3_defeat
    callstd MSG_FACE
    end

ow_script_route_2_clouds_trainer_4:
    trainerbattlestd 0 0x115 0 str_trainer4_challange str_trainer4_defeat
    loadpointer 0 str_trainer4_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer2_challange:
    .autostring 34 2 "Wenn heute der Himmel auf die Welt herabfälltDOTS\pDOTSich habe den Faden verloren!"
str_trainer2_defeat:
    .autostring 34 2 "DOTSIch kann mich einfach nicht erinnern, was ich zu sagen hatteDOTS"
str_trainer3_challange:
    .autostring 34 2 "Das Wolkenvolk existiert seit Jahrhunderten.\pIch zeige dir, wie diese Menschen gekämpft haben!"
str_trainer3_defeat:
    .autostring 34 2 "Du bist sicherlich würdig, in solchen Höhen umherzustreifen, Kindchen!"
str_trainer4_challange:
    .autostring 34 2 "Wo könnte man besser Vögel fangen, als über den Wolken?"
str_trainer4_defeat:
    .autostring 34 2 "Hast du größere Vögel gefangen, als ich?"
.elseif LANG_EN
str_trainer2_challange:
    .autostring 34 2 "If today the sky would fall down\pDOTSnow I lost itDOTS"
str_trainer2_defeat:
    .autostring 34 2 "DOTSI just can't remember what I wanted to sayDOTS"
str_trainer3_challange:
    .autostring 34 2 "The people of the clouds have been existing for hundreds of years.\pI show you, how they fought!"
str_trainer3_defeat:
    .autostring 34 2 "You certainly are worthy to wander these heights, kid!"
str_trainer4_challange:
    .autostring 34 2 "Where to catch larger birds than above the clouds?"
str_trainer4_defeat:
    .autostring 34 2 "Did you catch larger birds than me?"
.endif