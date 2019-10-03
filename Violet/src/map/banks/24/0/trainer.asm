.include "overworld_script.s"
.include "callstds.s"

.global ow_script_kuestenberg_trainer_0

ow_script_kuestenberg_trainer_0:
    trainerbattlestd 0 0x12d 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Meine Arme beginnen langsam wehzutun.\pWie wäre es mit einem Kampf?"
str_trainer0_defeat:
    .autostring 34 2 "Ich sollte zurück zum Boden und mich ausruhenDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "My arms start to hurt.\pWhat about a battle?"
str_trainer0_defeat:
    .autostring 34 2 "I should return to the ground and get some restDOTS"
.endif