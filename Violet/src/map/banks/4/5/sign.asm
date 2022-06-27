.include "overworld_script.s"
.include "callstds.s"

.global ow_script_amonia_clouds_sign_0

ow_script_amonia_clouds_sign_0:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Die Schrift ist verwittert und wirkt fremdDOTS"
.elseif LANG_EN
.endif