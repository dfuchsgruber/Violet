.include "overworld_script.s"
.include "callstds.s"

.global ow_script_kaskada_sign_0
.global ow_script_kaskada_sign_1
.global ow_script_kaskada_sign_2
.global ow_script_kaskada_sign_3
.global ow_script_kaskada_sign_4
.global ow_script_kaskada_sign_5
.global ow_script_kaskada_sign_6

ow_script_kaskada_sign_0:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end
ow_script_kaskada_sign_1:
    loadpointer 0 str_1
    callstd MSG_SIGN
    end
ow_script_kaskada_sign_2:
    loadpointer 0 str_2
    callstd MSG_SIGN
    end
ow_script_kaskada_sign_3:
    loadpointer 0 str_3
    callstd MSG_SIGN
    end
ow_script_kaskada_sign_4:
    loadpointer 0 str_4
    callstd MSG_SIGN
    end
ow_script_kaskada_sign_5:
    loadpointer 0 str_5
    callstd MSG_SIGN
    end
ow_script_kaskada_sign_6:
    loadpointer 0 str_6
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "DOWN_ARROW Kaktus-Labyrinth"
str_1:
    .autostring 34 2 "DOWN_ARROW Route 5"
str_2:
    .autostring 34 2 "Kaskada\pDie Stadt, deren Schönheit im Wasser verborgen liegt."
str_3:
    .autostring 34 2 "Kaskada-Teehaus\pGenieße eine Tasse des besten Tees der Region."
str_4:
    .autostring 34 2 "Haus des Namenbewerters"
str_5:
    .autostring 34 2 "Milotic-Plaza"
str_6:
    .autostring 34 2 "UP_ARROW Tafelberg-Gipfel"
.elseif LANG_EN
.endif