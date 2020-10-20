.include "overworld_script.s"
.include "callstds.s"

.global ow_script_orina_city_ruins_sign

ow_script_orina_city_ruins_sign:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "QUOTE_STARTEinst regierte eine mächtige Königin dieses Reich.\pIhr Hochmut sollte dessen Untergang einläuten.QUOTE_END"
.elseif LANG_EN
str_0:
    .autostring 34 2 "QUOTE_STARTOnce a powerful queen ruled this kingdom.\pHer arrogance should be the beginning of its downfall.QUOTE_END"
.endif