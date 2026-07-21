.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_route_2_ruins_sign
.global ow_script_route_2_ruins_sign_scripture

ow_script_route_2_ruins_sign:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end
ow_script_route_2_ruins_sign_scripture:
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
    .autostring 34 2 "QUOTE_STARTIch habe diese verlorene Welt über den Wolken wiederentdeckt.\pIch bin entschlossen, ihre Geheimnisse zu lüften.QUOTE_END"
str_ask_scripture:
    .autostring 34 2 "Dort scheint ein Text in einer antiken Sprache eingraviert zu sein.\pMöchtest du den Text lesen?"
str_scripture:
    .autostring 24 2 "FONT_UNOWNHEIL DER GROSSEN DUNKLEN KOENIGIN.\pNAH IST DER TAG DER BEFREIUNG UNSERES VOLKES.\pNICHT EINMAL DIE GOETTER DIESER WELT VERMOEGEN NUN MEHR UNS ZU BINDEN.\pHEIL DIR, DUNKLE KOENIGIN."
.elseif LANG_EN
str_0:
    .autostring 34 2 "QUOTE_STARTI found this lost world above the clouds.\pI am determined to unravel its secrets.QUOTE_END"
str_ask_scripture:
    .autostring 34 2 "There seems to be a text engraved in an ancient language.\pDo you want to read the text?"
str_scripture:
    .autostring 24 2 "FONT_UNOWNHAIL THE GREAT DARK QUEEN.\pNEAR IS THE DAY OF LIBERATION OF OUR PEOPLE.\pNOT EVEN THE GODS OF THIS WORLD CAN BIND US ANYMORE.\pHAIL TO YOU, DARK QUEEN."
.endif