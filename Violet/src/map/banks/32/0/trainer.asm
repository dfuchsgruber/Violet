.include "overworld_script.s"
.include "callstds.s"

.global ow_script_dark_tower_trainer_0

ow_script_dark_tower_trainer_0:
    trainerbattlestd 0 0x181 0 str_before_0 str_after_0
    loadpointer 0 str_after_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Deine Anwesenheit entweiht diesen heiligen Ort!\pVerschwinde von hier!"
str_after_0:
    .autostring 34 2 "Du hast hier nichts verlorenDOTS"

.elseif LANG_EN
.endif