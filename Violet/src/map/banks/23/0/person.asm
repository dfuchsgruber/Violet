.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_8_clouds_person_0

ow_script_route_8_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Du meinst wohl auch, dass ein kleines Mädchen alleine nicht hier oben sein sollte.\pAber mir ist egal, was andere denken."
.elseif LANG_EN
str_0:
    .autostring 34 2 "You probably think that a little girl shouldn't be up here alone.\pBut I don't care what others think."
.endif