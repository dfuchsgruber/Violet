.include "overworld_script.s"
.include "callstds.s"

.global ow_script_sonnaufeld_sign_0
.global ow_script_sonnaufeld_sign_1
.global ow_script_sonnaufeld_sign_2
.global ow_script_sonnaufeld_sign_3
.global ow_script_sonnaufeld_lab_door

ow_script_sonnaufeld_sign_0:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end
ow_script_sonnaufeld_sign_1:
    loadpointer 0 str_1
    callstd MSG_SIGN
    end
ow_script_sonnaufeld_sign_2:
    loadpointer 0 str_2
    callstd MSG_SIGN
    end
ow_script_sonnaufeld_sign_3:
    loadpointer 0 str_3
    callstd MSG_SIGN
    end
ow_script_sonnaufeld_lab_door:
    loadpointer 0 str_door
    callstd MSG
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Sonnaufeld\pDie Stadt, die so hell leuchtet wie ihre Sonnenblumen."
str_1:
    .autostring 34 2 "Professor Tanns Labor"
str_2:
    .autostring 34 2 "Dieses Fossil stammt vermutlich von einem bereits ausgestorbenen Fisch-Pokémon."
str_3:
    .autostring 34 2 "Es ist schwer zu erkennen, ob es sich bei diesem Stein überhaupt um ein Fossil handeltDOTS"
str_door:
    .autostring 34 2 "Die Türe zum Labor scheint verschlossen zu sein.\pVermutlich ist der Professor nicht daDOTS"
.elseif LANG_EN
.endif