.include "overworld_script.s"
.include "callstds.s"

.global ow_script_feslige_oednis_clouds_trainer_0

ow_script_feslige_oednis_clouds_trainer_0:
    trainerbattlestd 0 0x121 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_after
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Ich bin total aufgedreht!\pLos, lass uns kämpfen!"
str_trainer0_defeat:
    .autostring 34 2 "Uff!\pDu bist ganz schön taff!"
str_trainer0_after:
    .autostring 34 2 "Jetzt bin ich wieder etwas heruntergekommen, denke ichDOTS\pWobeiDOTS\pNein, ich bin immer noch aufgedreht!"
str_trainer1_challange:
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "I am reallly pumped up!\pGo, let's fight!"
str_trainer0_defeat:
    .autostring 34 2 "Uff\pYou really are tough!"
.endif