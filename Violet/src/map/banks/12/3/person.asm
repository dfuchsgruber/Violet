
.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "move_tutor.s"
.include "movements.s"


.global ow_script_laubdorf_indoor_1_person_0
ow_script_laubdorf_indoor_1_person_0:
    loadpointer 0 str_0
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Laubdorf ist seit je her ein Ort, der die Familie in den Mittelpunkt stellt.\pHier sorgt man sich um seinen Nachwuchs!\pLeiderDOTS\pIst mir nicht das Glück zuteil geworden, Vater zu werden.\pAber ich habe einen Neffen in Kranzdorf!"
.endif