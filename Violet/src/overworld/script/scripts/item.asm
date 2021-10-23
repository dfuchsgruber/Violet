.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_no_room_for_giveitem
.global ow_script_std_1_find_item

ow_script_no_room_for_giveitem:
    lock
    faceplayer
    loadpointer 0x0 str_no_room_for_giveitem
    callstd MSG
    release
    end

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

.ifdef LANG_GER
str_no_room_for_giveitem:
    .autostring 34 2 "Sieht so aus, als hättest du keinen Platz für BUFFER_2.\pKomm wieder, wenn du Platz für das Item geschaffen hast."
.elseif LANG_EN
str_no_room_for_giveitem:
    .autostring 34 2 "Looks like you don't have room for that.\pCome back once you made room for the item."
.endif