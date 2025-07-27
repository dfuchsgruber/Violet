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
    .autostring 34 2 "Wusstest du, dass man die Bücher in einem Pokéstop einfach mitnehmen darf?\pNatürlich wird von einem erwartet, dass man selbst ein anderes zurücklässt.\pAuf diese Weise bleibt die Sammlung immer aktuell!"
str_4:
    .autostring 34 2 "Wiebitte?\nIch soll doch besser auf mein Pokémon Acht geben?\pIch lasse mir von so einem Dreikäsehoch doch nichts vorschreiben!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Are you a Trainer?\pAre you going to challenge the Pokémon League?"
str_1:
    .autostring 34 2 "My friend here is a bit hot-headed.\pHe asks every Trainer if they want to challenge the Pokémon League.\pIt's very embarrassing for me."
str_2:
    .autostring 34 2 "Have you tried using the Laz. Kessel?\pIt can make really fabulous items.\pOf course, only if you know the right recipes."
str_3:
    .autostring 34 2 "Did you know that you can take the books from a Pokéstop?\pOf course, you're expected to leave another book in return.\pThis way, the collection stays up to date!"
str_4:
    .autostring 34 2 "What?\nI should take better care of my Pokémon?\pI won't take orders from some little brat!"

.endif
