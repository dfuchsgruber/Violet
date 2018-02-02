.include "overworld_script.s"
.include "std.s"

.global ow_script_botogel

ow_script_botogel:
    lock
    checkflag PRESENT_INTRODUCED
    gotoif 0 introduce
query:
    cry POKEMON_BOTOGEL 0
    loadpointer 0 str_ow_script_botogel_2
    callstd 4
    waitcry
    setflag TRANS_DISABLE
    clearflag TRANS_PALETTE_FETCH
    special 0x4A
    waitstate
    lock
    clearflag TRANS_DISABLE
    compare LASTRESULT 1
    gotoif EQUAL receive_present
    cry POKEMON_BOTOGEL 0
    loadpointer 0 str_ow_script_botogel_0
    callstd 4
    waitcry
    loadpointer 0 str_ow_script_botogel_3
    callstd 6
    release
    end

receive_present:
    cry POKEMON_BOTOGEL 0
    loadpointer 0 str_ow_script_botogel_0
    callstd 4
    waitcry
    jumpram
    end

introduce:
    cry POKEMON_BOTOGEL 0
    loadpointer 0 str_ow_script_botogel_0
    callstd 4
    waitcry
    loadpointer 0 str_ow_script_botogel_1
    callstd 6
    setflag PRESENT_INTRODUCED
    goto query

