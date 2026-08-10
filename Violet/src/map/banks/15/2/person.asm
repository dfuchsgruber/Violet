.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_3_clouds_person_0
.global ow_script_route_3_clouds_person_1
.global ow_script_route_4_clouds_swamp_person_2
.global ow_script_route_4_clouds_swamp_person_3

ow_script_route_3_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_3_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_4_clouds_swamp_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_route_4_clouds_swamp_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Weißt du, was ich an diesem Ort liebe?\pEs kann niemals regnen!"
str_1:
    .autostring 34 2 "Viele Trainer wissen nicht einmal, dass es fast schon eine ganz neue Welt gibt hier über den Wolken."
str_2:
    .autostring 34 2 "Ich habe oft Angst, von den Inseln hier herunterzufallen.\pGeht das dir nicht so?"
str_3:
    .autostring 34 2 "Der Geruch der Sümpfe hier ist wirklich abstoßend.\pIch will mich hier nicht länger aufhalten, als unbedingt nötigDOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "You know what I love about this place?\pI can not ever rain!"
str_1:
    .autostring 34 2 "Many trainers are not even aware of this entire new world above the clouds here!"
str_2:
    .autostring 34 2 "I often get scared of falling off the islands here.\pDon't you feel the same way?"
str_3:
    .autostring 34 2 "The smell of the swamps here is really disgusting.\pI don't want to stay here any longer than absolutely necessaryDOTS"
    

.endif