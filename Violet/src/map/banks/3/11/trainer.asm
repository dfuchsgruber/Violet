.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_10_trainer_0
.global ow_script_route_10_trainer_1
.global ow_script_route_10_trainer_2
.global ow_script_route_10_trainer_3
.global ow_script_route_10_trainer_4
.global ow_script_route_10_trainer_5
.global ow_script_route_10_trainer_6
.global ow_script_route_10_trainer_7

ow_script_route_10_trainer_0:
    trainerbattlestd 0 0xd8 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

ow_script_route_10_trainer_1:
    trainerbattlestd 0 0xd9 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end

ow_script_route_10_trainer_2:
    trainerbattlestd 0 0xda 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_defeat
    callstd MSG_FACE
    end

ow_script_route_10_trainer_3:
    trainerbattlestd 0 0xdb 0 str_trainer3_challange str_trainer3_defeat
    loadpointer 0 str_trainer3_defeat
    callstd MSG_FACE
    end

ow_script_route_10_trainer_4:
    trainerbattlestd 0 0xdc 0 str_trainer4_challange str_trainer4_defeat
    loadpointer 0 str_trainer4_defeat
    callstd MSG_FACE
    end

ow_script_route_10_trainer_5:
    trainerbattlestd 0 0xdd 0 str_trainer5_challange str_trainer5_defeat
    loadpointer 0 str_trainer5_defeat
    callstd MSG_FACE
    end

ow_script_route_10_trainer_6:
    trainerbattlestd 0 0xde 0 str_trainer6_challange str_trainer6_defeat
    loadpointer 0 str_trainer6_defeat
    callstd MSG_FACE
    end

ow_script_route_10_trainer_7:
    trainerbattlestd 0 0xdf 0 str_trainer7_challange str_trainer7_defeat
    loadpointer 0 str_trainer7_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Sowohl im Wasser, aber auch an Land bin ich ein absoluter Star!"
str_trainer0_defeat:
    .autostring 34 2 "Einen Star besiegen?\nDu traust dich was!"
str_trainer1_challange:
    .autostring 34 2 "Ich liebe die frische Briese auf dem Meer.\pDas Salz ist Balsam für die Seele eines Anglers."
str_trainer1_defeat:
    .autostring 34 2 "Das Salz des Meeres wird meine Wunden heilenDOTS"
str_trainer2_challange:
    .autostring 34 2 "Ich kann von mir behaupten, noch nie einen Krampf gehabt zu haben!"
str_trainer2_defeat:
    .autostring 34 2 "UrghDOTS\nNein!\pIst das einDOTS?\nKrampf?"
str_trainer3_challange:
    .autostring 34 2 "Weißt du, was das Schwimmen so interessant macht?\pIch verrate es dir, wenn du mich schlägst!"
str_trainer3_defeat:
    .autostring 34 2 "Du rechnest bestimmt mit einer tiefgründigen Antwort.\pAber das Interessanteste am Schwimmen sind natürlich die Schwimmerinen!"
str_trainer4_challange:
    .autostring 34 2 "Mein tägliches Training sieht es vor, vom Küstenberg bis nach Laubdorf zu schwimmen!"
str_trainer4_defeat:
    .autostring 34 2 "ArghDOTS\nDu bist auch nicht von schlechten ElternDOTS"
str_trainer5_challange:
    .autostring 34 2 "Meine ganze Familie besteht aus Schwimmern.\pIch hatte keine andere Wahl, als auch eine Schwimmerin zu werden."
str_trainer5_defeat:
    .autostring 34 2 "Wäre es nach mir gegangen, ich hätte mich für Feuer-Pokémon interessiertDOTS"
str_trainer6_challange:
    .autostring 34 2 "Einen Triathlon zu gewinnen, erfordert viel Willenstärke."
str_trainer6_defeat:
    .autostring 34 2 "Hast du schon einmal darüber nachgedacht, selbst zum Triathleten zu werden?"
str_trainer7_challange:
    .autostring 34 2 "Manus aus Meriana City trainiert oft tagelang auf einer abgelegenen Insel im Meer.\pWenn ich das auch mache, werde ich eines Tages so stark wie er!"
str_trainer7_defeat:
    .autostring 34 2 "Meine Niederlage spornt mich nur noch mehr an!"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "In the water and but also on land I am an absolute star."
str_trainer0_defeat:
    .autostring 34 2 "Defeating a star?\nHow bold of you!"
str_trainer1_challange:
    .autostring 34 2 "I love the fresh breeze on the ocean.\pThe salt is balm for my soul."
str_trainer1_defeat:
    .autostring 34 2 "The salt of the ocean will heal my woundsDOTS"
str_trainer2_challange:
    .autostring 34 2 "I am proud to say that I never ever had any cramp!"
str_trainer2_defeat:
    .autostring 34 2 "UrghDOTS\nNo!\pIs that a?DOTS\nCramp?"
str_trainer3_challange:
    .autostring 34 2 "Do you know what makes swimming so interesting?\pIf you can beat me I will tell you!"
str_trainer3_defeat:
    .autostring 34 2 "You may want to hear something very deep.\pBut the most interesting thing in swimming are of course the female swimmers!"
str_trainer4_challange:
    .autostring 34 2 "My daily training requires me to swim from the Shore Hill up to Leaf Village!"
str_trainer4_defeat:
    .autostring 34 2 "ArghDOTS\pYou are not half badDOTS"
str_trainer5_challange:
    .autostring 34 2 "My entire family consists of swimmers.\pI did not have any choice but to become a swimmer as well."
str_trainer5_defeat:
    .autostring 34 2 "If I had to choose, Fire-Pokémon would be of great interest for meDOTS"
str_trainer6_challange:
    .autostring 34 2 "To win a triathlon demands a lot of will power."
str_trainer6_defeat:
    .autostring 34 2 "Did you ever think about becoming a triathlete yourself?"
str_trainer7_challange:
    .autostring 34 2 "Manus from Meriana City often trains on islands like these for days.\pIf I do the same, I will become as strong as him."
str_trainer7_defeat:
    .autostring 34 2 "My defeat only encourages me further!"
.endif