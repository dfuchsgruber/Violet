.include "overworld_script.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"
.include "items.s"
.include "callstds.s"
.include "specials.s"

.global ow_script_ardeal_rooms_door
.global ow_script_ardeal_rooms_switch

ow_script_ardeal_rooms_door:
    checkflag FLAG_ARDEAL_TOWER_UNLOCKED
    gotoif EQUAL door_unlocked
    checkitem ITEM_GOLDSCHLUESSEL 1
    compare LASTRESULT 1
    gotoif EQUAL unlock_door
    loadpointer 0 str_door_locked
    callstd MSG_SIGN
    end

door_unlocked:
    loadpointer 0 str_door_unlocked
    callstd MSG_SIGN
    end

unlock_door:
    sound 46
    call map_ardeal_rooms_unlock_tower
    special SPECIAL_MAP_UPDATE_BLOCKS
    checksound
    pause 32
    setflag FLAG_ARDEAL_TOWER_UNLOCKED
    loadpointer 0 str_unlock_door
    callstd MSG_SIGN
    end

ow_script_ardeal_rooms_switch:
    checkflag FLAG_ARDEAL_DUNGEON_UNLOCKED
    gotoif EQUAL dungeon_unlocked
    loadpointer 0 str_ask_unlock_dungeon
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif EQUAL unlock_dungeon
    closeonkeypress
    end

unlock_dungeon:
    sound 46
    checksound
    pause 32
    setflag FLAG_ARDEAL_DUNGEON_UNLOCKED
    loadpointer 0 str_unlock_dungeon
    callstd MSG_SIGN
    end

dungeon_unlocked:
    loadpointer 0 str_dungeon_unlocked
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_door_unlocked:
    .autostring 34 2 "Die Tore sind offen."
str_door_locked:
    .autostring 34 2 "Die Tore sind geschlossen.\pEin Schlüssel könnte sie vielleicht öffnenDOTS"
str_unlock_door:
    .autostring 34 2 "Der Goldschlüssel hat die Tore geöffnet."
str_ask_unlock_dungeon:
    .autostring 34 2 "Hinter den Büchern scheint ein Schalter versteckt zu sein.\pMöchtest du den Schalter betätigen?"
str_unlock_dungeon:
    .autostring 34 2 "Es hört sich so an, als hätte sich irgendwo in der Nähe eine Türe geöffnet!"
str_dungeon_unlocked:
    .autostring 34 2 "Der geheime Schalter wurde betätigt.\pIrgendwo in der Nähe hat sich eine Türe geöffnet!"

.elseif LANG_EN
str_door_unlocked:
    .autostring 34 2 "The doors are opened."
str_door_locked:
    .autostring 34 2 "The doors are closed.\pA key might be able to open them howeverDOTS"
str_unlock_door:
    .autostring 34 2 "The golden key opened the doors."
str_ask_unlock_dungeon:
    .autostring 34 2 "There seems to be a switch hidden behind the books.\pDou you want to use it?"
str_unlock_dungeon:
    .autostring 34 2 "It sounded as if a door opened somewhere nearby!"
str_dungeon_unlocked:
    .autostring 34 2 "The hidden switch was used.\pSomewhere nearby a door has opened!"

.endif