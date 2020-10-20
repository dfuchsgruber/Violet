.include "overworld_script.s"
.include "callstds.s"

.global ow_script_feslige_oednis_clouds_trainer_0
.global ow_script_feslige_oednis_clouds_trainer_1

ow_script_feslige_oednis_clouds_trainer_0:
    trainerbattlestd 0 0x121 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

ow_script_feslige_oednis_clouds_trainer_1:
    trainerbattlestd 0 0x122 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Ich bin total aufgedreht!\pLos, lass uns kämpfen!"
str_trainer0_defeat:
    .autostring 34 2 "Uff!\pDu bist ganz schön taff!"
str_trainer1_challange:
    .autostring 34 2 "Manchmal wirbelt der Wind Sand in meine Augen.\pÜber eine Wüste auf den Wolken zu reiten ist wirklich nicht angenehm!"
str_trainer1_defeat:
    .autostring 34 2 "Hust\nHust\pDas ist wirklich unterträglichDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "I am reallly pumped up!\pGo, let's fight!"
str_trainer0_defeat:
    .autostring 34 2 "Uff\pYou really are tough!"
str_trainer1_challange:
    .autostring 34 2 "Sometimes the wind blasts sand into my eyes.\pCloud riding above a desert really isn't a lot of fun!"
str_trainer1_defeat:
    .autostring 34 2 "Cough\nCough\pIt really is a pestDOTS"
.endif