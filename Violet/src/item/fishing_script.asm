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
fishing_start:
    special SPECIAL_FISHING_START
    end

bait:
    loadpointer 0 str_use
    callstd MSG_KEEPOPEN
    checkitem ITEM_KOEDER 1
    compare LASTRESULT 0x1
    gotoif EQUAL has_bait
    checkitem ITEM_GOLDKOEDER 1
    compare LASTRESULT 0x1
    gotoif EQUAL has_golden_bait
    end

has_bait:
    checkitem ITEM_GOLDKOEDER 1
    compare LASTRESULT 0x1
    gotoif EQUAL has_both_baits
    setvar DYN_MULTICHOICE_ITEM_CNT 0x2
    loadpointer 0x0 choice_bait
    multichoice 0x0 0x0 0x0 0x0
    setvar DYN_MULTICHOICE_ITEM_CNT 0x0
    compare LASTRESULT 0x1
    callif EQUAL use_bait
    closeonkeypress
    goto fishing_start

has_golden_bait:
    checkitem ITEM_KOEDER 1
    compare LASTRESULT 0x1
    gotoif EQUAL has_both_baits
    setvar DYN_MULTICHOICE_ITEM_CNT 0x2
    loadpointer 0x0 choice_golden_bait
    multichoice 0x0 0x0 0x0 0x0
    setvar DYN_MULTICHOICE_ITEM_CNT 0x0
    compare LASTRESULT 0x1
    callif EQUAL use_golden_bait
    closeonkeypress
    goto fishing_start

has_both_baits:
    setvar DYN_MULTICHOICE_ITEM_CNT 0x3
    loadpointer 0x0 choice_both_baits
    multichoice 0x0 0x0 0x0 0x0
    setvar DYN_MULTICHOICE_ITEM_CNT 0x0
    compare LASTRESULT 0x1
    callif EQUAL use_bait
    compare LASTRESULT 0x2
    callif EQUAL use_golden_bait
    closeonkeypress
    goto fishing_start


use_bait:
    setflag FLAG_FISHING_BAIT_USED
    return

use_golden_bait:
    setflag FLAG_FISHING_GOLDEN_BAIT_USED
    return

.align 4
choice_bait:
    .word str_no_bait, 0
    .word str_bait, 0
choice_golden_bait:
    .word str_no_bait, 0
    .word str_golden_bait, 0
choice_both_baits:
    .word str_no_bait, 0
    .word str_bait, 0
    .word str_golden_bait, 0

.ifdef LANG_GER
str_use:
    .autostring 34 2 "Möchtest du einen Köder benutzen?"
str_bait:
    .string "Köder"
str_golden_bait:
    .string "Goldköder"
str_no_bait:
    .string "Kein Köder"

.elseif LANG_EN
str_use:
    .autostring 34 2 "Do you want to use a bait?"
str_bait:
    .string "Bait"
str_golden_bait:
    .string "Golden Bait"
str_no_bait:
    .string "No bait"
.endif