.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_7_3_person_1
.global ow_script_map_7_3_person_2

ow_script_map_7_3_person_1:
    loadpointer 0x0 str_0x194666
    callstd MSG_FACE
    end

ow_script_map_7_3_person_2:
    loadpointer 0x0 str_0x81c244
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0x194666:
    .autostring 34 2 "Es ist erstaunlich, was manche Leute wegwerfen!\pIch habe schon das ein oder andere Mal etwas im Müll gefunden, das sich als äußerst nützlich erwiesen hat."
str_0x81c244:
    .autostring 34 2 "Der Kranzwald gilt als der älteste Wald der Region.\pIch habe einmal gehört, dass die Leute das Funkeln der Steine als den Atem der Zeit bezeichnet haben."
.elseif LANG_EN

.endif


