.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_4_north_cave_person_0
.global ow_script_route_4_north_cave_person_1

ow_script_route_4_north_cave_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_4_north_cave_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Man kann dem klaren Wasser, das aus dem Tafelberg entspringt bis nach Blütenbach folgen.\pDa wundert es keinen recht, dass in Blütenbach so schöne Bäume wachsen, oder?"
str_1:
    .autostring 34 2 "Der Tafelberg ist wirklich ein einzigartiger Ort.\pSo viele verschiedenfarbige GesteinsschichtenDOTS\pDas ist doch wirklich ein Fest für die Augen, oder?"
.elseif LANG_EN
.endif