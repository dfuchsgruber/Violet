.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_12_trainer_5
.global ow_script_route_12_trainer_6
.global ow_script_route_12_trainer_7
.global ow_script_route_12_trainer_8

ow_script_route_12_trainer_5:
    trainerbattlestd 0 0x101 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_6:
    trainerbattlestd 0 0x102 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_7:
    trainerbattlestd 0 0x103 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_8:
    trainerbattlestd 0 0x104 0 str_trainer3_challange str_trainer3_defeat
    loadpointer 0 str_trainer3_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_9:
    trainerbattlestd 0 0x105 0 str_trainer4_challange str_trainer4_defeat
    loadpointer 0 str_trainer4_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Meine Arme tun vom ganzen Schwimmen weh.\pEin Kampf wird meine Muskeln auflockern."
str_trainer0_defeat:
    .autostring 34 2 "Zumindest meine Arme fühlen sich besser an."
str_trainer1_challange:
    .autostring 34 2 "Schiffe und Schwimmer stehen seit Jahren auf Kriegsfuß.\pDabei sind die Schiffe eindeutig im Unrecht!"
str_trainer1_defeat:
    .autostring 34 2 "Denkst du etwa, dass wir Schwimmer den Schiffen ein Hindernis sind?"
str_trainer2_challange:
    .autostring 34 2 "Mein Pokémon und ich trainieren seit Jahren auf der See!\pMal sehen, ob du unserer Wellenkraft gewachsen bist!"
str_trainer2_defeat:
    .autostring 34 2 "Du warst wie ein Fels in unserer BrandungDOTS"
str_trainer3_challange:
    .autostring 34 2 "Die Luft hier ist viel zu feucht, um beim Angeln Spaß zu haben.\pWie wäre es mit einem Kampf stattdessen?"
str_trainer3_defeat:
    .autostring 34 2 "UffDOTS\nIch bin geschafftDOTS"
str_trainer4_challange:
    .autostring 34 2 "Die Seeluft bekommt meinen Flug-Pokémon nicht gutDOTS"
str_trainer4_defeat:
    .autostring 34 2 "UffDOTS\nKönnen Vögel seekrank werden?"

.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "Because of all this swimming my arms are aching.\pA battle will rest them well."
str_trainer0_defeat:
    .autostring 34 2 "At least my arms don't hurt any more."
str_trainer1_challange:
    .autostring 34 2 "Ships and swimmers have been in opposition for years.\pEven though swimmers obviously are right!"
str_trainer1_defeat:
    .autostring 34 2 "Do you think that swimmers are in the way of ships?"
str_trainer2_challange:
    .autostring 34 2 "My pokémon and me have been training out here in the sea for years.\pLet's see if you are grown to face our wave power!"
str_trainer2_defeat:
    .autostring 34 2 "You have been like a rock!"
str_trainer3_challange:
    .autostring 34 2 "The air here is way to moist to have any fun fishing.\pHow about a battle instead?"
str_trainer3_defeat:
    .autostring 34 2 "UffDOTS\nI am doneDOTS"
str_trainer4_challange:
    .autostring 34 2 "The air arround the sea is no good for my flying pokémon."
str_trainer4_defeat:
    .autostring 34 2 "UffDOTS\nCan birds get seasick?"

.endif