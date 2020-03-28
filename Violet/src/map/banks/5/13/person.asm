.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_meriana_city_gym_referee

ow_script_meriana_city_gym_referee:
    checkflag FRBADGE_3
    gotoif EQUAL gym_beaten
    loadpointer 0 str_meriana_city_gym_referee
    callstd MSG_FACE
    end
gym_beaten:
    loadpointer 0 str_beaten
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_beaten:
    .autostring 34 2 "Starke Leistung, Manus zu besiegen!\pAllein ihm gegenüberzutreten fällt manchen nicht leicht."
.elseif LANG_EN
.endif