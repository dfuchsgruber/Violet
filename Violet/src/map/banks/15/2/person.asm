.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_3_clouds_person_0
.global ow_script_route_3_clouds_person_1

ow_script_route_3_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_3_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Weißt du, was ich an diesem Ort liebe?\pEs kann niemals regnen!"
str_1:
    .autostring 34 2 "Viele Trainer wissen nicht einmal, dass es fast schon eine ganz neue Welt gibt hier über den Wolken."

.elseif LANG_EN
str_0:
    .autostring 34 2 "You know what I love about this place?\pI can not ever rain!"
str_1:
    .autostring 34 2 "Many trainers are not even aware of this entire new world above the clouds here!"

.endif