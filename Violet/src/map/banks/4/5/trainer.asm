.include "overworld_script.s"
.include "callstds.s"

.global ow_script_anemonia_clouds_trainer_0

ow_script_anemonia_clouds_trainer_0:
    trainerbattlestd 0 0x1d5 0 str_before_0 str_after_0
    loadpointer 0 str_later_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Ich habe den großen Traum, alle Ruinen der antiken Zivilisation über den Wolken zu erkunden.\pDabei macht mir keinen einen Strich durch die Rechnung."
str_after_0:
    .autostring 34 2 "Mein TraumDOTS\pWillst du ihn mir etwa zerstören?"
str_later_0:
    .autostring 34 2 "Hier oben über Anemonia findet man sowieso keine interessanten Ruinen oder etwas vergleichbaresDOTS"
.elseif LANG_EN
.endif
