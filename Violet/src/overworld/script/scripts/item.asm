.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "specials.s"
.include "constants/item_pockets.s"

.global ow_script_no_room_for_giveitem
.global ow_script_std_1_find_item
.global ow_script_std_0_obtain_item

ow_script_no_room_for_giveitem:
    lock
    faceplayer
    loadpointer 0x0 str_no_room_for_giveitem
    callstd MSG
    release
    end


ow_script_std_0_obtain_item:
    copyvar 0x8004, 0x8000
    copyvar 0x8005, 0x8001
    bufferitems 1, 0x8004, 0x8005
    checkitemtype 0x8004
    call ow_script_buffer_item_pocket_name_and_play_item_fanfare
    compare 0x8007, 1
    callif EQUAL ow_script_obtain_item_print_text
    compare 0x8007, 0
    callif EQUAL ow_script_callstd_0_no_room_to_obtain_item
    return

ow_script_std_1_find_item:
    lock
    faceplayer
    checksound
    copyvar 0x8004, 0x8000
    copyvar 0x8005, 0x8001
    checkitemroom 0x8000, 0x8001
    copyvar 0x8007, LASTRESULT
    bufferitems 1, 0x8000, 0x8001
    checkitemtype 0x8000
    call ow_script_buffer_item_pocket_name_and_play_item_fanfare
    compare 0x8007, 1
    callif EQUAL ow_script_pick_up_item
    compare 0x8007, 0
    callif EQUAL ow_script_cant_pick_up_item
    release
    end

ow_script_buffer_item_pocket_name_and_play_item_fanfare:
    compare LASTRESULT, POCKET_ITEMS
    gotoif EQUAL buffer_pocket_items
    compare LASTRESULT, POCKET_KEY_ITEMS
    gotoif EQUAL buffer_pocket_key_items
    compare LASTRESULT, POCKET_POKEBALLS
    gotoif EQUAL buffer_pocket_pokeballs
    compare LASTRESULT, POCKET_TM_HM
    gotoif EQUAL buffer_pocket_tm_hm
    compare LASTRESULT, POCKET_BERRIES
    gotoif EQUAL buffer_pocket_berries
    compare LASTRESULT, POCKET_BAIT
    gotoif EQUAL buffer_pocket_bait
    end

buffer_pocket_items:
    bufferstd 2, 0x18
    compare 0x8007, 1
    callif EQUAL play_item_fanfare_std
    return
buffer_pocket_key_items:
    bufferstd 2, 0x19
    compare 0x8007, 1
    callif EQUAL play_item_fanfare_std
    return
buffer_pocket_pokeballs:
    bufferstd 2, 0x1a
    compare 0x8007, 1
    callif EQUAL play_item_fanfare_std
    return
buffer_pocket_tm_hm:
    bufferstd 2, 0x1b
    compare 0x8007, 1
    callif EQUAL play_item_fanfare_tm_hm
    return
buffer_pocket_berries:
    bufferstd 2, 0x1c
    compare 0x8007, 1
    callif EQUAL play_item_fanfare_std
    return
buffer_pocket_bait:
    bufferstring 2, str_bait
    compare 0x8007, 1
    callif EQUAL play_item_fanfare_std
    return

ow_script_pick_up_item:
    hidesprite LASTTALKED
    additem 0x8004, 0x8005
    special2 LASTRESULT, SPECIAL_BUFFER_TM_HM_MOVE_NAME
    copyvar 0x8008, LASTRESULT
    special SPECIAL_ITEM_OBTAIN_SHOW_DESCRIPTION
    compare 0x8008, 1
    callif EQUAL ow_script_find_hm_tm
    compare 0x8008, 0
    callif EQUAL ow_script_find_non_hm_tm
    waitfanfare
    waitmsg
    waitkeypress
    special SPECIAL_ITEM_OBTAIN_DELETE_DESCRIPTION
    waitstate
    loadpointer 0 str_put_item_away
    callstd MSG_KEEPOPEN
    return

ow_script_obtain_item_print_text:
    special SPECIAL_ITEM_OBTAIN_SHOW_DESCRIPTION
    preparemsg str_player_obtained_item
    waitfanfare
    waitmsg
    waitkeypress
    special SPECIAL_ITEM_OBTAIN_DELETE_DESCRIPTION
    waitstate
    loadpointer 0 str_put_item_away
    callstd MSG
    return


.ifdef LANG_GER
str_no_room_for_giveitem:
    .autostring 34 2 "Sieht so aus, als hättest du keinen Platz für BUFFER_2.\pKomm wieder, wenn du Platz für das Item geschaffen hast."
str_bait:
    .autostring 34 2 "Ködertasche"

.elseif LANG_EN
str_no_room_for_giveitem:
    .autostring 34 2 "Looks like you don't have room for that.\pCome back once you made room for the item."
.endif