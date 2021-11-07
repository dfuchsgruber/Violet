.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_2_clouds_trainer_0
.global ow_script_route_2_clouds_trainer_1
.global ow_script_route_2_clouds_trainer_2

ow_script_route_2_clouds_trainer_0:
    trainerbattlestd 0 0x111 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_after
    callstd MSG_FACE
    end

ow_script_route_2_clouds_trainer_1:
    trainerbattlestd 0 0x112 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_after
    callstd MSG_FACE
    end

ow_script_route_2_clouds_trainer_2:
    trainerbattlestd 0 0x1fc 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_after
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Mein Haar mischt sich mit dem WolkenDOTS\pIst es nicht zauberhaft?"
str_trainer0_defeat:
    .autostring 34 2 "Oh nein!\nIst das etwa Spliss?"
str_trainer0_after:
    .autostring 34 2 "Sieh dir an, was du mit meinem Haar gemacht hast!\pDa ist überall Spliss!"
str_trainer1_challange:
    .autostring 34 2 "Orte wie diese sind nichts für Menschen mit Höhenangst!"
str_trainer1_defeat:
    .autostring 34 2 "Schlottern mir etwa die Knie?"
str_trainer1_after:
    .autostring 34 2 "Eines ist 'mal sicher!\pDu hast sicherlich keine Höhenangst, oder?"
str_trainer2_challange:
    .autostring 34 2 "Hier oben hat man wirklich die Ruhe weg.\pWas fällt dir also ein, mir hier auf die Nerven zu gehen?"
str_trainer2_defeat:
    .autostring 34 2 "N-Nichts für ungut, ja?"
str_trainer2_after:
    .autostring 34 2 "Nur weil du stark bist, musst du noch lange nicht andere Leute ärgernDOTS"
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