.include "overworld_script.s"
.include "callstds.s"

.global ow_script_laubdorf_indoor_0_person_0
.global ow_script_laubdorf_indoor_0_person_1

ow_script_laubdorf_indoor_0_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_laubdorf_indoor_0_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Findest du nicht, dass die Welt aus den Fugen geraten ist?\pDiese Revolutionäre bringen nichts als UnruheDOTS"
str_1:
    .autostring 34 2 "Ich habe meine Pokémon in die Pension gegeben.\pDort haben sie sogar neue Attacken gelernt."
.elseif LANG_EN
str_0:
    .autostring 34 2 "Don't you find the world has gone mad?\nThese revolutionaries only bring chaosDOTS"
str_1:
    .autostring 34 2 "I brought my Pokémon into the daycare.\pThey even learned new moves there."
.endif