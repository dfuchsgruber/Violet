.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_9_horizontal_trainer_0
.global ow_script_route_9_horizontal_trainer_1
.global ow_script_route_9_horizontal_trainer_2
.global ow_script_route_9_horizontal_trainer_3
.global ow_script_route_9_horizontal_trainer_4
.global ow_script_route_9_horizontal_trainer_5
.global ow_script_route_9_horizontal_trainer_6

ow_script_route_9_horizontal_trainer_0:
    trainerbattlestd 0 0xd1 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

ow_script_route_9_horizontal_trainer_1:
    trainerbattlestd 0 0xd2 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end

ow_script_route_9_horizontal_trainer_2:
    trainerbattlestd 0 0xd3 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_defeat
    callstd MSG_FACE
    end

ow_script_route_9_horizontal_trainer_3:
    trainerbattlestd 0 0xd4 0 str_trainer3_challange str_trainer3_defeat
    loadpointer 0 str_trainer3_defeat
    callstd MSG_FACE
    end

ow_script_route_9_horizontal_trainer_4:
    trainerbattlestd 0 0xd5 0 str_trainer4_challange str_trainer4_defeat
    loadpointer 0 str_trainer4_defeat
    callstd MSG_FACE
    end

ow_script_route_9_horizontal_trainer_5:
    trainerbattlestd 0 0xd6 0 str_trainer5_challange str_trainer5_defeat
    loadpointer 0 str_trainer5_defeat
    callstd MSG_FACE
    end

ow_script_route_9_horizontal_trainer_6:
    trainerbattlestd 0 0xd7 0 str_trainer6_challange str_trainer6_defeat
    loadpointer 0 str_trainer6_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Manchmal, wenn ich zuweit hinaus schwimme, sehe ich eine Höhle.\pSie macht mir AngstDOTS"
str_trainer0_defeat:
    .autostring 34 2 "Halte dich lieber nah am Ufer.\pIrgendetwas ist hier in der GegendDOTS"
str_trainer1_challange:
    .autostring 34 2 "In der Nähe von Aktania beißen die Pokémon sehr schlecht.\pEs ist wirklich eine Tragödie, was dort vorgefallen ist."
str_trainer1_defeat:
    .autostring 34 2 "Ich kannte Lesters Vater.\pEr ist bei dem Unglück damals ums Leben gekommenDOTS"
str_trainer2_challange:
    .autostring 34 2 "Hast du schon von Blackbeard gehört?\pEr ist ein berüchtigter Pirat, der Pokémon stiehlt und auf dem Schwarzmarkt verkauft."
str_trainer2_defeat:
    .autostring 34 2 "Ich habe einmal sogar Blackbeards Schiff aus der Ferne gesehen.\pBeängstigendDOTS"
str_trainer3_challange:
    .autostring 34 2 "Ständig wird man von Quabbel gestochen.\pDas Meer ist kein Spielplatz!"
str_trainer3_defeat:
    .autostring 34 2 "Vielleicht gehe ich besser zurück ins Schwimmbad."
str_trainer4_challange:
    .autostring 34 2 "Hast du dich schon einmal gefragt, wo wir Schwimmer unsere Pokébälle aufbewahren?"
str_trainer4_defeat:
    .autostring 34 2 "Wo würdest du sie denn aufbewahren?"
str_trainer5_challange:
    .autostring 34 2 "Ich will nicht angeben, aber viele sagen, ich sei die beste Schwimmerin der Region!"
str_trainer5_defeat:
    .autostring 34 2 "Urgh!\nIch glaube, ich habe einen KrampfDOTS"
str_trainer6_challange:
    .autostring 34 2 "Zwischen Schwimmern und Anglern herrscht seit jeher eine Rivalität.\pAuch wenn es außer Frage steht, dass der Schwimmer der überlegene Trainer ist!"
str_trainer6_defeat:
    .autostring 34 2 "Eine Niederlage muss man akzeptieren, solange sie einem nicht von einem Angler beigebracht wurde!"

.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "Sometimes, when I swim out too far, I see a cave in the distant.\pIt somehow scares meDOTS"
str_trainer0_defeat:
    .autostring 34 2 "Stay close to the shore.\pSomething is nearbyDOTS"
str_trainer1_challange:
    .autostring 34 2 "Nearby Aktania the Pokémon don't bite well at all.\pIt really is a tragedy what happend there."
str_trainer1_defeat:
    .autostring 34 2 "I knew Lester's father.\pHe lost his live during the catastrophy back then."
str_trainer2_challange:
    .autostring 34 2 "Ever heard of Blackbeard?\pHe is a well-known pirate that steals Pokémon to sell them on the black market."
str_trainer2_defeat:
    .autostring 34 2 "Once I spotted Blackbards ship from the distant.\pTerrifyingDOTS"
str_trainer3_challange:
    .autostring 34 2 "All the time I am stung by some Frillish.\pThe sea is no playground!"
str_trainer3_defeat:
    .autostring 34 2 "Maybe I should return to the swimming pool."
str_trainer4_challange:
    .autostring 34 2 "Did you ever ask where we swimmers put our Pokéballs?"
str_trainer4_defeat:
    .autostring 34 2 "Well, where would you put them?"
str_trainer5_challange:
    .autostring 34 2 "I really don't want to boast, but people call me the best swimmer in the region!"
str_trainer5_defeat:
    .autostring 34 2 "Urgh!\nIch believe I have a crampDOTS"
str_trainer6_challange:
    .autostring 34 2 "Since long ago there has been a rivalry between swimmers and fishers.\pEven though its clear that swimmers are the superior trainers!"
str_trainer6_defeat:
    .autostring 34 2 "One has to accept a defeat as long as it was not by a fisher!"
.endif