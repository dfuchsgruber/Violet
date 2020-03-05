.include "overworld_script.s"
.include "callstds.s"

.global ow_script_kaskada_clouds_person_0
.global ow_script_kaskada_clouds_person_1

ow_script_kaskada_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_kaskada_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Viele Menschen wissen nicht, dass ein erheblicher Teil des Wassers in Kaskada aus den Wolken fällt.\pIst das nicht interessant?"
str_1:
    .autostring 34 2 "Wegen der trockenen Bedingungen in der Felsigen Ödnis, gibt es dort wenig Wolken.\pDaher haben die Menschen hier einst eine riesige Brücke errichtet."
.elseif LANG_EN
str_0:
    .autostring 34 2 "Many people don't know that a significant part of the water in Cascada falls down from the clouds.\pIsn't that interesting?"
str_1:
    .autostring 34 2 "Because of the arrid conditions in the Rocky Desolation there are not many clouds.\pTherefore, people once built a giant bridge."
.endif