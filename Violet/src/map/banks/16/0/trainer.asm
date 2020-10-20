.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_4_clouds_trainer_0
.global ow_script_route_4_clouds_trainer_1

ow_script_route_4_clouds_trainer_0:
    trainerbattlestd 0 0x11d 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

ow_script_route_4_clouds_trainer_1:
    trainerbattlestd 0 0x11e 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Weißt du, wie ich zu meiner Wolke gekommen bin?\pIch werde es dir verraten, wenn du mich besiegst!"
str_trainer0_defeat:
    .autostring 34 2 "Buh.\pDie Geschichte hinter meiner Wolke ist sehr langweilig, ich werde dir das ersparenDOTS"
str_trainer1_challange:
    .autostring 34 2 "GähnDOTS\pDie Langeweile hier oben ist wirklich unendlich großDOTS\pLass uns kämpfen!"
str_trainer1_defeat:
    .autostring 34 2 "Lieber langweile ich mich, als gegen dich zu verlierenDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "Do you want to know how I got to get my cloud?\pI will tell you if you can defeat me!"
str_trainer0_defeat:
    .autostring 34 2 "Meh.\pThe story behind my cloud is so boring, I will spare you the detailsDOTS"
str_trainer1_challange:
    .autostring 34 2 "YawnDOTS\pIt is so boring up hereDOTS\pLet's battle!"
str_trainer1_defeat:
    .autostring 34 2 "I'd rather be bored than lose to youDOTS"
.endif