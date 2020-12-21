.include "overworld_script.s"
.include "callstds.s"

.global ow_script_kaskada_house_0_person_0
.global ow_script_kaskada_house_0_person_1
.global ow_script_kaskada_house_0_person_2

ow_script_kaskada_house_0_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_kaskada_house_0_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_kaskada_house_0_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Opi verbringt den ganzen Tag mit seinen BüchernDOTS\pDas ist doch sowas von öde!"
str_1:
    .autostring 34 2 "Es ist wirklich bedauerlich, dass ich meine Leidenschaft fürs Lesen erst im Alter entwickelt habe.\pWie viel mir mein Wissensschatz doch in meinen jungen Jahren geholfen hätteDOTS"
str_2:
    .autostring 34 2 "Mein Schwiegervater hat sich eine ganze Reihe teurer Bücher bestellt.\pUnd dreimal darfst du raten, wer das ganze bezahlen mussDOTS"

.elseif LANG_EN
.endif