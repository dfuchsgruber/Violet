.include "overworld_script.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "specials.s"

.global ow_script_hidden_item_find

ow_script_hidden_item_find:
    lockall
    checksound
    compare 0x8005 0x0
    gotoif 0x1 no_item
hidden_item_add:
    call ow_script_item_obtainable
    compare 0x8007 0x1
    gotoif 0x1 ow_script_hidden_item_obtain @item find succeded
    compare 0x8007 0x0
    gotoif 0x1 ow_script_hidden_item_no_space_in_bag @nospace in bag
    end

ow_script_hidden_item_obtain:
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
    special SPECIAL_HIDDEN_ITEM_SET_FLAG
    releaseall
    end


no_item: @found coins or ash
    compare 0x8007 0x0
    gotoif 0x1 ow_script_hidden_item_obtain_coin @coin find
    compare 0x8007 0x1
    gotoif 0x1 ashfind
    end

ashfind:
    special2 0x8000 0x46 @checks if ashbag has space, adds ash in 0x8006 and buffers the endamount in [buffer1] (=\b\02)
    buffernumber 0 0x8006
    checkflag ASHBAG_RECEIVED
    gotoif 0x0 no_ashbag
    compare 0x8000 1
    gotoif 0x0 no_ashbag_space
    special 0x96
    fanfare 0x101
    loadpointer 0 str_ashbag_picked_up
    callstd 4
    setvar 0x800D 0x0
    releaseall
    end

no_ashbag_space:
    loadpointer 0 str_ashbag_picked_up
    callstd 4
    loadpointer 0 str_ashbag_full
    callstd 4
    setvar LASTRESULT 0
    releaseall
    end

no_ashbag:
    loadpointer 0 str_ashbag_picked_up
    callstd 4
    loadpointer 0 str_ashbag_not_received
    callstd 4
    setvar LASTRESULT 0
    releaseall
    end

ow_script_item_obtainable:
    additem 0x8005, 0x8006
    copyvar 0x8007, LASTRESULT
    bufferitem 1, 0x8005
    checkitemtype 0x8005
    call ow_script_buffer_item_pocket_name_and_play_item_fanfare
    return


@ // Define strings

.ifdef LANG_GER

	.global str_ashbag_not_received

	str_ashbag_not_received:
		.string "Zu Schade!\nDu besitzt keinen Aschebeutel!"


	.global str_ashbag_full

	str_ashbag_full:
		.string "Zu Schade!\nDeine Aschetasche ist voll!"


	.global str_ashbag_picked_up

	str_ashbag_picked_up:
		.string "PLAYER findet\nBUFFER_1 Asche!"


.elseif LANG_EN

	.global str_ashbag_not_received

	str_ashbag_not_received:
		.string "What a shame!\nYou do not own an ashbag!"

	.global str_ashbag_full

	str_ashbag_full:
		.string "What a shame!\nYour ashbag seems to be full."

	.global str_ashbag_picked_up

	str_ashbag_picked_up:
		.string "PLAYER obtains\nBUFFER_1 ashes!"
.endif


