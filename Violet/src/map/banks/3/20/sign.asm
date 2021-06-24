.include "overworld_script.s"
.include "callstds.s"

.global ow_script_power_plant_sign

ow_script_power_plant_sign:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Pokémon-Kraftwerk\pWir machen aus Sonnenlicht Strom."
.elseif LANG_EN
.endif