.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_6_trainer_0
.global ow_script_route_6_couple

ow_script_route_6_trainer_0:
    trainerbattlestd 0 0x16e 0 str_before0 str_after0
    loadpointer 0 str_after0
    callstd MSG_FACE
    end

ow_script_route_6_couple:
    trainerbattledouble 4 0x16f 0 str_before1 str_after1 str_cant_battle1
    loadpointer 0 str_after1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Kampfsport in dieser Hitze fordert den Körper!\pIch bin wie im Fieber!"
str_after0:
    .autostring 34 2 "UffDOTS\pVielleicht brauche ich erst einmal etwas kühles WasserDOTS"
str_before1:
    .autostring 34 2 "Wollen wir gegen diesen Trainer kämpfen, Schatzi?\pNatürlich fordern wir dich heraus!"
str_after1:
    .autostring 34 2 "Wie, Schatzi?\pHaben wir etwa verloren?"
str_cant_battle1:
    .autostring 34 2 "Schatzi und ich kämpfen nur im Doppel!\pWenn du mit uns kämpfen willst, brauchst du zwei kampffähige Pokémon!"

.elseif LANG_EN
.endif