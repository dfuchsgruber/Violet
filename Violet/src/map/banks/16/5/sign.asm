.include "overworld_script.s"
.include "specials.s"
.include "flags.s"
.include "ordinals.s"
.include "callstds.s"
.include "vars.s"

.global ow_script_clouds_mine_switch_sign

ow_script_clouds_mine_switch_sign:
    loadpointer 0 str_switch
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif EQUAL do_switch
    closeonkeypress
    end
do_switch:
    closeonkeypress
    checkflag FLAG_ROUTE_5_CLOUDS_CAVE_SWITCH
    gotoif EQUAL clear_flag
    checkflag FLAG_ROUTE_5_CLOUDS_CAVE_SWITCH
    gotoif NOT_EQUAL set_flag
after_flag_toggle:
    call ow_script_route_5_clouds_cave_switch
    special SPECIAL_MAP_UPDATE_BLOCKS
    sound 29
    checksound
    end

clear_flag:
    clearflag FLAG_ROUTE_5_CLOUDS_CAVE_SWITCH
    goto after_flag_toggle
set_flag:
    setflag FLAG_ROUTE_5_CLOUDS_CAVE_SWITCH
    goto after_flag_toggle

.ifdef LANG_GER
str_switch:
    .autostring 34 2 "Den Schalter umlegen?"
.elseif LANG_EN
str_switch:
    .autostring 34 2 "Do you want to switch the lever?"
.endif



