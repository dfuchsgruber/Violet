.include "callstds.s"
.include "overworld_script.s"

.global ow_script_tafelberg_sign_0

ow_script_tafelberg_sign_0:
    loadpointer 0x0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "UP_ARROW Tafelberg\nUP_ARROW Kaskada"

.elseif LANG_EN
str_0:
    .autostring 34 2 "UP_ARROW Tafelberg\nUP_ARROW Kaskada"
.endif