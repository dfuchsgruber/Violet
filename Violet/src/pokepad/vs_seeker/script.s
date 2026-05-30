.include "overworld_script.s"
.include "ordinals.s"
.include "vars.s"
.include "callstds.s"

.global ow_script_vs_seeker

ow_script_vs_seeker:
    callasm vs_seeker
    waitstate
    compare LASTRESULT 0
    gotoif EQUAL none_found
    compare LASTRESULT 1
    gotoif EQUAL rematches_found
    compare LASTRESULT 2
    gotoif EQUAL not_ready
    end

none_found:
    loadpointer 0 str_none_found
    callstd MSG
    end

rematches_found:
    loadpointer 0 str_rematches_found
    callstd MSG
    end

not_ready:
    loadpointer 0 str_not_ready
    callstd MSG
    end

.ifdef LANG_GER
str_none_found:
    .autostring 34 2 "Hier scheint niemand zu sein, der kämpfen will."
str_rematches_found:
    .autostring 34 2 "Hier sind Trainer, die einen Kampf wollen!"
str_not_ready:
    .autostring 34 2 "Hier scheint niemand zu sein, der schon bereit ist zu kämpfen."
.elseif LANG_EN
str_none_found:
    .autostring 34 2 "There doesn't seem to be anyone around who wants to battle."
str_rematches_found:
    .autostring 34 2 "There are trainers around who want to battle!"
str_not_ready:
    .autostring 34 2 "There doesn't seem to be anyone around who is ready to battle."
.endif