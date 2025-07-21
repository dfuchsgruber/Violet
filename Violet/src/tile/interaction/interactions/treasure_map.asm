.include "overworld_script.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "specials.s"

.global ow_script_treasure_find

ow_script_treasure_find:
    lockall
    checksound
    sound 0x15
    applymovement 0xFF mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_something_burried
    callstd MSG_KEEPOPEN
    checksound
    lockall
    checksound
hidden_item_add:
    call ow_script_item_obtainable
    compare 0x8007 0x1
    gotoif 0x1 treasure_obtain @item find succeded
    compare 0x8007 0x0
    gotoif 0x1 ow_script_hidden_item_no_space_in_bag @nospace in bag
    end

treasure_obtain:
    copyvar 0x8008, 0x8004 @// backup
    copyvar 0x8004, 0x8005 @// item idx
    special SPECIAL_ITEM_OBTAIN_SHOW_DESCRIPTION
    compare 0x8006, 1
    callif EQUAL, ow_script_hidden_item_found_one
    compare 0x8006, 1
    callif NOT_EQUAL, ow_script_hidden_item_found_many
    waitfanfare
    waitmsg
    waitkeypress
    special SPECIAL_ITEM_OBTAIN_DELETE_DESCRIPTION
    waitstate
    loadpointer 0 str_put_item_away
    callstd MSG_KEEPOPEN
    copyvar 0x8004, 0x8008
    special SPECIAL_HIDDEN_ITEM_SET_FLAG @// just sets the flag in 0x8004
    releaseall
    end

.ifdef LANG_GER
str_something_burried:
    .autostring 34 2 "Hier scheint etwas vergraben zu liegen!"
.elseif LANG_EN
.endif