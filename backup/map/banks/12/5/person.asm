.include "overworld_script.s"
.include "callstds.s"

.global ow_script_laubdorf_clouds_person_0

ow_script_laubdorf_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Selbst über den Wolken hat Laubdorf eine äußert beruhigende Wirkung, findest du nicht?"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Even above the clouds, Leaf Village has a very soothing effect, don't you agree?"
.endif