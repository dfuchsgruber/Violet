.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_12_clouds_person_0

ow_script_route_12_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Die Geschichte um das Reich über den Wolken ist nur teilweise überliefert worden.\pEs gibt verschiedene Theorien, wie es untergangen ist."
.elseif LANG_EN
str_0:
    .autostring 34 2 "The story arround the realm above the clouds was only partialy passed down.\pThere are multiple theories how exactly it perished."
.endif
