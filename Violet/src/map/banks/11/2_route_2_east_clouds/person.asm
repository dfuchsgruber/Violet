.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_2_clouds_person_0
.global ow_script_route_2_clouds_person_1
.global ow_script_route_2_clouds_person_2
.global ow_script_route_2_clouds_person_3
.global ow_script_route_2_clouds_person_4

ow_script_route_2_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_2_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_2_clouds_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_route_2_clouds_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_route_2_clouds_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Es heißt, dass Menschen vor vielen tausend Jahren eine Zivilisation über den Wolken errichtet haben.\pSie waren in der Lage, Steine zu fertigen, die von Wolken getragen werden können."
str_1:
    .autostring 34 2 "In diesem Tempeln leben Pokémon, die in engem Zusammenhang mit den legendären Pokémon stehen.\pVor einiger Zeit kam ein Junge zu mir, der sich dafür sehr interessierte."
str_2:
    .autostring 34 2 "Von den Brücken im Himmel zu blicken, lässt einen bewusst werden, wie klein man selbst doch ist."
str_3:
    .autostring 34 2 "Ich erblickte einmal einen Vogel, dessen drei eisblaue Schweife so anmutig glänzten, dass ich seither keinen Tag verbracht habe, ohne hier oben nach ihm Ausschau zu halten."
str_4:
    .autostring 34 2 "Als der ehemalige Champion Lucius begonnen hatte, auf einer Wolke nach einem Drachen-Pokémon zu suchen, eiferten ihm viele Menschen in Theto nach.\pMan kann sagen, dass er nach Jahrhunderten wieder Menschen dazu gebracht hat, die Himmel zu bereisen."

.elseif LANG_EN
str_0:
    .autostring 34 2 "It is said that thousands of years ago people formed a civilization above the clouds.\pThey were able to craft rocks that could be carried by the clouds."
str_1:
    .autostring 34 2 "In this temple live pokémon that are strongly connected to the legendary pokémon.\pSome time ago a boy came to me who was most curious about them."
str_2:
    .autostring 34 2 "To look down from the bridges in the skies makes you aware of how small you actually are."
str_3:
    .autostring 34 2 "I once saw a bird with three ice blue tails that shined so gracefully, I wasn't able to spend a day without coming here to look for it."
str_4:
    .autostring 34 2 "When the former champ Lucius began searching for a certain dragon pokémon on a cloud, many people followed his example.\pYou could say that he, after hundreds of years, made people travel the skies again."
.endif