.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_9_vertical_clouds_clouds_person_0
.global ow_script_route_9_vertical_clouds_clouds_person_1

ow_script_route_9_vertical_clouds_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_9_vertical_clouds_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Es gibt eine Legende, dass die Menschen, die einst hier Städte erbaut haben, dadurch die Götter dieser Welt verärgert hätten, woraufhin diese deren Reich in Schutt und Asche gelegt haben."
str_1:
    .autostring 34 2 "Viele Areale am Boden sind schwer zu erreichen.\pÜber die Wolken hat man eine bequeme Möglichkeit, solche Orte zu Gesicht zu bekommen."

.elseif LANG_EN
str_0:
    .autostring 34 2 "There is a legende that claims that the people who once built cities here on the clouds angered the gods of the world doing so and thus were punished by having their realm be destroyed entirely."
str_1:
    .autostring 34 2 "Many areas on the ground are hard to reach.\pTraveling above the ground provides a convenient way seeing these places."

.endif