.include "overworld_script.s"
.include "levelscript_types.s"
.include "movements.s"
.include "flags.s"
.include "ordinals.s"

.global route_4_clouds_cave_levelscripts
.global ow_script_route_4_clouds_cave_disable_north_button
.global ow_script_route_4_clouds_cave_disable_east_button
.global ow_script_route_4_clouds_cave_disable_south_button
.global ow_script_route_4_clouds_cave_disable_west_button

route_4_clouds_cave_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word lscr_on_load
    .byte 0

lscr_on_load:
    compare 0x4001 1
    callif EQUAL ow_script_route_4_clouds_cave_disable_north_button
    compare 0x4002 1
    callif EQUAL ow_script_route_4_clouds_cave_disable_east_button
    compare 0x4003 1
    callif EQUAL ow_script_route_4_clouds_cave_disable_south_button
    compare 0x4004 1
    callif EQUAL ow_script_route_4_clouds_cave_disable_west_button
    checkflag FLAG_ROUTE_4_AMBER_STONE_QUEST_DONE
    gotoif 1 disable_buttons
    // If the amber stone is visible but the quest is not done, the buttons also are disabled
    checkflag FLAG_ROUTE_4_AMBER_STONE
    gotoif 1 disable_buttons
    end

disable_buttons:
    call ow_script_route_4_clouds_cave_disable_north_button
    call ow_script_route_4_clouds_cave_disable_east_button
    call ow_script_route_4_clouds_cave_disable_south_button
    call ow_script_route_4_clouds_cave_disable_west_button
    end

ow_script_route_4_clouds_cave_disable_north_button:
    setmaptile 0x20 0x13 0x3a 0
    setvar 0x4001 1
    return
ow_script_route_4_clouds_cave_disable_east_button:
    setmaptile 0x28 0x1d 0x3a 0
    setvar 0x4002 1
    return
ow_script_route_4_clouds_cave_disable_south_button:
    setmaptile 0x22 0x2b 0x3a 0
    setvar 0x4003 1
    return
ow_script_route_4_clouds_cave_disable_west_button:
    setmaptile 0x11 0x1d 0x3a 0
    setvar 0x4004 1
    return
