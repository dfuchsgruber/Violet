.include "overworld_script.s"
.include "callstds.s"

.global ow_script_tanns_lab_sign_box
.global ow_script_tanns_lab_sign_machine_0
.global ow_script_tanns_lab_sign_machine_1
.global ow_script_tanns_lab_sign_notes_0
.global ow_script_tanns_lab_sign_notes_1
.global ow_script_tanns_lab_sign_notes_2
.global ow_script_tanns_lab_sign_computer_0
.global ow_script_tanns_lab_sign_computer_1
.global ow_script_tanns_lab_sign_equipment_0
.global ow_script_tanns_lab_sign_whiteboard
.global ow_script_tanns_lab_sign_fridge
.global ow_script_tanns_lab_sign_fossil_0
.global ow_script_tanns_lab_sign_fossil_1

ow_script_tanns_lab_sign_box:
    loadpointer 0 str_box
    callstd MSG_SIGN
    end
ow_script_tanns_lab_sign_machine_0:
    loadpointer 0 str_machine_0
    callstd MSG_SIGN
    end
ow_script_tanns_lab_sign_machine_1:
    loadpointer 0 str_machine_1
    callstd MSG_SIGN
    end
ow_script_tanns_lab_sign_notes_0:
    loadpointer 0 str_notes_0
    callstd MSG_SIGN
    end
ow_script_tanns_lab_sign_notes_1:
    loadpointer 0 str_notes_1
    callstd MSG_SIGN
    end
ow_script_tanns_lab_sign_notes_2:
    loadpointer 0 str_notes_2
    callstd MSG_SIGN
    end
ow_script_tanns_lab_sign_computer_0:
    loadpointer 0 str_computer_0
    callstd MSG_SIGN
    end
ow_script_tanns_lab_sign_computer_1:
    loadpointer 0 str_computer_1
    callstd MSG_SIGN
    end
ow_script_tanns_lab_sign_equipment_0:
    loadpointer 0 str_equipment_0
    callstd MSG_SIGN
    end
ow_script_tanns_lab_sign_whiteboard:
    loadpointer 0 str_whiteboard
    callstd MSG_SIGN
    end
ow_script_tanns_lab_sign_fridge:
    loadpointer 0 str_fridge
    callstd MSG_SIGN
    end
ow_script_tanns_lab_sign_fossil_0:
    loadpointer 0 str_fossil_0
    callstd MSG_SIGN
    end
ow_script_tanns_lab_sign_fossil_1:
    loadpointer 0 str_fossil_1
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_box:
    .autostring 34 2 "In der Box sind allerlei seltsame GerätschaftenDOTS\pIch sollte besser nicht darin herumwühlen."
str_machine_0:
    .autostring 34 2 "Diese Maschine gibt ein seltsames puslierendes Geräusch von sich.\pWenn man genau hinhört, klingt es so, als würden im Inneren kleine Kieselsteine herumgeschleudert werden."
str_machine_1:
    .autostring 34 2 "In der Glasröhre befindet sich eine bläuliche Flüssigkeit.\pSchwimmt darin etwa ein Pokémon?"
str_notes_0:
    .autostring 34 2 "Diese handschriftlichen Notizen sind mit bloßem Auge kaum zu entziffernDOTS"
str_notes_1:
    .autostring 34 2 "Die Notizen wirken wirr.\pEs sind Wörter zu erkennen wie: Atlantea, Flut, Kataklysmus. Einige der Wörter sind mehrfach unterstrichen."
str_notes_2:
    .autostring 34 2 "Die Notizen von Professor Tann.\pEs scheint, um eine alte Ziviliastion zu gehen, die auf in den Wolken schwebenden Inseln gelebt hat."
str_computer_0:
    .autostring 34 2 "Der Computer ist passwortgesichert.\pOb der Account Elise gehört?"
str_computer_1:
    .autostring 34 2 "Einige seltsame Programme scheinen hier zu laufen.\pEines der Fenster zeigt eine sich stetig veränderende Kennlinie.\pWas das wohl zu bedeuten hat?"
str_equipment_0:
    .autostring 34 2 "Das Laborzubehör scheint auf dem neusten Stand der Technik zu sein."
str_whiteboard:
    .autostring 34 2 "Auf dem Whiteboard sind einige komplizierte Formel abgebildet.\pMan kann deutlich zwei verschiedene Handschriften erkennen."
str_fridge:
    .autostring 34 2 "Im Kühlschrank befinden sich einige Gläser voller Laborproben, aber leider nichts zu essen."
str_fossil_0:
    .autostring 34 2 "Das scheint das Fossil eines bereits ausgestorbenen Pokémon zu sein.\pOb Professor Tann es entdeckt hat?"
str_fossil_1:
    .autostring 34 2 "Dieses Pokémon-Fossil muss aus einer längst vergangenen Zeitepoche stammen.\pWas Professor Tann wohl darüber weiß?"
.elseif LANG_EN
.endif