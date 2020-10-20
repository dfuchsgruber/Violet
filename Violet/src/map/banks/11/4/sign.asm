.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_2_ruins_sign

ow_script_route_2_ruins_sign:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "QUOTE_STARTIch habe diese verlorene Welt über den Wolken wiederentdeckt.\pIch bin entschlossen, ihre Geheimnisse zu lüften.QUOTE_END"
.elseif LANG_EN
str_0:
    .autostring 34 2 "QUOTE_STARTI found this lost world above the clouds.\pI am determined to unravel its secrets.QUOTE_END"
.endif