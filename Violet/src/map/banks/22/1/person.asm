.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_tafelberg_west_clouds_cryptic_house_person_0
.global ow_script_tafelberg_west_clouds_cryptic_house_person_1
.global ow_script_tafelberg_west_clouds_cryptic_house_person_2
.global ow_script_tafelberg_west_clouds_cryptic_house_person_3

ow_script_tafelberg_west_clouds_cryptic_house_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_tafelberg_west_clouds_cryptic_house_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_tafelberg_west_clouds_cryptic_house_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_tafelberg_west_clouds_cryptic_house_person_3:
    checkflag FLAG_TAFELBERG_CLOUDS_CRYPTICS_TM_HIDDEN_POWER
    gotoif EQUAL tm_done
    lock
    faceplayer
    loadpointer 0 str_tm_give
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_TM10
	copyvarifnotzero 0x8001 5
	callstd ITEM_OBTAIN
    compare LASTRESULT 0
    gotoif EQUAL tm_no_space
    setflag FLAG_TAFELBERG_CLOUDS_CRYPTICS_TM_HIDDEN_POWER
tm_done:
    loadpointer 0 str_tm_done
    callstd MSG_FACE
    end
tm_no_space:
    loadpointer 0 str_no_space
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ein Kryptiker spezialisiert sich darauf, die antiken Schriftzeichen, die man hier oben findet, zu entziffern.\pSo können wir über den Untergang dieser verlorenen Welt lernen."
str_1:
    .autostring 34 2 "Das Pokémon Icognito ist bei Kryptikern sehr beliebt.\pDie Zivilisation, die diese Wolkeninseln einst bewohnt hat, benutzte sie als Schriftzeichen."
str_2:
    .autostring 34 2 "Du hast uns wirklich vorgeführt, weißt du das?\pEs mag zwar sein, dass Icognito nicht die stärksten Pokémon sindDOTS\pAber sie bergen den Schlüssel, um die Geheimnisse dieser Wolkeninseln zu lüften."
str_tm_give:
    .autostring 34 2 "Alle Achtung, dass du uns geschlagen hast.\pDie Icognito, die wir Kryptiker studieren, besitzen eine geheime Kraft.\pDie Wenigsten wissen aber, dass auch andere Pokémon diese Kraft nutzen können.\pHier, probier es doch einfach selbst aus."
str_no_space:
    .autostring 34 2 "M-Moment, warte einmal!\pDu hast ja gar keinen Platz dafür!"
str_tm_done:
    .autostring 34 2 "Der Angriff Kraftreserve setzt eine uralte Energie frei.\pSein Typ und seine Stärke sind von Pokémon zu Pokémon unterschiedlich."
.elseif LANG_EN
.endif
