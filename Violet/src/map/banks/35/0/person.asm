.include "overworld_script.s"
.include "callstds.s"

.global ow_script_sonnaufeld_pokestop_person_0
.global ow_script_sonnaufeld_pokestop_person_1
.global ow_script_sonnaufeld_pokestop_person_2
.global ow_script_sonnaufeld_pokestop_person_3
.global ow_script_sonnaufeld_pokestop_person_4

ow_script_sonnaufeld_pokestop_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_sonnaufeld_pokestop_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_sonnaufeld_pokestop_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_sonnaufeld_pokestop_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_sonnaufeld_pokestop_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Du bist ein Trainer, oder?\pHast du etwa vor, die Top-Vier im Kampf herauszufordern?"
str_1:
    .autostring 34 2 "Mein Freund hier ist etwas hitzköpfig.\pEr frägt jeden Trainer, ob er die Pokémon-Liga zum Kampf herausfordern möchteDOTS\pMir ist das sehr unangenehmDOTS"
str_2:
    .autostring 34 2 "Hast du schonmal versucht, den Laz. Kessel zu benutzen?\pDamit kann man wirklich fabelhafte Items herstellen.\pNatürlich nur, wenn du auch die entsprechenden Rezepte kennstDOTS"
str_3:
    .autostring 34 2 "Theto ist so eine große Region.\pOhne eine Karte würde ich mich als Trainer gar nicht wirklich zurecht finden."
str_4:
    .autostring 34 2 "Wiebitte?\nIch soll doch besser auf mein Pokémon Acht geben?\pIch lasse mir von so einem Dreikäsehoch doch nichts vorschreiben!"
.elseif LANG_EN
.endif
