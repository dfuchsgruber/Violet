.include "overworld_script.s"
.include "items.s"
.include "specials.s"
.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"

.global ow_script_fishing

ow_script_fishing:
    checkitem ITEM_KOEDER 1
    compare LASTRESULT 0x1
    gotoif EQUAL bait
    checkitem ITEM_GOLDKOEDER 1
    compare LASTRESULT 0x1
    gotoif EQUAL bait
    checkitem ITEM_LEUCHTKOEDER 1
    compare LASTRESULT 0x1
    gotoif EQUAL bait
fishing_start:
    special SPECIAL_FISHING_START
    end

bait:
    loadpointer 0 str_use
    callstd MSG_KEEPOPEN
    callasm fishing_print_bait_selection
    waitstate
    compare LASTRESULT 0x7F
    gotoif EQUAL fishing_start
    callasm fishing_execute_bait_selection
    closeonkeypress
    goto fishing_start





.ifdef LANG_GER
str_use:
    .autostring 34 2 "Möchtest du einen Köder benutzen?"

.elseif LANG_EN
str_use:
    .autostring 34 2 "Do you want to use a bait?"

.endif