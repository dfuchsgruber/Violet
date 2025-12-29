.include "overworld_script.s"
.include "callstds.s"

.global ow_script_sonnaufeld_inside_1_person_0
.global ow_script_sonnaufeld_inside_1_person_1
.global ow_script_sonnaufeld_inside_1_person_2
.global ow_script_sonnaufeld_inside_1_person_3
.global ow_script_sonnaufeld_inside_1_person_4

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
ow_script_sonnaufeld_inside_1_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_sonnaufeld_inside_1_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich übe jeden Tag hier!\pIrgendwann laufe ich über den ganzen Tafelberg!"
str_1:
    .autostring 34 2 "Ach, wie schön!\pMeine Enkelin kommt ganz nach mirDOTS\pIn jungen Jahren habe ich alle Berge der Region erklommen.\pHeute bin ich froh, es bis nach Blütenbach zu schaffen."
str_2:
    .autostring 34 2 "Ich habe jedes von Professor Tanns Büchern gelesen.\pWie er die Geschichte Thetos aufarbeitetDOTS\pUnd seine Funde bezüglich der antiken Zivilisation hier sind einfach unglaublich, findest du nicht?"
str_3:
    .autostring 34 2 "Wenn man an der Küste in Sonnaufeld nachts lang genug gen Süden sieht, flackern seltsame Lichter in der Ferne auf.\pOb das Geist Pokémon aus Ceometria sind?"
str_4:
    .autostring 34 2 "Am Strand hier kann man super Muscheln sammeln.\pManchmal finde ich sogar funkelnde Perlen und schimmernde Schuppen im Sand!"
.elseif LANG_EN
.endif