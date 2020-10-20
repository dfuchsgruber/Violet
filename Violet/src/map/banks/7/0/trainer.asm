.include "overworld_script.s"
.include "callstds.s"

.global ow_script_silvania_clouds_trainer_0

ow_script_silvania_clouds_trainer_0:
    trainerbattlestd 0 0x123 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end



.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Die Waldluft von Kranzdorf reicht bis hier hinauf.\pDas heißtDOTS DOTS DOTS\pIch bin unschlagbar!"
str_trainer0_defeat:
    .autostring 34 2 "Ach, ich habe ganz vergessen, dass wir die gleiche Luft atmenDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "The forest air of Kranzdorf is also up here.\pThat meansDOTS DOTS DOTS\pI am invincible!"
str_trainer0_defeat:
    .autostring 34 2 "Oh, seems like I forgot that we breathe the same airDOTS"
.endif