.include "overworld_script.s"
.include "callstds.s"

.global ow_script_blackbeard_ship_canon_room_trainer0

ow_script_blackbeard_ship_canon_room_trainer0:
    trainerbattlestd 0 0x18b 0 str_before0 str_after0
    loadpointer 0 str_after0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Ein Gefangener auf dem Kanondeck?\pDas riecht nach Ärger!\nOder ist dieser Geruch doch bloß das Schwarzpulver?"
str_after0:
    .autostring 34 2 "Vor lauter Schwarzpulver konnte ich nichts sehenDOTS"
.elseif LANG_EN
.endif