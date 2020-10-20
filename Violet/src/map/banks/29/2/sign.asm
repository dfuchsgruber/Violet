.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_7_castle_sign

ow_script_route_7_castle_sign:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Schloss Ardeal\pEine Burg, die in die Wolken ragt!"
.elseif LANG_EN
str_1:
    .autostring 34 2 "Castle Ardeal\pA castle that reaches to the clouds!"
.endif