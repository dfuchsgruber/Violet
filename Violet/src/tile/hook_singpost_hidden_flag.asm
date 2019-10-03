.include "overworld_script.s"
.include "flags.s"
.include "ordinals.s"

.global hook_singpost_hidden_flag

.global ow_script_hidden_item_mushroom
.global ow_script_hidden_item_mushroom_already_plucked

.global ow_script_hidden_item_shell
.global ow_script_hidden_item_shell_already_found

.align 2
.thumb

.thumb_func
hook_singpost_hidden_flag:
    ldr r0, [r5, #8]
    mov r1, #4
    bl singpost_get_hidden_field
    ldr r1, =0x020370C6 @Var 0x8007
    strh r0, [r1]
    ldr r1, =0x020370D4
    strh r6, [r1]
    ldr r0, =script_singpost_hidden_find
    
    ldr r1, =0x0806D14A | 1
    bx r1 @return

singpost_get_hidden_field:
    ldr r2, =singpost_get_flag
    bx r2


// Scripts

ow_script_hidden_item_mushroom:
    lockall
    checkflag TRAINER_TIPP_MUSHROOM
    callif NOT_EQUAL ow_script_trainer_tipp_mushroom
    goto hidden_item_add

ow_script_trainer_tipp_mushroom:
    setflag TRAINER_TIPP_MUSHROOM
    checksound
    sound 366
    loadpointer 0 str_trainer_tipp_mushroom
    callstd 4
    checksound
    return

ow_script_hidden_item_shell:
    lockall
    checkflag TRAINER_TIPP_SHELL
    callif NOT_EQUAL ow_script_trainer_tipp_shell
    goto hidden_item_add

ow_script_trainer_tipp_shell:
    setflag TRAINER_TIPP_SHELL
    checksound
    sound 366
    loadpointer 0 str_trainer_tipp_shell
    callstd 4
    checksound
    return

script_singpost_hidden_find:
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
    setvar 0x800D 0
    releaseall
    end

no_ashbag:
    loadpointer 0 str_ashbag_picked_up
    callstd 4
    loadpointer 0 str_ashbag_not_received
    callstd 4
    setvar 0x800D 0
    releaseall
    end

ow_script_hidden_item_mushroom_already_plucked:
    lockall
    checkflag TRAINER_TIPP_MUSHROOM
    callif NOT_EQUAL ow_script_trainer_tipp_mushroom
    loadpointer 0 str_mushroom_already_plucked
    callstd 4
    setvar 0x800D 0
    releaseall
    end

ow_script_hidden_item_shell_already_found:
    lockall
    checkflag TRAINER_TIPP_SHELL
    callif NOT_EQUAL ow_script_trainer_tipp_shell
    loadpointer 0 str_shell_already_found
    callstd 4
    setvar 0x800D 0
    releaseall
    end

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

	str_trainer_tipp_shell:
		.string "Trainer-Tipp!\nIn Muscheln versteckten sich\lItems, die vom Detektor nicht\lgefunden werden können.\pWöchentlich werden neue Items\nangespült."

	str_trainer_tipp_mushroom:
		.string "Trainer-Tipp!\nWo Pilze wachsen, können Pilze\lgefunden werden.\pSelbst der Detektor kann Pilze nicht\nfinden.\pPilze können im Wochentakt\nnachwachsen."
    str_mushroom_already_plucked:
        .autostring 34 2 "Irgendjemand scheint die Pilze bereits gepflückt zu habenDOTS"
    str_shell_already_found:
        .autostring 34 2 "Die Flut hat die Muschel bereits ausgespültDOTS"

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

	str_trainer_tipp_shell:
		.string "Trainer-Tipp!\nItems can hide inside shells.\pThose can not be traced by\nthe detector and are washed\lup weekly."

	str_trainer_tipp_mushroom:
		.string "Trainer-Tipp!\nWhere mushrooms grow mushrooms\ncan be found!\pEven the detector can not\ntrace mushrooms!\pThey also regrow weekly!"
    str_mushroom_already_plucked:
        .autostring 34 2 "Someone seems to have already plucked those mushroomsDOTS"
    str_shell_already_found:
        .autostring 34 2 "The flood has already rinsed this shellDOTS"

.endif


