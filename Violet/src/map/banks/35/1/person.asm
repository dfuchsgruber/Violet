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
    .autostring 34 2 "Es war wirklich keine Idee, unserem Sohn dieses Menki zu schenken.\pJetzt toben die beiden den ganzen Tag im Haus herumDOTS"
str_1:
    .autostring 34 2 "Meine Frau ist manchmal eine echte Spaßbremse.\pJetzt hat sie etwas daran auszusetzten, dass unser Junge mit seinem Pokémon spielt.\pIch begreife das wirklich nichtDOTS"
str_2:
    .autostring 34 2 "Hui!\nHui! Juhu!\pDu kriegst mich nicht, Menki!"
.elseif LANG_EN
.endif