.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_12_person_0

ow_script_route_12_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Theto ist voller Gegensätze.\pWährend hier eine düstere Stimmung einhält, liegt im Westen ein Urlaubsparadies."

.elseif LANG_EN
str_0:
    .autostring 34 2 "Theto is full of contrasts.\pWhile a sinister mood lies on the ground here, a holiday resort can be found in the west."


.endif