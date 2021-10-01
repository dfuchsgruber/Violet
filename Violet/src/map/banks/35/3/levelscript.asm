.include "levelscript_types.s"
.include "overworld_script.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"

.global sonnaufeld_clouds_levelscripts
.global ow_script_sonnaufeld_clouds_set_red_gear
.global ow_script_sonnaufeld_clouds_set_blue_gear
.global ow_script_sonnaufeld_clouds_set_yellow_gear
.global ow_script_sonnaufeld_clouds_set_green_gear
.global ow_script_sonnaufeld_clouds_show_shrine

sonnaufeld_clouds_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word levelscript_set_blocks
	.byte LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE
	.word levelscript_player_set_on_cloud
    .byte 0

levelscript_set_blocks:
    checkflag FLAG_ROTES_ZAHNRAD_PLACED
    callif EQUAL ow_script_sonnaufeld_clouds_set_red_gear
    checkflag FLAG_BLAUES_ZAHNRAD_PLACED
    callif EQUAL ow_script_sonnaufeld_clouds_set_blue_gear
    checkflag FLAG_GELBES_ZAHNRAD_PLACED
    callif EQUAL ow_script_sonnaufeld_clouds_set_yellow_gear
    checkflag FLAG_GRUENES_ZAHNRAD_PLACED
    callif EQUAL ow_script_sonnaufeld_clouds_set_green_gear
    checkflag FLAG_SONNAUFELD_SHRINE_VISIBLE
    callif EQUAL ow_script_sonnaufeld_clouds_show_shrine
    end

.equ RED_GEAR_X, 0x3
.equ RED_GEAR_Y, 0xC
ow_script_sonnaufeld_clouds_set_red_gear:
    setmaptile RED_GEAR_X, RED_GEAR_Y, 0x282, 1
    setmaptile RED_GEAR_X + 1, RED_GEAR_Y, 0x283, 1
    setmaptile RED_GEAR_X, RED_GEAR_Y + 1, 0x28a, 1
    setmaptile RED_GEAR_X + 1, RED_GEAR_Y + 1, 0x28b, 1
    return

.equ BLUE_GEAR_X, 0xf
.equ BLUE_GEAR_Y, 0x3
ow_script_sonnaufeld_clouds_set_blue_gear:
    setmaptile BLUE_GEAR_X, BLUE_GEAR_Y, 0x292, 1
    setmaptile BLUE_GEAR_X + 1, BLUE_GEAR_Y, 0x293, 1
    setmaptile BLUE_GEAR_X, BLUE_GEAR_Y + 1, 0x29a, 1
    setmaptile BLUE_GEAR_X + 1, BLUE_GEAR_Y + 1, 0x29b, 1
    return

.equ YELLOW_GEAR_X, 0x37
.equ YELLOW_GEAR_Y, 0xC
ow_script_sonnaufeld_clouds_set_yellow_gear:
    setmaptile YELLOW_GEAR_X, YELLOW_GEAR_Y, 0x294, 1
    setmaptile YELLOW_GEAR_X + 1, YELLOW_GEAR_Y, 0x295, 1
    setmaptile YELLOW_GEAR_X, YELLOW_GEAR_Y + 1, 0x29c, 1
    setmaptile YELLOW_GEAR_X + 1, YELLOW_GEAR_Y + 1, 0x29d, 1
    return

.equ GREEN_GEAR_X, 0x2b
.equ GREEN_GEAR_Y, 0x3
ow_script_sonnaufeld_clouds_set_green_gear:
    setmaptile GREEN_GEAR_X, GREEN_GEAR_Y, 0x284, 1
    setmaptile GREEN_GEAR_X + 1, GREEN_GEAR_Y, 0x285, 1
    setmaptile GREEN_GEAR_X, GREEN_GEAR_Y + 1, 0x28c, 1
    setmaptile GREEN_GEAR_X + 1, GREEN_GEAR_Y + 1, 0x28d, 1
    return

.equ SHRINE_X, 0x1C
.equ SHRINE_Y, 0x9
ow_script_sonnaufeld_clouds_show_shrine:
    setmaptile SHRINE_X, SHRINE_Y, 0x2a2, 1
    setmaptile SHRINE_X + 1, SHRINE_Y, 0x2a3, 1
    setmaptile SHRINE_X + 2, SHRINE_Y, 0x2a4, 1
    setmaptile SHRINE_X, SHRINE_Y + 1, 0x2aa, 1
    setmaptile SHRINE_X + 1, SHRINE_Y + 1, 0x2ab, 1
    setmaptile SHRINE_X + 2, SHRINE_Y + 1, 0x2ac, 1
    setmaptile SHRINE_X, SHRINE_Y + 2, 0x2b2, 1
    setmaptile SHRINE_X + 1, SHRINE_Y + 2, 0x2b3, 1
    setmaptile SHRINE_X + 2, SHRINE_Y + 2, 0x2b4, 1
    return
