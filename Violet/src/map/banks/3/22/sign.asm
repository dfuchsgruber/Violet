.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_route_4_sign_0
.global ow_script_map_route_4_sign_1

ow_script_map_route_4_sign_0:
    loadpointer 0x0 str_0
    callstd MSG_SIGN
    end
ow_script_map_route_4_sign_1:
    loadpointer 0x0 str_1
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "UP_ARROWKaskada"
str_1:
    .autostring 34 2 "UP_ARROWBlütenbach"

.elseif LANG_EN

.endif