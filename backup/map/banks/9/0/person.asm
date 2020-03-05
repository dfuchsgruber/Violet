.include "overworld_script.s"
.include "callstds.s"


.global ow_script_orina_city_clouds_person_0
.global ow_script_orina_city_clouds_person_1
.global ow_script_orina_city_clouds_person_2

ow_script_orina_city_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_orina_city_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_orina_city_clouds_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Meine Eltern waren wie besessen von den Wolkenruinen.\pUnd irgendwie ist diese Besessenheit wohl auch auf mich übergegangen.\pWorin liegt die Magie, die an diesem Ort herrscht?"
str_1:
    .autostring 34 2 "Dieser Ort hat eine uralte Geschichte.\pDen Legenden nach verehrten ihre Bewohner eine ganze Reihe von Göttern, die das Weltgeschick lenkten."
str_2:
    .autostring 34 2 "Ich bin von den Ruinen dieser antiken Welt fasziniert.\pWie konnten Menschen hier oben überhaupt irgendetwas erbauen?"
.elseif LANG_EN
str_0:
    .autostring 34 2 "My parents were obsessed with the cloud ruins.\pAnd somehow this obesession was passed down to me.\pWhere does the magic of this place come from?"
str_1:
    .autostring 34 2 "This place has a very old history.\pAccording to the legends its inhabitants woreshipped a whole set of deities that controlled the worlds course ever since."
str_2:
    .autostring 34 2 "I am fascinated by the ruins of this ancient world.\pHow were people able to build even anything up here?"

.endif