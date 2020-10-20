.include "overworld_script.s"
.include "callstds.s"

.global ow_script_inferior_clouds_person_0

ow_script_inferior_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Wir Hexen verehren die dunkle Königin.\pEs heißt, dass ihre Magie die Wolken zum Schweben gebracht hat."
.elseif LANG_EN
str_0:
    .autostring 34 2 "We witches woreship the dark queen.\pIt is said that her magic made the clouds levitate."
.endif