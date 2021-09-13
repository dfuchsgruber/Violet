.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_2_east_trainer_0
.global ow_script_route_2_east_trainer_1
.global ow_script_route_2_east_trainer_2


ow_script_route_2_east_trainer_0:
    trainerbattlestd 0x0 0x162 0x0 str_challange_0 str_defeat_0
    loadpointer 0x0 str_after_0
    callstd MSG_FACE
    end
ow_script_route_2_east_trainer_1:
    trainerbattlestd 0x0 0x1e9 0x0 str_challange_1 str_defeat_1
    loadpointer 0x0 str_after_1
    callstd MSG_FACE
    end
ow_script_route_2_east_trainer_2:
    trainerbattlestd 0x0 0x1ea 0x0 str_challange_2 str_defeat_2
    loadpointer 0x0 str_after_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_challange_0:
    .autostring 34 2 "Ich habe einige nette Käfer-Pokémon gefangen!\pGegen die kannst du gar nichts ausrichten!"
str_defeat_0:
    .autostring 34 2 "Meine armen Pokémon wurden von dir regelrecht zerquetschtDOTS"
str_after_0:
    .autostring 34 2 "Wie kannst du es wagen?\pDu hast meine armen Käfer-Pokémon einfach so zerquetscht.\pWas fällt dir ein?"
str_challange_1:
    .autostring 34 2 "Sieh mal, ich kann im Sand meine Fußspuren sehen!"
str_defeat_1:
    .autostring 34 2 "Oh, war ich etwa zu abgelenkt?"
str_after_1:
    .autostring 34 2 "Ich habe mich wohl zu sehr auf meine Fußspuren konzentriert.\pWie gemein, dass ich deswegen gleich einen Kampf verliere."
str_challange_2:
    .autostring 34 2 "Eigentlich ist es recht entspannend, aufs Meer hinauszublicken.\pAber ein wenig Abwechslung kann nicht schaden!"
str_defeat_2:
    .autostring 34 2 "Das war wirklich abwechslungsreich."
str_after_2:
    .autostring 34 2 "Du hast mich ehrlich geschlagen.\pAber im Angeln machst du mir so schnell keine Konkurrenz."
.elseif LANG_EN
str_challange_0:
    .autostring 34 2 "I caught some nice Bug-Type Pokémon!\pYou won't be able to do anything against them!"
str_defeat_0:
    .autostring 34 2 "My poor Pokémon have been crushedDOTS"


.endif