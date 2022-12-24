
.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_5_4_person_1
.global ow_script_map_5_4_person_2
.global ow_script_map_5_4_person_3

ow_script_map_5_4_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_map_5_4_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_map_5_4_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_1:
    .autostring 34 2 "Ich habe meinem Fiffyen etwas zu viel zugemutet.\pJetzt muss es sich hier erholen.\nDie Schwester hat wirklich Wunder auf mein Pokémon gewirkt."
str_2:
    .autostring 34 2 "Die Laz. Corp stellt Kessel her, mit denen man nützliche Items herstellen kann.\pAllerdings sind mir kaum Rezepte bekanntDOTS"
str_3:
    .autostring 34 2 "Findest du es nicht auch sinnvoll, dass man im Pokéstop praktisch alles finden kann?\pEine Schwester, die deine Pokémon wieder auf Vordermann bringt, eine Möglichkeit Items zu kaufen, Zugriff auf den PC und sogar einen Kessel zur Herstellung von Items.\pEs ist wirklich klasse, dass man alles am selben Ort ist."
.elseif LANG_EN
str_1:
    .autostring 34 2 "I probably asked a bit too much of my Poochyena.\pNow it has to rest for a time.\pThe nurse here really did wonders for my Pokémon."
str_2:
    .autostring 34 2 "The Laz. Corp fabricates cauldrons that allow you to craft items.\pHowever, I don't even know that many recipiesDOTS"
str_3:
    .autostring 34 2 "It really is well thought out that you can find practically everything in a Pokéstop, don't you think?\pI nurse that heals your Pokémon, a mart that sells all sorts of items, access to the PC-system and even a cauldron for crafting items.\pIt really is nice that everything is located at the same place."
.endif