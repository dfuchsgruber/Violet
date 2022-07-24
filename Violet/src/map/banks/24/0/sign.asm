.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_kuestenberg_clouds_blue_gear
.global str_return_gear_to_sonnaufeld

ow_script_kuestenberg_clouds_blue_gear:
    copyvarifnotzero 0x8000 ITEM_BLAUES_ZAHNRAD
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    hidesprite 5
    loadpointer 0 str_return_gear_to_sonnaufeld
    callstd MSG_KEEPOPEN
    releaseall
    end

.ifdef LANG_GER
str_return_gear_to_sonnaufeld:
    .autostring 34 2 "Bring es in die passende Vorrichtung in Sonnaufeld."
.elseif LANG_EN
.endif