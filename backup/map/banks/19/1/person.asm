.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ceometria_indoor_0_person_0
.global ow_script_ceometria_indoor_0_person_1
.global ow_script_ceometria_indoor_0_person_2

ow_script_ceometria_indoor_0_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_ceometria_indoor_0_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

ow_script_ceometria_indoor_0_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Die Königin der Nacht hätte es beinahe geschafft, die gesamte Welt zu unterwerfen.\pSie war die größte aller Hexen."
str_1:
    .autostring 34 2 "Ich kann dieses Gerede über die Königin der Nacht nicht mehr hören.\pHat meine Tochter auch noch etwas anderes im Kopf?"
str_2:
    .autostring 34 2 "Gibt es für einen Vater etwas enttäuschenderes, als wenn die eigene Tochter beschließt, zu einer Hexe zu werden?"

.elseif LANG_EN
str_0:
    .autostring 34 2 "The Queen of the Night almost managed to rule over the entire world.\pShe really was the greatest among all witches."
str_1:
    .autostring 34 2 "I can't stand this talk of the Queen of the Night anymore.\pDoes my daughter not have anything else to say?"
str_2:
    .autostring 34 2 "Is there anything more disappoiting for a father than seeing his own daughter become a witch?"
.endif