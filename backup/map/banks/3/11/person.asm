.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_10_person_0

ow_script_route_10_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Wusstest du, dass man in Muscheln manchmal Perlen findet?\pSie glitzern so schön!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Did you know that you can find Pearls in shells?\pThey sparkle so nicely!"
.endif