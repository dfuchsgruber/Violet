.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_9_vertical_clouds_clouds_trainer_0
.global ow_script_route_9_vertical_clouds_clouds_trainer_1

ow_script_route_9_vertical_clouds_clouds_trainer_0:
    trainerbattlestd 0 0x129 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

ow_script_route_9_vertical_clouds_clouds_trainer_1:
    trainerbattlestd 0 0x12a 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Allein durch meine telekinetischen Kräfte bin ich bis hier hinauf geschwebt.\pDu glaubst mir nicht?\pLass es mich dir zeigen!"
str_trainer0_defeat:
    .autostring 34 2 "Oh nein, meine Konzentration!\pIch werde zurück zum Boden fallenDOTS"
str_trainer1_challange:
    .autostring 34 2 "Es ist wirklich ärgerlich, wie viele Menschen, die keine wahren Wolkenreiter sind, hier oben sich herumtreiben.\pBist du einer von ihnen?"
str_trainer1_defeat:
    .autostring 34 2 "Ah nein, es scheint, du bist würdig, auf einer Wolke zu reiten."
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "With my telecinetic powers alone I levitated up here.\pYou don't believe me?\pLet me show you!"
str_trainer0_defeat:
    .autostring 34 2 "Oh no, my focus!\pNow I will fall back to the ground."
str_trainer1_challange:
    .autostring 34 2 "It really is a shame how many people who are not real cloud riders lurk arround up here.\pAre you one of those?"
str_trainer1_defeat:
    .autostring 34 2 "Oh no, it seems you are worthy to ride a cloud."
.endif