.include "overworld_script.s"
.include "levelscript_types.s"
.include "vars.s"
.include "flags.s"
.include "specials.s"

.global map_13_2_route_9_cave_levelscripts
.global ow_script_route_9_cave_puzzle_solved

map_13_2_route_9_cave_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_LOAD 
    .word levelscript_on_load
    .byte 0

levelscript_on_load:
    checkflag FLAG_ROUTE_9_CAVE_PUZZLE_SOLVED
    callif 1 ow_script_route_9_cave_puzzle_solved
    special SPECIAL_ROUTE_9_CAVE_PUZZLE_RESET
    end
ow_script_route_9_cave_puzzle_solved:
    setmaptile 0xC 0x4 0x28B 1
    setmaptile 0xD 0x4 0x28C 1
    setmaptile 0xE 0x4 0x28D 1
    setmaptile 0xC 0x5 0x293 1
    setmaptile 0xD 0x5 0x294 0
    setmaptile 0xE 0x5 0x295 1
    return