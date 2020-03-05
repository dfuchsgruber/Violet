.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ardeal_trainer_2

ow_script_ardeal_trainer_2:
    trainerbattlestd 0x0 0x15c 0 str_before_0 str_after_0
    loadpointer 0x0 str_after_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Unser Kommandant ist nicht aufzuhalten.\pNicht einmal die Top Vier sind ihm gewachsen!"
str_after_0:
    .autostring 34 2 "Meine Niederlage tut nichts zur Sache.\pMit deinen kümmerlichen Fähigkeiten wirst du hier nichts erreichen."

.elseif LANG_EN
str_before_0:
    .autostring 34 2 "Nobody can stop our commander.\pNot even the Elite Four are any match for him."
str_after_0:
    .autostring 34 2 "My defeat doesn't mean anything.\pWith your pityful skills you won't achieve anything here."

.endif