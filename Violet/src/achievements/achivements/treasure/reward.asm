.include "overworld_script.s"
.include "items.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "achievement.s"

.global ow_script_achievement_treasure_1_reward
.global ow_script_achievement_treasure_5_reward
.global ow_script_achievement_treasure_all_reward

ow_script_achievement_treasure_1_reward:
    copyvarifnotzero 0x8000 ITEM_GOLDAPFEL
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL no_room_for_item
    setflag FLAG_ACHIEVEMENT_TREASURE_REWARD_1
no_room_for_item:
    goto ow_script_end_achievement_reward

ow_script_achievement_treasure_5_reward:
    copyvarifnotzero 0x8000 ITEM_AP_TOP
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL no_room_for_item_5
    setflag FLAG_ACHIEVEMENT_TREASURE_REWARD_5
no_room_for_item_5:
    goto ow_script_end_achievement_reward

ow_script_achievement_treasure_all_reward:
    copyvarifnotzero 0x8000 ITEM_TM59
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL no_room_for_item_all
    setflag FLAG_ACHIEVEMENT_TREASURE_REWARD_ALL
no_room_for_item_all:
    goto ow_script_end_achievement_reward
