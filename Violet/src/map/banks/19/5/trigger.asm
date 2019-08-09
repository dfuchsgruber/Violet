.include "overworld_script.s"
.include "specials.s"
.include "ordinals.s"
.include "vars.s"
.include "flags.s"

.global ow_script_ceometria_gym_entrance_door

ow_script_ceometria_gym_entrance_door:
    @ // Step 1
    setmaptile 2 0 0x2b8 0
    setmaptile 3 0 0x2b9 0
    setmaptile 4 0 0x2ba 0
    setmaptile 2 1 0x2c0 0
    setmaptile 3 1 0x2c1 0
    setmaptile 4 1 0x2c2 0
    setmaptile 2 2 0x2c8 0
    setmaptile 3 2 0x2c9 0
    setmaptile 4 2 0x2ca 0
    setmaptile 2 3 0x2d0 0
    setmaptile 3 3 0x2d1 0
    setmaptile 4 3 0x2d2 0
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 8
    @ // Step 2
    setmaptile 2 0 0x2bb 0
    setmaptile 3 0 0x2bc 0
    setmaptile 4 0 0x2bd 0
    setmaptile 2 1 0x2c3 0
    setmaptile 3 1 0x2c4 0
    setmaptile 4 1 0x2c5 0
    setmaptile 2 2 0x2cb 0
    setmaptile 3 2 0x2cc 0
    setmaptile 4 2 0x2cd 0
    setmaptile 2 3 0x2d3 0
    setmaptile 3 3 0x2d4 0
    setmaptile 4 3 0x2d5 0
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 8
    @ // Step 3
    setmaptile 2 0 0x2be 0
    setmaptile 3 0 0x2be 0
    setmaptile 4 0 0x2be 0
    setmaptile 2 1 0x2c6 0
    setmaptile 3 1 0x2c6 0
    setmaptile 4 1 0x2c6 0
    setmaptile 2 2 0x2ce 0
    setmaptile 3 2 0x2ce 0
    setmaptile 4 2 0x2ce 0
    setmaptile 2 3 0x2d6 0
    setmaptile 3 3 0x2d6 0
    setmaptile 4 3 0x2d6 0
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 32
    checkflag FRBADGE_5
    gotoif 1 ow_script_ceometria_gym_warp_to_gym_leader
    warpmuted 19 6 0 255 255
    waitstate
    end 


