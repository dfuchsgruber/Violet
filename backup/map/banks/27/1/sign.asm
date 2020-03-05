.include "overworld_script.s"
.include "callstds.s"

.global ow_script_haweiland_ruins_sign

ow_script_haweiland_ruins_sign:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "QUOTE_STARTDer Untergang des Reiches über den Wolken war eine Bestrafung der Götter.QUOTE_END"
.elseif LANG_EN
str_0:
    .autostring 34 2 "QUOTE_STARTThe downfall of the realm above the clouds was a divine punishment.QUOTE_END"
.endif