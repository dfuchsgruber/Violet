.include "overworld_script.s"
.include "callstds.s"

.global ow_script_silvania_wald_clouds_trainer_0
.global ow_script_silvania_wald_clouds_trainer_1

ow_script_silvania_wald_clouds_trainer_0:
    trainerbattlestd 0 0x125 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end
ow_script_silvania_wald_clouds_trainer_1:
    trainerbattlestd 0 0x126 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Du frägst dich bestimmt, was ein Käfersammler so weit oben treibt.\pNun, das geht dich rein gar nichts an!"
str_trainer0_defeat:
    .autostring 34 2 "Ich sollte wieder zurück auf den Boden und nach Käfer-Pokémon suchenDOTS"
str_trainer1_challange:
    .autostring 34 2 "Eine Blume verbreitet sich durch den Wind!\pMit einer Böhe werde ich dich also besiegen!"
str_trainer1_defeat:
    .autostring 34 2 "Vielleicht ist mein Talent doch nicht mehr als eine laue BriseDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "You probably wonder what a bug catcher does all the way up here.\pWell, that's none of your buisness!"
str_trainer0_defeat:
    .autostring 34 2 "I should head back to the ground to look for some bug pokémonDOTS"
str_trainer1_challange:
    .autostring 34 2 "A flower spreads with the wind!\pAnd with the wind I will defeat you!"
str_trainer1_defeat:
    .autostring 34 2 "Maybe all my talent is just a gentle breezeDOTS"
.endif