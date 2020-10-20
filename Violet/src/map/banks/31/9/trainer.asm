.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ardeal_trainer_1

ow_script_ardeal_trainer_1:
    trainerbattlestd 0 0x15a 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Hey, was stöberst du hier umher?\pWer hat dir erlaubt, diesen Turm zu betreten?"
str_trainer0_defeat:
    .autostring 34 2 "Meinetwegen, dann sieh dich eben umDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "Hey, what are you wandering about?\pHow gave you permission to enter this tower?"
str_trainer0_defeat:
    .autostring 34 2 "Fine then, I guess, help yourself and look arroundDOTS"
.endif