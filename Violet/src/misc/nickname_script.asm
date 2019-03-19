.include "overworld_script.s"
.include "vars.s"
.include "flags.s"
.include "callstds.s"
.include "ordinals.s"

.global ow_script_set_nickname
    ow_script_set_nickname:
    setflag TRANS_DISABLE
    clearflag TRANS_PALETTE_FETCH
    call set_nickname
    closeonkeypress
    clearflag TRANS_DISABLE
    return


set_nickname:
    compare LASTRESULT 0x0
    gotoif EQUAL ask_nickname_team
    compare LASTRESULT 0x1
    gotoif EQUAL ask_nickname_box
    return


ask_nickname_team:
    loadpointer 0x0 str_set_nickname
    callstd MSG_YES_NO
    compare LASTRESULT 0x1
    gotoif EQUAL show_team_nickname_form
    return


show_team_nickname_form:
    countpokemon
    subvar LASTRESULT 0x1
    copyvar 0x8004 LASTRESULT
    fadescreen 0x1
    special 0x9e
    waitstate
    return


ask_nickname_box:
    loadpointer 0x0 str_set_nickname
    callstd MSG_YES_NO
    compare LASTRESULT 0x1
    gotoif EQUAL set_nickname_box
    return


set_nickname_box:
    call show_box_nickname_form
    bufferboxname 0x0 0x4037
    special2 0x800d 0x165
    compare LASTRESULT 0x1
    gotoif EQUAL fullbox_fallback
    loadpointer 0x0 box_notification
    callstd MSG_KEEPOPEN
    return

.global show_box_nickname_form
show_box_nickname_form:
    fadescreen 0x1
    special 0x166
    waitstate
    lock
    faceplayer
    return


fullbox_fallback:
    special2 0x800d 0x18a
    bufferboxname 0x2 0x800d
    loadpointer 0x0 str_full_box
    callstd MSG_KEEPOPEN
    return

.global str_set_nickname
str_set_nickname:
    .string "Möchtest du BUFFER_1 einen\nSpitznamen geben?"

box_notification:
    .string "BUFFER_2 wurde an das Lagerungs-\nSystem gesendet.\pEs wurde in Box\nQUOTE_STARTBUFFER_1QUOTE_END abgelegt."

str_full_box:
    .string "Box QUOTE_STARTBUFFER_3QUOTE_END im\nLagerungssystem ist voll.\pBUFFER_2 wurde in Box\nQUOTE_STARTBUFFER_1QUOTE_END übertragen."