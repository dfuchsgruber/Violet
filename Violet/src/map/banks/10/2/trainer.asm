.include "overworld_script.s"
.include "callstds.s"

.global ow_script_inferior_clouds_trainer_0

ow_script_route_2_clouds_trainer_0:
    trainerbattlestd 0 0x11c 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Die Asche vermischt sich hier oben mit den Wolken.\pDas macht das Wolkenreiten besonders interessant!"
str_trainer0_defeat:
    .autostring 34 2 "UffDOTS DOTS DOTS\pIch habe mich verschlucktDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "The ash up here mixes with the clouds.\pThat makes riding clouds especially interesting!"
str_trainer0_defeat:
    .autostring 34 2 "UffDOTS DOTS DOTS\pI think I caught a coughDOTS"
.endif