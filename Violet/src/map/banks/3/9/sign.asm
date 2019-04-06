.include "overworld_script.s"
.include "callstds.s"

.global ow_script_laubdorf_sign_0
.global ow_script_laubdorf_sign_1

ow_script_laubdorf_sign_0:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end
ow_script_laubdorf_sign_1:
    loadpointer 0 str_1
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Laubdorf\pWo Mensch und Pokémon eine Familie sind."
str_1:
    .autostring 34 2 "Pokémon-Pension"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Leaf Village\pWhere man and Pokémon are family."
str_1:
    .autostring 34 2 "Pokémon-Daycare"

.endif