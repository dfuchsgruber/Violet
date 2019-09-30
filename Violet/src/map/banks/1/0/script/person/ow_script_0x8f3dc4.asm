.include "flags.s"
.include "attacks.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_silvania_wald_person_28

ow_script_silvania_wald_person_28:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Mir kommt es immer wieder vor, als würde die Zeit hier im Wald stillstehenDOTS"

.elseif LANG_EN
str_0:
    .autostring 34 2 "From time to time I feel like the time in this forest would stand stillDOTS"
.endif