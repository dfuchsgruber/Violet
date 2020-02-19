.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_7_trainer_3
.global ow_script_route_7_trainer_4
.global ow_script_route_7_trainer_5
.global ow_script_route_7_trainer_6
.global ow_script_route_7_trainer_7
.global ow_script_route_7_trainer_8
.global ow_script_route_7_trainer_9

ow_script_route_7_trainer_3:
    trainerbattlestd 0x0 0x142 0 str_before_3 str_after_3
    loadpointer 0x0 str_after_3
    callstd MSG_FACE
    end
ow_script_route_7_trainer_4:
    trainerbattlestd 0x0 0x143 0 str_before_4 str_after_4
    loadpointer 0x0 str_after_4
    callstd MSG_FACE
    end
ow_script_route_7_trainer_5:
    trainerbattlestd 0x0 0x144 0 str_before_5 str_after_5
    loadpointer 0x0 str_after_5
    callstd MSG_FACE
    end
ow_script_route_7_trainer_6:
    trainerbattlestd 0x0 0x145 0 str_before_6 str_after_6
    loadpointer 0x0 str_after_6
    callstd MSG_FACE
    end
ow_script_route_7_trainer_7:
    trainerbattlestd 0x0 0x146 0 str_before_7 str_after_7
    loadpointer 0x0 str_after_7
    callstd MSG_FACE
    end
ow_script_route_7_trainer_8:
    trainerbattlestd 0x0 0x147 0 str_before_8 str_after_8
    loadpointer 0x0 str_after_8
    callstd MSG_FACE
    end
ow_script_route_7_trainer_9:
    trainerbattlestd 0x0 0x15b 0 str_before_9 str_after_9
    loadpointer 0x0 str_after_9
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_3:
    .autostring 34 2 "In der Nähe soll der ehemalige Champ Lucius in seinem Schloss Ardeal leben.\pOb hier auch deshalb so starke Pokémon anbeißen?"
str_after_3:
    .autostring 34 2 "UffDOTS\pDu hast Nerven meinen Fang so herunterzumachen!"
str_before_4:
    .autostring 34 2 "Laufen am Strand hält fit und macht dich stark!\pSchau zu, wie ich mit dir den Boden aufwische!"
str_after_4:
    .autostring 34 2 "Aua, ich habe einen WadenkrampfDOTS"
str_before_5:
    .autostring 34 2 "Nachdem Lucius, der ehemalige Champion, besiegt wurde, hatte mein Vater gehofft, das Schloss Ardeal besetzten zu können.\pMeinen Furst über den Fehlschlag dieses Planes werde ich nun an dir auslassen!"
str_after_5:
    .autostring 34 2 "Was?\pErst bekomme ich nicht mein Schloss und dann erhalte ich stattdessen eine Niederlage?"
str_before_6:
    .autostring 34 2 "Diese frische Meeresbrise, die sanft durchs grüne Laub weht.\pWessen Herz könnte da nicht höher schlagen?"
str_after_6:
    .autostring 34 2 "Du hast einfach kein Herz für unsere Natur, Kindchen!"
str_before_7:
    .autostring 34 2 "Der höchste Turm des Schlosses Ardeal ragt bis in die Wolken!\pDahin werde ich dich jetzt fliegen schicken!"
str_after_7:
    .autostring 34 2 "UffDOTS\pDu bist wohl auf dem Boden geblieben, was?"
str_before_8:
    .autostring 34 2 "Ein junger Trainer, hat viel zu lernen.\pIch als alter Mann, kann dir folglich viel beibringen!"
str_after_8:
    .autostring 34 2 "Andererseits, kann auch ein alter Trainer von einem aufstrebenden Talent lernen."
str_before_9:
    .autostring 34 2 "Geheimtür?\pIch weiß nichts von einer Geheimtür!"
str_after_9:
    .autostring 34 2 "Ich würde dir niemals verraten, dass man im Schloss eine Geheimtür öffnen kann!\pUnd der Schalter ist auch nicht in der Bibliothek versteckt!"

.elseif LANG_EN
str_before_3:
    .autostring 34 2 "Somewhere arround here the former champ Lucius is supposed to live in his castle, Ardeal.\pIs that why only strong Pokémon bite here?"
str_after_3:
    .autostring 34 2 "UffDOTS\pYou got some nerves to denunciate my catch!"
str_before_4:
    .autostring 34 2 "Running at the beach keeps you fit and gets you strong.\pLook at how I will wipe the floor with you!"
str_after_4:
    .autostring 34 2 "Ouch, I got a cramp in my legsDOTS"
str_before_5:
    .autostring 34 2 "After Lucius, the former champ, was defeated, my father hoped to be able to occupy the castle Ardeal.\pMy frustration about the failure of this plot will be released upon you!"
str_after_5:
    .autostring 34 2 "What?\pFirst I don't get my castle and now I instead am being dealt a defeat?"
str_before_6:
    .autostring 34 2 "This fresh ocean breeze, that gently blows through the green leaves.\pWhich heart wouldn't beat faster?"
str_after_6:
    .autostring 34 2 "You simply don't feel anything for our nature, brat!"
str_before_7:
    .autostring 34 2 "The highest tower of the castle Ardeal reaches up in the clouds.\pThis is where I will send you flying!"
str_after_7:
    .autostring 34 2 "UffDOTS\pSo you remained grounded, hu?"
str_before_8:
    .autostring 34 2 "A young trainer has yet still much to learn.\pThus, I as an old man can teach you quite a lot."
str_after_8:
    .autostring 34 2 "Then again, even an old trainer can learn something from a young talent."
str_before_9:
    .autostring 34 2 "A secret door?\pI know nothing about any secret doors!"
str_after_9:
    .autostring 34 2 "I would never tell you that there is a secret door hidden within the castle.\pAnd the secret switch also isn't hidden in the library!"

.endif
