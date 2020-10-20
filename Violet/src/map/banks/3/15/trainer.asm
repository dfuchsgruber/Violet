.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_12_trainer_0
.global ow_script_route_12_trainer_1
.global ow_script_route_12_trainer_2
.global ow_script_route_12_trainer_3
.global ow_script_route_12_trainer_4

ow_script_route_12_trainer_0:
    trainerbattlestd 0 0xfc 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_1:
    trainerbattlestd 0 0xfd 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_2:
    trainerbattlestd 0 0xfe 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_3:
    trainerbattlestd 0 0xff 0 str_trainer3_challange str_trainer3_defeat
    loadpointer 0 str_trainer3_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_4:
    trainerbattlestd 0 0x100 0 str_trainer4_challange str_trainer4_defeat
    loadpointer 0 str_trainer4_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "In meinem Herzen schlummert eine unendliche DunkelheitDOTS\pDOTSsie wird dich verschlingen!"
str_trainer0_defeat:
    .autostring 34 2 "Du warst im Stande die Dunkelheit in meinem Herzen zu besiegenDOTS"
str_trainer1_challange:
    .autostring 34 2 "Die Revolutionsbewegung sammelt ihre Kräfte.\pUnd wenn die Zeit kommt, dann werde ich ihr meine Unterstützung zukommen lassen!"
str_trainer1_defeat:
    .autostring 34 2 "Heißt das, dass du gegen die Revolutionsbewegung wetterst?"
str_trainer2_challange:
    .autostring 34 2 "Die Meere hier sind gefährlich für Schwimmer.\pIst man zu schwach, holen einen die Piraten!"
str_trainer2_defeat:
    .autostring 34 2 "Du brauchst dir keine Sorgen machen, von Piraten gefangen genommen zu werden."
str_trainer3_challange:
    .autostring 34 2 "Ein starker Trainer braucht auch einen starken Geist.\pUnd wo könnte man den besser stärken, als an einem trostlosen Ort wie diesem?"
str_trainer3_defeat:
    .autostring 34 2 "Deine Willenskraft ist wirklich beeindruckend.\pWo hast du deinen Geist gestählt?"
str_trainer4_challange:
    .autostring 34 2 "Seit Tagen beißt in diesen Gewässern nichtsDOTS\pEs ist als ob der Ozean verflucht wäre!"
str_trainer4_defeat:
    .autostring 34 2 "Ist mit meiner Niederlage der Fluch endlich gebrochen?"

.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "Endless darkness slumbers in my heartDOTS\pDOTSand it will embrace you!"
str_trainer0_defeat:
    .autostring 34 2 "You were able to triumph over the darkness in my heartDOTS"
str_trainer1_challange:
    .autostring 34 2 "The revolutionary movement gathers there forces.\pAnd when the time comes, I will supply my support!"
str_trainer1_defeat:
    .autostring 34 2 "Does that mean you fight against the revolutionary movement?"
str_trainer2_challange:
    .autostring 34 2 "These seas here are dangerous for swimmers.\pIf you are too weak, the pirates will get you."
str_trainer2_defeat:
    .autostring 34 2 "You don't need to worry being captured by pirates though."
str_trainer3_challange:
    .autostring 34 2 "A strong trainer needs a strong mind.\pAnd where to better strengthen it than in a joyless place as here?"
str_trainer3_defeat:
    .autostring 34 2 "Your willpower really is impressive.\pWhere did you train your mind?"
str_trainer4_challange:
    .autostring 34 2 "For days now nothing bites in these watersDOTS\pIt is like the ocean itself had been cursed!"
str_trainer4_defeat:
    .autostring 34 2 "With my defeat, has the curse been broken?"

.endif