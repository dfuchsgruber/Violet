.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_4_clouds_trainer_0
.global ow_script_route_4_clouds_trainer_1
.global ow_script_route_4_clouds_trainer_2
.global ow_script_route_4_clouds_trainer_3
.global ow_script_route_4_clouds_trainer_4
.global ow_script_route_4_clouds_trainer_5

ow_script_route_4_clouds_trainer_0:
    trainerbattlestd 0 0x11d 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_after
    callstd MSG_FACE
    end
ow_script_route_4_clouds_trainer_1:
    trainerbattlestd 0 0x11e 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_after
    callstd MSG_FACE
    end
ow_script_route_4_clouds_trainer_2:
    trainerbattlestd 0 0x1d6 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_after
    callstd MSG_FACE
    end
ow_script_route_4_clouds_trainer_3:
    trainerbattlestd 0 0x1d7 0 str_trainer3_challange str_trainer3_defeat
    loadpointer 0 str_trainer3_after
    callstd MSG_FACE
    end
ow_script_route_4_clouds_trainer_4:
    trainerbattlestd 0 0x1d8 0 str_trainer4_challange str_trainer4_defeat
    loadpointer 0 str_trainer4_after
    callstd MSG_FACE
    end
ow_script_route_4_clouds_trainer_5:
    trainerbattlestd 0 0x1d9 0 str_trainer5_challange str_trainer5_defeat
    loadpointer 0 str_trainer5_after
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Weißt du, wie ich zu meiner Wolke gekommen bin?\pIch werde es dir verraten, wenn du mich besiegst!"
str_trainer0_defeat:
    .autostring 34 2 "Nein, ich verrate es dir trotzdem nicht."
str_trainer0_after:
    .autostring 34 2 "Buh.\pDie Geschichte hinter meiner Wolke ist sehr langweilig, ich werde dir das ersparenDOTS"
str_trainer1_challange:
    .autostring 34 2 "GähnDOTS\pDie Langeweile hier oben ist wirklich unendlich großDOTS\pLass uns kämpfen!"
str_trainer1_defeat:
    .autostring 34 2 "Das ist wirklich nicht langweilig."
str_trainer1_after:
    .autostring 34 2 "Lieber langweile ich mich, als gegen dich zu verlierenDOTS"
str_trainer2_challange:
    .autostring 34 2 "Hier oben findet man fast gar keine PflanzenDOTS\pDas macht mich ganz traurigDOTS\pDu musst mich jetzt ablenken, ok?"
str_trainer2_defeat:
    .autostring 34 2 "Wo sind all die schönen Blüten?"
str_trainer2_after:
    .autostring 34 2 "Ob es an der dünnen Luft liegt, dass hier oben kaum Blumen wachsen?"
str_trainer3_challange:
    .autostring 34 2 "Irgendein Spaßvogel hat einen Mechaniker hierher bestellt.\pUnd hier bin ich nunDOTS\pWas soll ich denn jetzt bitte machen?"
str_trainer3_defeat:
    .autostring 34 2 "Ein Mechaniker über den WolkenDOTS"
str_trainer3_after:
    .autostring 34 2 "Wenn ich die Göre in die Finger kriege, die sich diesen Streich mit mir erlaubt hatDOTS"
str_trainer4_challange:
    .autostring 34 2 "Ich hatte gehofft, hier oben einige seltene Pokémon angeln zu können, aber stattdessen beißen hier wohl die selben Pokémon, wie auch auf dem Boden."
str_trainer4_defeat:
    .autostring 34 2 "Siehst du?\pMit solchen Fängen kann man nicht gewinnen."
str_trainer4_after:
    .autostring 34 2 "Wie kann es sein, dass man hier oben keine seltenen Pokémon angeln kann?"
str_trainer5_challange:
    .autostring 34 2 "Ich hatte gehofft, hier oben einige seltene Pokémon angeln zu können, aber stattdessen beißen hier wohl die selben Pokémon, wie auch auf dem Boden."
str_trainer5_defeat:
    .autostring 34 2 "Siehst du?\pMit solchen Fängen kann man nicht gewinnen."
str_trainer5_after:
    .autostring 34 2 "Wie kann es sein, dass man hier oben keine seltenen Pokémon angeln kann?"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "Do you want to know how I got to get my cloud?\pI will tell you if you can defeat me!"
str_trainer0_defeat:
    .autostring 34 2 "Meh.\pThe story behind my cloud is so boring, I will spare you the detailsDOTS"
str_trainer1_challange:
    .autostring 34 2 "YawnDOTS\pIt is so boring up hereDOTS\pLet's battle!"
str_trainer1_defeat:
    .autostring 34 2 "I'd rather be bored than lose to youDOTS"
.endif