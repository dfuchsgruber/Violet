.include "callstds.s"
.include "overworld_script.s"

.global ow_script_tafelberg_south_person_0

ow_script_tafelberg_south_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich komme direkt aus KaskadaDOTS\pIch muss sagen, dass der Sandsturm mir hier wirklich zusetzt.\pOb das da unten noch schlimmer wird?"
.elseif LANG_EN
.endif