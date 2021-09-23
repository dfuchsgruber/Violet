.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_map_route_5_sign_0
.global ow_script_map_route_5_sign_1

ow_script_map_route_5_sign_0:
    loadpointer 0x0 str_0
    callstd MSG_SIGN
    end
ow_script_map_route_5_sign_1:
    loadpointer 0x0 str_1
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL close_sign_1
    loadpointer 0 str_2
    callstd MSG_KEEPOPEN
close_sign_1:
    closeonkeypress
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "LEFT_ARROWOrina City\nRIGHT_ARROWRoute 3"
str_1:
    .autostring 34 2 "Auf dieser Tafel sind verblasste Lettern zu erkennen.\pMöchtest du sie lesen?"
str_2:
    .autostring 34 2 "Dieser Tempel wurde zu Ehren des Pokémon Altaria errichtet.\pEs lehrte uns die Kunst des Wolkenwebens.\pDank ihm eroberten wir die unendlichen Weiten des Himmels.\pUnser ewiger Dank gelte dem Pokémon Altaria."
.elseif LANG_EN

.endif