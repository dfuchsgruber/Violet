.include "overworld_script.s"
.include "items.s"
.include "flags.s"
.include "specials.s"
.include "callstds.s"
.include "ordinals.s"
.include "vars.s"

.global ow_script_ceometria_clouds_dark_tower_door
.global ow_script_ceometria_clouds_dark_tower_set_unlocked_door_tiles

ow_script_ceometria_clouds_dark_tower_door:
    checkflag FLAG_DARK_TOWER_UNLOCKED
    gotoif EQUAL unlocked
    loadpointer 0 str_locked
    callstd MSG_SIGN
    checkitem ITEM_GEISTERSCHLUESSEL 1
    compare LASTRESULT 1
    gotoif 0 locked
    pause 32
    call ow_script_ceometria_clouds_dark_tower_set_unlocked_door_tiles
    special SPECIAL_MAP_UPDATE_BLOCKS
    sound 0x21
    checksound
    pause 32
    loadpointer 0 str_unlocked
    callstd MSG_SIGN
    setflag FLAG_DARK_TOWER_UNLOCKED
    end

unlocked:
    loadpointer 0 str_unlocked
    callstd MSG_SIGN
    end

locked:
    end

ow_script_ceometria_clouds_dark_tower_set_unlocked_door_tiles:
    setmaptile 0x20 0x12 0x2CD 1
    setmaptile 0x21 0x12 0x2CE 1
    setmaptile 0x22 0x12 0x2CF 1
    setmaptile 0x20 0x13 0x2D5 1
    setmaptile 0x21 0x13 0x2D6 0
    setmaptile 0x22 0x13 0x2D7 1
    return

.ifdef LANG_GER
str_locked:
    .autostring 34 2 "Die Tür ist verschlossen."
str_unlocked:
    .autostring 34 2 "Der Geisterschlüssel hat die Tür geöffnet."
.elseif LANG_EN
.endif