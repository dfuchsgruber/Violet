.include "overworld_script.s"
.include "vars.s"
.include "flags.s"
.include "specials.s"
.include "ordinals.s"
.include "callstds.s"
.include "species.s"

.global ow_script_route_9_cave_stone_0
.global ow_script_route_9_cave_stone_1
.global ow_script_route_9_cave_stone_2
.global ow_script_route_9_cave_stone_3
.global ow_script_route_9_cave_stone_4

ow_script_route_9_cave_stone_0:
    setvar 0x8000 0
    goto stone_script
ow_script_route_9_cave_stone_1:
    setvar 0x8000 1
    goto stone_script
ow_script_route_9_cave_stone_2:
    setvar 0x8000 2
    goto stone_script
ow_script_route_9_cave_stone_3:
    setvar 0x8000 3
    goto stone_script
ow_script_route_9_cave_stone_4:
    setvar 0x8000 4
    goto stone_script

stone_script:
    checkflag FLAG_ROUTE_9_CAVE_PUZZLE_SOLVED
    gotoif 1 solved
    special2 LASTRESULT SPECIAL_ROUTE_9_CAVE_PUZZLE_GET_LAST_ROCK
    comparevars LASTRESULT 0x8000
    gotoif EQUAL failed
    special2 0x8004 SPECIAL_ROUTE_9_CAVE_PUZZLE_GET_STATE
    special SPECIAL_ROUTE_9_CAVE_PUZZLE_ROCK
    special2 LASTRESULT SPECIAL_ROUTE_9_CAVE_PUZZLE_GET_STATE
    compare LASTRESULT 0xFFFF
    gotoif EQUAL failed
    compare LASTRESULT 0
    gotoif EQUAL puzzle_started
    comparevars LASTRESULT 0x8004
    gotoif EQUAL failed
    compare LASTRESULT 10
    gotoif EQUAL unlock_entrance
    loadpointer 0 str_new_connection
    callstd MSG
end_script:
    end

failed:
    loadpointer 0 str_failed
    callstd MSG
    special SPECIAL_ROUTE_9_CAVE_PUZZLE_RESET
    end

solved:
    loadpointer 0 str_solved
    callstd MSG
    end

puzzle_started:
    loadpointer 0 str_puzzle_started
    callstd MSG
    end

unlock_entrance:
    call ow_script_route_9_cave_puzzle_solved
    special SPECIAL_MAP_UPDATE_BLOCKS
    sound 0x21
    loadpointer 0 str_unlock_entrance
    callstd MSG
    checksound
    setflag FLAG_ROUTE_9_CAVE_PUZZLE_SOLVED
    special SPECIAL_ROUTE_9_CAVE_PUZZLE_RESET
    end

.ifdef LANG_GER
str_solved:
    .autostring 34 2 "Ein Bannsiegel wurde gebrochenDOTSDOTSDOTS"
str_puzzle_started:
    .autostring 34 2 "Von diesem Ort scheint eine bösartige Energie auszugehenDOTS\pDiese Steinformation errinert anDOTS"
str_new_connection:
    .autostring 34 2 "Von diesem Ort scheint eine bösartige Energie auszugehenDOTS\pDiese Steinformation errinert anDOTS"
str_unlock_entrance:
    .autostring 34 2 "Von diesem Ort scheint eine bösartige Energie auszugehenDOTS\pDiese Steinformation errinert anDOTS"
str_failed:
    .autostring 34 2 "Von diesem Ort scheint eine bösartige Energie auszugehenDOTS\pDiese Steinformation errinert anDOTS"

.elseif LANG_EN
str_solved:
    .autostring 34 2 "A binding seal was brokenDOTSDOTSDOTS"
str_puzzle_started:
    .autostring 34 2 "An evil energy emerges from this placeDOTS\pThe formation of this rocks resemblesDOTS"
str_new_connection:
    .autostring 34 2 "An evil energy emerges from this placeDOTS\pThe formation of this rocks resemblesDOTS"
str_unlock_entrance:
    .autostring 34 2 "An evil energy emerges from this placeDOTS\pThe formation of this rocks resemblesDOTS"
str_failed:
    .autostring 34 2 "An evil energy emerges from this placeDOTS\pThe formation of this rocks resemblesDOTS"

.endif