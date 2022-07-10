.include "overworld_script.s"
.include "callstds.s"

.global ow_script_kaskada_ruins_sign

ow_script_kaskada_ruins_sign:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "QUOTE_STARTDas Wissen, das die antike Zivilisation aufgebaut hatte, übersteigt jede Vorstellungskraft.\pWarum ist sie untergangen?QUOTE_END"
.elseif LANG_EN
str_0:
    .autostring 34 2 "QUOTE_STARTThe knowledge that this ancient civilisation had built is beyond any belief.\pWhat caused it to perish?QUOTE_END"
.endif