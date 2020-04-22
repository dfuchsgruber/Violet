.include "overworld_script.s"
.include "callstds.s"

.global ow_script_blackbeard_ship_storage_trainer0
.global ow_script_blackbeard_ship_storage_trainer1
.global ow_script_blackbeard_ship_storage_trainer2
.global ow_script_blackbeard_ship_storage_trainer3
.global ow_script_blackbeard_ship_storage_trainer4
.global ow_script_blackbeard_ship_storage_trainer5

ow_script_blackbeard_ship_storage_trainer0:
    trainerbattlestd 0 0x184 0 str_before0 str_after0
    loadpointer 0 str_after0
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_storage_trainer1:
    trainerbattlestd 0 0x185 0 str_before1 str_after1
    loadpointer 0 str_after1
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_storage_trainer2:
    trainerbattlestd 0 0x186 0 str_before2 str_after2
    loadpointer 0 str_after2
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_storage_trainer3:
    trainerbattlestd 0 0x187 0 str_before3 str_after3
    loadpointer 0 str_after3
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_storage_trainer4:
    trainerbattlestd 0 0x188 0 str_before4 str_after4
    loadpointer 0 str_after4
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_storage_trainer5:
    trainerbattlestd 0 0x189 0 str_before5 str_after5
    loadpointer 0 str_after5
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Hey du!\nWas hast du hier zu suchen?\pDu solltest in deiner Zelle verrotten!"
str_after0:
    .autostring 34 2 "Wie bist du an deine Pokémon gekommen?"
str_before1:
    .autostring 34 2 "Willst du etwa unser Lager plündern?\pDas werden wir noch sehen, Kindchen!"
str_after1:
    .autostring 34 2 "Wie gemein!\nEinen Piraten auszuraubenDOTS"
str_before2:
    .autostring 34 2 "Du bist nicht mehr in deiner Zelle?\pKapitän Blackbeard wird außer sich sein, wenn ich dich nicht wieder einfange."
str_after2:
    .autostring 34 2 "Jetzt hat mein letztes Stündlein geschlagenDOTS"
str_before3:
    .autostring 34 2 "He!\nStehen geblieben!\pHier im Lager hast du nichts verloren!"
str_after3:
    .autostring 34 2 "Du bist nicht gerade schwachDOTS"
str_before4:
    .autostring 34 2 "Bist du nicht unser Gefangener?\pWas machst du hier auf freiem Fuß?"
str_after4:
    .autostring 34 2 "Moment!\pSo geht das doch nichtDOTS"
str_before5:
    .autostring 34 2 "Genug herumgestreunert!\pIch führe dich direkt zurück in deine gemütliche Zelle!"
str_after5:
    .autostring 34 2 "Uff, ich habe dich etwas unterschätzt, du RotznaseDOTS"
.elseif LANG_EN
.endif