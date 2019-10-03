.include "overworld_script.s"
.include "callstds.s"

.global ow_script_aktania_clouds_trainer_0

ow_script_aktania_clouds_trainer_0:
    trainerbattlestd 0 0x12c 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_after
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Diese Ruinen verraten mir viel über den Untergang dieses antiken Reiches über den Wolken.\pWenn du mich besiegst, werde ich dir vielleicht etwas verraten."
str_trainer0_defeat:
    .autostring 34 2 "NunDOTS\nDOTSdann werde ich dir wohl etwas über dieses gefallene Reich verratenDOTS"
str_trainer0_after:
    .autostring 34 2 "Den Inschriften zufolge hat sich diese Zivilisation gegen die Götter der Welt gestellt.\pFür diesen Hochmut wurde sie mit ihrer völligen Auslöschung bestraft."
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "These ruins tell me a lot about the downfall of this ancient realm over the clouds.\pIf you can defeat me, I might tell you something about it."
str_trainer0_defeat:
    .autostring 34 2 "WellDOTS\nDOTSthen I will tell you something about this sunken kingdomDOTS"
str_trainer0_after:
    .autostring 34 2 "The writings tell that this ancient civilization wagered against the gods of the world.\pFor their arrogance they were punished with total eradication."

.endif