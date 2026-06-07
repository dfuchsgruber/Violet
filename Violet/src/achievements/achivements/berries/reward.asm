.include "overworld_script.s"
.include "items.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_achievement_berries_reward_1
.global ow_script_achievement_berries_reward_20
.global ow_script_achievement_berries_reward_50
.global ow_script_achievement_berries_reward_100

ow_script_achievement_berries_reward_1:
    copyvarifnotzero 0x8000 ITEM_UNBEKANNTER_SAMEN
    copyvarifnotzero 0x8001 5
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL no_room_for_item
    setflag FLAG_BERRIES_ACHIEVEMENT_PICK_1_REWARD_RECEIVED
no_room_for_item:
    goto ow_script_end_achievement_reward

ow_script_achievement_berries_reward_20:
    lockall
    fanfare 0x13e
    loadpointer 0x0 str_berries_achievement_pick_20_reward
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_BERRIES_ACHIEVEMENT_PICK_20_REWARD_RECEIVED
    goto ow_script_end_achievement_reward

ow_script_achievement_berries_reward_50:
    copyvarifnotzero 0x8000 ITEM_PRUNUSBEERE
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL no_room_for_item_50
    setflag FLAG_BERRIES_ACHIEVEMENT_PICK_50_REWARD_RECEIVED
no_room_for_item_50:
    goto ow_script_end_achievement_reward

ow_script_achievement_berries_reward_100:
    copyvarifnotzero 0x8000 ITEM_ANTIKER_SAMEN
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL no_room_for_item_100
    setflag FLAG_BERRIES_ACHIEVEMENT_PICK_100_REWARD_RECEIVED
no_room_for_item_100:
    goto ow_script_end_achievement_reward


.ifdef LANG_GER
str_berries_achievement_pick_20_reward:
    .autostring 34 2 "Die Ernte von Beeren, die du gepflanzt hast, erhöht sich um 50%."
.elseif LANG_EN
str_berries_achievement_pick_20_reward:
    .autostring 34 2 "The harvest of berries you've planted is increased by 50%."
.endif
