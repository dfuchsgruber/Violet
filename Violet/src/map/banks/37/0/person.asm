.include "overworld_script.s"
.include "callstds.s"

.global ow_script_desert_village_pokestop_person_0
.global ow_script_desert_village_pokestop_person_1
.global ow_script_desert_village_pokestop_person_2
.global ow_script_desert_village_pokestop_person_3

ow_script_desert_village_pokestop_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_desert_village_pokestop_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_desert_village_pokestop_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_desert_village_pokestop_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Mein armes Pokémon ist ganz ausgetrocknet, nachdem wir stundenlang im Kaktus-Labyrinth umhergeirrt sindDOTS\pJetzt müssen wir uns erst einmal ausruhen."
str_1:
    .autostring 34 2 "Manchmal übernimmt eine jüngere Schwester hier den Dienst.\pScheinbar befindet sie sich noch in ihrer Ausbildung, aber sie ist sehr freundlich."
str_2:
    .autostring 34 2 "Es gibt eine Legende über diese Wüste, dass hier ein bösartiges Drachenpokémon gelebt haben soll.\pNiemand geringeres als der ehemalige Champion selbst soll dieses Monster zur Strecke gebracht haben!"
str_3:
    .autostring 34 2 "Was soll ich denn nun machen?\pZurück nach Kranzwald möchte ich nicht, weil ich bereits hierher stundenlang in einer Höhle umhergeirrt bin.\pAber nach Kaskada kann ich auch nicht weiter, weil sich mir buchstäblich ein Labyrinth aus Kakteen in den Weg stelltDOTS"
.elseif LANG_EN
.endif