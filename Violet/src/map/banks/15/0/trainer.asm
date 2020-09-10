.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_3_trainer_0

ow_script_route_3_trainer_0:
    trainerbattlestd 0 0x167 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Kranzdorf ist kein Ort für hartgesottene Gemüter wie mich!\pIch sehne mich nach roher Schlagkraft!"
str_trainer0_defeat:
    .autostring 34 2 "Soll das bedeuten, dass ich nicht Manns genug bin?"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "Kranzdorf is no place for hardboiled spirits like mine!\pI crave raw force!"
str_trainer0_defeat:
    .autostring 34 2 "Should that mean that I am not manly enough?"

.endif