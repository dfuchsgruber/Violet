.include "callstds.s"
.include "overworld_script.s"


.global ow_script_route_1_clouds_person_0
.global ow_script_route_1_clouds_person_1

ow_script_route_1_clouds_person_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end
ow_script_route_1_clouds_person_1:
    loadpointer 0x0 str_1
    callstd MSG_FACE
    end



.ifdef LANG_GER
str_0:
    .autostring 34 2 "Viele Wolkenreiter sehen zu Lucius, dem ehemaligen Champion auf.\pEr hat sich auf eigene Faust auf die Jagd nach einem großen legendären Pokémon begeben, das irgendwo im Himmel lebt."
str_1:
    .autostring 34 2 "Es heißt, hier über den Wolken habe einst die bedeutendste Zivilisation aller Zeiten gelebt.\pOb das wohl stimmt?"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Many cloud riders look up towards Lucius, the former champion.\pOut of own strength he began chasing a big legendary dragon pokémon that lives up here."
str_1:
    .autostring 34 2 "It is said that above the clouds the most important civilization of all times prospered.\pI wonder if that is trueDOTS"

.endif
