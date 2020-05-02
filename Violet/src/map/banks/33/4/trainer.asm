.include "overworld_script.s"
.include "callstds.s"

.global ow_script_blackbeard_ship_deck_trainer0
.global ow_script_blackbeard_ship_deck_trainer1
.global ow_script_blackbeard_ship_deck_trainer2
.global ow_script_blackbeard_ship_deck_trainer3
.global ow_script_blackbeard_ship_deck_trainer4
.global ow_script_blackbeard_ship_deck_trainer5

ow_script_blackbeard_ship_deck_trainer0:
    trainerbattlestd 0 0x192 0 str_before0 str_after0
    loadpointer 0 str_after0
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_trainer1:
    trainerbattlestd 0 0x193 0 str_before1 str_after1
    loadpointer 0 str_after1
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_trainer2:
    trainerbattlestd 0 0x194 0 str_before2 str_after2
    loadpointer 0 str_after2
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_trainer3:
    trainerbattlestd 0 0x195 0 str_before3 str_after3
    loadpointer 0 str_after3
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_trainer4:
    trainerbattlestd 0 0x196 0 str_before4 str_after4
    loadpointer 0 str_after4
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_trainer5:
    trainerbattlestd 0 0x197 0 str_before5 str_after5
    loadpointer 0 str_after5
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Na sieh mal einer an!\pDas ich auf dem Ausguck auch noch kämpfen darf!"
str_after0:
    .autostring 34 2 "Selbst eine Niederlage ist hier oben eine willkommene Abwechslung."
str_before1:
    .autostring 34 2 "Ein Gefangener an Deck?\pDich beseitige ich besser, bevor die Kapitän Wind davon kriegt."
str_after1:
    .autostring 34 2 "Oh je, ich ahne nichts GutesDOTS"
str_before2:
    .autostring 34 2 "Es überrascht mich nicht, dass die anderen Pappnasen dich aus der Zelle entkommen haben lassen.\pAber hier ist Schluss, Kindchen!"
str_after2:
    .autostring 34 2 "Hmpf.\nDu hast betrogen, was?"
str_before3:
    .autostring 34 2 "Einen Gefangen lasse ich hier ganz sicher nicht umherwandern!"
str_after3:
    .autostring 34 2 "Tangela-Grütze!\nIch hab mich doch glatt besiegen lassenDOTS"
str_before4:
    .autostring 34 2 "Ganz schön waghalsig von dir, hier so weit oben Ärger zu machen!\pWenn du Pech hast, stoße ich dich ins Meer hinunter!"
str_after4:
    .autostring 34 2 "Uah!\nIch gerate ins TaumelnDOTS"
str_before5:
    .autostring 34 2 "Wie bist du so nah an die Kabine des Kapitäns gekommen?\pIch kann dich hier auf gar keinen Fall durchlassen!"
str_after5:
    .autostring 34 2 "Blackbeard lässt mich Kiel holen, wenn er das erfährtDOTS"

.elseif LANG_EN
.endif