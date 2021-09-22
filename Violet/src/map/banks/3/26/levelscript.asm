
.include "overworld_script.s"
.include "levelscript_types.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"

.global map_desert_village_levelscripts
.global ow_script_felsige_oednis_open_regirock_cave

map_desert_village_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_LOAD
	.word cave
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word worldmapflag_script
	.byte 0x0

worldmapflag_script:
	setworldmapflag WM_DESERT_VILLAGE
    end

cave:
	checkflag FLAG_REGIROCK_CAVE_OPENED
	callif EQUAL ow_script_felsige_oednis_open_regirock_cave
	end

.equ REGIROCK_CAVE_WALL_X, 0x14
.equ REGIROCK_CAVE_WALL_Y, 0x4

ow_script_felsige_oednis_open_regirock_cave:
	setmaptile REGIROCK_CAVE_WALL_X + 0, REGIROCK_CAVE_WALL_Y + 0, 0x148, 0x1
	setmaptile REGIROCK_CAVE_WALL_X + 1, REGIROCK_CAVE_WALL_Y + 0,  0x149, 0x1
	setmaptile REGIROCK_CAVE_WALL_X + 2, REGIROCK_CAVE_WALL_Y + 0,  0x14a, 0x1
	setmaptile REGIROCK_CAVE_WALL_X + 0, REGIROCK_CAVE_WALL_Y + 1,  0x150, 0x1
	setmaptile REGIROCK_CAVE_WALL_X + 1, REGIROCK_CAVE_WALL_Y + 1,  0x151, 0x0
	setmaptile REGIROCK_CAVE_WALL_X + 2, REGIROCK_CAVE_WALL_Y + 1,  0x152, 0x1
	setmaptile REGIROCK_CAVE_WALL_X + 0, REGIROCK_CAVE_WALL_Y + 2,  0x158, 0x0
	setmaptile REGIROCK_CAVE_WALL_X + 1, REGIROCK_CAVE_WALL_Y + 2,  0x159, 0x0
	setmaptile REGIROCK_CAVE_WALL_X + 2, REGIROCK_CAVE_WALL_Y + 2,  0x15a, 0x0
	return
