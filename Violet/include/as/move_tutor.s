.include "move_tutors.s"
.include "vars.s"
.include "callstds.s"

.equ MOVE_TUTOR_NUM_BIG_MUSHROOMS, 1
.equ MOVE_TUTOR_NUM_TINY_MUSHROOMS, 10

.macro make_move_tutor_std macro_name:req str_intro:req str_abort:req move_tutor_idx_var=0x8000
\macro_name:
    copyvar 0x8008 \move_tutor_idx_var
    lock
    faceplayer
    copyvar 0x8004 0x8008
    callasm move_tutor_set_flag_by_var
    setvar 0x8005 MOVE_TUTOR_NUM_BIG_MUSHROOMS
    buffernumber 0 0x8005
    setvar 0x8006 MOVE_TUTOR_NUM_TINY_MUSHROOMS
    buffernumber 1 0x8006
    callasm move_tutor_buffer_string
    loadpointer 0x0 \str_intro
    callstd MSG_KEEPOPEN
    call move_tutor_item_check
    compare LASTRESULT 0
    gotoif NOT_EQUAL _has_mushrooms
    closeonkeypress
    release
    return
_has_mushrooms:
    applymovement LASTTALKED mov_exclam
    waitmovement 0x0
    lock
    faceplayer
    copyvar 0x8004 0x8008
    callasm move_tutor_set_flag
    setvar 0x8005 MOVE_TUTOR_NUM_BIG_MUSHROOMS
    buffernumber 1 0x8005
    setvar 0x8006 MOVE_TUTOR_NUM_TINY_MUSHROOMS
    buffernumber 2 0x8006
    callasm move_tutor_buffer_string
    loadpointer 0x0 str_move_tutor_ask
    callstd MSG_YES_NO
    compare LASTRESULT 0x1
    gotoif LESS _selection_exited
    loadpointer 0x0 str_move_tutor_select
    callstd MSG
    copyvar 0x8005 0x8008
    call ow_script_move_tutor_do
    compare LASTRESULT 0x0
    gotoif EQUAL _selection_exited
    call ow_script_move_tutor_pay_items
    loadpointer 0x0 str_move_tutor_pay_items
    callstd MSG
    return

_selection_exited:
    copyvar 0x8004 0x8008
    callasm move_tutor_buffer_string
    loadpointer 0x0 \str_abort
    callstd MSG_KEEPOPEN
    release
    return
.endm
