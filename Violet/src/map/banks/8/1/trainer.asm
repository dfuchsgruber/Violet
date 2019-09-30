.include "overworld_script.s"
.include "callstds.s"

.global ow_script_kaskada_clouds_trainer_0
.global ow_script_kaskada_clouds_trainer_1

ow_script_kaskada_clouds_trainer_0:
    trainerbattlestd 0 0x11f 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

ow_script_kaskada_clouds_trainer_1:
    trainerbattlestd 0 0x120 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Es besteht im Allgemeinen eine Überzeugung, dass die Golem Pokémon im Zusammenhang mit den Ruinen über den Wolken stehen.\pWenn du mich besiegen kannst, verrate ich dir mehr!"
str_trainer0_defeat:
    .autostring 34 2 "Aus den Pokémon in den Ruinen lassen sich Wörter formenDOTS"
str_trainer1_challange:
    .autostring 34 2 "Wenn du diese Brücke überqueren willst, musst du mich schon besiegen können!"
str_trainer1_defeat:
    .autostring 34 2 "Nun gut, du kannst passieren, schätze ichDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "There is a common understanding that the golem pokémon are somehow related to the ruins above the clouds.\pIf you want to know more, you have to defeat me first!"
str_trainer0_defeat:
    .autostring 34 2 "The pokémon inside the ruinsDOTS\pThey spell wordsDOTS"
str_trainer1_challange:
    .autostring 34 2 "If you want to cross this bridge you have to be able to defeat me!"
str_trainer1_defeat:
    .autostring 34 2 "Fine then, you can pass I supposeDOTS"
.endif