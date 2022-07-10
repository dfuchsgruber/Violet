.include "overworld_script.s"
.include "callstds.s"

.global ow_script_kaskada_clouds_trainer_0
.global ow_script_kaskada_clouds_trainer_1
.global ow_script_kaskada_clouds_trainer_2

ow_script_kaskada_clouds_trainer_0:
    trainerbattlestd 0 0x11f 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_later
    callstd MSG_FACE
    end
ow_script_kaskada_clouds_trainer_1:
    trainerbattlestd 0 0x120 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_later
    callstd MSG_FACE
    end
ow_script_kaskada_clouds_trainer_2:
    trainerbattlestd 0 0x1fe 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_later
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Diese RuinenDOTS\pIch untersuche sie seit Jahren!\pWenn du mich besiegen kannst, werde ich dir verraten, was ich weiß."
str_trainer0_defeat:
    .autostring 34 2 "W-Was?\pIch hätte nicht gedacht, dass du wirklich gewinnstDOTS"
str_trainer0_later:
    .autostring 34 2 "Na gut.\pIch verrate dir, was ich über diese Ruinen herausgefunden habe.\pVor langer Zeit, haben darin einmal Pokémon gelebt, aus denen sich Wörter formen lassen."
str_trainer1_challange:
    .autostring 34 2 "Wenn du hier vorbei willst, musst du mich schon im Kampf besiegen!"
str_trainer1_defeat:
    .autostring 34 2 "Nun gut, du kannst passieren, schätze ichDOTS"
str_trainer1_later:
    .autostring 34 2 "Hm.\nIch hatte gehofft, dass ich stark genug bin, um dich besiegen zu können."
str_trainer2_challange:
    .autostring 34 2 "Hier beißen die Pokémon nicht sehr gutDOTS\pDu hast sie mit deinem Getrampel verscheucht!"
str_trainer2_defeat:
    .autostring 34 2 "Na gut, na gutDOTS\pIch entschuldige michDOTS"
str_trainer2_later:
    .autostring 34 2 "Vielleicht ist doch nicht deine Schuld, dass die Pokémon hier nicht beißenDOTS"
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