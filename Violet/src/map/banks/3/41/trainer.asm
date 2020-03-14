.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_2_trainer_0


ow_script_route_2_trainer_0:
    trainerbattlestd 0x0 0x163 0x0 str_challange_0 str_defeat_0
    loadpointer 0x0 str_defeat_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_challange_0:
    .autostring 34 2 "Hörst du die Musik?\pDas ist dein Abgesang!"
str_defeat_0:
    .autostring 34 2 "Oh nein!\pIch kann die Musik nicht mehr hören!"
.elseif LANG_EN
str_challange_0:
    .autostring 34 2 "Can you hear this sound?\pThat is your Perish Song!"
str_defeat_0:
    .autostring 34 2 "Oh no!\nI can't hear the music anymore!"


.endif