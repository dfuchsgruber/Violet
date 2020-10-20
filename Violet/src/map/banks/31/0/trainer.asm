.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ardeal_trainer_0

ow_script_ardeal_trainer_0:
    trainerbattlestd 0 0x159 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Ich diene meinem Herren Lucius, ganz gleich, mit welchen Leuten er sich einlässt.\pIch werde dir meine Treue zu ihm beweisen!"
str_trainer0_defeat:
    .autostring 34 2 "Du hast kein Recht, über das Verhalten meines Herren zu urteilen!"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "I serve my lord no matter what people he surrounds himself with.\pI will prove my loyality to him!"
str_trainer0_defeat:
    .autostring 34 2 "You are in no position to judge the behaviour of my lord!"
.endif