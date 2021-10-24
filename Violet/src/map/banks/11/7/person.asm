.include "overworld_script.s"
.include "callstds.s"
.include "movements.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_route_2_clouds_cave_eg_person_0
.global ow_script_route_2_clouds_cave_eg_person_1

ow_script_route_2_clouds_cave_eg_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_2_clouds_cave_eg_person_1:
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Findest du nicht, dass es hier irgendwie kalt ist?\pAls würde von irgendwo aus dieser Höhle ein eisiger Windzug kommenDOTS"
str_1:
    .autostring 34 2 ""
.elseif LANG_EN
.endif