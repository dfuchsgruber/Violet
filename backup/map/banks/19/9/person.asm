.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ceometria_clouds_person_0
.global ow_script_ceometria_clouds_person_1

ow_script_ceometria_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_ceometria_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Es braucht schon einen hartgesottenes Wesen, über der Geisterstadt Ceometria zu schwebenDOTS"
str_1:
    .autostring 34 2 "Selbst die Wolken werden dunkel, wenn sie sich in der Nähe des Waldfriedhofs aufhalten.\pIst das nicht seltsam?"
.elseif LANG_EN
str_0:
    .autostring 34 2 "It really needs a tough nature to levitate above the ghost town Ceometria."
str_1:
    .autostring 34 2 "Even the clouds get darker when they are near the Forest Cemetery.\pIsn't that curious?"
.endif
