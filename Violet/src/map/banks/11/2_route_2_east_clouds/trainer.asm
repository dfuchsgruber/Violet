.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_2_clouds_trainer_0
.global ow_script_route_2_clouds_trainer_1

ow_script_route_2_clouds_trainer_0:
    trainerbattlestd 0 0x111 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

ow_script_route_2_clouds_trainer_1:
    trainerbattlestd 0 0x112 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Mein Haar mischt sich mit dem WolkenDOTS\pIst es nicht zauberhaft?"
str_trainer0_defeat:
    .autostring 34 2 "Oh nein!\nIst das etwa Spliss?"
str_trainer1_challange:
    .autostring 34 2 "Orte wie diese sind nichts für Menschen mit Höhenangst!"
str_trainer1_defeat:
    .autostring 34 2 "Schlottern mir etwa die Knie?"
str_trainer2_challange:
    .autostring 34 2 "Wenn heute der Himmel auf die Welt herabfälltDOTS\pDOTSich habe den Faden verloren!"
str_trainer2_defeat:
    .autostring 34 2 "DOTSIch kann mich einfach nicht erinnern, was ich zu sagen hatteDOTS"
str_trainer3_challange:
    .autostring 34 2 "Wenn heute der Himmel auf die Welt herabfälltDOTS\pDOTSich habe den Faden verloren!"
str_trainer3_defeat:
    .autostring 34 2 "DOTSIch kann mich einfach nicht erinnern, was ich zu sagen hatteDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "My hair mixes with the cloudsDOTS\pIsn't it fabulous?"
str_trainer0_defeat:
    .autostring 34 2 "Oh no!\pDid my hair spliced?"
str_trainer1_challange:
    .autostring 34 2 "Places like these are not for people that are afraid of heights."
str_trainer1_defeat:
    .autostring 34 2 "Did my knees get weak?"
str_trainer2_challange:
    .autostring 34 2 "If today the sky would fall down\pDOTSnow I lost itDOTS"
str_trainer2_defeat:
    .autostring 34 2 "DOTSI just can't remember what I wanted to sayDOTS"
.endif