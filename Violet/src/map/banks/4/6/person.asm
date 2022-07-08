.include "overworld_script.s"
.include "callstds.s"

.global ow_script_anemonia_cloud_cave_person_0

ow_script_anemonia_cloud_cave_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Diese Höhle ist regelrecht überwuchert mit Gewächsen.\pOb das an der hohen Feuchtigkeit liegt, die vom Nebel draußen nach innen dringt?"
.elseif LANG_EN
.endif