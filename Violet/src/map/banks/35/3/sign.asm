.include "overworld_script.s"
.include "callstds.s"
.include "specials.s"
.include "flags.s"
.include "items.s"
.include "vars.s"
.include "ordinals.s"
.include "specials.s"
.include "map_weathers.s"
.include "person_behaviours.s"

.macro lightning x:req y:req
	setvar 0x8004 \x
	setvar 0x8005 \y
	special SPECIAL_OVERWORLD_EFFECT_LIGHTNING
	sound 111
.endm

.global ow_script_sonnaufeld_clouds_red_lock
.global ow_script_sonnaufeld_clouds_blue_lock
.global ow_script_sonnaufeld_clouds_green_lock
.global ow_script_sonnaufeld_clouds_yellow_lock
.global ow_script_sonnaufeld_shrine

ow_script_sonnaufeld_shrine:
    checkflag FLAG_UNOWN_ENABLED
    gotoif NOT_EQUAL shrine_not_enabled
    loadpointer 0 str_shrine
    callstd MSG
    end
shrine_not_enabled:
    loadpointer 0 str_shrine_not_enabled
    callstd MSG
    end

ow_script_sonnaufeld_clouds_red_lock:
    checkflag FLAG_ROTES_ZAHNRAD_PLACED
    gotoif EQUAL unlocked
    setvar 0x8004 ITEM_ROTES_ZAHNRAD
    call tower_check_activation
    call ow_script_sonnaufeld_clouds_set_red_gear
    call tower_activate
    setflag FLAG_ROTES_ZAHNRAD_PLACED
    goto show_shrine
    end
ow_script_sonnaufeld_clouds_blue_lock:
    checkflag FLAG_BLAUES_ZAHNRAD_PLACED
    gotoif EQUAL unlocked
    setvar 0x8004 ITEM_BLAUES_ZAHNRAD
    call tower_check_activation
    call ow_script_sonnaufeld_clouds_set_blue_gear
    call tower_activate
    setflag FLAG_BLAUES_ZAHNRAD_PLACED
    goto show_shrine
    end
ow_script_sonnaufeld_clouds_green_lock:
    checkflag FLAG_GRUENES_ZAHNRAD_PLACED
    gotoif EQUAL unlocked
    setvar 0x8004 ITEM_GRUENES_ZAHNRAD
    call tower_check_activation
    call ow_script_sonnaufeld_clouds_set_green_gear
    call tower_activate
    setflag FLAG_GRUENES_ZAHNRAD_PLACED
    goto show_shrine
    end
ow_script_sonnaufeld_clouds_yellow_lock:
    checkflag FLAG_GELBES_ZAHNRAD_PLACED
    gotoif EQUAL unlocked
    setvar 0x8004 ITEM_GELBES_ZAHNRAD
    call tower_check_activation
    call ow_script_sonnaufeld_clouds_set_yellow_gear
    call tower_activate
    setflag FLAG_GELBES_ZAHNRAD_PLACED
    goto show_shrine
    end

show_shrine:
    checkflag FLAG_ROTES_ZAHNRAD_PLACED
    gotoif NOT_EQUAL locked
    checkflag FLAG_BLAUES_ZAHNRAD_PLACED
    gotoif NOT_EQUAL locked
    checkflag FLAG_GELBES_ZAHNRAD_PLACED
    gotoif NOT_EQUAL locked
    checkflag FLAG_GRUENES_ZAHNRAD_PLACED
    gotoif NOT_EQUAL locked

    fadescreen 1
    setvar 0x8004 0x1d
    setvar 0x8005 0xb
	special SPECIAL_OVERWORLD_VIEWPORT_SET_POSITION
    fadescreen 0
    pause 40
    setweather MAP_WEATHER_CLOUDY
    doweather
    pause 16
    lockall
    applymovement 3 mov_fu
    applymovement 4 mov_fu
    waitmovement 0
    spritebehave 3 BEHAVIOUR_FACE_UP
    spritebehave 4 BEHAVIOUR_FACE_UP
    
    sound 0x15
    applymovement 3 mov_exclam
    applymovement 4 mov_exclam
    waitmovement 0
    checksound
    sound 227
    setvar 0x8004 0x1
    setvar 0x8005 0x1
    setvar 0x8006 0x8
    setvar 0x8007 0x4
    special SPECIAL_EARTHQUAKE
    waitstate
    sound 227
    setvar 0x8004 0x1
    setvar 0x8005 0x1
    setvar 0x8006 32
    setvar 0x8007 0x4
    special SPECIAL_EARTHQUAKE
    setvar 0x8004 0x1d
    setvar 0x8005 0xb
    special SPECIAL_OVERWORLD_EFFECT_LIGHTNING
    pause 32
    setvar 0x8004 0x1c
    setvar 0x8005 0xa
    special SPECIAL_OVERWORLD_EFFECT_LIGHTNING
    pause 16
    setvar 0x8004 0x1d
    setvar 0x8005 0xa
    special SPECIAL_OVERWORLD_EFFECT_LIGHTNING
    pause 8
    setvar 0x8004 0x1e
    setvar 0x8005 0xb
    special SPECIAL_OVERWORLD_EFFECT_LIGHTNING
    pause 64
    resetweather
    call ow_script_sonnaufeld_clouds_show_shrine
    setflag FLAG_SONNAUFELD_SHRINE_VISIBLE
	setvar 0x8004 20
	special SPECIAL_CUTSCENE_SHOW
	waitstate
    pause 100
    fadescreen 1
	special SPECIAL_OVERWORLD_VIEWPORT_SET_TO_PLAYER_POSITION
    fadescreen 0
    end

unlocked:
    loadpointer 0 str_unlocked
    callstd MSG
    end
locked:
    closeonkeypress
    end

tower_activate:
    special SPECIAL_MAP_UPDATE_BLOCKS
    checksound
    pause 24
    sound 227
    setvar 0x8004 0x1
    setvar 0x8005 0x1
    setvar 0x8006 0x8
    setvar 0x8007 0x3
    special SPECIAL_EARTHQUAKE
    pause 64
    loadpointer 0 str_activated
    callstd MSG
    return

tower_check_activation:
    loadpointer 0 str_tower_intro
    callstd MSG
    sound 0x15
    applymovement 0xFF mov_question
    waitmovement 0
    checksound
    loadpointer 0 str_gear_could_be_placed
    callstd MSG_KEEPOPEN
    bufferitem 0 0x8004
    checkitem 0x8004 1
    compare LASTRESULT 1
    gotoif LESS locked
    loadpointer 0 str_ask_place_gear
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL locked
    closeonkeypress
    removeitem 0x8004 1
    pause 16
    sound 10 
    return

.ifdef LANG_GER
str_unlocked:
    .autostring 34 2 "Der Schlüssel rotiert im TurmDOTS\pEs scheint, als hätte er gepasstDOTS"
str_tower_intro:
    .autostring 34 2 "Eine merkwürdige Energie geht von diesem Turm ausDOTS"
str_gear_could_be_placed:
    .autostring 34 2 "Scheinbar befindet sich dort eine Vorrichtung, in die ein Zahnrad passen könnteDOTS"
str_ask_place_gear:
    .autostring 34 2 "Möchtest du den BUFFER_1 platzieren?"
str_activated:
    .autostring 34 2 "Es scheint so, als wäre ein Siegel gebrochen wordenDOTS"
str_shrine:
    .autostring 34 2 "Die Lettern auf diesem Schrein ähneln den Pokémon, die darin gefangen warenDOTS\pEs ist unmöglich, sie zu lesenDOTS"
str_shrine_not_enabled:
    .autostring 34 2 "Die Lettern auf diesem Schrein scheinen in einer völlig fremden Schriftart zu seinDOTS\pEs ist unmöglich, sie zu lesenDOTS"
.elseif LANG_EN
.endif