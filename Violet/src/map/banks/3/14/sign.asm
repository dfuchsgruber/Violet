.include "overworld_script.s"
.include "callstds.s"

.global ow_script_forest_cemetery_sign_teahs_house

ow_script_forest_cemetery_sign_teahs_house:
    loadpointer 0 str_teahs_house
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_teahs_house:
    .string "Teahs Haus"
.elseif LANG_EN
    .string "Teah's House"
.endif