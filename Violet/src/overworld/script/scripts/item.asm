.include "overworld_script.s"
.include "callstds.s"

.global ow_script_no_room_for_giveitem

ow_script_no_room_for_giveitem:
    lock
    faceplayer
    loadpointer 0x0 str_no_room_for_giveitem
    callstd MSG
    release
    end

.ifdef LANG_GER
str_no_room_for_giveitem:
    .autostring 34 2 "Sieht so aus, als hättest du dafür keinen Platz.\pKomm wieder, wenn du Platz für das Item geschaffen hast."
.elseif LANG_EN
str_no_room_for_giveitem:
    .autostring 34 2 "Looks like you don't have room for that.\pCome back once you made room for the item."
.endif