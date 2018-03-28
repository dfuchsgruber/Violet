.include "overworld_script.s"
.include "items.s"
.include "callstds.s"
.include "flags.s"

.global ow_script_present_0

present_already_received:
    loadpointer 0 str_present_already_received
    callstd 6
    release
    end

ow_script_present_0:
    checkflag PRESENT_0
    gotoif 1 present_already_received
    loadpointer 0 str_present_0
    callstd 6
    copyvarifnotzero 0x8000 ITEM_SONDERBONBON
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    closeonkeypress
    setflag PRESENT_0
    release
    end



    