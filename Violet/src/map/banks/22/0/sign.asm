.include "overworld_script.s"
.include "callstds.s"

.global ow_script_tafelberg_clouds_west_sign_cryiptic_base

ow_script_tafelberg_clouds_west_sign_cryiptic_base:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hauptquartier der selbsternannten Kryptiker-Vereinigung"
.elseif LANG_EN
.endif