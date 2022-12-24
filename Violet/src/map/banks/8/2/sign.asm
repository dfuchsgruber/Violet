.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_kaskada_ruins_sign
.global ow_script_kaskada_ruins_sign_scripture

ow_script_kaskada_ruins_sign:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end
ow_script_kaskada_ruins_sign_scripture:
    loadpointer 0 str_ask_scripture
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL dont_show_scripture
    loadpointer 0 str_scripture
    callstd MSG_KEEPOPEN
dont_show_scripture:
    closeonkeypress
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "QUOTE_STARTDas Wissen, das die antike Zivilisation aufgebaut hatte, übersteigt jede Vorstellungskraft.\pWarum ist sie untergangen?QUOTE_END"
str_ask_scripture:
    .autostring 34 2 "Dort scheint ein Text in einer antiken Sprache eingraviert zu sein.\pMöchtest du den Text lesen?"
str_scripture:
    .autostring 24 2 "FONT_UNOWN"
.elseif LANG_EN
str_0:
    .autostring 34 2 "QUOTE_STARTThe knowledge that this ancient civilisation had built is beyond any belief.\pWhat caused it to perish?QUOTE_END"
.endif