.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "movements.s"
.include "items.s"

.global ow_script_bluetenbach_clouds_expert_belt
ow_script_bluetenbach_clouds_expert_belt:
    checkflag FLAG_ITEM_EXPERT_BELT
    gotoif EQUAL done
    lock
    faceplayer
    loadpointer 0 str_0
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_EXPERTENGURT
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL no_room_for_item
    setflag FLAG_ITEM_EXPERT_BELT
    release
    end
done:
    loadpointer 0 str_bye
    callstd MSG_FACE
    end
no_room_for_item:
    loadpointer 0 str_no_room_for_item
    callstd MSG_KEEPOPEN
    release
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 ".TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT .TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT\n.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT .TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT\pMeine Konzentration wird von meinem Gurt gestärktDOTS\pMein GurtDOTS"
str_bye:
    .autostring 34 2 "Der Expertengurt macht dich stärkerDOTS\pEr kann auch deinen Fokus verbessern!"
str_no_room_for_item:
    .autostring 34 2 "Du hast keinen Platz im Beutel.\pKomm wieder, wenn du Platz hast."
.elseif LANG_EN
str_0:
    .autostring 34 2 ".TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT .TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT\n.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT .TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT\pMy concentration is strengthened by my beltDOTS\pMy beltDOTS"
str_bye:
    .autostring 34 2 "The Expert Belt makes you strongerDOTS\pIt can also improve your focus!"
str_no_room_for_item:
    .autostring 34 2 "You have no room in your bag.\pCome back when you have room."
.endif
