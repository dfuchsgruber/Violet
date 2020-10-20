.include "overworld_script.s"
.include "callstds.s"

.global ow_script_haweiland_sign_0
.global ow_script_haweiland_sign_1
.global ow_script_haweiland_sign_2

ow_script_haweiland_sign_0:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end
ow_script_haweiland_sign_1:
    loadpointer 0 str_1
    callstd MSG_SIGN
    end
ow_script_haweiland_sign_2:
    loadpointer 0 str_2
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Haweiland\nEntspannung pur!"
str_1:
    .autostring 34 2 "Haweiland Lagerhaus"
str_2:
    .autostring 34 2 "Strandhaus"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Haweiland\nJust relax!"
str_1:
    .autostring 34 2 "Haweiland Cargo Hall"
str_2:
    .autostring 34 2 "Beach House"
.endif