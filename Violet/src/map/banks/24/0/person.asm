.include "overworld_script.s"
.include "callstds.s"

.global ow_script_kuestenberg_clouds_person_0
.global ow_script_kuestenberg_clouds_person_1

ow_script_kuestenberg_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_kuestenberg_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ach, die Seeluft über dem Küstenberg ist wirklich unvergleichlich.\pAm liebsten würde ich mir hier ein Haus bauen."
str_1:
    .autostring 34 2 "Hast du schonmal von der versunkenen Stadt gehört?\pEs heißt, dass sie einst als Brücke zur Welt über den Wolken gedient haben soll."
.elseif LANG_EN
str_0:
    .autostring 34 2 "Ah, the salty air above the Shore Hill really is unique.\pIf I could I would build myself a house up here."
str_1:
    .autostring 34 2 "Did you ever hear about the sunken city?\pIt is said that it once served as bridge to the world above the clouds."
.endif
