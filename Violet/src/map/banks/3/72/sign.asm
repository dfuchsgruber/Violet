.include "overworld_script.s"
.include "callstds.s"

.global ow_script_trainerschule_inside_sign_0
.global ow_script_trainerschule_inside_sign_1
.global ow_script_trainerschool_bookshelf
.global ow_script_trainerschool_statue

ow_script_trainerschule_inside_sign_0:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

ow_script_trainerschule_inside_sign_1:
    loadpointer 0 str_1
    callstd MSG_SIGN
    end

ow_script_trainerschool_bookshelf:
    loadpointer 0 str_bookshelf
    callstd MSG_SIGN
    end

ow_script_trainerschool_statue:
    loadpointer 0 str_statue
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ein Plakat, dass junge Trainer dazu anhält, alle acht Arena-Orden zu erringen und die Top-Vier herauszufordern."
str_1:
    .autostring 34 2 "Dieses Bild zeigt Faun in seinen jungen Jahren.\pSind seine Arme etwa tätowiert?"
str_bookshelf:
    .autostring 34 2 "Eine ganze Reihe von Büchern über Pokémon-Kampfstrategien.\pFaun hat stets darauf geachtet, dass sie gut behandelt werden."
str_statue:
    .autostring 34 2 "Eine Statue von einem Pokémon.\pMan erzählt sich, es sei das Lieblings-Pokémon des Schulleiters Faun."
.elseif LANG_EN
str_0:
    .autostring 34 2 "A poster that inspires young trainers to fight for all eight gym badges and challange the elite four."
str_1:
    .autostring 34 2 "This poster shows Faun in his young years.\pAre those tattoos on his arms?"
str_bookshelf:
    .autostring 34 2 "A whole shelf of books about Pokémon battle strategies.\pFaun always made sure they were well treated."
str_statue:
    .autostring 34 2 "A statue of a Pokémon.\pIt is said to be the favorite Pokémon of the school principal Faun."
.endif
