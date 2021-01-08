.include "overworld_script.s"
.include "callstds.s"

.global ow_script_kaskada_blackmarket_trainer_0
.global ow_script_kaskada_blackmarket_trainer_1

ow_script_kaskada_blackmarket_trainer_0:
    trainerbattlestd 0 0x71 0 str_before_0 str_after_0
    loadpointer 0 str_after_0
    callstd MSG_FACE
    end
ow_script_kaskada_blackmarket_trainer_1:
    trainerbattlestd 0 0x72 0 str_before_1 str_after_1
    loadpointer 0 str_after_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Was willst du denn hier?\pBist du etwa auch einer dieser nervigen Polizisten?"
str_after_0:
    .autostring 34 2 "Na gut, du scheinst zumindest kein Polizist zu seinDOTS"
str_before_1:
    .autostring 34 2 "Die Revolutionsbewegung hat hier wichtige Geschäfte zu erledigen.\pDa lasse ich kein Kind einfach dazwischen funken."
str_after_1:
    .autostring 34 2 "Oh, das ist gar nicht gut.\pLass unsere Bewegung einfach ihr Ding machen, ok?"
.elseif LANG_EN
.endif
