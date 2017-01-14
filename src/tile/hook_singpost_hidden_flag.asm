.include "overworld_script.s"

.global hook_singpost_hidden_flag
.global script_hidden_item_add
.global script_hidden_item_trainer_tipp_mushroom

.global script_hidden_item_trainer_tipp_shell

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

script_hidden_item_trainer_tipp_mushroom:
    lockall
    checksound
    sound 366
    loadpointer 0 str_trainer_tipp_mushroom
    callstd 4
    goto script_hidden_item_add

script_hidden_item_trainer_tipp_shell:
    lockall
    checksound
    sound 366
    loadpointer 0 str_trainer_tipp_shell
    callstd 4
    goto script_hidden_item_add

script_hidden_item_add:
    lockall
    checksound
    goto hidden_item_add

script_singpost_hidden_find:
    lockall
    checksound
    compare 0x8005 0x0
    gotoif 0x1 no_item
hidden_item_add:
    call 0x81A971F
    compare 0x8007 0x1
    gotoif 0x1 0x81A9736 @item find succeded
    compare 0x8007 0x0
    gotoif 0x1 0x81A9775 @nospace in bag
    end

no_item: @found coins or ash
    compare 0x8007 0x0
    gotoif 0x1 0x81A978C @coin find
    compare 0x8007 0x1
    gotoif 0x1 ashfind
    compare 0x8007 0x2
    gotoif 0x1 mushroomfind
    end

mushroomfind:
    special 0x47
    goto hidden_item_add

ashfind:
    special2 0x8000 0x46 @checks if ashbag has space, adds ash in 0x8006 and buffers the endamount in [buffer1] (=\b\02)
    buffernumber 0 0x8006

    checkflag 0x951
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

