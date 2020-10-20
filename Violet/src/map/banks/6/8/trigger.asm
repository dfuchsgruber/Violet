.include "overworld_script.s"
.include "specials.s"
.include "ordinals.s"
.include "specials.s"
.include "flags.s"

.global ow_script_bruchfels_gym_puzzle_flip_boulders_horizontally
.global ow_script_bruchfels_gym_puzzle_flip_boulders_vertically
.global ow_script_bruchfels_gym_puzzle_room_1_switch
.global ow_script_bruchfels_gym_puzzle_room_1_open_door

ow_script_bruchfels_gym_puzzle_flip_boulders_horizontally:
    lockall
    pause 16
    sound 42
    callasm bruchfels_gym_puzzle_flip_boulders_horizontally
    pause 16
    checksound
    releaseall
    end

ow_script_bruchfels_gym_puzzle_flip_boulders_vertically:
    lockall
    pause 16
    sound 42
    callasm bruchfels_gym_puzzle_flip_boulders_vertically
    pause 16
    checksound
    releaseall
    end

ow_script_bruchfels_gym_puzzle_room_1_switch:
    lockall
    pause 16
    sound 29
    checksound
    addvar 0x4002 1
    compare 0x4002 3
    callif NOT_EQUAL dont_open_door 
    pause 32
    sound 8
    call ow_script_bruchfels_gym_puzzle_room_1_open_door
    special SPECIAL_MAP_UPDATE_BLOCKS
    checksound
    setflag FLAG_BRUCHFELS_GYM_PUZZLE_ROOM_1_SOLVED
    pause 16
dont_open_door:
    releaseall
    end

ow_script_bruchfels_gym_puzzle_room_1_open_door:
    setmaptile 0x5 0x1 0x28e 1
    setmaptile 0x5 0x2 0x296 1
    setmaptile 0x6 0x1 0x28f 1
    setmaptile 0x6 0x2 0x297 0
    setmaptile 0x7 0x1 0x288 1
    setmaptile 0x7 0x2 0x290 1
    return
