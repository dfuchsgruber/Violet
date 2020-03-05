.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_12_clouds_trainer_1
.global ow_script_route_12_clouds_trainer_2

ow_script_route_12_clouds_trainer_1:
    trainerbattlestd 0 0x131 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

ow_script_route_12_clouds_trainer_2:
    trainerbattlestd 0 0x132 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Über Haweiland sind sehr wenige Wolken.\pDie Sonne brennt mir auf den Nacken!\pLass uns im Kampf etwas Schatten finden!"
str_trainer0_defeat:
    .autostring 34 2 "Uff, habe ich etwa einen Sonnenstich?"
str_trainer1_challange:
    .autostring 34 2 "Weißt du wie dir Himmel klingt?\pLass mich dir einen Vorgeschmack geben!"
str_trainer1_defeat:
    .autostring 34 2 "Oh, ich habe dir versehentlich ein Requiem zum Besten gegebenDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "Above Haweiland there are only few clouds.\pThe sun is burning down on my neck.\pLet us find some shadow in a battle!"
str_trainer0_defeat:
    .autostring 34 2 "Urgh, did I get a sunstroke?"
str_trainer1_challange:
    .autostring 34 2 "Do you know how the sky sounds?\pLet me give you a taste of it!"
str_trainer1_defeat:
    .autostring 34 2 "Oh, I accidentially played a requiem for youDOTS"
.endif