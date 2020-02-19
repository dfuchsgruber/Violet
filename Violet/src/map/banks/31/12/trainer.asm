.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ardeal_trainer_3

ow_script_ardeal_trainer_3:
    trainerbattlestd 0x0 0x15d 0 str_before_0 str_after_0
    loadpointer 0x0 str_after_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Unsere Division besteht nur aus Elite-Mitgliedern.\pDas ist das Beste, was Team Violet zu bieten hat!"
str_after_0:
    .autostring 34 2 "Gar nicht übel, aber im Vergleich zu unserem Kommandanten, bist du ein Nichts!"

.elseif LANG_EN
str_before_0:
    .autostring 34 2 "Our division is made up only of elite members!\pWe are the best that Team Violet has to offer!"
str_after_0:
    .autostring 34 2 "Not even half bad, but commpared to our commander you're nothing!"

.endif