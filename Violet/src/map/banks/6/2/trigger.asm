.include "overworld_script.s"
.include "specials.s"
.include "ordinals.s"
.include "specials.s"
.include "flags.s"

.global ow_script_bruchfels_gym_puzzle_rotate_boulders
.global ow_script_bruchfels_gym_puzzle_room_0_switch
.global ow_script_bruchfels_gym_puzzle_room_0_open_door

ow_script_bruchfels_gym_puzzle_rotate_boulders:
    lockall
    pause 16
    sound 42
    callasm bruchfels_gym_puzzle_rotate_boulders
    pause 16
    checksound
    releaseall
    end

ow_script_bruchfels_gym_puzzle_room_0_switch:
    lockall
    pause 16
    sound 29
    checksound
    addvar 0x4002 1
    compare 0x4002 2
    callif NOT_EQUAL dont_open_door 
    pause 32
    sound 8
    call ow_script_bruchfels_gym_puzzle_room_0_open_door
    special SPECIAL_MAP_UPDATE_BLOCKS
    checksound
    setflag FLAG_BRUCHFELS_GYM_PUZZLE_ROOM_0_SOLVED
    pause 16
dont_open_door:
    releaseall
    end

ow_script_bruchfels_gym_puzzle_room_0_open_door:
    setmaptile 0x6 0x1 0x28e 1
    setmaptile 0x6 0x2 0x296 1
    setmaptile 0x7 0x1 0x28f 1
    setmaptile 0x7 0x2 0x297 0
    setmaptile 0x8 0x1 0x288 1
    setmaptile 0x8 0x2 0x290 1
    return
