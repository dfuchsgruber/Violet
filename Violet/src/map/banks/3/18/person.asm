.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_7_person_10
.global ow_script_route_7_person_11
.global ow_script_route_7_person_12
.global ow_script_route_7_person_13
.global ow_script_route_7_person_14
.global ow_script_route_7_person_15

ow_script_route_7_person_10:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_7_person_11:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_7_person_12:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_route_7_person_13:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_route_7_person_14:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_route_7_person_15:
    loadpointer 0 str_5
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich starre manchmal stundenlang in den HimmelDOTS\pWie es wohl wäre, ein Flug-Pokémon zu sein?"
str_1:
    .autostring 34 2 "Kennst du Professor Tann?\pIch habe ihn einmal in einer Dokumentation über die Stadt Atlantea gesehen.\pEr ist geradezu besessen davon, diesen sagenumwobenen Ort zu finden."
str_2:
    .autostring 34 2 "Was?\nKämpfen möchtest du?\pWieso darf ein Angler nicht einmal in Ruhe seiner Beschäftigung nachgehenDOTS"
str_3:
    .autostring 34 2 "Ein Sonnenbrand kann einer Schwimmerin nichts anhaben.\pMan kann sich ja jederzeit im Wasser wieder abkühlen!"
str_4:
    .autostring 34 2 "Was geht über einen kühlen C.O.-Mix am Strand?\pVielleicht ein C-Saft?\pOder doch das C-Serum?\pSchau doch mal im Strandhaus von Haweiland vorbei.\pDort kannst du dir Erfrischungen kaufen."
str_5:
    .autostring 34 2 "Was eine Hexe wie mich hierher verschlägt?\pWeißt du nicht, dass sich nördlich von hier die Burg Ardeal befindet?\pDer Legende nach wurde sie von der Dunklen Königin errichtetDOTS\pVon dort hat sie den gesamten Kontinent beherrschtDOTS\pIst das nicht unfassbar spannend?"

.elseif LANG_EN
str_0:
    .autostring 34 2 "I catch myself staring into the sky for hours sometimesDOTS\pI wonder how it would feel to be flying PokémonDOTS"
str_1:
    .autostring 34 2 "Do you know Professor Tann?\pI once watched him commenting on a documentary about the city of Atlantea.\pHe is almost obsessed with finding this legendary place."
str_2:
    .autostring 34 2 "What?\pYou want to battle?\pWhy can't a fisherman not even once do what he is ought to doDOTS"
str_3:
    .autostring 34 2 "Being sun burnt can't do nothing to a swimmer.\pOne can just go back into the water to cool!"
str_4:
    .autostring 34 2 "Nothing better than a cold C.O.-Mix on the beach, right?\pOr maybe a C-Juice?\pWhat about C-Serum?\pMaybe you want to visit the beach house in Haweiland.\pThey sell all sorts of refreshments there."
str_5:
    .autostring 34 2 "You wonder what a witch like me is doing in a place like this?\pDidn't you know that further up north stands the Castle Ardeal?\pAccording to the legend, it was built by the Dark Queen herselfDOTS\pFrom there she ruled over the continentDOTS\pIsn't that exciting?"

.endif