.include "vars.s"
.include "levelscript_types.s"
.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"
.include "person_behaviours.s"

.equ SPARK_YELLOW, 1
.equ SPARK_BLUE, 0

.macro hide_spark_horizontal x:req y:req
    setmaptile \x, \y, 0x282, 0
    setmaptile (\x + 1), \y, 0x282, 0
    setmaptile (\x + 2), \y, 0x287, 0
    setmaptile \x, (\y + 1), 0x282, 0
    setmaptile (\x + 1), (\y + 1), 0x282, 0
    setmaptile (\x + 2), (\y + 1), 0x287, 0
.endm

.macro show_spark_horizontal x:req y:req color:req
    setmaptile \x, \y, (0x2dc + (8 *\color)), 0, level=(0xb * 4)
    setmaptile (\x + 1), \y, (0x2dd + (8 *\color) + 1), 0, level=(0xb * 4)
    setmaptile (\x + 2), \y, (0x2ef + (8 *\color)), 0, level=(0xb * 4)
    setmaptile \x, (\y + 1), (0x2dc + (8 *\color)), 1
    setmaptile (\x + 1), (\y + 1), (0x2dd + (8 *\color) + 1), 1
    setmaptile (\x + 2), (\y + 1), (0x2ef + (8 *\color)), 1
.endm

.macro hide_spark_vertical x:req y:req
    setmaptile \x, (\y), 0x2d4, 1
    setmaptile \x, (\y + 1), 0x298, 0
    setmaptile \x, (\y + 2), 0x282, 0
    setmaptile \x, (\y + 3), 0x282, 0
    setmaptile (\x + 1), (\y), 0x2d4, 1
    setmaptile (\x + 1), (\y + 1), 0x298, 0
    setmaptile (\x + 1), (\y + 2), 0x282, 0
    setmaptile (\x + 1), (\y + 3), 0x282, 0
.endm

.macro show_spark_vertical x:req y:req color:req
    setmaptile \x, (\y), (0x2e8 + \color), 1
    setmaptile \x, (\y + 1), (0x2f0 + \color), 1
    setmaptile \x, (\y + 2), (0x2f8 + \color), 1
    setmaptile \x, (\y + 3), (0x300 + \color), 1
    setmaptile \x + 1, (\y), (0x2e8 + \color), 1
    setmaptile \x + 1, (\y + 1), (0x2f0 + \color), 1
    setmaptile \x + 1, (\y + 2), (0x2f8 + \color), 1
    setmaptile \x + 1, (\y + 3), (0x300 + \color), 1
.endm

.global map_power_plant_inside_levelscripts
.global ow_script_power_plant_inside_hide_blue_sparks
.global ow_script_power_plant_inside_hide_yellow_sparks

.align 4

map_power_plant_inside_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word on_load_script
	.byte 0x0
    
on_load_script:
    compare 0x4000 1
    callif EQUAL ow_script_power_plant_inside_hide_blue_sparks
    compare 0x4000 0
    callif EQUAL ow_script_power_plant_inside_hide_yellow_sparks
    end

ow_script_power_plant_inside_hide_blue_sparks:
    hide_spark_horizontal 0x17 0x12 
    hide_spark_horizontal 0x17 0x1a
    hide_spark_horizontal 0x17 0x29
    hide_spark_horizontal 0x24 0x17
    hide_spark_horizontal 0x24 0x21
    hide_spark_horizontal 0x24 0x9
    hide_spark_horizontal 0x2c 0x24
    hide_spark_vertical 0x6 0x2c
    hide_spark_vertical 0x1e 0x2c
    hide_spark_vertical 0x32 0x1d
    show_spark_vertical 0x5 0x22 SPARK_YELLOW
    show_spark_vertical 0x11 0x2c SPARK_YELLOW
    show_spark_vertical 0x1b 0x13 SPARK_YELLOW
    show_spark_vertical 0x21 0x1d SPARK_YELLOW
    show_spark_vertical 0x28 0xc SPARK_YELLOW
    show_spark_horizontal 0x2c 0x17 SPARK_YELLOW
    
    // Buttons
    setmaptile 0xa, 0x2d, 0x2d0, 0
    setmaptile 0xd, 0x2d, 0x2d2, 0

    setmaptile 0x23, 0x2d, 0x2d0, 0
    setmaptile 0x27, 0x2d, 0x2d2, 0

    setmaptile 0x1c, 0x1d, 0x308, 0
    setmaptile 0x1f, 0x1d, 0x311, 0

    setmaptile 0xa, 0x15, 0x2d0, 0
    setmaptile 0xc, 0x15, 0x2d2, 0

    return

ow_script_power_plant_inside_hide_yellow_sparks:
    show_spark_horizontal 0x17 0x12 SPARK_BLUE
    show_spark_horizontal 0x17 0x1a SPARK_BLUE
    show_spark_horizontal 0x17 0x29 SPARK_BLUE
    show_spark_horizontal 0x24 0x17 SPARK_BLUE
    show_spark_horizontal 0x24 0x21 SPARK_BLUE
    show_spark_horizontal 0x24 0x9 SPARK_BLUE
    show_spark_horizontal 0x2c 0x24 SPARK_BLUE
    show_spark_vertical 0x6 0x2c SPARK_BLUE
    show_spark_vertical 0x1e 0x2c SPARK_BLUE
    show_spark_vertical 0x32 0x1d SPARK_BLUE
    hide_spark_vertical 0x5 0x22
    hide_spark_vertical 0x11 0x2c
    hide_spark_vertical 0x1b 0x13
    hide_spark_vertical 0x21 0x1d
    hide_spark_vertical 0x28 0xc
    hide_spark_horizontal 0x2c 0x17

    // Buttons
    setmaptile 0xa, 0x2d, 0x2d2, 0
    setmaptile 0xd, 0x2d, 0x2d1, 0

    setmaptile 0x23, 0x2d, 0x2d2, 0
    setmaptile 0x27, 0x2d, 0x2d1, 0

    setmaptile 0x1c, 0x1d, 0x309, 0
    setmaptile 0x1f, 0x1d, 0x310, 0

    setmaptile 0xa, 0x15, 0x2d2, 0
    setmaptile 0xc, 0x15, 0x2d1, 0

    return
