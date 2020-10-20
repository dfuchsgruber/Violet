.include "overworld_script.s"
.include "callstds.s"

.global ow_script_blackbeard_ship_cells_trainer0

ow_script_blackbeard_ship_cells_trainer0:
    trainerbattlestd 0 0x18a 0 str_before0 str_after0
    loadpointer 0 str_after0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Hey, was treibst du hier?\pIch bewache die Zelle vom Professor, bis Kapitän Blackbeard mit ihm fertig ist.\pDu hast hier nicht herumzustreunern!"
str_after0:
    .autostring 34 2 "Na warte, bis Blackbeard dich in die Finger kriegt!"
.elseif LANG_EN
.endif