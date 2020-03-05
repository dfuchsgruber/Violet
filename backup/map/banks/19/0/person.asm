.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ceometria_pokestop_person_0
.global ow_script_ceometria_pokestop_person_1
.global ow_script_ceometria_pokestop_person_2

ow_script_ceometria_pokestop_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_ceometria_pokestop_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

ow_script_ceometria_pokestop_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Unter Hexen erzählt man sich, dass die Königin der Nacht in der Lage gewesen sein soll, unzählige böse Geister heraufzubeschwören."
str_1:
    .autostring 34 2 "Wusstest du, dass es ein Pokémon gibt, dessen Geist bei seiner Entwicklung von der alten Schale besitz ergreift?"
str_2:
    .autostring 34 2 "Die Schwestern in den Pokéstops sind einfach wunderschöne FrauenDOTS"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Among witches it is told that the Queen of the Night was able to summon countless evil spirits."
str_1:
    .autostring 34 2 "Did you know that there exists a Pokémon which ghost takes posession of its old shell when evolving?"
str_2:
    .autostring 34 2 "The sisters in the Pokéstops are just beautiful womenDOTS"
.endif