.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_12_clouds_trainer_0
.global ow_script_route_12_clouds_trainer_1

ow_script_route_12_clouds_trainer_0:
    trainerbattlestd 0 0x133 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

ow_script_route_12_clouds_trainer_1:
    trainerbattlestd 0 0x134 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Eines Tages werde ich das Geheimnis hinter der Geschichte dieses Reiches lüften.\pBis dahin werde ich mich im Kampf üben!"
str_trainer0_defeat:
    .autostring 34 2 "Du hast offensichtlich andere Ambitionen als ich."
str_trainer1_challange:
    .autostring 34 2 "Hast du manchmal Angst, dass deine Wolke dich nicht mehr tragen könnte?\pEin Feigling wie du sollte nicht hier oben sein!"
str_trainer1_defeat:
    .autostring 34 2 "W-Wie?\nIch hab doch keine Angst, dass meine Wolke mich nicht mehr trägtDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "One day I will unravel all the secrets of the story of this ancient kingdom.\pUntil then I will just do battles!"
str_trainer0_defeat:
    .autostring 34 2 "You obviously have different ambitions than me."
str_trainer1_challange:
    .autostring 34 2 "Are you sometimes scared that your cloud might not be able to carry you?\pA coward like you shouldn't be up here!"
str_trainer1_defeat:
    .autostring 34 2 "W-What?\nI am not scared that my cloud wouldn't carry meDOTS"
.endif