.include "callstds.s"
.include "overworld_script.s"

.global ow_script_aschhain_trainer_0
.global ow_script_aschhain_trainer_1
.global ow_script_aschhain_trainer_2


ow_script_aschhain_trainer_0:
    trainerbattlestd 0x0 0x9c 0x0 str_before_0 str_after_0
    loadpointer 0x0 str_later_0
    callstd MSG_FACE
    end
ow_script_aschhain_trainer_1:
    trainerbattlestd 0x0 0x9d 0x0 str_before_1 str_after_1
    loadpointer 0x0 str_later_1
    callstd MSG_FACE
    end
ow_script_aschhain_trainer_2:
    trainerbattlestd 0x0 0x9e 0x0 str_before_2 str_after_2
    loadpointer 0x0 str_later_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Ein Ass-Trainer wie ich kann es ohne Weiteres mit der Hitze hier aufnehmen.\pWie sieht es mit dir aus?"
str_after_0:
    .autostring 34 2 "I-Ich schwitze noch nicht einmal!"
str_later_0:
    .autostring 34 2 "Na gut, vielleicht machen mir die Temperaturen doch ein wenig zu schaffenDOTS"
str_before_1:
    .autostring 34 2 "Diese Hitze hier ist gar nicht gut für mich.\pNicht, dass man noch einen Schweißfleck auf meinem neuen Kleid sieht."
str_after_1:
    .autostring 34 2 "Man sieht aber keinen Schweißfleck, oder?"
str_later_1:
    .autostring 34 2 "Jemand wie ich sollte wirklich nicht hier sein müssenDOTS"
str_before_2:
    .autostring 34 2 "Viele Trainer kommen hierher, weil sie Gerüchte von einem seltenen Pokémon gehört haben.\pUnd ich erleichtere sie dann um ihre Pokémon!"
str_after_2:
    .autostring 34 2 "Gut, du kannst deine Pokémon behalten."
str_later_2:
    .autostring 34 2 "Meine Masche funktioniert sonst eigentlich immer gut.\pAber du bist wohl etwas zu stark, was?"
.elseif LANG_EN
.endif