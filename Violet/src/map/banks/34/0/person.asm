.include "overworld_script.s"
.include "callstds.s"

.global ow_script_power_plant_inside_person_0
.global ow_script_power_plant_inside_person_1
.global ow_script_power_plant_inside_person_2
.global ow_script_power_plant_inside_person_3
.global ow_script_power_plant_inside_person_4

ow_script_power_plant_inside_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_power_plant_inside_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_power_plant_inside_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_power_plant_inside_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_power_plant_inside_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hier im Kraftwerk erzeugen wir den Strom für die gesamte Region.\pUnd dafür verwenden wir außerdem nur Sonnenlicht.\pNachhaltigkeit steht für uns hier an erster Stelle."
str_1:
    .autostring 34 2 "Die Solarzellen, die wir draußen einsetzen, wurden von der Laz. Corp. entwickelt.\pSelbst bei schlechtem Wetter machen sie einen großen Teil der Sonnenergie nutzbar."
str_2:
    .autostring 34 2 "Wenn man in diesem Kraftwerk beschäftig ist, steht man quasi immer unter Spannung.\pDas muss einem schon Spaß machen, sonst muss man sich schnell eine andere Beschäftigung suchen!"
str_3:
    .autostring 34 2 "Elektro-Pokémon lieben das Kraftwerk.\pViele meiner Kollegen bringen ihre Pokémon mit an den Arbeitsplatz.\pIch finde das ehrlichgesagt aber ziemlich unprofessionell."
str_4:
    .autostring 34 2 "Seitdem ich mein Pokémon mit zur Arbeit nehme, fühle ich mich viel besser.\pSchon erstaunlich, wie viel einem die eigenen Pokémon geben."
.elseif LANG_EN
.endif