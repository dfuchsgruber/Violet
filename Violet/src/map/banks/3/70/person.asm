.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_3_70_trainer_2
.global ow_script_map_3_70_trainer_0
.global ow_script_map_3_70_trainer_1

ow_script_map_3_70_trainer_0:
    trainerbattlestd 0x0 0x5 0x0 str_before_0 str_after_0
    loadpointer 0x0 str_after_0
    callstd MSG_FACE
    end

ow_script_map_3_70_trainer_1:
    trainerbattlestd 0x0 0x7 0x0 str_before_1 str_after_1
    loadpointer 0x0 str_after_1
    callstd MSG_FACE
    end

ow_script_map_3_70_trainer_2:
    trainerbattlestd 0x0 0x19b 0x0 str_before_2 str_after_2
    loadpointer 0x0 str_after_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Mein bester Freund war einmal auf Fauns Trainerschule.\pIch mir einiges von ihm abgeschaut!"
str_after_0:
    .autostring 34 2 "Was?\nDu warst auch auf Fauns Trainerschule?"
str_before_1:
    .autostring 34 2 "Die Welt der Blumen ist das, wofür ich lebe.\pIch werde dir die Stärke der Natur vor Augen führen!"
str_after_1:
    .autostring 34 2 "Wie?\nDu hast mich besiegt?\pAber ich war doch im Einklang mit der NaturDOTS"
str_before_2:
    .autostring 34 2 "Die anderen Kinder nennen mich Schleimer!\pHah!\nIch werde dir zeigen, warum sie damit Recht haben!"
str_after_2:
    .autostring 34 2 "UffDOTS\nIch konnte trotz meiner Vorbereitungen nichts ausrichtenDOTS"

.elseif LANG_EN
str_before_0:
    .autostring 34 2 "My best friend visited Faun's trainer school.\pI did copy some of his tricks!"
str_after_0:
    .autostring 34 2 "Huh?\nYou also were on Faun's trainer school?"
str_before_1:
    .autostring 34 2 "The world of flowers is what I live for.\pI will demonstrate its strength to you!"
str_after_1:
    .autostring 34 2 "What?\nYou defeated me?\pBut nature and I were in perfect harmonyDOTS"
str_before_2:
    .autostring 34 2 "The other kids just call me the slimer!\pHeh!\nI'm gonna show you why!"
str_after_2:
    .autostring 34 2 "UffDOTS\pI couldn't do anything regardless of my preparationsDOTS"
.endif

