.include "overworld_script.s"
.include "callstds.s"

.global ow_script_orina_city_clouds_trainer_0
.global ow_script_orina_city_clouds_trainer_1
.global ow_script_orina_city_clouds_trainer_2

ow_script_orina_city_clouds_trainer_0:
    trainerbattlestd 0 0x117 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

ow_script_orina_city_clouds_trainer_1:
    trainerbattlestd 0 0x118 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end

ow_script_orina_city_clouds_trainer_2:
    trainerbattlestd 0 0x119 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Das Band zwischen Pokémon und Trainer ist der Schlüssel zum Sieg.\pDas werde ich dir beweisen!"
str_trainer0_defeat:
    .autostring 34 2 "Du hast tatsächlich einfach nur ein stärkeres Band zu deinen Pokémon, deshalb konntest du gewinnen."
str_trainer1_challange:
    .autostring 34 2 "Als Elite der Trainerprofession muss man auch über den Wolken trainieren!"
str_trainer1_defeat:
    .autostring 34 2 "Du machst allen Trainern von Theto alle Ehre!"
str_trainer2_challange:
    .autostring 34 2 "Ich forsche seit Langem intensiv an den Ruinen hier oben.\pWillst du hinter die Geheminisse kommen?\pBesiege mich im Kampf!"
str_trainer2_defeat:
    .autostring 34 2 "Wie beschämend, dass ich jetzt zugeben muss, dass ich bisher keinerlei Geheimnisse gelüftet habeDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "The bond between pokémon and trainer is the key to victory.\pI will prove that to you!"
str_trainer0_defeat:
    .autostring 34 2 "In fact the bond between you and your pokémon is stronger and that's why you won."
str_trainer1_challange:
    .autostring 34 2 "As the elite of all trainers you also have to train over the clouds!"
str_trainer1_defeat:
    .autostring 34 2 "You honor all the trainers of Theto."
str_trainer2_challange:
    .autostring 34 2 "For I long time I have been doing research on the ruins up here.\pYou want to know their secrets?\pDefeat me in battle!"
str_trainer2_defeat:
    .autostring 34 2 "How embarassing that I have to admit I did not unravel any mysteries so farDOTS"
.endif