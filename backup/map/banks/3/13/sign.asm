.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ceometria_sign_arena
.global ow_script_ceometria_sign_town
.global ow_script_ceometria_sign_move_deleter

ow_script_ceometria_sign_arena:
    loadpointer 0 str_arena
    callstd MSG_SIGN
    end

ow_script_ceometria_sign_town:
    loadpointer 0 str_town
    callstd MSG_SIGN
    end

ow_script_ceometria_sign_move_deleter:
    loadpointer 0 str_move_deleter
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_arena:
    .autostring 34 2 "Arena von Ceometria\pTyp: Geist\nLeiter: Teah"
str_town:
    .autostring 34 2 "Ceometria\nDie Stadt der Besinnung"
str_move_deleter:
    .autostring 34 2 "Haus des Attacken-Verlerners"
.elseif LANG_EN
str_arena:
    .autostring 34 2 "Gym of Ceometria\pType: Ghost\nLeader: Teah"
str_town:
    .autostring 34 2 "Ceometria\nThe town of contemplation"
str_move_deleter:
    .autostring 34 2 "House of the Move Deleter"
.endif