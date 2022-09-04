.include "overworld_script.s"
.include "flags.s"
.include "ordinals.s"
.include "callstds.s"
.include "treasure_map.s"

.global ow_script_obtain_treasure_map

@ To be called with 
@ 0x8004 : the treasure map idx
@ 0x8005 : if it was found or obtained (0 := found, 1 := obtain)
ow_script_obtain_treasure_map:
    callasm treasure_map_set_flag
    checksound
    callasm treasure_map_buffer_number
    compare 0x8005 TREASURE_MAP_FIND
    callif EQUAL load_treasure_map_find
    compare 0x8005 TREASURE_MAP_OBTAIN
    callif EQUAL load_treasure_map_obtain
    fanfare 0x13E
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
    callasm treasure_map_initialize_show
    waitstate
    return
load_treasure_map_find:
    loadpointer 0 str_found_treasure_map
    return
load_treasure_map_obtain:
    loadpointer 0 str_obtained_treasure_map
    return

.ifdef LANG_GER
str_found_treasure_map:
    .autostring 34 2 "PLAYER hat Schatzkarte Nr.BUFFER_1 gefunden!"
str_obtained_treasure_map:
    .autostring 34 2 "PLAYER hat Schatzkarte Nr.BUFFER_1 erhalten!"
str_cant_decipher:
    .autostring 34 2 "Es ist schwer, die Karte zu verstehenDOTS\pVielleicht kann etwas helfen, die Karte zu entschlüsselnDOTS"
.elseif LANG_EN
.endif
