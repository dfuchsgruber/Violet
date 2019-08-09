.include "overworld_script.s"
.include "specials.s"
.include "vars.s"

.global ow_script_ceometria_gym_waiting_room_door_0
.global ow_script_ceometria_gym_waiting_room_door_1
.global ow_script_ceometria_gym_waiting_room_door_2

ow_script_ceometria_gym_waiting_room_door_0:
    @ // Step 1
    setmaptile 1 0 0x2b8 0
    setmaptile 2 0 0x2b9 0
    setmaptile 3 0 0x2ba 0
    setmaptile 1 1 0x2c0 0
    setmaptile 2 1 0x2c1 0
    setmaptile 3 1 0x2c2 0
    setmaptile 1 2 0x2c8 0
    setmaptile 2 2 0x2c9 0
    setmaptile 3 2 0x2ca 0
    setmaptile 1 3 0x2d0 0
    setmaptile 2 3 0x2d1 0
    setmaptile 3 3 0x2d2 0
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 8
    @ // Step 2
    setmaptile 1 0 0x2bb 0
    setmaptile 2 0 0x2bc 0
    setmaptile 3 0 0x2bd 0
    setmaptile 1 1 0x2c3 0
    setmaptile 2 1 0x2c4 0
    setmaptile 3 1 0x2c5 0
    setmaptile 1 2 0x2cb 0
    setmaptile 2 2 0x2cc 0
    setmaptile 3 2 0x2cd 0
    setmaptile 1 3 0x2d3 0
    setmaptile 2 3 0x2d4 0
    setmaptile 3 3 0x2d5 0
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 8
    @ // Step 3
    setmaptile 1 0 0x2be 0
    setmaptile 2 0 0x2be 0
    setmaptile 3 0 0x2be 0
    setmaptile 1 1 0x2c6 0
    setmaptile 2 1 0x2c6 0
    setmaptile 3 1 0x2c6 0
    setmaptile 1 2 0x2ce 0
    setmaptile 2 2 0x2ce 0
    setmaptile 3 2 0x2ce 0
    setmaptile 1 3 0x2d6 0
    setmaptile 2 3 0x2d6 0
    setmaptile 3 3 0x2d6 0
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 32
    setvar CEOMETRIA_GYM_NEXT_ROOM 0
    setvar CEOMETRIA_GYM_PUNISHMENT_ROOM_TRIGGER 0
    warpmuted 19 7 0 255 255
    waitstate
    end 

ow_script_ceometria_gym_waiting_room_door_1:
    @ // Step 1
    setmaptile 6 0 0x2b8 0
    setmaptile 7 0 0x2b9 0
    setmaptile 8 0 0x2ba 0
    setmaptile 6 1 0x2c0 0
    setmaptile 7 1 0x2c1 0
    setmaptile 8 1 0x2c2 0
    setmaptile 6 2 0x2c8 0
    setmaptile 7 2 0x2c9 0
    setmaptile 8 2 0x2ca 0
    setmaptile 6 3 0x2d0 0
    setmaptile 7 3 0x2d1 0
    setmaptile 8 3 0x2d2 0
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 8
    @ // Step 2
    setmaptile 6 0 0x2bb 0
    setmaptile 7 0 0x2bc 0
    setmaptile 8 0 0x2bd 0
    setmaptile 6 1 0x2c3 0
    setmaptile 7 1 0x2c4 0
    setmaptile 8 1 0x2c5 0
    setmaptile 6 2 0x2cb 0
    setmaptile 7 2 0x2cc 0
    setmaptile 8 2 0x2cd 0
    setmaptile 6 3 0x2d3 0
    setmaptile 7 3 0x2d4 0
    setmaptile 8 3 0x2d5 0
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 8
    @ // Step 3
    setmaptile 6 0 0x2be 0
    setmaptile 7 0 0x2be 0
    setmaptile 8 0 0x2be 0
    setmaptile 6 1 0x2c6 0
    setmaptile 7 1 0x2c6 0
    setmaptile 8 1 0x2c6 0
    setmaptile 6 2 0x2ce 0
    setmaptile 7 2 0x2ce 0
    setmaptile 8 2 0x2ce 0
    setmaptile 6 3 0x2d6 0
    setmaptile 7 3 0x2d6 0
    setmaptile 8 3 0x2d6 0
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 32
    setvar CEOMETRIA_GYM_NEXT_ROOM 1
    setvar CEOMETRIA_GYM_PUNISHMENT_ROOM_TRIGGER 0
    warpmuted 19 7 0 255 255
    waitstate
    end 

ow_script_ceometria_gym_waiting_room_door_2:
    @ // Step 1
    setmaptile 11 0 0x2b8 0
    setmaptile 12 0 0x2b9 0
    setmaptile 13 0 0x2ba 0
    setmaptile 11 1 0x2c0 0
    setmaptile 12 1 0x2c1 0
    setmaptile 13 1 0x2c2 0
    setmaptile 11 2 0x2c8 0
    setmaptile 12 2 0x2c9 0
    setmaptile 13 2 0x2ca 0
    setmaptile 11 3 0x2d0 0
    setmaptile 12 3 0x2d1 0
    setmaptile 13 3 0x2d2 0
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 8
    @ // Step 2
    setmaptile 11 0 0x2bb 0
    setmaptile 12 0 0x2bc 0
    setmaptile 13 0 0x2bd 0
    setmaptile 11 1 0x2c3 0
    setmaptile 12 1 0x2c4 0
    setmaptile 13 1 0x2c5 0
    setmaptile 11 2 0x2cb 0
    setmaptile 12 2 0x2cc 0
    setmaptile 13 2 0x2cd 0
    setmaptile 11 3 0x2d3 0
    setmaptile 12 3 0x2d4 0
    setmaptile 13 3 0x2d5 0
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 8
    @ // Step 3
    setmaptile 11 0 0x2be 0
    setmaptile 12 0 0x2be 0
    setmaptile 13 0 0x2be 0
    setmaptile 11 1 0x2c6 0
    setmaptile 12 1 0x2c6 0
    setmaptile 13 1 0x2c6 0
    setmaptile 11 2 0x2ce 0
    setmaptile 12 2 0x2ce 0
    setmaptile 13 2 0x2ce 0
    setmaptile 11 3 0x2d6 0
    setmaptile 12 3 0x2d6 0
    setmaptile 13 3 0x2d6 0
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 32
    setvar CEOMETRIA_GYM_NEXT_ROOM 2
    setvar CEOMETRIA_GYM_PUNISHMENT_ROOM_TRIGGER 0
    warpmuted 19 7 0 255 255
    waitstate
    end 


