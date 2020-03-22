.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_4_trainer_0

ow_script_route_4_trainer_0:
    trainerbattlestd 0 0x75 0 str_before str_after
    loadpointer 0 str_after
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before:
    .autostring 34 2 "Mein Geist ist der eines Flug-Pokémons!\pNiemand besitzt mehr Freiheit!"
str_after:
    .autostring 34 2 "Ist das der Käfig, mit dem du mich einfangen willst?"
.elseif LANG_EN

.endif