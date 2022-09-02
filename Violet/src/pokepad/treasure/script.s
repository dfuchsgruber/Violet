.include "overworld_script.s"
.include "flags.s"
.include "ordinals.s"
.include "callstds.s"

.global ow_script_obtain_treasure_map

@ To be called with the treasure map idx in 0x8004
ow_script_obtain_treasure_map:
    checksound
    fanfare 0x13E
    loadpointer 0 str_found_treasure_map
    callstd MSG_KEEPOPEN
    waitfanfare
    checkflag FLAG_TREASURE_MAPS_APP
    gotoif EQUAL has_app
has_no_app:
    loadpointer 0 str_cant_decipher
    callstd MSG_KEEPOPEN
end_obtain_treasure_map:
    return
has_app:
    loadpointer 0 str_find_treasure
    callstd MSG_KEEPOPEN
    callasm treasure_map_initialize_show
    waitstate
    end


.ifdef LANG_GER
str_found_treasure_map:
    .autostring 34 2 "PLAYER hat eine Schatzkarte gefunden!"
str_cant_decipher:
    .autostring 34 2 "Es ist schwer, die Karte zu verstehenDOTS\pVielleicht kann etwas helfen, die Karte zu entschlüsselnDOTS"
str_find_treasure:
    .autostring 34 2 "Die Karten-App zeigt, wo ein Schatz vergraben liegt!"
.elseif LANG_EN
.endif
