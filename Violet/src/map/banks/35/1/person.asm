.include "overworld_script.s"
.include "callstds.s"

.global ow_script_sonnaufeld_inside_0_person_0
.global ow_script_sonnaufeld_inside_0_person_1
.global ow_script_sonnaufeld_inside_0_person_2

ow_script_sonnaufeld_inside_0_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_sonnaufeld_inside_0_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_sonnaufeld_inside_0_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Es war wirklich keine tolle Idee, unserem Sohn dieses Menki zu schenken.\pJetzt toben die beiden den ganzen Tag im Haus herum und machen alles schmutzig!"
str_1:
    .autostring 34 2 "Meine Frau ist Floristin und bringt oft Sonnenblumen mit nach Hause.\pManchmal macht sie sich sogar auf den weiten Weg nach Kranzdorf, um sie dort gegen ein paar Beeren oder Mulch einzutauschen."
str_2:
    .autostring 34 2 "Hui!\nHui! Juhu!\pDu kriegst mich nicht, Menki!"
.elseif LANG_EN
.endif