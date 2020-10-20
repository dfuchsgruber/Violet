.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_7_sign_1


ow_script_route_7_sign_1:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Haus des legendären Anglers"
.elseif LANG_EN
str_0:
    .autostring 34 2 "The legendary fishermen's house"
.endif