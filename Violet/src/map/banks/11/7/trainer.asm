.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_2_clouds_cave_eg_trainer_0
.global ow_script_route_2_clouds_cave_eg_trainer_1

ow_script_route_2_clouds_cave_eg_trainer_0:
    trainerbattlestd 0 0x1fa 0 str_before_0 str_after_0
    loadpointer 0 str_later_0
    callstd MSG_FACE
    end

ow_script_route_2_clouds_cave_eg_trainer_1:
    trainerbattlestd 0 0x1fb 0 str_before_1 str_after_1
    loadpointer 0 str_later_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Diese Höhle ist aus einer wissenschaftlichen Perspektive höchst bemerkenswert.\pIch verrate dir aber nicht, wieso!"
str_after_0:
    .autostring 34 2 "Wie?\nDu hast mich trotz meines Fachwissens besiegt?"
str_later_0:
    .autostring 34 2 "Na gut!\nIch sage dir zwar nicht, was diese Höhle so interessant macht, aber dir muss doch auch aufgefallen sein, wie ungewöhnlich kalt es hier istDOTS"
str_before_1:
    .autostring 34 2 "B-Bist du ein Polizist?\pI-Ich habe nichts gestohlen und ich verstecke mich auch nicht hier in dieser Höhle!"
str_after_1:
    .autostring 34 2 "I-Ich gestehe!"
str_later_1:
    .autostring 34 2 "Moment einmal!\pDu bist ja gar kein Polizist.\pUnd warum hast dann gegen mich gekämpft?"
.elseif LANG_EN
.endif
