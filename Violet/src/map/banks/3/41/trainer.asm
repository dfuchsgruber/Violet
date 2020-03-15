.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_2_trainer_0
.global ow_script_route_2_trainer_1
.global ow_script_route_2_trainer_2


ow_script_route_2_trainer_0:
    trainerbattlestd 0x0 0x163 0x0 str_challange_0 str_defeat_0
    loadpointer 0x0 str_defeat_0
    callstd MSG_FACE
    end
    
ow_script_route_2_trainer_1:
    trainerbattlestd 0x0 0x166 0x0 str_challange_1 str_defeat_1
    loadpointer 0x0 str_defeat_1
    callstd MSG_FACE
    end

ow_script_route_2_trainer_2:
    trainerbattledouble 0x4 0x165 0 str_challange_2 str_defeat_2 trainer_2_one_poke
    loadpointer 0x0 str_defeat_2
    callstd MSG_FACE
    end
trainer_2_one_poke:
    loadpointer 0 str_one_poke_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_challange_0:
    .autostring 34 2 "Hörst du die Musik?\pDas ist dein Abgesang!"
str_defeat_0:
    .autostring 34 2 "Oh nein!\pIch kann die Musik nicht mehr hören!"
str_challange_1:
    .autostring 34 2 "Ich werde eines Tages der größte Trainer aller Zeiten sein!"
str_defeat_1:
    .autostring 34 2 "Von dieser Niederlage wirst du aber keinem erzählen, oder?"
str_challange_2:
    .autostring 34 2 "Meine Schwester und ich sind Zwillinge!\pWir kämpfen zusammen gegen dich!"
str_defeat_2:
    .autostring 34 2 "Wir haben sogar zusammen gegen dich verloren?"
str_one_poke_2:
    .autostring 34 2 "Meine Schwester und ich kämpfen nur als Team.\pWenn du gegen uns kämpfen willst, brauchst du schon zwei kampfbereite Pokémon."
.elseif LANG_EN
str_challange_0:
    .autostring 34 2 "Can you hear this sound?\pThat is your Perish Song!"
str_defeat_0:
    .autostring 34 2 "Oh no!\nI can't hear the music anymore!"
str_challange_1:
    .autostring 34 2 "One day I will be the greatest trainer of them all!"
str_defeat_1:
    .autostring 34 2 "You won't tell anybody about this, will you?"
str_challange_2:
    .autostring 34 2 "My sister and I are twins!\pWe will battle you together!"
str_defeat_2:
    .autostring 34 2 "Even the two of us have lost to you?"
str_one_poke_2:
    .autostring 34 2 "My sister and I only battle as a team.\pIf you want to challange us, you need two Pokémon ready for battle."


.endif