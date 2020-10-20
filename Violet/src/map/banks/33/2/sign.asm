.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "specials.s"
.include "ordinals.s"

.global ow_script_blackbeard_ship_storage_treasure_room_door

ow_script_blackbeard_ship_storage_treasure_room_door:
    checkflag FLAG_BBSHIP_KEY_TO_TREASURE_ROOM
    gotoif EQUAL unlock
    loadpointer 0 str_locked
    callstd MSG
    end
unlock:
    pause 16
    call ow_script_blackbeard_ship_storage_open_treasure_room
    special SPECIAL_MAP_UPDATE_BLOCKS
    sound 46
    checksound
    pause 16
    loadpointer 0 str_unlock
    callstd MSG
    setflag FLAG_BBSHIP_TREASURE_ROOM_UNLOCKED
    end

.ifdef LANG_GER
str_locked:
    .autostring 34 2 "Die Türe ist verschlossen."
str_unlock:
    .autostring 34 2 "PLAYER benutzt den Schlüssel zur Schatzkammer, um die Türe zu öffnen."
.elseif LANG_EN
.endif