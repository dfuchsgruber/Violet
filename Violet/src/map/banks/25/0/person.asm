.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_11_clouds_person_0

ow_script_route_11_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Die Geist-Pokémon aus Ceometria verirren sich bis hier hinauf auf die Wolken."
.elseif LANG_EN
str_0:
    .autostring 34 2 "The ghost pokémon of Ceometria sometimes wander arround even up here."
.endif
