.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_9_trainer_0
.global ow_script_route_9_trainer_1
.global ow_script_route_9_trainer_2
.global ow_script_route_9_trainer_3
.global ow_script_route_9_trainer_4
.global ow_script_route_9_trainer_5
.global ow_script_route_9_trainer_6
.global ow_script_route_9_trainer_7
.global ow_script_route_9_trainer_8

ow_script_route_9_trainer_0:
    trainerbattlestd 0 0xcA 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

ow_script_route_9_trainer_1:
    trainerbattlestd 0 0xcb 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end

ow_script_route_9_trainer_2:
    trainerbattlestd 0 0xcc 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_defeat
    callstd MSG_FACE
    end

ow_script_route_9_trainer_3:
    trainerbattlestd 0 0xcd 0 str_trainer3_challange str_trainer3_defeat
    loadpointer 0 str_trainer3_defeat
    callstd MSG_FACE
    end

ow_script_route_9_trainer_4:
    trainerbattlestd 0 0xce 0 str_trainer4_challange str_trainer4_defeat
    loadpointer 0 str_trainer4_defeat
    callstd MSG_FACE
    end
    
ow_script_route_9_trainer_5:
    trainerbattlestd 0 0xcf 0 str_trainer5_challange str_trainer5_defeat
    loadpointer 0 str_trainer5_defeat
    callstd MSG_FACE
    end
    
ow_script_route_9_trainer_6:
    trainerbattlestd 0 0xd0 0 str_trainer6_challange str_trainer6_defeat
    loadpointer 0 str_trainer6_defeat
    callstd MSG_FACE
    end
ow_script_route_9_trainer_7:
    trainerbattlestd 0 0x174 0 str_trainer7_challange str_trainer7_defeat
    loadpointer 0 str_trainer7_defeat
    callstd MSG_FACE
    end
ow_script_route_9_trainer_8:
    trainerbattlestd 0 0x175 0 str_trainer8_challange str_trainer8_defeat
    loadpointer 0 str_trainer8_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Bei dem ganzen Schwimmen muss ich mir um meine Bikini-Figur keine Sorgen machen."
str_trainer0_defeat:
    .autostring 34 2 "Du bist vielleicht im Kämpfen besser, aber meinen Beinschlag macht mir niemand nach."
str_trainer1_challange:
    .autostring 34 2 "Ich habe mich zuweit aufs Meer gewagt.\pZum Glück habe ich diese kleine Insel hier gefundenDOTS"
str_trainer1_defeat:
    .autostring 34 2 "Wie soll ich zurück an Land kommen?\pIch kann doch nicht einmal schwimmenDOTS"
str_trainer2_challange:
    .autostring 34 2 "Auf dem Ozeanen trifft man die interessantesten Menschen.\pVon welchem Schlag bist du?"
str_trainer2_defeat:
    .autostring 34 2 "Urgh!\nDu bist wirklich stark!"
str_trainer3_challange:
    .autostring 34 2 "Als Kind habe ich unglaublich gerne nach Perlu getaucht!"
str_trainer3_defeat:
    .autostring 34 2 "Perlu kann sich in zwei verschiedene Pokémon entwickeln."
str_trainer4_challange:
    .autostring 34 2 "Es gibts nicht Friedlicheres, als im Sonnenuntergang seine Bahnen zu ziehenDOTS\pFindest du nicht auch?"
str_trainer4_defeat:
    .autostring 34 2 "Du bist kein Schwimmer, du kannst das nicht nachvollziehenDOTS"
str_trainer5_challange:
    .autostring 34 2 "Jeden Morgen schwimme ich fünfzehn Kilometer, laufe fünfzig und dann steige ich aufs Rad!"
str_trainer5_defeat:
    .autostring 34 2 "Wie konntest du mich trotz meiner beeindruckenden Trainigsroutine besiegen?"
str_trainer6_challange:
    .autostring 34 2 "Im Herzen bin ich ein Wasser-Pokémon.\pIch würde alles dafür geben, einmal den Grund der Meere zu sehen!"
str_trainer6_defeat:
    .autostring 34 2 "Denkst du nicht, dass der Meeresgrund faszinierend ist?"
str_trainer7_challange:
    .autostring 34 2 "Ich bin die beste Schwimmerin der Welt.\pDu glaubst mir nicht?\nWarte ab!"
str_trainer7_defeat:
    .autostring 34 2 "Du bist kein Schwimmer!\pAlso kannst du mir den Titel der besten Schwimmerin auch nicht streitig machen!"
str_trainer8_challange:
    .autostring 34 2 "Warum ich Schwimmer geworden bin?\pSicherlich nicht wegen der schönen Schwimmerinen!"
str_trainer8_defeat:
    .autostring 34 2 "UffDOTS\nWelche Schwimmerin findet den einen Verlierer gut?"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "After all this swimming I don't have to worry about my summer body."
str_trainer0_defeat:
    .autostring 34 2 "You might be better when it comes to battling, but my leg technique is unmatched."
str_trainer1_challange:
    .autostring 34 2 "I went out too far.\nLuckily I found this little island hereDOTS"
str_trainer1_defeat:
    .autostring 34 2 "How can I go back to land?\pI can't even swim properlyDOTS"
str_trainer2_challange:
    .autostring 34 2 "Out here on the oceans one meets the most interesting people.\pWhich type of person are you?"
str_trainer2_defeat:
    .autostring 34 2 "Urgh!\nYou're really strong!"
str_trainer3_challange:
    .autostring 34 2 "As child I loved diving and looking for Clamperl."
str_trainer3_defeat:
    .autostring 34 2 "Clamperl evolves into two different Pokémon."
str_trainer4_challange:
    .autostring 34 2 "There is nothing more peaceful than swiming ones length in the sunsetDOTS\pAm I right?"
str_trainer4_defeat:
    .autostring 34 2 "You are not a swimmer, you wouldn't possibly understandDOTS"
str_trainer5_challange:
    .autostring 34 2 "Every morning I swim fifteen kilometers, run another fifty and then I mount my bicycle!"
str_trainer5_defeat:
    .autostring 34 2 "How could you defeat me regardless of my impressive training routine?"
str_trainer6_challange:
    .autostring 34 2 "In my very heart I am a water Pokémon.\pWouldn't it be fascinating to get a glimpse at the bottom of the sea?"
str_trainer6_defeat:
    .autostring 34 2 "Don't you find the bottom of the sea appealing?"

.endif