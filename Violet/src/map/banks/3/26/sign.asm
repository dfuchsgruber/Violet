.include "overworld_script.s"
.include "callstds.s"

.global ow_script_desert_village_sign
.global ow_script_desert_village_sign_1

ow_script_desert_village_sign:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end
ow_script_desert_village_sign_1:
    loadpointer 0 str_1
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Basis Trockentag\pRaststation für ausgetrocknete Trainer"
str_1:
    .autostring 34 2 "UP_ARROW Felsige Ödnis"
.elseif LANG_EN
.endif