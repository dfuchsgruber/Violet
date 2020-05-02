.include "overworld_script.s"
.include "callstds.s"

.global ow_script_blackbeard_ship_cells_trainer0
.global ow_script_blackbeard_ship_cells_trainer1
.global ow_script_blackbeard_ship_cells_trainer2
.global ow_script_blackbeard_ship_cells_trainer3

ow_script_blackbeard_ship_cells_trainer0:
    trainerbattlestd 0 0x18e 0 str_before0 str_after0
    loadpointer 0 str_after0
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_cells_trainer1:
    trainerbattlestd 0 0x18f 0 str_before1 str_after1
    loadpointer 0 str_after1
    callstd MSG_FACE
    end
    end
ow_script_blackbeard_ship_cells_trainer2:
    trainerbattlestd 0 0x190 0 str_before2 str_after2
    loadpointer 0 str_after2
    callstd MSG_FACE
    end
    end
ow_script_blackbeard_ship_cells_trainer3:
    trainerbattlestd 0 0x191 0 str_before3 str_after3
    loadpointer 0 str_after3
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Was hast du in unseren Kajüten zu suchen, Kindchen?"
str_after0:
    .autostring 34 2 "Na gut, du kannst hier bleiben.\pAber leg dich ja nicht in meine Hängematte!"
str_before1:
    .autostring 34 2 "Na sowas!\nEiner unserer Gefangen streunt hier herum.\pWenn ich dich besiege, degradier' ich dich zu unserem neuen Koch!"
str_after1:
    .autostring 34 2 "Wiebitte?\nDu kannst gar nicht kochen?"
str_before2:
    .autostring 34 2 "Dieser Knirps?\nIn meiner Kajüte?\pDir werd' ich helfen!"
str_after2:
    .autostring 34 2 "Was soll's?\nLange wirst du hier ohnehin nicht frei herumlaufen!"
str_before3:
    .autostring 34 2 "Du bist aus deiner Zelle entkommen?\pUnd trotzdem bist du dumm genug, mir direkt in die Arme zu laufen!"
str_after3:
    .autostring 34 2 "Soll ein anderer dich zurück in deine Zelle werfenDOTS"
.elseif LANG_EN
.endif