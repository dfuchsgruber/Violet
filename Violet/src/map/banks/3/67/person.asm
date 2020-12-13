.include "callstds.s"
.include "overworld_script.s"

.global ow_script_felsige_oednis_east_caves_person_0
.global ow_script_felsige_oednis_east_caves_person_1
.global ow_script_felsige_oednis_east_caves_person_2

ow_script_felsige_oednis_east_caves_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_felsige_oednis_east_caves_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_felsige_oednis_east_caves_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Die Wanderung von Kranzdorf nach Kaskada war sicherlich eine die anstrengendste Unternehmung meines Lebens.\pFinstere Höhlen, eine staubtrockene Wüste und jetzt muss ich auch nach all dem auch noch einen Berg erklimmenDOTS"
str_1:
    .autostring 34 2 "Der Tafelberg setzt sich aus verschiedensten Gesteinsschichten zusammen.\pDer See auf dem Plateau ist umgeben von bläulichen Felswänden.\pKein Wunder, dass man dort Kaskada errichtet hat."
str_2:
    .autostring 34 2 "Ich fühle mich in Höhlen wirklich unwohlDOTS\pAber ich versuche, meine Ängste zu bewältigen.\pAlso komme ich jeden Tag für ein paar Minuten hierher und stelle mich meinen Ängsten."
.elseif LANG_EN
.endif

