.include "overworld_script.s"
.include "callstds.s"

.global ow_script_laubdorf_person_0
.global ow_script_laubdorf_person_1
.global ow_script_laubdorf_person_2
.global ow_script_laubdorf_person_3
.global ow_script_laubdorf_person_4
.global ow_script_laubdorf_person_5
.global ow_script_laubdorf_person_6

ow_script_laubdorf_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_laubdorf_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

ow_script_laubdorf_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

ow_script_laubdorf_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end

ow_script_laubdorf_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end

ow_script_laubdorf_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end

ow_script_laubdorf_person_6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Laubdorf wirkt auf mich wie ein großes Nest.\pHier sind alle eine Familie, egal ob Mensch oder Pokémon."
str_1:
    .autostring 34 2 "Manche Pokémon lassen sich nur züchten, wenn ihre Eltern ein bestimmtes Item tragen."
str_2:
    .autostring 34 2 "Ich habe miterlebt, wie Lucius in dieser Region die Pokémon Liga errichtet hat.\pEr hat großen Eindruck auf uns alle gemacht, damals."
str_3:
    .autostring 34 2 "Oft blicke ich abends in den Himmel und starre die Sterne an.\pOb es noch andere Wesen da draußen gibt?"
str_4:
    .autostring 34 2 "Hast du schon einmal von der dunklen Königin gehört?\pEs ist eine sehr alte Legende.\pWegen ihrer Boshaftigkeit, wurde ihr Geist verbannt."
str_5:
    .autostring 34 2 "Für ein gesundes Leben ist körperliche Betätigung unerlässlich.\pUnd das Joggen ist hier am Strand gleich umso anstrengender!"
str_6:
    .autostring 34 2 "Der Traum eines jeden Anglers ist es, ein rotes Garados zu besitzen!\pUnd nur, wer immerzu seine Rute ins Wasser wirft, kann das schaffen!"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Leaf Village is like a large nest to me.\pHere, everyone is family, no matter if human or Pokémon."
str_1:
    .autostring 34 2 "Some Pokémon can only be bred if their parents hold a specific item."
str_2:
    .autostring 34 2 "I remember Lucius building the Pokémon League in this region.\pHe really made an impression on us all."
str_3:
    .autostring 34 2 "Often I stare in the skies when night has come and wonder about the stars.\pAre there other creatures out there?"
str_4:
    .autostring 34 2 "Did you ever hear about the dark queen?\pIt's a very old legend that says her ghost was banished because of her evilness."
str_5:
    .autostring 34 2 "For a healthy life sports is essential!\pAnd jogging at the beach is even more exhausting."
str_6:
    .autostring 34 2 "It's a fisherman's dream to own a red Gyarados.\pAnd only the one who keeps fishing can achieve this dream."

.endif