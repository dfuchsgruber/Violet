.include "overworld_script.s"
.include "callstds.s"

.global ow_script_kuestenberg_trainer_0
.global ow_script_kuestenberg_trainer_1
.global ow_script_kuestenberg_trainer_2

ow_script_kuestenberg_trainer_0:
    trainerbattlestd 0 0x12d 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_later
    callstd MSG_FACE
    end
ow_script_kuestenberg_trainer_1:
    trainerbattlestd 0 0x200 0 str_before_1 str_after_1
    loadpointer 0 str_later_1
    callstd MSG_FACE
    end
ow_script_kuestenberg_trainer_2:
    trainerbattlestd 0 0x201 0 str_before_2 str_after_2
    loadpointer 0 str_later_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Meine Arme beginnen langsam wehzutun.\pWie wäre es mit einem Kampf?"
str_trainer0_defeat:
    .autostring 34 2 "Ich sollte zurück zum Boden und mich ausruhenDOTS"
str_trainer0_later:
    .autostring 34 2 "Meine Arme tun mir wehDOTS\pIch sollte wirklich schnell zurück zum BodenDOTS"
str_before_1:
    .autostring 34 2 "Hier oben hat man es als Vogelfänger sehr leicht.\pEs ist fast so, als würden die Pokémon zu einem fliegen!"
str_after_1:
    .autostring 34 2 "UffDOTS\nVielleicht sollte ich nicht jedes erstbeste Pokémon fangenDOTS"
str_later_1:
    .autostring 34 2 "Denkst du, dass ich dich besiegt hätte, wenn ich bei der Auswahl meiner Pokémon achtsamer gewesen wäre?"
str_before_2:
    .autostring 34 2 "Die Geister des gefallenen Königreichs suchen uns heim!"
str_after_2:
    .autostring 34 2 "Ahh!\nIch habe ein Gespenst gesehenDOTS"
str_later_2:
    .autostring 34 2 "Ich kann sie sehenDOTS\pViele Seelen, die mit diesem Königreich untergangen sind.\pSie kommen nicht zur Ruhe."
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "My arms start to hurt.\pWhat about a battle?"
str_trainer0_defeat:
    .autostring 34 2 "I should return to the ground and get some restDOTS"
.endif