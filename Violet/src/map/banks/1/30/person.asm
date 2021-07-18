.include "callstds.s"
.include "overworld_script.s"

.global ow_script_aschhain_person_0
.global ow_script_aschhain_person_1
.global ow_script_aschhain_person_2

ow_script_aschhain_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_aschhain_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_aschhain_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "In diesem Haus lebt ein berühmter Glasbläser.\pEr kann aus Asche Flöten herstellen."
str_1:
    .autostring 34 2 "Bei dieser Hitze muss man in meinem Alter schon aufpassenDOTS\pSonst kriegt man noch einen HitzekollerDOTS"
str_2:
    .autostring 34 2 "Soll ich dir ein Geheimnis über den Aschhain verraten?\pManchmal sehe ich hier ein großes Vogel-Pokémon am Himmel.\pAber es scheint sehr scheu zu seinDOTS"
.elseif LANG_EN
.endif
