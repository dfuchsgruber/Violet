.include "overworld_script.s"
.include "callstds.s"

.global ow_script_blackbeard_ship_cells_person0
.global ow_script_blackbeard_ship_cells_person1
.global ow_script_blackbeard_ship_cells_person2
.global ow_script_blackbeard_ship_cells_person3
.global ow_script_blackbeard_ship_cells_person4
.global ow_script_blackbeard_ship_cells_person5
.global ow_script_blackbeard_ship_cells_person6
.global ow_script_blackbeard_ship_cells_person7

ow_script_blackbeard_ship_cells_person0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_cells_person1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_cells_person2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_cells_person3:
    loadpointer 0 str_3
    callstd MSG
    end
ow_script_blackbeard_ship_cells_person4:
    loadpointer 0 str_4
    callstd MSG
    end
ow_script_blackbeard_ship_cells_person5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_cells_person6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_cells_person7:
    loadpointer 0 str_7
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Seitdem der Kapitän unseren Koch über Bord geschickt hat, essen wir nichts ordentliches mehr.\pIch bin am VerhungernDOTS"
str_1:
    .autostring 34 2 "Versteh mich nicht falschDOTS\pUnser ehemaliger Koch hat miserabele Gerichte zubereitetDOTS\pAber immerhin hatten wir etwas zu essen."
str_2:
    .autostring 34 2 "Wenn ich nicht bald etwas zwischen die Zähne kriege, zettle ich eine Meuterei an!"
str_3:
    .autostring 34 2 "Du Dreckssack!\nDenk ja nicht, dass ich nicht mitkriegen würde, wie du schummelst!"
str_4:
    .autostring 34 2 "Ich soll schummeln?\pKönnte ich beim Würfel betrügen, wäre ich längst reich!\pDu hast einfach nur Pech!"
str_5:
    .autostring 34 2 "Ich will ganz ehrlich sein.\pAls ich meinen Beruf als Matrose an den Nagel gehängt und hier auf der Schattenflut angeheuert habe, wusste ich nicht, in was für schäbigen Kajüten ich zukünftig schlafen würdeDOTS"
str_6:
    .autostring 34 2 "Weißt du, was mir am meisten fehlt auf diesem Schiff?\pNaja, ich sag es mal so!\pHast du auch schon eine einzige Frau an Bord der Schattenflut gesehen?"
str_7:
    .autostring 34 2 "Na sicher ist das hier auf der Schattenflut nicht der Komfort eines Kreuzfahrtschiffes.\pDafür kann man als Pirat tun und lassen, was man möchte.\pFür nichts auf der Welt würde ich diese Freiheit eintauschen!"
.elseif LANG_EN
.endif