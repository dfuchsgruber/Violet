.include "overworld_script.s"
.include "callstds.s"

.global ow_script_sonnaufeld_inside_1_person_0
.global ow_script_sonnaufeld_inside_1_person_1
.global ow_script_sonnaufeld_inside_1_person_2

ow_script_sonnaufeld_inside_1_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_sonnaufeld_inside_1_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_sonnaufeld_inside_1_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich will jetzt Fernsehen schauen!\pJetzt sofort!\pIchDOTS\nWillDOTS\lFernsehen schauen!"
str_1:
    .autostring 34 2 "Meine Enkelin ist wirklich schrecklichDOTS\pWas wohl einmal aus ihr werden soll?"
str_2:
    .autostring 34 2 "Diese ganze Familie ist wirklich verkorkst.\pKein Wunder, dass mein Vater sich schon vor Jahren aus dem Staub gemacht hat.\pJetzt muss Mami jeden Tag sehr lange im Kraftwerk von Orina City arbeitenDOTS"
.elseif LANG_EN
.endif