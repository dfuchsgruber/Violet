.include "overworld_script.s"
.include "movements.s"
.include "flags.s"
.include "ordinals.s"
.include "specials.s"

.global ow_script_route_4_clouds_cave_north_button
.global ow_script_route_4_clouds_cave_east_button
.global ow_script_route_4_clouds_cave_south_button
.global ow_script_route_4_clouds_cave_west_button

ow_script_route_4_clouds_cave_north_button:
    pause 32
    sound 10
    call ow_script_route_4_clouds_cave_disable_north_button
    special SPECIAL_MAP_UPDATE_BLOCKS
    checksound
    setvar 0x4001 1
    compare 0x4005 2
    callif EQUAL button_progress
    end
ow_script_route_4_clouds_cave_east_button:
    pause 32
    sound 10
    call ow_script_route_4_clouds_cave_disable_east_button
    special SPECIAL_MAP_UPDATE_BLOCKS
    checksound
    setvar 0x4002 1
    compare 0x4005 0
    callif EQUAL button_progress
    end
ow_script_route_4_clouds_cave_south_button:
    pause 32
    sound 10
    call ow_script_route_4_clouds_cave_disable_south_button
    special SPECIAL_MAP_UPDATE_BLOCKS
    checksound
    setvar 0x4003 1
    compare 0x4005 3
    callif EQUAL show_amber_stone
    end
ow_script_route_4_clouds_cave_west_button:
    pause 32
    sound 10
    call ow_script_route_4_clouds_cave_disable_west_button
    special SPECIAL_MAP_UPDATE_BLOCKS
    checksound
    setvar 0x4004 1
    compare 0x4005 1
    callif EQUAL button_progress
    end

button_progress:
    addvar 0x4005 1 // Setup next button
    return

show_amber_stone:
    fadescreen 1
    setvar 0x8004 28
    setvar 0x8005 12
	special SPECIAL_OVERWORLD_VIEWPORT_SET_POSITION
	fadescreen 0
    sound 37
    clearflag (FLAG_ROUTE_4_AMBER_STONE | 0x8000)
    showsprite 1
    applymovement 1 mov_stone_appear
    waitmovement 0
    checksound
    pause 32
    fadescreen 1
	special SPECIAL_OVERWORLD_VIEWPORT_SET_TO_PLAYER_POSITION
	callasm ow_script_fadescreen_palette_backup
	fadescreen 0
    return

mov_stone_appear:
    .byte SHOW_SPRITE, FLY_OUT_OF_SCREEN, STOP
