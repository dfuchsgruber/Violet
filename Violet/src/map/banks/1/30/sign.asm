.include "callstds.s"
.include "overworld_script.s"

.global ow_script_aschhain_sign_0
.global ow_script_aschhain_sign_1

ow_script_aschhain_sign_0:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end
ow_script_aschhain_sign_1:
    loadpointer 0 str_1
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "UP_ARROW Haus des Glasbläsers\nDOWN_ARROW Route 6"
str_1:
    .autostring 34 2 "Haus des Glasbläsers"
.elseif LANG_EN
.endif
