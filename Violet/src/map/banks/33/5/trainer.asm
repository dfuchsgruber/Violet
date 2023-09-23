.include "overworld_script.s"
.include "callstds.s"

.global ow_script_blackbeard_ship_canon_room_trainer1

ow_script_blackbeard_ship_canon_room_trainer1:
    trainerbattlestd 0 0x18d 0 str_before1 str_after1
    loadpointer 0 str_after1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Was hast du hier zu suchen?\pWir Piraten schlafen auf diesem Deck!\pVerzieh dich, du Rotzlöffel!"
str_after0:
    .autostring 34 2 "Wenn wir dich in die Finger kriegenDOTS"
str_before1:
    .autostring 34 2 "Auf diesem Schiff sind dir Ruhm und Reichtum sicher!\pDavon verstehst du nichts!"
str_after1:
    .autostring 34 2 "ArghDOTS\pWillst du unsere Schätze stehlen?"
.elseif LANG_EN
.endif