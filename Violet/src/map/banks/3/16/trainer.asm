.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_12_trainer_5
.global ow_script_route_12_trainer_6
.global ow_script_route_12_trainer_7
.global ow_script_route_12_trainer_8
.global ow_script_route_12_trainer_9
.global ow_script_route_12_trainer_10
.global ow_script_route_12_trainer_11
.global ow_script_route_12_trainer_12
.global ow_script_route_12_trainer_13
.global ow_script_route_12_trainer_14
.global ow_script_route_12_trainer_15
.global ow_script_route_12_trainer_16
.global ow_script_route_12_trainer_17
.global ow_script_route_12_trainer_18
.global ow_script_route_12_trainer_19
.global ow_script_route_12_trainer_20

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
ow_script_route_12_trainer_10:
    trainerbattlestd 0 0x106 0 str_trainer5_challange str_trainer5_defeat
    loadpointer 0 str_trainer5_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_11:
    trainerbattlestd 0 0x107 0 str_trainer6_challange str_trainer6_defeat
    loadpointer 0 str_trainer6_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_12:
    trainerbattlestd 0 0x108 0 str_trainer7_challange str_trainer7_defeat
    loadpointer 0 str_trainer7_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_13:
    trainerbattlestd 0 0x109 0 str_trainer8_challange str_trainer8_defeat
    loadpointer 0 str_trainer8_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_14:
    trainerbattlestd 0 0x10a 0 str_trainer9_challange str_trainer9_defeat
    loadpointer 0 str_trainer9_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_15:
    trainerbattlestd 0 0x10b 0 str_trainer10_challange str_trainer10_defeat
    loadpointer 0 str_trainer10_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_16:
    trainerbattlestd 0 0x10c 0 str_trainer11_challange str_trainer11_defeat
    loadpointer 0 str_trainer11_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_17:
    trainerbattlestd 0 0x10d 0 str_trainer12_challange str_trainer12_defeat
    loadpointer 0 str_trainer12_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_18:
    trainerbattlestd 0 0x10e 0 str_trainer13_challange str_trainer13_defeat
    loadpointer 0 str_trainer13_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_19:
    trainerbattlestd 0 0x10f 0 str_trainer14_challange str_trainer14_defeat
    loadpointer 0 str_trainer14_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_20:
    trainerbattlestd 0 0x110 0 str_trainer15_challange str_trainer15_defeat
    loadpointer 0 str_trainer15_defeat
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
str_trainer5_challange:
    .autostring 34 2 "Ich frage mich, wie manche Schwimmer in eisigen Gewässern so lange trainieren können.\pFür mich wäre das nichts."
str_trainer5_defeat:
    .autostring 34 2 "Habe ich verloren, weil ich nur in warmen Gewässern trainiert habe?"
str_trainer6_challange:
    .autostring 34 2 "Für einen Matrosen kommt es in erster Linie darauf an, welchen Umfang der Oberarm besitzt."
str_trainer6_defeat:
    .autostring 34 2 "Du hast mich besiegt?\pMit so kümmerlichen Armen?"
str_trainer7_challange:
    .autostring 34 2 "Ich bin äußerst grazil im Wasser.\pMir macht keiner Konkurenz!"
str_trainer7_defeat:
    .autostring 34 2 "Du magst zwar besser kämpfen, aber meine Eleganz bleibt ungeschlagen."
str_trainer8_challange:
    .autostring 34 2 "Für den unwahrscheinlichen Fall einer Niederlage, werden mir meine Eltern einfach bessere Pokémon kaufen."
str_trainer8_defeat:
    .autostring 34 2 "Vati!\pDieses gemeine Kind hier hat mich besiegtDOTS"
str_trainer9_challange:
    .autostring 34 2 "Hui!\nIch liebe es im seichten Wasser zu planschen."
str_trainer9_defeat:
    .autostring 34 2 "Buh!\nWieso hast du mich besiegtDOTS"
str_trainer10_challange:
    .autostring 34 2 "Meine Haut wird ganz schrumpelig vom vielem SchwimmenDOTS"
str_trainer10_defeat:
    .autostring 34 2 "Ich sollte aus dem Wasser gehenDOTS"
str_trainer11_challange:
    .autostring 34 2 "Blackbeard und seine Bande machen diese Gegend oft unsicher.\pSie sind den Rangern wirklich ein Dorn im Auge!"
str_trainer11_defeat:
    .autostring 34 2 "Nimm dich in Acht, Piraten lauern überall in diesen Gewässern."
str_trainer12_challange:
    .autostring 34 2 "Hey, Finger weg von unserer Beute!"
str_trainer12_defeat:
    .autostring 34 2 "Du traust dich was, dich mit Blackbeard anzulegen!"
str_trainer13_challange:
    .autostring 34 2 "Hey du!\nWillst du mich etwa in meinem wohl verdienten Urlaub stören?"
str_trainer13_defeat:
    .autostring 34 2 "Ich finde einen Strandurlaub sowieso öde!"
str_trainer14_challange:
    .autostring 34 2 "Was denkst du, wie stark mein Rücken durch das ganze Schwimmen geworden ist?\pIch könnte einen ganzen Kontinent tragen!"
str_trainer14_defeat:
    .autostring 34 2 "Völlig unmöglich!\pWie konntest du mich trotz meines starken Rückens besiegen?"
str_trainer15_challange:
    .autostring 34 2 "Eines Tages werde ich der größte Wasser-Pokémon Trainer aller Zeiten sein!"
str_trainer15_defeat:
    .autostring 34 2 "Bis dahin muss ich wohl noch eine ganze Menge übenDOTS"

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
str_trainer5_challange:
    .autostring 34 2 "I wonder how some swimmers can train for hours in cold waters.\pThis wouldn't be for me!"
str_trainer5_defeat:
    .autostring 34 2 "Did I lose because I only trained in warm waters?"
str_trainer6_challange:
    .autostring 34 2 "For a sailor it is most important how large the cirumference of ones biceps is."
str_trainer6_defeat:
    .autostring 34 2 "You defeated me?\pWith those pityful arms?"
str_trainer7_challange:
    .autostring 34 2 "I am most gracile in the water.\pI am above all competetion."
str_trainer7_defeat:
    .autostring 34 2 "You may be better at fighting, but in the water my elegance is unmatched."
str_trainer8_challange:
    .autostring 34 2 "In the unlikely case of my defeat my parents will just buy me better pokémon."
str_trainer8_defeat:
    .autostring 34 2 "Daddy!\pThis mean child here defeated meDOTS"
str_trainer9_challange:
    .autostring 34 2 "Hu!\nI love playing in the shallow water!"
str_trainer9_defeat:
    .autostring 34 2 "Ba!\nWhy did you defeat meDOTS"
str_trainer10_challange:
    .autostring 34 2 "My skin gets so wrinkeled because of all the swimming."
str_trainer10_defeat:
    .autostring 34 2 "I should leave the waterDOTS"
str_trainer11_challange:
    .autostring 34 2 "Blackeard and his crew make these waters very unsafe.\pThey are a very big concern to us rangers."
str_trainer11_defeat:
    .autostring 34 2 "Be cautious, pirates lurk everyhwere in these waters."
str_trainer12_challange:
    .autostring 34 2 "Hey, don't touch my loot!"
str_trainer12_defeat:
    .autostring 34 2 "You have some nerves to pick a fight with Blackbeard."
str_trainer13_challange:
    .autostring 34 2 "You you!\nDo you want to bother me while being on my well earned vaccation?"
str_trainer13_defeat:
    .autostring 34 2 "A holiday at the beach is boring anyway!"
str_trainer14_challange:
    .autostring 34 2 "What do you think how strong my back has become because of all my swimming?\pI could carry an entire continent on it!"
str_trainer14_defeat:
    .autostring 34 2 "Impossible!\pHow could you defeat me even though my back is that strong?"
str_trainer15_challange:
    .autostring 34 2 "One day I will be the greatest water pokémon trainer of all times."
str_trainer15_defeat:
    .autostring 34 2 "Until then I guess I will have to practice a lot stillDOTS"

.endif