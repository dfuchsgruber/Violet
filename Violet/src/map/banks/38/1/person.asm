.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "items.s"
.include "specials.s"
.include "flags.s"

.global ow_script_sun_moon_tower_bridge_solrocknite
.global ow_script_sun_moon_tower_bridge_lunatonite

ow_script_sun_moon_tower_bridge_solrocknite:
    loadpointer 0 str_take_stone
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL dont_take_stone
    hidesprite LASTTALKED
    copyvarifnotzero 0x8000 ITEM_SONNFELNIT
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
    compare LASTRESULT 0
    gotoif EQUAL no_room_for_item
    call glass_breaking
    loadpointer 0 str_something_fell
    callstd MSG_KEEPOPEN
    setflag FLAG_MEGA_SOLROCKNITE_CHOSEN
    setflag FLAG_MEGA_LUNATONITE_FALLEN
    setflag FLAG_MEGA_SOLROCKNITE
    release
    end

ow_script_sun_moon_tower_bridge_lunatonite:
    loadpointer 0 str_take_stone
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL dont_take_stone
    hidesprite LASTTALKED
    copyvarifnotzero 0x8000 ITEM_LUNASTEINIT
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
    compare LASTRESULT 0
    gotoif EQUAL no_room_for_item
    call glass_breaking
    loadpointer 0 str_something_fell
    callstd MSG_KEEPOPEN
    setflag FLAG_MEGA_SOLROCKNITE_FALLEN
    setflag FLAG_MEGA_LUNATONITE_CHOSEN
    setflag FLAG_MEGA_LUNATONITE
    release
    end

no_room_for_item:
    loadpointer 0 str_no_room_for_item
    callstd MSG_KEEPOPEN
dont_take_stone:
    release
    end

glass_breaking:
    sound 36
    setmaptile 15 7 0x2F1 1
    setmaptile 16 7 0x2F1 1
    setmaptile 17 7 0x2F1 1
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 32
    sound 36
    setmaptile 15 7 0x2F2 1
    setmaptile 16 7 0x2F2 1
    setmaptile 17 7 0x2F2 1
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 32
    sound 36
    setmaptile 15 7 0x2F3 1
    setmaptile 16 7 0x329 1
    setmaptile 17 7 0x2F4 1
    special SPECIAL_MAP_UPDATE_BLOCKS
    hidesprite 0
    hidesprite 1
    pause 32
    return

.ifdef LANG_GER
str_take_stone:
    .autostring 34 2 "Die Brücke sieht instabil aus.\pWillst du das Funkeln trotzdem untersuchen?"
str_no_room_for_item:
    .autostring 34 2 "Du hast keinen Platz mehr im Beutel."
str_something_fell:
    .autostring 34 2 "Etwas scheint heruntergefallen zu seinDOTS"
.elseif LANG_EN
str_take_stone:
    .autostring 34 2 "The bridge looks unstable.\pDo you want to investigate the shimmering?"
str_no_room_for_item:
    .autostring 34 2 "You have no more room in your bag."
str_something_fell:
    .autostring 34 2 "Something seems to have fallenDOTS"
.endif