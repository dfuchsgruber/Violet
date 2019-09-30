.include "overworld_script.s"
.include "callstds.s"

.global ow_script_feslige_oednis_clouds_person_0
.global ow_script_feslige_oednis_clouds_person_1

ow_script_feslige_oednis_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_feslige_oednis_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Wenn du von hier auf den Boden siehst, kannst du wegen der heftigen Sandstürme rein gar nichts erkennenDOTS"
str_1:
    .autostring 34 2 "Diese riesige Brücke wurde erbaut, weil es in dieser trockenen Gegend so selten Wolken hat."

.elseif LANG_EN
str_0:
    .autostring 34 2 "If you try to look to the ground from up here you won't see a thing because of the heavy sandstormsDOTS"
str_1:
    .autostring 34 2 "This giant bridge was built because in this arrid area there are scarcely any clouds."

.endif