.include "overworld_script.s"
.include "callstds.s"

.global ow_script_haweiland_clouds_person_0
.global ow_script_haweiland_clouds_person_1

ow_script_haweiland_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_haweiland_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich frage mich ganz ehrlich, welche Katastrophe eine derartig riesige Welt in Schutt und Asche gelegt haben könnteDOTS"
str_1:
    .autostring 34 2 "Die eine Hälfte des Tages verbringe ich am Strand von Haweiland, die andere hier in der Luft.\pDas ist ein tolles Leben, oh ja!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "I really wonder what kind of catastrophy could have been able to completely destroy this gigantic realmDOTS"
str_1:
    .autostring 34 2 "One half of the day I am relaxing at the beach of Haweiland, the other one I spend up here.\pWhat a sweet life that is, oh yes!"
.endif
