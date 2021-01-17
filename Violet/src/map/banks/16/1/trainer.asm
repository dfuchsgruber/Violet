.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_4_north_cave_trainer_0

ow_script_route_4_north_cave_trainer_0:
    trainerbattlestd 0 0x1c1 0 str_before_0 str_after_0
    loadpointer 0 str_after_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Auch wenn meine Muskeln schon schmerzenDOTS\pNein, vorallem dann!\pDann trainiere ich mit aller Härte!"
str_after_0:
    .autostring 34 2 "Aua, auaDOTS\pIch habe einen MuskelkaterDOTS"
.elseif LANG_EN
.endif