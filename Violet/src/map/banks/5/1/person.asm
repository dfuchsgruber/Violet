.include "overworld_script.s"
.include "callstds.s"
.include "items.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"

.global ow_script_meriana_city_clouds_person_0
.global ow_script_meriana_city_clouds_person_1
.global ow_script_meriana_city_clouds_person_2
.global ow_script_meriana_city_clouds_person_3

ow_script_meriana_city_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_meriana_city_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_meriana_city_clouds_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end

ow_script_meriana_city_clouds_person_2:
    checkflag FLAG_MERIANA_CITY_CLOUDS_LAUCHSTANGE
    gotoif 1 done
    lock
    faceplayer
    loadpointer 0 str_ask
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL dont_like
    loadpointer 0 str_receive_lauchstange
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_LAUCHSTANGE
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0
    gotoif EQUAL no_space
    setflag FLAG_MERIANA_CITY_CLOUDS_LAUCHSTANGE
done:
    lock
    faceplayer
    loadpointer 0 str_received_lauchstange
    callstd MSG_KEEPOPEN
    release
    end
no_space:
    lock
    faceplayer
    loadpointer 0 str_no_space
    callstd MSG_KEEPOPEN
    release
    end
dont_like:
    lock
    faceplayer
    loadpointer 0 str_dont_like
    callstd MSG_KEEPOPEN
    release
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Bis heute streiten sich die Menschen darüber, wie einerseits ganze Städte im Himmel erbaut werden konnten und andererseits, wieso diese wohl antike Zivilisation überhaupt untergegangen ist."
str_1:
    .autostring 34 2 "Es ist wirklich nervig, dass so viele Menschen, die vom Wolkenreiten gar nichts verstehen, heutzutage auf Wolken unterwegs sindDOTS"
str_3:
    .autostring 34 2 "Diese Ruinen auf schwebenden InselnDOTS\pWürde ich es nicht mit eigenen Augen sehen, ich würde es dir nicht glauben!"
str_ask:
    .autostring 34 2 "Es gibt für mich kein interessanteres Pokémon, als Porenta.\pSeine Anmut, seine Stärke!\pUnd erst die Lauchstange, die es bei sich trägt!\pDOTS DOTS DOTS\pFindest du nicht auch, dass Porenta ohnegleichen ist?"
str_receive_lauchstange:
    .autostring 34 2 "Ich wusste es, als ich dich gesehen habe!\pHier, nimm das!"
str_received_lauchstange:
    .autostring 34 2 "Ich sammle dieses Item schon, seit ich denken kann.\pAber in den Händen eines anderen Porenta-Liebhabers ist sie auch sehr gut aufgehoben!"
str_dont_like:
    .autostring 34 2 "Wie bitte?\pDas ist doch absurd!\pDu hast überhaupt keinen Geschmack, sag ich dir!"
str_no_space:
    .autostring 34 2 "Was für ein Jammer!\pDu hast keinen Platz dafür!\pKomm wieder, wenn du Platz geschaffen hast."

.elseif LANG_EN
str_0:
    .autostring 34 2 "Up until today people argue how not only entire cities could be built in the sky but also why this probably ancient civilisation perished in the first place."
str_1:
    .autostring 34 2 "It really is a shame that so many people that do not know anything about cloud riding at all roam the skies nowadaysDOTS"
str_ask:
    .autostring 34 2 "For me there is no pokémon that is more interesting than Farfetch'd.\pIts grace, its strenght!\pAnd don't get me started about its stick!\pDOTS DOTS DOTS\pDon't you think that there is no pokémon like Farfetch'd?"
str_receive_lauchstange:
    .autostring 34 2 "I knew it when I saw you!\pHere, take this!"
str_received_lauchstange:
    .autostring 34 2 "I have been collecting this item for as long as I can think.\pBut I am sure another Farfetch'd lover will make good use of it!"
str_dont_like:
    .autostring 34 2 "Come again?\pThat is frankly absurd!\pYou do not have any taste, that I can tell you for sure!"
str_no_space:
    .autostring 34 2 "What a pity!\pYou don't seem to have room in your bag for it.\pCome bag once you made room."
.endif