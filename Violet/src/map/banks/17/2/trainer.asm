.include "callstds.s"
.include "overworld_script.s"

.global ow_script_route_5_clouds_trainer_0
.global ow_script_route_5_clouds_trainer_1
.global ow_script_route_5_clouds_trainer_2

ow_script_route_5_clouds_trainer_0:
    trainerbattlestd 0x0 0x89 0x0 str_challange_0 str_defeat_0
    loadpointer 0x0 str_after_0
    callstd MSG_FACE
    end

ow_script_route_5_clouds_trainer_1:
    trainerbattlestd 0x0 0x8a 0x0 str_challange_1 str_defeat_1
    loadpointer 0x0 str_after_1
    callstd MSG_FACE
    end

ow_script_route_5_clouds_trainer_2:
    trainerbattlestd 0x0 0x116 0x0 str_challange_2 str_defeat_2
    loadpointer 0x0 str_after_2
    callstd MSG_FACE
    end

.ifdef LANG_GER

str_challange_0:
    .autostring 34 2 "Du scheinst mir noch nicht so vertraut zu sein, mit dem Wolkenreiten!\pEs wird Zeit, dass du auf einer Wolke kämpfst!"
str_defeat_0:
    .autostring 34 2 "Oh je!\pDu hast ja richtig Talent, Kindchen!"
str_after_0:
    .autostring 34 2 "Nicht übel, Kindchen!\pWenn du so weitermachst, könntest du einer der berühmtesten Wolkenreiter werden."
str_challange_1:
    .autostring 34 2 "Weißt du, wie man zum Boden zurückkehrt?\pIch verrate es dir, wenn du mich besiegen kannst!"
str_defeat_1:
    .autostring 34 2 "Ich werde dir also verraten müssen, wie man zum Boden zurückkehrtDOTS"
str_after_1:
    .autostring 34 2 "Wenn du etwas dunklere Löcher in den Wolken siehst, bedeutet das, dass ein Luftstrom dich sanft zurück zum Boden tragen kann.\pAber nimm dich in Acht!\pAnderswo solltest du nicht von deiner Wolke fallen."
str_challange_2:
    .autostring 34 2 "Sind dir hier oben schon einmal leuchtende Kristalle aufgefallen?\pAls Ass-Trainer weiß ich natürlich, was es damit auf sich hat!"
str_defeat_2:
    .autostring 34 2 "M-Moment!\nIch habe verloren?"
str_after_2:
    .autostring 34 2 "Da habe ich meinen Pokémon mittels der leuchtenden Kristalle sogar neue Attacken beigebrachtDOTS\pUnd trotzdem habe ich verloren!"
.elseif LANG_EN
str_challange_0:
    .autostring 34 2 "You don't seem to be used to cloud riding!\pTime for your first battle on a cloud!"
str_defeat_0:
    .autostring 34 2 "Oh my!\pYou really seem to be talented, child!"
str_challange_1:
    .autostring 34 2 "Do you know how to return to the ground?\pI will tell you if you can defeat me!"
str_defeat_1:
    .autostring 34 2 "Whenever you see dark patches in the clouds, you can return to the ground there."
str_challange_2:
    .autostring 34 2 "Are you suprised to see an athlete above the clouds?\pThe air here trains my lungs!"
str_defeat_2:
    .autostring 34 2 "You really should try swimming in cloudy water also!"

.endif