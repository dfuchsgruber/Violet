.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_5_trainer_0
.global ow_script_route_5_twins

ow_script_route_5_trainer_0:
    trainerbattlestd 0 0x16c 0 str_before0 str_after0
    loadpointer 0 str_after0
    callstd MSG_FACE
    end

ow_script_route_5_twins:
    trainerbattledouble 4 0x16d 0 str_before1 str_after1 str_cant_battle1
    loadpointer 0 str_after1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Mein Leben dreht sich nur um Pokémon!\pEinen Maniac wie mich kannst du gar nicht schlagen!"
str_after0:
    .autostring 34 2 "Wie konntest du mich besiegen?\pIch weiß doch alles über Pokémon!"
str_before1:
    .autostring 34 2 "Meine Schwester und ich können die Sätze derDOTS\pDOTSjeweils anderen beenden.\pOb uns dasDOTS\pDOTSim Kampf etwas nützt?"
str_after1:
    .autostring 34 2 "Wir habenDOTS\pDOTSverloren, Schwester!"
str_cant_battle1:
    .autostring 34 2 "Wir kämpfen nur zu zweit, musst du wissen!"

.elseif LANG_EN
.endif